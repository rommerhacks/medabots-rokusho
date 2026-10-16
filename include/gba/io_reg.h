#ifndef GUARD_GBA_IO_REG_H
#define GUARD_GBA_IO_REG_H

#define REG_BASE 0x04000000

#define REG_ADDR_IE       (REG_BASE + 0x200)
#define REG_ADDR_IF       (REG_BASE + 0x202)
#define REG_ADDR_IME      (REG_BASE + 0x208)
#define REG_ADDR_KEYINPUT (REG_BASE + 0x130)
#define REG_ADDR_WAITCNT  (REG_BASE + 0x204)
#define REG_ADDR_DMA3     (REG_BASE + 0x0D4)

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
