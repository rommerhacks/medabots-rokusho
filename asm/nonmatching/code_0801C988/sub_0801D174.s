	.syntax unified

	thumb_func_start sub_0801D174
sub_0801D174: @ 0x0801D174
	push {lr}
	ldr r0, _0801D19C @ =0x03002C30
	ldr r1, _0801D1A0 @ =0x00000863
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, _0801D1A4 @ =0x03000440
	adds r0, #0x84
	strb r1, [r0]
	movs r0, #0x34
	bl play_sound_effect
	ldr r1, _0801D1A8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0801D19C: .4byte 0x03002C30
_0801D1A0: .4byte 0x00000863
_0801D1A4: .4byte 0x03000440
_0801D1A8: .4byte 0x03001800
	.syntax divided
