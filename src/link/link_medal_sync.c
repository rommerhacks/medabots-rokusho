// Link handshakes: state 27 (link_medal_sync_update, from link_menu) sends the owned-Medal mask over the serial
// packets (0xF4xx data bytes / 0xFCxx acks) and then goes to state 17 or, on the receiving side, stores the mask
// in gUnk_03002B68 and returns to mode 0; state 26 (link_handshake_update) syncs on 0xFEDF and enters link_menu.
// link_enter_* are the mode-2 entry points that goto_link_scene in engine/sprite_engine.c picks from: 26 (from the
// Medals list), 17 Medal trade (Medals screen), 16 Medapart trade (Medaparts screen), 20 link menu (link Robattle).
#include "global.h"

// guess: Medal flag 0x80 = owned; one bit per Medal graphic index.
void link_medal_sync_init(void) {
    u32 mask = 0;
    s32 i;

    for (i = 0; i < 30; i++) {
        if (gMedals[i].flags & 0x80)
            mask |= 1 << gMedals[i].graphicId;
    }
    gMenuWork->unk48 = 0;
    gMenuWork->unk49 = 0;
    gMenuWork->unk4A = 0;
    gMenuWork->unk4B = 0;
    gMenuWork->unk1C = gMenuWork->unk7A ? mask : 0;
    gGameSubState++;
}

void link_medal_sync_exchange(void) {
    struct MenuWork *s;
    s32 pkt;
    u32 m;
    s32 i;

    pkt = gUnk_03005010.unk8[gUnk_03000B90 == 0][1];
    s = gMenuWork;
    if (!s->unk7A) {
        if ((pkt & 0xFC00) == 0xF400) {
            m = ((u32)pkt >> 8) & 3;
            s->unk1C |= (pkt & 0xFF) << (m * 8);
            s->unk48 |= 1 << m;
        }
        gUnk_03005010.unk6 = gMenuWork->unk48 | 0xFC00;
    } else if ((pkt & 0xFF00) == 0xFC00) {
        if (pkt == 0xFC0F)
            gUnk_03005010.unk6 = pkt;
        else {
            m = s->unk1C;
            for (i = 0; i <= 3; i++) {
                if (!((pkt >> i) & 1)) {
                    gUnk_03005010.unk6 = (m & 0xFF) | (i << 8 | 0xF400);
                    break;
                }
                m >>= 8;
            }
        }
    }
    if (gUnk_03005010.unk8[0][1] == 0xFC0F && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1]) {
        if (gMenuWork->unk7A) {
            gGameState = 0x11;
            gGameSubState = 0;
        } else {
            gUnk_03002B68 = gMenuWork->unk1C;
            init_game_mode(0);
        }
    }
}

void link_medal_sync_update(void) {
    struct FuncTable2 t = gUnk_080AFAE0;

    t.f[gGameSubState]();
}

void link_handshake_update(void) {
    gUnk_03005010.unk6 = 0xFEDF;
    if (gUnk_03005010.unk8[0][1] == 0xFEDF && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1]) {
        gGameState = 0x14;
        gGameSubState = 0;
    }
}

void link_enter_handshake(void) {
    gGameMode = 2;
    gGameState = 0x1a;
    gGameSubState = 0;
}

void link_enter_medal_trade(void) {
    gGameMode = 2;
    gGameState = 0x11;
    gGameSubState = 0;
}

void link_enter_medapart_trade(void) {
    gGameMode = 2;
    gGameState = 0x10;
    gGameSubState = 0;
}

void link_enter_menu(void) {
    gGameMode = 2;
    gGameState = 0x14;
    gGameSubState = 0;
}
