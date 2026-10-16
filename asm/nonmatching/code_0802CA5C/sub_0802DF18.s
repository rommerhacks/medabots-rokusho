	.syntax unified

	thumb_func_start sub_0802DF18
sub_0802DF18: @ 0x0802DF18
	push {lr}
	ldr r0, _0802DF38 @ =0x03002C30
	ldr r1, _0802DF3C @ =0x00000846
	adds r0, r0, r1
	ldr r1, _0802DF40 @ =0x00007F02
	strh r1, [r0]
	movs r0, #0x38
	bl play_sound_effect
	ldr r1, _0802DF44 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0802DF38: .4byte 0x03002C30
_0802DF3C: .4byte 0x00000846
_0802DF40: .4byte 0x00007F02
_0802DF44: .4byte 0x03001800
	.syntax divided
