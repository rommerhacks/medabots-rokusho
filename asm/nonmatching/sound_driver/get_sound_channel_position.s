	.syntax unified

	thumb_func_start get_sound_channel_position
get_sound_channel_position: @ 0x08074DD4
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080750CC
	movs r1, #0x74
	muls r1, r4, r1
	adds r1, r0, r1
	ldr r0, [r1, #0x14]
	cmp r0, #0
	beq _08074DF0
	adds r0, r1, #0
	adds r0, #0x4e
	ldrh r0, [r0]
	b _08074DF4
_08074DF0:
	movs r0, #1
	rsbs r0, r0, #0
_08074DF4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
