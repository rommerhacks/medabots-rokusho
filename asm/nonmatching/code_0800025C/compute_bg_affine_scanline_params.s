	.syntax unified

	thumb_func_start compute_bg_affine_scanline_params
compute_bg_affine_scanline_params: @ 0x08001188
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp]
	adds r2, r1, #0
	str r3, [sp, #4]
	ldr r0, [sp, #0x34]
	mov sl, r0
	ldr r1, [sp, #0x38]
	mov sb, r1
	ldr r0, _0800125C @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r3, _08001260 @ =0x02030A00
	cmp r0, #0
	bne _080011B2
	ldr r3, _08001264 @ =0x02030000
_080011B2:
	movs r7, #0
	ldr r0, _08001268 @ =0x080750E0
	ldr r1, _0800126C @ =0x000003FF
	ands r1, r2
	lsls r2, r1, #1
	adds r2, r2, r0
	str r2, [sp, #0xc]
	adds r6, r3, #0
	movs r2, #1
	mov r8, r2
	adds r2, #0xff
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r0
	str r1, [sp, #8]
_080011D0:
	ldr r0, [sp, #8]
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #7
	mov r0, r8
	bl DivArm
	adds r4, r0, #0
	ldr r0, [sp, #0xc]
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r1, r1, #7
	mov r0, r8
	bl DivArm
	rsbs r5, r0, #0
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r3, r4, #1
	adds r3, r3, r4
	strh r4, [r6]
	strh r1, [r6, #2]
	strh r5, [r6, #4]
	strh r3, [r6, #6]
	mov r2, sl
	muls r2, r4, r2
	rsbs r2, r2, #0
	mov r0, sb
	muls r0, r1, r0
	subs r2, r2, r0
	ldr r0, [sp, #4]
	subs r2, r2, r0
	adds r0, r1, #0
	muls r0, r7, r0
	adds r2, r2, r0
	mov r0, sl
	muls r0, r5, r0
	rsbs r0, r0, #0
	mov r1, sb
	muls r1, r3, r1
	subs r0, r0, r1
	ldr r1, [sp, #0x30]
	subs r0, r0, r1
	adds r1, r3, #0
	muls r1, r7, r1
	adds r0, r0, r1
	strh r2, [r6, #8]
	asrs r2, r2, #0x10
	strh r2, [r6, #0xa]
	strh r0, [r6, #0xc]
	asrs r0, r0, #0x10
	strh r0, [r6, #0xe]
	ldr r2, [sp]
	add r8, r2
	adds r7, #1
	adds r6, #0x10
	cmp r7, #0x9f
	ble _080011D0
	ldr r1, _08001270 @ =0x03000B98
	ldr r0, _08001274 @ =hblank_dma0_bg2affine
	str r0, [r1]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800125C: .4byte 0x03001780
_08001260: .4byte 0x02030A00
_08001264: .4byte 0x02030000
_08001268: .4byte 0x080750E0
_0800126C: .4byte 0x000003FF
_08001270: .4byte 0x03000B98
_08001274: .4byte hblank_dma0_bg2affine
	.syntax divided
