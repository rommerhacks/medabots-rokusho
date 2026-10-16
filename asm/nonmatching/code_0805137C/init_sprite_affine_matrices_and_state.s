	.syntax unified

	thumb_func_start init_sprite_affine_matrices_and_state
	.global init_sprite_affine_matrices_and_state
init_sprite_affine_matrices_and_state: @ 0x08053398
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	mov r8, r3
	bl sub_080492CC
	movs r4, #0
_080533AC:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl calculate_oam_affine_matrix
	adds r4, #1
	cmp r4, #0x1f
	ble _080533AC
	ldr r4, _08053408 @ =0x03005350
	movs r1, #0x90
	lsls r1, r1, #2
	adds r0, r4, #0
	bl sub_080496C8
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r4, r1
	str r5, [r0]
	movs r0, #0x40
	ands r0, r5
	cmp r0, #0
	beq _080533E4
	ldr r0, _0805340C @ =0x030057E0
	ldr r2, _08053410 @ =0x00000C52
	adds r1, r0, r2
	ldrh r7, [r1]
	ldr r1, _08053414 @ =0x00000C54
	adds r0, r0, r1
	ldrh r6, [r0]
_080533E4:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r4, r2
	str r7, [r0]
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r4, r1
	str r6, [r0]
	adds r2, #8
	adds r0, r4, r2
	mov r1, r8
	str r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053408: .4byte 0x03005350
_0805340C: .4byte 0x030057E0
_08053410: .4byte 0x00000C52
_08053414: .4byte 0x00000C54
	.syntax divided
