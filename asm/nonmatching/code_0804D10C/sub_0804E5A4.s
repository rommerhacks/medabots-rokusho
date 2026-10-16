	.syntax unified

	thumb_func_start sub_0804E5A4
sub_0804E5A4: @ 0x0804E5A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	movs r7, #0
	movs r4, #0
	ldr r1, _0804E5CC @ =0x030057E0
	ldr r2, _0804E5D0 @ =0x00000C93
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804E5D4
	cmp r0, #1
	beq _0804E658
	b _0804E6A8
	.align 2, 0
_0804E5CC: .4byte 0x030057E0
_0804E5D0: .4byte 0x00000C93
_0804E5D4:
	movs r5, #0
	ldr r0, _0804E620 @ =0x030055A0
	mov sb, r0
	ldr r2, _0804E624 @ =0x00000C94
	adds r7, r1, r2
_0804E5DE:
	lsls r0, r5, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	bl sub_0804DBA4
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _0804E63C
	adds r0, r4, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #2
	add r0, sb
	ldrh r0, [r0]
	cmp r0, #0
	beq _0804E63C
	mov r0, r8
	cmp r0, #1
	bne _0804E628
	adds r0, r4, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r7]
	adds r2, r6, #0
	bl setup_battle_sprite_terrain
	b _0804E63C
	.align 2, 0
_0804E620: .4byte 0x030055A0
_0804E624: .4byte 0x00000C94
_0804E628:
	adds r0, r4, #0
	bl sub_0804DBA4
	adds r0, #0x4f
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r7]
	adds r2, r6, #0
	bl sub_080500D8
_0804E63C:
	adds r5, #1
	cmp r5, #3
	ble _0804E5DE
	ldr r1, _0804E650 @ =0x030057E0
	ldr r2, _0804E654 @ =0x00000C93
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0804E6A8
	.align 2, 0
_0804E650: .4byte 0x030057E0
_0804E654: .4byte 0x00000C93
_0804E658:
	movs r5, #0
	ldr r6, _0804E688 @ =0x030055A0
_0804E65C:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	bl sub_0804DBA4
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0804E690
	adds r1, #0x4f
	lsls r0, r1, #2
	adds r0, r0, r6
	ldrh r0, [r0]
	cmp r0, #0
	beq _0804E68C
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	mov r1, r8
	bl update_battle_sprite_movement
	adds r4, r4, r0
	b _0804E692
	.align 2, 0
_0804E688: .4byte 0x030055A0
_0804E68C:
	adds r4, #1
	b _0804E692
_0804E690:
	adds r7, #1
_0804E692:
	adds r5, #1
	cmp r5, #3
	ble _0804E65C
	cmp r7, #4
	bne _0804E6A0
	bl sub_08050244
_0804E6A0:
	cmp r4, #0
	beq _0804E6A8
	bl sub_08050244
_0804E6A8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
