#ifndef GUARD_GBA_IO_REG_H
#define GUARD_GBA_IO_REG_H

#define REG_BASE 0x04000000

#define REG_ADDR_IE       (REG_BASE + 0x200)
#define REG_ADDR_IF       (REG_BASE + 0x202)
#define REG_ADDR_IME      (REG_BASE + 0x208)
#define REG_ADDR_KEYINPUT (REG_BASE + 0x130)
#define REG_ADDR_WAITCNT  (REG_BASE + 0x204)

#define REG_IE       (*(vu16 *)REG_ADDR_IE)
#define REG_IF       (*(vu16 *)REG_ADDR_IF)
#define REG_IME      (*(vu16 *)REG_ADDR_IME)
#define REG_KEYINPUT (*(vu16 *)REG_ADDR_KEYINPUT)
#define REG_WAITCNT  (*(vu16 *)REG_ADDR_WAITCNT)

#endif // GUARD_GBA_IO_REG_H
