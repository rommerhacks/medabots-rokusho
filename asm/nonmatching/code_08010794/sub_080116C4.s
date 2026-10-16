	.syntax unified

	thumb_func_start sub_080116C4
sub_080116C4: @ 0x080116C4
	push {r4, r5, r6, r7, lr}
	bl sub_08043CA8
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r5, _080116F8 @ =0x03000440
	adds r1, r5, #0
	adds r1, #0x96
	movs r0, #0
	strb r0, [r1]
	ldr r1, _080116FC @ =0x03000430
	str r0, [r1]
	ldr r7, _08011700 @ =0x03001800
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r6, [r0]
	cmp r6, #1
	beq _08011720
	cmp r6, #1
	bgt _08011704
	cmp r6, #0
	beq _08011720
	b _08011750
	.align 2, 0
_080116F8: .4byte 0x03000440
_080116FC: .4byte 0x03000430
_08011700: .4byte 0x03001800
_08011704:
	cmp r6, #2
	beq _0801170E
	cmp r6, #3
	beq _08011720
	b _08011750
_0801170E:
	adds r4, r5, #0
	adds r4, #0x3c
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	strb r6, [r4]
	b _08011732
_08011720:
	adds r4, r5, #0
	adds r4, #0x3c
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	movs r0, #2
	strb r0, [r4]
_08011732:
	ldr r1, _08011758 @ =0x00000169
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x3d
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x3e
	strb r6, [r0]
	ldr r1, _0801175C @ =0x03002B8C
	movs r0, #5
	str r0, [r1]
	ldr r1, _08011760 @ =0x0300137C
	movs r0, #0x10
	str r0, [r1]
_08011750:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011758: .4byte 0x00000169
_0801175C: .4byte 0x03002B8C
_08011760: .4byte 0x0300137C
	.syntax divided
