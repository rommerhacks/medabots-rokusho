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
gUnk_03002B70       = 0x03002B70;
gUnk_03006D20       = 0x03006D20;
gUnk_03000440       = 0x03000440;
gUnk_03002C30       = 0x03002C30;
gUnk_03007014       = 0x03007014;
gUnk_03005170       = 0x03005170;
gUnk_03001800       = 0x03001800;
gUnk_03000BE0       = 0x03000BE0;
gUnk_030017A0       = 0x030017A0;
gUnk_030057A0       = 0x030057A0;
gUnk_030057E0       = 0x030057E0;
gUnk_03005350       = 0x03005350;
gUnk_03000590       = 0x03000590;

/* ===== ROM data ===== */
gGameStateHandlers_083AC148 = 0x083AC148;
gUnk_083B6410       = 0x083B6410;
gUnk_083BA4D8       = 0x083BA4D8;
gUnk_08484444       = 0x08484444;
gUnk_083AB9D0       = 0x083AB9D0;
gUnk_083BB9CC       = 0x083BB9CC;
gUnk_083ABA88       = 0x083ABA88;
gUnk_083ABA8C       = 0x083ABA8C;
gUnk_083ABAB2       = 0x083ABAB2;
gUnk_083ABAC2       = 0x083ABAC2;
gSoundFifoAddrs     = 0x084873B8;
gSoundFifoDmaCnt    = 0x084873C8;
gSoundTrackConfigs  = 0x083ABBE0;
gSoundSemitoneRatios = 0x083ABAC6;
gSoundFinetuneRatios = 0x083ABADE;
gSoundEffectTracks  = 0x083ABC7C;
gSoundWavePatterns  = 0x080B06AC;
gSoundTimerRegs     = 0x084873C0;
gSoundFifoResetBits = 0x083ABAAC;
gSoundFifoEnableBits = 0x083ABAAE;
gUnk_083ABA62       = 0x083ABA62;
