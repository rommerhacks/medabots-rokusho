	.syntax unified

	thumb_func_start sub_0801DD30
sub_0801DD30: @ 0x0801DD30
	push {lr}
	ldr r1, _0801DD50 @ =0x03002C30
	ldr r0, _0801DD54 @ =0x00000848
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0x40
	bne _0801DD5C
	movs r0, #0x30
	bl play_sound_effect
	ldr r1, _0801DD58 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _0801DD68
	.align 2, 0
_0801DD50: .4byte 0x03002C30
_0801DD54: .4byte 0x00000848
_0801DD58: .4byte 0x03001800
_0801DD5C:
	subs r0, #4
	strb r0, [r2]
	ldr r0, _0801DD70 @ =0x00000849
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #4
_0801DD68:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0801DD70: .4byte 0x00000849
	.syntax divided
