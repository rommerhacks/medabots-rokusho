	.syntax unified

	thumb_func_start soft_reset_to_title
soft_reset_to_title: @ 0x0803EF20
	push {lr}
	ldr r1, _0803EF6C @ =0x03005030
	movs r0, #0
	strb r0, [r1]
	bl serial_multiplayer_init
	bl VBlankIntrWait
	ldr r0, _0803EF70 @ =0x04000084
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803EF74 @ =0x04000208
	strh r1, [r0]
	bl hw_reset_init
	bl irq_init
	bl serial_link_init
	ldr r1, _0803EF78 @ =0x0300178C
	movs r0, #3
	str r0, [r1]
	ldr r0, _0803EF7C @ =0x03002B8C
	movs r1, #0
	str r1, [r0]
	ldr r0, _0803EF80 @ =0x0300137C
	str r1, [r0]
	ldr r0, _0803EF84 @ =0x040000BA
	strh r1, [r0]
	bl VBlankIntrWait
	ldr r0, _0803EF88 @ =0x03002430
	bl sound_init
	bl VBlankIntrWait
	pop {r0}
	bx r0
	.align 2, 0
_0803EF6C: .4byte 0x03005030
_0803EF70: .4byte 0x04000084
_0803EF74: .4byte 0x04000208
_0803EF78: .4byte 0x0300178C
_0803EF7C: .4byte 0x03002B8C
_0803EF80: .4byte 0x0300137C
_0803EF84: .4byte 0x040000BA
_0803EF88: .4byte 0x03002430
	.syntax divided
