	.syntax unified

	thumb_func_start load_battle_field_graphics
load_battle_field_graphics: @ 0x08070A94
	push {r4, lr}
	ldr r0, _08070B78 @ =0x087C481C
	ldr r1, _08070B7C @ =0x02031000
	bl LZ77UnCompVram
	ldr r4, _08070B80 @ =0x040000D4
	ldr r0, _08070B84 @ =0x087C4C5C
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _08070B88 @ =0x84000068
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08070B8C @ =0x085E3AC8
	ldr r1, _08070B90 @ =0x06011B00
	bl LZ77UnCompVram
	ldr r0, _08070B94 @ =0x085E32C0
	ldr r1, _08070B98 @ =0x06012400
	bl LZ77UnCompVram
	ldr r0, _08070B9C @ =0x085E1A0C
	ldr r1, _08070BA0 @ =0x06012D00
	bl LZ77UnCompVram
	ldr r0, _08070BA4 @ =0x085E0A58
	ldr r1, _08070BA8 @ =0x06013600
	bl LZ77UnCompVram
	ldr r0, _08070BAC @ =0x085E3AA8
	str r0, [r4]
	ldr r0, _08070BB0 @ =0x05000200
	str r0, [r4, #4]
	ldr r2, _08070BB4 @ =0x80000010
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08070BB8 @ =0x085E32A0
	str r0, [r4]
	ldr r0, _08070BBC @ =0x05000220
	str r0, [r4, #4]
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08070BC0 @ =0x085E19EC
	str r0, [r4]
	ldr r0, _08070BC4 @ =0x05000240
	str r0, [r4, #4]
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _08070BC8 @ =0x085E0A38
	str r0, [r4]
	ldr r0, _08070BCC @ =0x05000260
	str r0, [r4, #4]
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _08070BD0 @ =0x0807C720
	str r1, [r4]
	ldr r0, _08070BD4 @ =0x050003C0
	str r0, [r4, #4]
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	subs r1, #0x40
	str r1, [r4]
	ldr r0, _08070BD8 @ =0x05000280
	str r0, [r4, #4]
	str r2, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _08070BDC @ =0x0400000A
	ldr r2, _08070BE0 @ =0x00000D05
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _08070BE4 @ =0x00000E06
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _08070BE8 @ =0x00000F07
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #0x42
	movs r3, #0xc4
	lsls r3, r3, #4
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _08070BEC @ =0x00000A0C
	adds r0, r2, #0
	strh r0, [r1]
	ldr r2, _08070BF0 @ =0x03001800
	movs r0, #0
	strb r0, [r2, #0xc]
	ldr r1, _08070BF4 @ =0x03001C04
	strh r0, [r1]
	strh r0, [r1, #2]
	movs r4, #1
	strb r4, [r2, #0xd]
	movs r0, #4
	movs r1, #2
	movs r2, #0
	bl setup_screen_transition_effect_080682CC
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0xf0
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08070BF8 @ =0x0300137C
	str r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08070B78: .4byte 0x087C481C
_08070B7C: .4byte 0x02031000
_08070B80: .4byte 0x040000D4
_08070B84: .4byte 0x087C4C5C
_08070B88: .4byte 0x84000068
_08070B8C: .4byte 0x085E3AC8
_08070B90: .4byte 0x06011B00
_08070B94: .4byte 0x085E32C0
_08070B98: .4byte 0x06012400
_08070B9C: .4byte 0x085E1A0C
_08070BA0: .4byte 0x06012D00
_08070BA4: .4byte 0x085E0A58
_08070BA8: .4byte 0x06013600
_08070BAC: .4byte 0x085E3AA8
_08070BB0: .4byte 0x05000200
_08070BB4: .4byte 0x80000010
_08070BB8: .4byte 0x085E32A0
_08070BBC: .4byte 0x05000220
_08070BC0: .4byte 0x085E19EC
_08070BC4: .4byte 0x05000240
_08070BC8: .4byte 0x085E0A38
_08070BCC: .4byte 0x05000260
_08070BD0: .4byte 0x0807C720
_08070BD4: .4byte 0x050003C0
_08070BD8: .4byte 0x05000280
_08070BDC: .4byte 0x0400000A
_08070BE0: .4byte 0x00000D05
_08070BE4: .4byte 0x00000E06
_08070BE8: .4byte 0x00000F07
_08070BEC: .4byte 0x00000A0C
_08070BF0: .4byte 0x03001800
_08070BF4: .4byte 0x03001C04
_08070BF8: .4byte 0x0300137C
	.syntax divided
