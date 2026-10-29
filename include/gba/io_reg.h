#ifndef GUARD_GBA_IO_REG_H
#define GUARD_GBA_IO_REG_H

#define REG_BASE 0x04000000

#define EWRAM 0x02000000
#define IWRAM 0x03000000
#define VRAM 0x06000000
#define OAM 0x07000000

// BIOS interrupt check flags and IRQ vector, at the top of IWRAM.
#define INTR_CHECK (*(u16 *)0x03007FF8)
#define INTR_VECTOR (*(void **)0x03007FFC)

#define REG_ADDR_DISPCNT (REG_BASE + 0x000)
#define REG_ADDR_DISPSTAT (REG_BASE + 0x004)
#define REG_ADDR_VCOUNT (REG_BASE + 0x006)
#define REG_ADDR_BG0CNT (REG_BASE + 0x008)
#define REG_ADDR_BG1CNT (REG_BASE + 0x00A)
#define REG_ADDR_BG2CNT (REG_BASE + 0x00C)
#define REG_ADDR_BG3CNT (REG_BASE + 0x00E)
#define REG_ADDR_BG0HOFS (REG_BASE + 0x010)
#define REG_ADDR_BG0VOFS (REG_BASE + 0x012)
#define REG_ADDR_BG1HOFS (REG_BASE + 0x014)
#define REG_ADDR_BG1VOFS (REG_BASE + 0x016)
#define REG_ADDR_BG2HOFS (REG_BASE + 0x018)
#define REG_ADDR_BG2VOFS (REG_BASE + 0x01A)
#define REG_ADDR_BG3HOFS (REG_BASE + 0x01C)
#define REG_ADDR_BG3VOFS (REG_BASE + 0x01E)
#define REG_ADDR_BG2PA (REG_BASE + 0x020)
#define REG_ADDR_BG2X_L (REG_BASE + 0x028)
#define REG_ADDR_BG2X_H (REG_BASE + 0x02A)
#define REG_ADDR_WIN0H (REG_BASE + 0x040)
#define REG_ADDR_WIN1H (REG_BASE + 0x042)
#define REG_ADDR_WIN0V (REG_BASE + 0x044)
#define REG_ADDR_WIN1V (REG_BASE + 0x046)
#define REG_ADDR_WININ (REG_BASE + 0x048)
#define REG_ADDR_WINOUT (REG_BASE + 0x04A)
#define REG_ADDR_MOSAIC (REG_BASE + 0x04C)
#define REG_ADDR_BLDCNT (REG_BASE + 0x050)
#define REG_ADDR_BLDALPHA (REG_BASE + 0x052)
#define REG_ADDR_BLDY (REG_BASE + 0x054)
#define REG_ADDR_BG3PA (REG_BASE + 0x030)
#define REG_ADDR_BG3PB (REG_BASE + 0x032)
#define REG_ADDR_BG3PC (REG_BASE + 0x034)
#define REG_ADDR_BG3PD (REG_BASE + 0x036)
#define REG_ADDR_BG3X_L (REG_BASE + 0x038)
#define REG_ADDR_BG3X_H (REG_BASE + 0x03A)
#define REG_ADDR_BG3Y_L (REG_BASE + 0x03C)
#define REG_ADDR_BG3Y_H (REG_BASE + 0x03E)
#define REG_ADDR_SOUND1CNT_L (REG_BASE + 0x060)
#define REG_ADDR_SOUND1CNT_H (REG_BASE + 0x062)
#define REG_ADDR_SOUND1CNT_X (REG_BASE + 0x064)
#define REG_ADDR_NR14 (REG_BASE + 0x065)
#define REG_ADDR_SOUND2CNT_L (REG_BASE + 0x068)
#define REG_ADDR_SOUND2CNT_H (REG_BASE + 0x06C)
#define REG_ADDR_NR24 (REG_BASE + 0x06D)
#define REG_ADDR_SOUND3CNT_L (REG_BASE + 0x070)
#define REG_ADDR_SOUND3CNT_H (REG_BASE + 0x072)
#define REG_ADDR_SOUND3CNT_X (REG_BASE + 0x074)
#define REG_ADDR_SOUND4CNT_L (REG_BASE + 0x078)
#define REG_ADDR_SOUND4CNT_H (REG_BASE + 0x07C)
#define REG_ADDR_SOUNDCNT_L (REG_BASE + 0x080)
#define REG_ADDR_NR51 (REG_BASE + 0x081)
#define REG_ADDR_SOUNDCNT_H (REG_BASE + 0x082)
// High byte of SOUNDCNT_H: Direct Sound A/B enable, timer and FIFO reset bits.
#define REG_ADDR_SOUNDCNT_H_HI (REG_BASE + 0x083)
#define REG_ADDR_WAVE_RAM (REG_BASE + 0x090)
#define REG_ADDR_SOUNDCNT_X (REG_BASE + 0x084)
#define REG_ADDR_DMA0CNT_H (REG_BASE + 0x0BA)
#define REG_ADDR_TM3CNT (REG_BASE + 0x10C)
#define REG_ADDR_TM3CNT_H (REG_BASE + 0x10E)
#define REG_ADDR_SIOMULTI0 (REG_BASE + 0x120)
#define REG_ADDR_SIOCNT (REG_BASE + 0x128)
#define REG_ADDR_RCNT (REG_BASE + 0x134)

