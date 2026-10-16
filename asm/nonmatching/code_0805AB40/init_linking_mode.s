	.syntax unified

	thumb_func_start init_linking_mode
	.global init_linking_mode
init_linking_mode: @ 0x0805DC20
	push {lr}
	ldr r1, _0805DC68 @ =0x03005030
	movs r0, #0
	strb r0, [r1]
	bl serial_multiplayer_init
	bl VBlankIntrWait
	ldr r1, _0805DC6C @ =0x04000050
	movs r0, #0xff
	strh r0, [r1]
	adds r1, #4
	movs r0, #0x10
	strh r0, [r1]
	adds r1, #0x30
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0805DC70 @ =0x0300178C
	movs r0, #3
	str r0, [r1]
	ldr r0, _0805DC74 @ =0x03002B8C
	movs r1, #0
	str r1, [r0]
	ldr r0, _0805DC78 @ =0x0300137C
	str r1, [r0]
	ldr r0, _0805DC7C @ =0x040000BA
	strh r1, [r0]
	bl VBlankIntrWait
	ldr r0, _0805DC80 @ =0x03002430
	bl sound_init
	bl VBlankIntrWait
	pop {r0}
	bx r0
	.align 2, 0
_0805DC68: .4byte 0x03005030
_0805DC6C: .4byte 0x04000050
_0805DC70: .4byte 0x0300178C
_0805DC74: .4byte 0x03002B8C
_0805DC78: .4byte 0x0300137C
_0805DC7C: .4byte 0x040000BA
_0805DC80: .4byte 0x03002430
	.syntax divided
