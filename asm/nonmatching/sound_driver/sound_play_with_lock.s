	.syntax unified

	thumb_func_start sound_play_with_lock
sound_play_with_lock: @ 0x08074EB0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r6, _08074EEC @ =0x03007014
	ldr r0, [r6]
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r1, r0, r3
	ldrh r3, [r1]
	ldr r0, _08074EF0 @ =0x0000FFFE
	cmp r3, r0
	bhi _08074ECC
	adds r0, r3, #1
	strh r0, [r1]
_08074ECC:
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_08074E84
	ldr r0, [r6]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08074EE6
	subs r0, #1
	strh r0, [r1]
_08074EE6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08074EEC: .4byte 0x03007014
_08074EF0: .4byte 0x0000FFFE
	.syntax divided