#define REG_ADDR_IE (REG_BASE + 0x200)
#define REG_ADDR_IF (REG_BASE + 0x202)
#define REG_ADDR_IME (REG_BASE + 0x208)
#define REG_ADDR_KEYINPUT (REG_BASE + 0x130)
#define REG_ADDR_WAITCNT (REG_BASE + 0x204)
#define REG_ADDR_DMA0 (REG_BASE + 0x0B0)
#define REG_ADDR_DMA3 (REG_BASE + 0x0D4)

#define REG_DISPCNT (*(vu16 *)REG_ADDR_DISPCNT)
#define REG_DISPSTAT (*(vu16 *)REG_ADDR_DISPSTAT)
#define REG_VCOUNT (*(vu8 *)REG_ADDR_VCOUNT)
#define REG_BG0CNT (*(vu16 *)REG_ADDR_BG0CNT)
#define REG_BG0HOFS (*(vu16 *)REG_ADDR_BG0HOFS)
#define REG_BG0VOFS (*(vu16 *)REG_ADDR_BG0VOFS)
#define REG_BG1HOFS (*(vu16 *)REG_ADDR_BG1HOFS)
#define REG_BG1VOFS (*(vu16 *)REG_ADDR_BG1VOFS)
#define REG_BG2HOFS (*(vu16 *)REG_ADDR_BG2HOFS)
#define REG_BG2VOFS (*(vu16 *)REG_ADDR_BG2VOFS)
#define REG_BG3HOFS (*(vu16 *)REG_ADDR_BG3HOFS)
#define REG_BG3VOFS (*(vu16 *)REG_ADDR_BG3VOFS)
#define REG_BG1CNT (*(vu16 *)REG_ADDR_BG1CNT)
#define REG_BG2CNT (*(vu16 *)REG_ADDR_BG2CNT)
#define REG_BG3CNT (*(vu16 *)REG_ADDR_BG3CNT)

