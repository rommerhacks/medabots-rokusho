	.syntax unified

	thumb_func_start sub_080059D0
	.global sub_080059D0
sub_080059D0: @ 0x080059D0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r1, _080059F4 @ =0x030017A0
	ldr r4, _080059F8 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrb r2, [r0, #2]
	cmp r2, #0x1e
	bne _080059FC
	adds r0, r4, #0
	adds r0, #0x97
	strb r2, [r0]
	b _08005A0A
	.align 2, 0
_080059F4: .4byte 0x030017A0
_080059F8: .4byte 0x03000440
_080059FC:
	ldrb r0, [r0, #2]
	bl find_medal_slot_by_id
	subs r0, #1
	adds r1, r4, #0
	adds r1, #0x97
	strb r0, [r1]
_08005A0A:
	ldr r1, _08005AC4 @ =0x03000440
	ldr r4, _08005AC8 @ =0x030017A0
	adds r3, r1, #0
	adds r3, #0x51
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldrb r0, [r0, #3]
	adds r5, r1, #0
	adds r5, #0x98
	strb r0, [r5]
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldrb r0, [r0, #4]
	adds r6, r1, #0
	adds r6, #0x99
	strb r0, [r6]
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldrb r0, [r0, #5]
	adds r7, r1, #0
	adds r7, #0x9a
	strb r0, [r7]
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldrb r0, [r0, #6]
	movs r2, #0x9b
	adds r2, r2, r1
	mov r8, r2
	strb r0, [r2]
	adds r1, #0x97
	ldrb r0, [r1]
	cmp r0, #0x1e
	beq _08005A64
	ldr r0, _08005ACC @ =0x03000BE0
	ldrb r1, [r1]
	lsls r1, r1, #6
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0xbf
	ands r0, r2
	strb r0, [r1]
_08005A64:
	ldrb r0, [r3]
	lsls r0, r0, #3
	adds r0, r0, r4
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r5]
	cmp r0, #0x77
	bhi _08005A80
	str r4, [sp]
	movs r1, #0
	movs r2, #1
	movs r3, #1
	bl modify_medapart_quantity
_08005A80:
	ldrb r0, [r6]
	cmp r0, #0x77
	bhi _08005A92
	str r4, [sp]
	movs r1, #1
	movs r2, #1
	movs r3, #1
	bl modify_medapart_quantity
_08005A92:
	ldrb r0, [r7]
	cmp r0, #0x77
	bhi _08005AA4
	str r4, [sp]
	movs r1, #2
	movs r2, #1
	movs r3, #1
	bl modify_medapart_quantity
_08005AA4:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0x77
	bhi _08005AB8
	str r4, [sp]
	movs r1, #3
	movs r2, #1
	movs r3, #1
	bl modify_medapart_quantity
_08005AB8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005AC4: .4byte 0x03000440
_08005AC8: .4byte 0x030017A0
_08005ACC: .4byte 0x03000BE0
	.syntax divided
