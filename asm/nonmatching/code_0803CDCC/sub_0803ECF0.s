	.syntax unified

	thumb_func_start sub_0803ECF0
sub_0803ECF0: @ 0x0803ECF0
	push {lr}
	ldr r0, _0803ED0C @ =0x03001800
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x60
	bne _0803ED06
	movs r0, #7
	bl play_sound_effect
_0803ED06:
	pop {r0}
	bx r0
	.align 2, 0
_0803ED0C: .4byte 0x03001800
	.syntax divided
