#ifndef GUARD_CONSTANTS_TEXT_H
#define GUARD_CONSTANTS_TEXT_H

// Message text bytes (text/message.c): font characters below 0xF7, then control codes. The argument bytes
// that follow a code are listed with it. 0xFE also ends names and other strings that are not messages.
enum {
    TEXT_CODE_WAIT = 0xF7,           // n: wait n frames (0xFF: TEXT_WAIT_INSTANT)
    TEXT_CODE_ALT_FONT = 0xF8,       // toggle the alternate font
    TEXT_CODE_VAR = 0xF9,            // n: print string variable n (0 = gPlayerName, 1-4 = gGameWork.textBuf)
    TEXT_CODE_WAIT_SKIPPABLE = 0xFA, // n: wait n frames, A / B ends the wait early
    TEXT_CODE_PORTRAIT = 0xFB,       // anim set idx: show / change the speaker portrait (set 0xFF = none)
    TEXT_CODE_NEXT_PAGE = 0xFC,      // wait for A / B, then clear the page
    TEXT_CODE_NEW_LINE = 0xFD,
    TEXT_EOS = 0xFE,      // end of a name / string; skipped inside a message
    TEXT_CODE_END = 0xFF, // mode: end of the message (end modes 0-4, gMessageEndModes)
};

// A TEXT_CODE_WAIT / TEXT_CODE_WAIT_SKIPPABLE argument of 0xFF does not wait: it stays in gGameWork.msgWait,
// and from then on message_print_step prints the rest of the message without stopping after each glyph.
#define TEXT_WAIT_INSTANT 0xFF

#endif // GUARD_CONSTANTS_TEXT_H
