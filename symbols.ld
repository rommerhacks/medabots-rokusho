/* Absolute addresses of variables and data referenced from decompiled C.
   RAM: until the IWRAM/EWRAM layout is reconstructed. ROM: until the data is split out of baserom.gba. */

/* ===== RAM ===== */

/* main.c */
gFrameCounter       = 0x03001780;
gGameMode           = 0x0300178C;
gGameState          = 0x03002B8C;
gGameSubState       = 0x0300137C;

/* keys */
gPrevKeys           = 0x03001790;
gRepeatKeys         = 0x03001798;
gNewKeys            = 0x0300058C;
gReleasedKeys       = 0x03001C00;
gHeldKeys           = 0x03002B64;
gKeyRepeatTimer     = 0x03002418;

/* ===== ROM data ===== */
gGameStateHandlers_083AC148 = 0x083AC148;
