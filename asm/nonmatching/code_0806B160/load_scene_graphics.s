	.syntax unified

	thumb_func_start load_scene_graphics
load_scene_graphics: @ 0x0806D60C
	push {r4, r5, lr}
	ldr r0, _0806D6B0 @ =0x087B55BC
	movs r1, #0xc0
	lsls r1, r1, #0x13
	bl LZ77UnCompVram
	ldr r4, _0806D6B4 @ =0x040000D4
	ldr r0, _0806D6B8 @ =0x087B9B6C
	str r0, [r4]
	ldr r0, _0806D6BC @ =0x06008000
	str r0, [r4, #4]
	ldr r0, _0806D6C0 @ =0x84000090
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0806D6C4 @ =0x087B9DAC
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _0806D6C8 @ =0x84000030
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r0, _0806D6CC @ =0x087B9E6C
	ldr r1, _0806D6D0 @ =0x06006800
	bl LZ77UnCompVram
	ldr r0, _0806D6D4 @ =0x087BA0AC
	ldr r1, _0806D6D8 @ =0x06007000
	bl LZ77UnCompVram
	ldr r0, _0806D6DC @ =0x087BA5EC
	str r0, [r4]
	ldr r0, _0806D6E0 @ =0x06007800
	str r0, [r4, #4]
	ldr r0, _0806D6E4 @ =0x840000A0
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _0806D6E8 @ =0x04000008
	ldr r2, _0806D6EC @ =0x00000D01
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0806D6F0 @ =0x00000E03
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0806D6F4 @ =0x00006F8A
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0806D6F8 @ =0x087ADDDC
	ldr r1, _0806D6FC @ =0x06010000
	bl LZ77UnCompVram
	ldr r1, _0806D700 @ =0x0807C320
	str r1, [r4]
	ldr r0, _0806D704 @ =0x05000200
	str r0, [r4, #4]
	ldr r0, _0806D708 @ =0x80000060
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	adds r1, #0xc0
	str r1, [r4]
	ldr r5, _0806D70C @ =0x0300180C
	str r5, [r4, #4]
	ldr r0, _0806D710 @ =0x8000000E
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	movs r0, #2
	movs r1, #1
	movs r2, #0
	bl setup_screen_transition_effect_080682CC
	subs r5, #0xc
	movs r0, #5
	strh r0, [r5, #4]
	ldr r1, _0806D714 @ =0x0300137C
	movs r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0806D6B0: .4byte 0x087B55BC
_0806D6B4: .4byte 0x040000D4
_0806D6B8: .4byte 0x087B9B6C
_0806D6BC: .4byte 0x06008000
_0806D6C0: .4byte 0x84000090
_0806D6C4: .4byte 0x087B9DAC
_0806D6C8: .4byte 0x84000030
_0806D6CC: .4byte 0x087B9E6C
_0806D6D0: .4byte 0x06006800
_0806D6D4: .4byte 0x087BA0AC
_0806D6D8: .4byte 0x06007000
_0806D6DC: .4byte 0x087BA5EC
_0806D6E0: .4byte 0x06007800
_0806D6E4: .4byte 0x840000A0
_0806D6E8: .4byte 0x04000008
_0806D6EC: .4byte 0x00000D01
_0806D6F0: .4byte 0x00000E03
_0806D6F4: .4byte 0x00006F8A
_0806D6F8: .4byte 0x087ADDDC
_0806D6FC: .4byte 0x06010000
_0806D700: .4byte 0x0807C320
_0806D704: .4byte 0x05000200
_0806D708: .4byte 0x80000060
_0806D70C: .4byte 0x0300180C
_0806D710: .4byte 0x8000000E
_0806D714: .4byte 0x0300137C
	.syntax divided
