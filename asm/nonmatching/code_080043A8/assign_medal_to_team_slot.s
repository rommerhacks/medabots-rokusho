	.syntax unified

	thumb_func_start assign_medal_to_team_slot
assign_medal_to_team_slot: @ 0x08006FB0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	movs r5, #0
	ldr r0, _08006FE8 @ =0x03000440
	movs r1, #0x97
	adds r1, r1, r0
	mov ip, r1
	ldrb r4, [r1]
	mov r8, r0
	cmp r4, #0x1e
	bne _08006FF0
	ldr r2, _08006FEC @ =0x030017A0
	mov r3, r8
	adds r3, #0x51
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r2
	strb r4, [r0, #2]
	mov sb, r2
	b _08007026
	.align 2, 0
_08006FE8: .4byte 0x03000440
_08006FEC: .4byte 0x030017A0
_08006FF0:
	ldr r3, _080070E8 @ =0x030017A0
	mov r2, r8
	adds r2, #0x51
	ldrb r0, [r2]
	lsls r0, r0, #3
	adds r0, r0, r3
	movs r1, #2
	strb r1, [r0]
	ldrb r1, [r2]
	lsls r1, r1, #3
	adds r1, r1, r3
	ldr r2, _080070EC @ =0x03000BE0
	mov r4, ip
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r2
	ldrb r0, [r0, #1]
	strb r0, [r1, #2]
	ldrb r1, [r4]
	lsls r1, r1, #6
	adds r1, r1, r2
	ldrb r2, [r1]
	movs r0, #0x40
	orrs r0, r2
	strb r0, [r1]
	movs r5, #1
	mov sb, r3
_08007026:
	mov r6, sb
	mov r4, r8
	adds r7, r4, #0
	adds r7, #0x51
	ldrb r0, [r7]
	lsls r0, r0, #3
	adds r0, r0, r6
	adds r2, r4, #0
	adds r2, #0x98
	ldrb r1, [r2]
	strb r1, [r0, #3]
	ldrb r0, [r2]
	cmp r0, #0x77
	bhi _08007056
	movs r1, #1
	str r1, [sp]
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl modify_medapart_quantity
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_08007056:
	ldrb r0, [r7]
	lsls r0, r0, #3
	adds r0, r0, r6
	adds r2, r4, #0
	adds r2, #0x99
	ldrb r1, [r2]
	strb r1, [r0, #4]
	ldrb r0, [r2]
	cmp r0, #0x77
	bhi _0800707C
	movs r1, #1
	str r1, [sp]
	movs r2, #1
	movs r3, #0
	bl modify_medapart_quantity
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_0800707C:
	ldrb r0, [r7]
	lsls r0, r0, #3
	adds r0, r0, r6
	adds r2, r4, #0
	adds r2, #0x9a
	ldrb r1, [r2]
	strb r1, [r0, #5]
	ldrb r0, [r2]
	cmp r0, #0x77
	bhi _080070A4
	movs r1, #1
	str r1, [sp]
	movs r1, #2
	movs r2, #1
	movs r3, #0
	bl modify_medapart_quantity
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080070A4:
	ldrb r0, [r7]
	lsls r0, r0, #3
	adds r0, r0, r6
	mov r2, r8
	adds r2, #0x9b
	ldrb r1, [r2]
	strb r1, [r0, #6]
	ldrb r0, [r2]
	cmp r0, #0x77
	bhi _080070CC
	movs r1, #1
	str r1, [sp]
	movs r1, #3
	movs r2, #1
	movs r3, #0
	bl modify_medapart_quantity
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080070CC:
	cmp r5, #5
	bne _080070DA
	ldrb r0, [r7]
	lsls r0, r0, #3
	add r0, sb
	movs r1, #3
	strb r1, [r0]
_080070DA:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080070E8: .4byte 0x030017A0
_080070EC: .4byte 0x03000BE0
	.syntax divided
