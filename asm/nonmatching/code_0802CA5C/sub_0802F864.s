	.syntax unified

	thumb_func_start sub_0802F864
sub_0802F864: @ 0x0802F864
	push {lr}
	movs r0, #0x22
	bl play_sound_effect
	ldr r1, _0802F87C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0802F87C: .4byte 0x03001800
	.syntax divided
