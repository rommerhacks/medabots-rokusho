	.syntax unified

	thumb_func_start sub_08024F90
sub_08024F90: @ 0x08024F90
	push {lr}
	movs r0, #0x33
	bl play_sound_effect
	ldr r1, _08024FBC @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r1, r0
	ldrh r2, [r1]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	ldr r1, _08024FC0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08024FBC: .4byte 0x03002C30
_08024FC0: .4byte 0x03001800
	.syntax divided
