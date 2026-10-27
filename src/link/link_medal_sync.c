// Link handshakes: state 27 (dispatch_fade_substate) exchanges owned-Medal masks over the serial packets
// (0xF4xx / 0xFCxx) and then goes to state 17 or back to mode 0; state 26 (sub_08064A44) syncs on 0xFEDF and
// enters link_menu. sub_08064A74..sub_08064AD4 are the mode-2 entry points (states 26/17/16/20) that
// goto_link_scene in engine/sprite_engine.c picks from.
#include "global.h"

void sub_08064890(void) {
    u32 mask = 0;
    s32 i;

    for (i = 0; i < 30; i++) {
        if (gUnk_03000BE0[i].unk0 & 0x80)
            mask |= 1 << gUnk_03000BE0[i].unk1;
    }
    gUnk_03006F74->unk48 = 0;
    gUnk_03006F74->unk49 = 0;
    gUnk_03006F74->unk4A = 0;
    gUnk_03006F74->unk4B = 0;
    gUnk_03006F74->unk1C = gUnk_03006F74->unk7A ? mask : 0;
    gGameSubState++;
}

void process_fade_transition_step(void) {
    struct Unk_03006F74 *s;
    s32 pkt;
    u32 m;
    s32 i;

    pkt = gUnk_03005010.unk8[gUnk_03000B90 == 0][1];
    s = gUnk_03006F74;
    if (!s->unk7A) {
        if ((pkt & 0xFC00) == 0xF400) {
            m = ((u32)pkt >> 8) & 3;
            s->unk1C |= (pkt & 0xFF) << (m * 8);
            s->unk48 |= 1 << m;
        }
        gUnk_03005010.unk6 = gUnk_03006F74->unk48 | 0xFC00;
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
        if (gUnk_03006F74->unk7A) {
            gGameState = 0x11;
            gGameSubState = 0;
        } else {
            gUnk_03002B68 = gUnk_03006F74->unk1C;
            init_game_mode(0);
        }
    }
}

void dispatch_fade_substate(void) {
    struct FuncTable2 t = gUnk_080AFAE0;

    t.f[gGameSubState]();
}

void sub_08064A44(void) {
    gUnk_03005010.unk6 = 0xFEDF;
    if (gUnk_03005010.unk8[0][1] == 0xFEDF && gUnk_03005010.unk8[1][1] == gUnk_03005010.unk8[0][1]) {
        gGameState = 0x14;
        gGameSubState = 0;
    }
}

void sub_08064A74(void) {
    gGameMode = 2;
    gGameState = 0x1a;
    gGameSubState = 0;
}

void sub_08064A94(void) {
    gGameMode = 2;
    gGameState = 0x11;
    gGameSubState = 0;
}

void sub_08064AB4(void) {
    gGameMode = 2;
    gGameState = 0x10;
    gGameSubState = 0;
}

void sub_08064AD4(void) {
    gGameMode = 2;
    gGameState = 0x14;
    gGameSubState = 0;
}
