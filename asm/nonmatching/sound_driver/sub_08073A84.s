	.syntax unified

	thumb_func_start sub_08073A84
sub_08073A84: @ 0x08073A84
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	cmp r0, #0
	beq _08073A98
	bl sound_volume_scale
	muls r0, r4, r0
	lsrs r0, r0, #0xc
	b _08073A9A
_08073A98:
	adds r0, r4, #0
_08073A9A:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
