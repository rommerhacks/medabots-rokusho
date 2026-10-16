	.syntax unified

	thumb_func_start calculate_oam_affine_matrix
	.global calculate_oam_affine_matrix
calculate_oam_affine_matrix: @ 0x08049328
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	ldr r6, _080493CC @ =0x080AE77C
	ldr r0, _080493D0 @ =0x03006D40
	lsrs r5, r5, #0x14
	adds r5, r5, r0
	movs r1, #4
	ldrsh r0, [r5, r1]
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r4, [r0, r1]
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl divide_by_65536
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_08048B24
	strh r0, [r5, #6]
	movs r1, #4
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r4, [r0, r1]
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl divide_by_65536
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_08048B24
	strh r0, [r5, #8]
	movs r1, #4
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r4, [r0]
	rsbs r4, r4, #0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	movs r1, #2
	ldrsh r0, [r5, r1]
	bl divide_by_65536
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_08048B24
	strh r0, [r5, #0xa]
	movs r1, #4
	ldrsh r0, [r5, r1]
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r4, [r0, r1]
	movs r1, #2
	ldrsh r0, [r5, r1]
	bl divide_by_65536
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_08048B24
	strh r0, [r5, #0xc]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080493CC: .4byte 0x080AE77C
_080493D0: .4byte 0x03006D40
	.syntax divided
