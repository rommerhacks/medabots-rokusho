	.syntax unified

	thumb_func_start sound_volume_scale
sound_volume_scale: @ 0x08073A50
	push {r4, lr}
	adds r1, r0, #0
	cmp r1, #0
	bne _08073A5C
	movs r0, #0
	b _08073A7A
_08073A5C:
	adds r0, r1, #0
	cmp r1, #0
	bge _08073A64
	adds r0, #0x7f
_08073A64:
	asrs r0, r0, #7
	lsls r4, r0, #7
	subs r4, r1, r4
	bl sound_volume_lookup
	ldr r1, _08073A80 @ =0x083ABADE
	lsls r4, r4, #1
	adds r4, r4, r1
	ldrh r1, [r4]
	muls r0, r1, r0
	lsrs r0, r0, #0xc
_08073A7A:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08073A80: .4byte 0x083ABADE
	.syntax divided