// Screen (tilemap) block of a background, from its BGxCNT value: bits 8-12 pick one of 32 blocks of 0x800 bytes.
#define BGCNT_SCREEN_BLOCK(cnt) (((cnt) >> 8) & 0x1F)
// Byte offset of that block in VRAM.
#define BGCNT_SCREEN_OFFSET(cnt) (BGCNT_SCREEN_BLOCK(cnt) * 0x800)
// The background's tilemap, 32 entries per row.
#define BG_TILEMAP(cnt) ((u16 *)(VRAM + BGCNT_SCREEN_OFFSET(cnt)))
#define REG_BG2PA (*(vu16 *)REG_ADDR_BG2PA)
#define REG_BG2X_L (*(vu16 *)REG_ADDR_BG2X_L)
#define REG_BG2X_H (*(vu16 *)REG_ADDR_BG2X_H)
#define REG_WIN0H (*(vu16 *)REG_ADDR_WIN0H)
#define REG_WIN1H (*(vu16 *)REG_ADDR_WIN1H)
#define REG_WIN0V (*(vu16 *)REG_ADDR_WIN0V)
#define REG_WIN1V (*(vu16 *)REG_ADDR_WIN1V)
#define REG_WININ (*(vu16 *)REG_ADDR_WININ)
#define REG_WINOUT (*(vu16 *)REG_ADDR_WINOUT)
#define REG_MOSAIC (*(vu16 *)REG_ADDR_MOSAIC)
#define REG_BLDCNT (*(vu16 *)REG_ADDR_BLDCNT)
#define REG_BLDALPHA (*(vu16 *)REG_ADDR_BLDALPHA)
#define REG_BLDY (*(vu16 *)REG_ADDR_BLDY)
#define REG_BG3PA (*(vu16 *)REG_ADDR_BG3PA)
#define REG_BG3PB (*(vu16 *)REG_ADDR_BG3PB)
#define REG_BG3PC (*(vu16 *)REG_ADDR_BG3PC)
#define REG_BG3PD (*(vu16 *)REG_ADDR_BG3PD)
#define REG_BG3X_L (*(vu16 *)REG_ADDR_BG3X_L)
#define REG_BG3X_H (*(vu16 *)REG_ADDR_BG3X_H)
#define REG_BG3Y_L (*(vu16 *)REG_ADDR_BG3Y_L)
#define REG_BG3Y_H (*(vu16 *)REG_ADDR_BG3Y_H)
#define REG_SOUND1CNT_L (*(vu16 *)REG_ADDR_SOUND1CNT_L)
#define REG_SOUND1CNT_H (*(vu16 *)REG_ADDR_SOUND1CNT_H)
#define REG_SOUND1CNT_X (*(vu16 *)REG_ADDR_SOUND1CNT_X)
#define REG_NR14 (*(vu8 *)REG_ADDR_NR14)
#define REG_SOUND2CNT_L (*(vu16 *)REG_ADDR_SOUND2CNT_L)
#define REG_SOUND2CNT_H (*(vu16 *)REG_ADDR_SOUND2CNT_H)
#define REG_NR24 (*(vu8 *)REG_ADDR_NR24)
#define REG_SOUND3CNT_L (*(vu16 *)REG_ADDR_SOUND3CNT_L)
#define REG_SOUND3CNT_H (*(vu16 *)REG_ADDR_SOUND3CNT_H)
#define REG_SOUND3CNT_X (*(vu16 *)REG_ADDR_SOUND3CNT_X)
#define REG_SOUND4CNT_L (*(vu16 *)REG_ADDR_SOUND4CNT_L)
#define REG_SOUND4CNT_H (*(vu16 *)REG_ADDR_SOUND4CNT_H)
#define REG_SOUNDCNT_L (*(vu16 *)REG_ADDR_SOUNDCNT_L)
#define REG_NR51 (*(vu8 *)REG_ADDR_NR51)
#define REG_SOUNDCNT_H (*(vu16 *)REG_ADDR_SOUNDCNT_H)
#define REG_SOUNDCNT_H_HI (*(vu8 *)REG_ADDR_SOUNDCNT_H_HI)
#define REG_SOUNDCNT_X (*(vu16 *)REG_ADDR_SOUNDCNT_X)
#define REG_DMA0CNT_H (*(vu16 *)REG_ADDR_DMA0CNT_H)
#define REG_TM3CNT (*(vu32 *)REG_ADDR_TM3CNT)
#define REG_TM3CNT_H (*(vu16 *)REG_ADDR_TM3CNT_H)
#define REG_SIOCNT (*(vu16 *)REG_ADDR_SIOCNT)
#define REG_RCNT (*(vu16 *)REG_ADDR_RCNT)
#define REG_IE (*(vu16 *)REG_ADDR_IE)
#define REG_IF (*(vu16 *)REG_ADDR_IF)
#define REG_IME (*(vu16 *)REG_ADDR_IME)
#define REG_KEYINPUT (*(vu16 *)REG_ADDR_KEYINPUT)
#define REG_WAITCNT (*(vu16 *)REG_ADDR_WAITCNT)

#define PLTT 0x05000000
#define OBJ_PLTT (PLTT + 0x200)

#define DMA_ENABLE 0x80000000
#define DMA_32BIT 0x04000000

// Writes source, destination and control of a DMA channel, then reads the control back.
#define DmaSet(dmaNum, src, dest, control)                                                                             \
    {                                                                                                                  \
        vu32 *dmaRegs = (vu32 *)REG_ADDR_DMA##dmaNum;                                                                  \
        dmaRegs[0] = (vu32)(src);                                                                                      \
        dmaRegs[1] = (vu32)(dest);                                                                                     \
        dmaRegs[2] = (vu32)(control);                                                                                  \
        dmaRegs[2];                                                                                                    \
    }

#define DmaCopy32(dmaNum, src, dest, size) DmaSet(dmaNum, src, dest, DMA_ENABLE | DMA_32BIT | ((size) / 4))

#endif // GUARD_GBA_IO_REG_H
