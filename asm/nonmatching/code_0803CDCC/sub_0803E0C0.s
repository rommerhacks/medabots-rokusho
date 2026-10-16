	.syntax unified

	thumb_func_start sub_0803E0C0
sub_0803E0C0: @ 0x0803E0C0
	push {lr}
	bl sub_0803E894
	bl sub_0803ED28
	cmp r0, #0
	beq _0803E0E4
	movs r0, #0x2a
	bl play_sound_effect
	ldr r0, _0803E0E8 @ =0x03000440
	adds r0, #0x86
	movs r1, #0
	strh r1, [r0]
	ldr r1, _0803E0EC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E0E4:
	pop {r0}
	bx r0
	.align 2, 0
_0803E0E8: .4byte 0x03000440
_0803E0EC: .4byte 0x0300137C
	.syntax divided
