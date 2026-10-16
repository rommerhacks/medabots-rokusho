	.syntax unified

	thumb_func_start sub_08026FF8
sub_08026FF8: @ 0x08026FF8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r5, #0
	ldr r0, _080270B4 @ =0x03001800
	adds r3, r0, #0
	adds r3, #0xd2
	movs r2, #0
	adds r1, r0, #0
	adds r1, #0xd6
_0802700E:
	adds r0, r5, r3
	strb r2, [r0]
	strh r2, [r1]
	adds r1, #2
	adds r5, #1
	cmp r5, #2
	bls _0802700E
	ldr r4, _080270B4 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r0, _080270B8 @ =0x03000590
	mov sb, r0
	adds r6, r4, #0
	adds r7, r1, #0
	movs r2, #0xc8
	adds r2, r2, r6
	mov r8, r2
_0802703E:
	ldrb r0, [r7]
	adds r2, r0, r5
	lsls r0, r2, #8
	mov r3, sb
	adds r1, r0, r3
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027098
	adds r0, r1, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _08027098
	adds r0, r2, #0
	bl get_random_battle_weight_entry
	adds r4, r6, #0
	adds r4, #0xd2
	adds r4, r5, r4
	strb r0, [r4]
	ldrb r0, [r7]
	adds r0, r0, r5
	ldrb r1, [r4]
	adds r2, r6, #0
	adds r2, #0xec
	movs r3, #0
	ldrsh r2, [r2, r3]
	bl battle_set_damage_vs_armor
	adds r0, r6, #0
	adds r0, #0xd1
	ldrb r0, [r0]
	lsls r0, r0, #7
	ldrb r1, [r4]
	orrs r0, r1
	strb r0, [r4]
	lsls r1, r5, #1
	adds r0, r6, #0
	adds r0, #0xd6
	adds r1, r1, r0
	mov r2, r8
	ldrh r0, [r2]
	strh r0, [r1]
_08027098:
	adds r5, #1
	cmp r5, #2
	bls _0802703E
	ldr r1, _080270B4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080270B4: .4byte 0x03001800
_080270B8: .4byte 0x03000590
	.syntax divided
