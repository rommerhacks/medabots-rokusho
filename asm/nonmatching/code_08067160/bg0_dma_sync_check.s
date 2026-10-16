	.syntax unified

	thumb_func_start bg0_dma_sync_check
bg0_dma_sync_check: @ 0x080687E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r1, #0
	mov r0, sp
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0x13
	mov sb, r0
	ldrh r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	orrs r0, r1
	mov r1, sb
	strh r0, [r1]
	ldr r2, _080688A8 @ =0x03000000
	mov sl, r2
	ldr r6, _080688AC @ =0x03000005
	ldrb r1, [r6]
	ldr r7, [r2]
	adds r0, r7, #0
	bl sub_0807CC88
	cmp r0, #0
	bne _08068896
	ldr r4, _080688B0 @ =0x040000D4
	mov r0, sp
	str r0, [r4]
	ldr r1, _080688B4 @ =0x03000008
	mov r8, r1
	ldrb r1, [r6]
	adds r0, r7, #0
	bl sub_0807CBBC
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ldr r2, _080688B8 @ =0x0600C000
	adds r0, r0, r2
	str r0, [r4, #4]
	ldr r5, _080688BC @ =0x80000001
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	mov r0, sp
	str r0, [r4]
	ldrb r1, [r6]
	adds r0, r7, #0
	bl sub_0807CBBC
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ldr r1, _080688C0 @ =0x0600C004
	adds r0, r0, r1
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	mov r2, sp
	str r2, [r4]
	ldrb r1, [r6]
	adds r0, r7, #0
	bl sub_0807CBBC
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ldr r1, _080688C4 @ =0x0600C008
	adds r0, r0, r1
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	mov r2, sp
	str r2, [r4]
	ldrb r1, [r6]
	adds r0, r7, #0
	bl sub_0807CBBC
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ldr r1, _080688C8 @ =0x0600C00C
	adds r0, r0, r1
	str r0, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
_08068896:
	ldrb r0, [r6]
	lsls r0, r0, #4
	mov r2, sl
	ldr r1, [r2]
	cmp r1, r0
	beq _080688CC
	movs r0, #0
	b _080688DA
	.align 2, 0
_080688A8: .4byte 0x03000000
_080688AC: .4byte 0x03000005
_080688B0: .4byte 0x040000D4
_080688B4: .4byte 0x03000008
_080688B8: .4byte 0x0600C000
_080688BC: .4byte 0x80000001
_080688C0: .4byte 0x0600C004
_080688C4: .4byte 0x0600C008
_080688C8: .4byte 0x0600C00C
_080688CC:
	mov r0, sb
	ldrh r1, [r0]
	ldr r0, _080688EC @ =0x0000FEFF
	ands r0, r1
	mov r1, sb
	strh r0, [r1]
	movs r0, #1
_080688DA:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080688EC: .4byte 0x0000FEFF
	.syntax divided
