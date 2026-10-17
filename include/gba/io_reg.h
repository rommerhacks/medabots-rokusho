#ifndef GUARD_GBA_IO_REG_H
#define GUARD_GBA_IO_REG_H

#define REG_BASE 0x04000000

#define EWRAM 0x02000000
#define IWRAM 0x03000000
#define VRAM  0x06000000
#define OAM   0x07000000

// BIOS interrupt check flags and IRQ vector, at the top of IWRAM.
#define INTR_CHECK  (*(u16 *)0x03007FF8)
#define INTR_VECTOR (*(void **)0x03007FFC)

#define REG_ADDR_DISPCNT  (REG_BASE + 0x000)
#define REG_ADDR_DISPSTAT (REG_BASE + 0x004)
#define REG_ADDR_BG0CNT   (REG_BASE + 0x008)
#define REG_ADDR_BG1CNT   (REG_BASE + 0x00A)
#define REG_ADDR_BG2CNT   (REG_BASE + 0x00C)
#define REG_ADDR_BG3CNT   (REG_BASE + 0x00E)
#define REG_ADDR_BG0HOFS  (REG_BASE + 0x010)
#define REG_ADDR_BG3HOFS  (REG_BASE + 0x01C)
#define REG_ADDR_WIN0H    (REG_BASE + 0x040)
#define REG_ADDR_WIN0V    (REG_BASE + 0x044)
#define REG_ADDR_WININ    (REG_BASE + 0x048)
#define REG_ADDR_WINOUT   (REG_BASE + 0x04A)
#define REG_ADDR_MOSAIC   (REG_BASE + 0x04C)
#define REG_ADDR_BLDCNT   (REG_BASE + 0x050)
#define REG_ADDR_BLDALPHA (REG_BASE + 0x052)
#define REG_ADDR_BLDY     (REG_BASE + 0x054)
#define REG_ADDR_SOUNDCNT_X (REG_BASE + 0x084)
#define REG_ADDR_DMA0CNT_H (REG_BASE + 0x0BA)

#define REG_ADDR_IE       (REG_BASE + 0x200)
#define REG_ADDR_IF       (REG_BASE + 0x202)
#define REG_ADDR_IME      (REG_BASE + 0x208)
#define REG_ADDR_KEYINPUT (REG_BASE + 0x130)
#define REG_ADDR_WAITCNT  (REG_BASE + 0x204)
#define REG_ADDR_DMA0     (REG_BASE + 0x0B0)
#define REG_ADDR_DMA3     (REG_BASE + 0x0D4)

#define REG_DISPCNT  (*(vu16 *)REG_ADDR_DISPCNT)
#define REG_DISPSTAT (*(vu16 *)REG_ADDR_DISPSTAT)
#define REG_BG0CNT   (*(vu16 *)REG_ADDR_BG0CNT)
#define REG_BG1CNT   (*(vu16 *)REG_ADDR_BG1CNT)
#define REG_BG2CNT   (*(vu16 *)REG_ADDR_BG2CNT)
#define REG_BG3CNT   (*(vu16 *)REG_ADDR_BG3CNT)
#define REG_WIN0H    (*(vu16 *)REG_ADDR_WIN0H)
#define REG_WIN0V    (*(vu16 *)REG_ADDR_WIN0V)
#define REG_WININ    (*(vu16 *)REG_ADDR_WININ)
#define REG_WINOUT   (*(vu16 *)REG_ADDR_WINOUT)
#define REG_MOSAIC   (*(vu16 *)REG_ADDR_MOSAIC)
#define REG_BLDCNT   (*(vu16 *)REG_ADDR_BLDCNT)
#define REG_BLDALPHA (*(vu16 *)REG_ADDR_BLDALPHA)
#define REG_BLDY     (*(vu16 *)REG_ADDR_BLDY)
#define REG_SOUNDCNT_X (*(vu16 *)REG_ADDR_SOUNDCNT_X)
#define REG_DMA0CNT_H (*(vu16 *)REG_ADDR_DMA0CNT_H)
#define REG_IE       (*(vu16 *)REG_ADDR_IE)
#define REG_IF       (*(vu16 *)REG_ADDR_IF)
#define REG_IME      (*(vu16 *)REG_ADDR_IME)
#define REG_KEYINPUT (*(vu16 *)REG_ADDR_KEYINPUT)
#define REG_WAITCNT  (*(vu16 *)REG_ADDR_WAITCNT)

#define PLTT     0x05000000
#define OBJ_PLTT (PLTT + 0x200)

#define DMA_ENABLE   0x80000000
#define DMA_32BIT    0x04000000

// Writes source, destination and control of a DMA channel, then reads the control back.
#define DmaSet(dmaNum, src, dest, control)                  \
{                                                           \
    vu32 *dmaRegs = (vu32 *)REG_ADDR_DMA##dmaNum;           \
    dmaRegs[0] = (vu32)(src);                               \
    dmaRegs[1] = (vu32)(dest);                              \
    dmaRegs[2] = (vu32)(control);                           \
    dmaRegs[2];                                             \
}

#define DmaCopy32(dmaNum, src, dest, size) \
    DmaSet(dmaNum, src, dest, DMA_ENABLE | DMA_32BIT | ((size) / 4))

#endif // GUARD_GBA_IO_REG_H
