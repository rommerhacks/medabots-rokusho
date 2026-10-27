// Serial link (link cable, multiplayer mode): init, per-frame packet send / receive and the serial
// interrupt handler. Used by the link battle / trade screens; AgbMain sends the packet every frame.

#include "global.h"

static u8 serial_link_receive_packets(u32 *dst);

void serial_link_init(void) {
    u32 zero;

    REG_IME = 0;
    REG_IE &= ~0xC0;
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = 0x2000;
    REG_SIOCNT |= 0x4003;
    zero = 0;
    CpuSet(&zero, &gSioLink, 0x05000036);
    CpuSet(link_buffer_swap_arm, gUnk_03005250, 0x04000010);
    CpuSet(serial_multiplayer_transfer_handler, gUnk_03005050, 0x04000048);
    gSioLink.sendIdx = 6;
    gSioLink.recvIdx = 6;
    gSioLink.nextSend = &gSioLink.sendBuf[0];
    gSioLink.curSend = &gSioLink.sendBuf[1];
    gSioLink.curRecv = (void *)gSioLink.recvBuf[0];
    gSioLink.lastRecv = (void *)gSioLink.recvBuf[1];
    gSioLink.recvCheck = gSioLink.recvBuf[2];
    REG_IME = 0;
    REG_IE |= 0x80;
    REG_IME = 1;
}

// The parent marks the link as started so the VBlank handler begins transfers.
void sio_start_transfers(void) {
    if (gSioLink.isParent)
        gSioLink.started = 1;
}

void serial_multiplayer_init(void) {
    REG_IME = 0;
    REG_IE &= ~0xC0;
    REG_IME = 1;
    REG_SIOCNT = 0x2003;
    REG_TM3CNT = 0x63F7;
    REG_IF = 0xC0;
    gSioLink.started = 0;
}

u32 serial_link_init_and_status(u32 *recv) {
    struct SioCnt *cnt = (struct SioCnt *)REG_ADDR_SIOCNT;
    struct SioCnt cur = *cnt;

    switch (gSioLink.running) {
    case 0:
        if (!cur.id) {
            if (!cur.sd || cur.enable)
                break;
            if (!cur.si && gSioLink.sendIdx == 6) {
                REG_IME = 0;
                REG_IE &= ~0x80;
                REG_IE |= 0x40;
                REG_IME = 1;
                cnt->irq = 0;
                REG_TM3CNT = 0x63F7;
                REG_IF = 0xC0;
                gSioLink.isParent = 8;
            }
            gSioLink.running = 1;
        }
    case 1:
        serial_link_receive_packets(recv);
        break;
    }

    gSioLink.frame++;
    return gSioLink.recvOk | (gSioLink.isParent == 8 ? 0x80 : 0) | (gSioLink.connected << 8) |
           (gSioLink.error ? 0x1000 : 0) | (cur.id > 3 ? 0x2000 : 0);
}

void serial_prepare_send_packet(u16 *packet) {
    s32 sum = 0;
    u32 i;

    gSioLink.nextSend->frame = gSioLink.frame;
    gSioLink.nextSend->errFlags = gSioLink.connected ^ gSioLink.recvOk;
    gSioLink.nextSend->checksum = 0;
    CpuSet(packet, gSioLink.nextSend->data, 0x04000001);
    for (i = 0; i < 4; i++)
        sum += ((u16 *)gSioLink.nextSend)[i];
    gSioLink.nextSend->checksum = ~sum;
    gSioLink.sendPending = 1;
}

static u8 serial_link_receive_packets(u32 *dst) {
    u8 (*swapBuffers)(void) = (u8(*)(void))0x03005250; // IWRAM copy of link_buffer_swap_arm
    vu32 unused = 0;
    u8 synced;
    s32 i;
    u32 j;

    synced = swapBuffers();
    gSioLink.recvOk = 0;
    if (synced) {
        for (i = 0; i < 4; i++) {
            struct SioPacket *pkt = &gSioLink.recvCheck[i];
            s32 sum = 0;
            vu32 zero;

            for (j = 0; j < 4; j++)
                sum += ((u16 *)pkt)[j];
            if ((s16)sum == -1) {
                CpuSet(pkt->data, &dst[i], 0x04000001);
                gSioLink.recvOk |= 1 << i;
            }
            zero = 0;
            CpuSet((void *)&zero, pkt->data, 0x05000001);
        }
    }
    gSioLink.connected |= gSioLink.recvOk;
    return gSioLink.recvOk;
}

// Called from the VBlank interrupt while linked: swaps the receive buffers (and the send buffers if a new
// packet is pending), then starts this frame's multiplayer transfer and timer 3.
void sio_vblank_start_frame(void) {
    if (gSioLink.running && gSioLink.started) {
        void *swap;

        gSioLink.recvIdx = -1;
        swap = gSioLink.lastRecv;
        gSioLink.lastRecv = gSioLink.curRecv;
        gSioLink.curRecv = swap;
        if (gSioLink.sendPending) {
            swap = gSioLink.curSend;
            gSioLink.curSend = gSioLink.nextSend;
            gSioLink.nextSend = swap;
            gSioLink.sendPending = 0;
            gSioLink.sendIdx = 0;
        }
        gSioLink.error = ((struct SioMultiCnt *)REG_ADDR_SIOCNT)->error;
        ((struct SioMultiCnt *)REG_ADDR_SIOCNT)->data = 0xFEFE;
        REG_SIOCNT |= 0x80;
        REG_TM3CNT_H = 0xC0;
    }
}

// SIO interrupt handler, run from its IWRAM copy at 0x03005050.
void serial_multiplayer_transfer_handler(void) {
    u16 recv[4];
    s32 i;

    *(unsigned long long *)recv = *(unsigned long long *)REG_ADDR_SIOMULTI0;
    gSioLink.error = ((struct SioMultiCnt *)REG_ADDR_SIOCNT)->error;
    if (recv[0] == 0xFEFE && gSioLink.recvIdx > 3) {
        u16(*p)[6];
        struct SioPacket *q;

        gSioLink.recvIdx = -1;
        p = gSioLink.lastRecv;
        gSioLink.lastRecv = gSioLink.curRecv;
        gSioLink.curRecv = p;
        if (gSioLink.sendPending) {
            q = gSioLink.curSend;
            gSioLink.curSend = gSioLink.nextSend;
            gSioLink.nextSend = q;
            gSioLink.sendPending = 0;
            gSioLink.sendIdx = 0;
        }
        REG_IME = 0;
        INTR_CHECK |= 0x80;
        REG_IME = 1;
    }
    if (gSioLink.sendIdx < 4)
        ((struct SioMultiCnt *)REG_ADDR_SIOCNT)->data = ((u16 *)gSioLink.curSend)[gSioLink.sendIdx];
    if (gSioLink.sendIdx < 5)
        gSioLink.sendIdx++;
    if (gSioLink.recvIdx >= 0) {
        for (i = 0; i < 4; i++)
            gSioLink.curRecv[i][gSioLink.recvIdx] = recv[i];
        if (gSioLink.recvIdx == 3)
            gSioLink.recvDone = 1;
    }
    if (gSioLink.recvIdx < 5)
        gSioLink.recvIdx++;
    if (gSioLink.isParent)
        REG_TM3CNT_H = 0;
    if (gSioLink.sendIdx < 5 && gSioLink.isParent) {
        REG_SIOCNT |= 0x80;
        REG_TM3CNT_H = 0xC0;
    }
}
