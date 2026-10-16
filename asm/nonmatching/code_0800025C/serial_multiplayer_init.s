	.syntax unified

	thumb_func_start serial_multiplayer_init
	.global serial_multiplayer_init
serial_multiplayer_init: @ 0x080021A4
	push {r4, lr}
	ldr r3, _080021D8 @ =0x04000208
	movs r4, #0
	strh r4, [r3]
	ldr r2, _080021DC @ =0x04000200
	ldrh r1, [r2]
	ldr r0, _080021E0 @ =0x0000FF3F
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r1, _080021E4 @ =0x04000128
	ldr r2, _080021E8 @ =0x00002003
	adds r0, r2, #0
	strh r0, [r1]
	subs r1, #0x1c
	ldr r0, _080021EC @ =0x000063F7
	str r0, [r1]
	adds r1, #0xf6
	movs r0, #0xc0
	strh r0, [r1]
	ldr r0, _080021F0 @ =0x03005170
	strb r4, [r0, #6]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080021D8: .4byte 0x04000208
_080021DC: .4byte 0x04000200
_080021E0: .4byte 0x0000FF3F
_080021E4: .4byte 0x04000128
_080021E8: .4byte 0x00002003
_080021EC: .4byte 0x000063F7
_080021F0: .4byte 0x03005170
	.syntax divided
