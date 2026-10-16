	.syntax unified

	thumb_func_start rotate_vector_2d
rotate_vector_2d: @ 0x08001FF8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r3, _08002054 @ =0x080750E0
	ldrh r0, [r2, #0x18]
	ldr r1, _08002058 @ =0x000003FF
	ands r1, r0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r1, r2
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r5, [r0, r2]
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r0, #0
	ldrsh r4, [r1, r0]
	ldr r2, [r6]
	ldr r3, [r7]
	adds r1, r2, #0
	muls r1, r5, r1
	adds r0, r3, #0
	muls r0, r4, r0
	subs r0, r1, r0
	cmp r0, #0
	bge _08002032
	ldr r1, _0800205C @ =0x00003FFF
	adds r0, r0, r1
_08002032:
	asrs r0, r0, #0xe
	str r0, [r6]
	adds r1, r2, #0
	muls r1, r4, r1
	adds r0, r3, #0
	muls r0, r5, r0
	adds r0, r1, r0
	cmp r0, #0
	bge _08002048
	ldr r2, _0800205C @ =0x00003FFF
	adds r0, r0, r2
_08002048:
	asrs r0, r0, #0xe
	str r0, [r7]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08002054: .4byte 0x080750E0
_08002058: .4byte 0x000003FF
_0800205C: .4byte 0x00003FFF
	.syntax divided
