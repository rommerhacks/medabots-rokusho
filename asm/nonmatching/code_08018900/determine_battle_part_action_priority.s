	.syntax unified

	thumb_func_start determine_battle_part_action_priority
	.global determine_battle_part_action_priority
determine_battle_part_action_priority: @ 0x0801B76C
	push {r4, r5, r6, lr}
	ldr r1, _0801B888 @ =0x03001800
	movs r0, #0xae
	lsls r0, r0, #1
	adds r5, r1, r0
	movs r0, #0
	strb r0, [r5]
	ldr r3, _0801B88C @ =0x0000015D
	adds r2, r1, r3
	strb r0, [r2]
	adds r3, #1
	adds r2, r1, r3
	strb r0, [r2]
	ldr r6, _0801B890 @ =0x03000590
	adds r4, r1, #0
	adds r4, #0x80
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801B79E
	movs r0, #4
	strb r0, [r5]
_0801B79E:
	ldrb r0, [r4]
	movs r1, #0
	bl sub_08016E5C
	cmp r0, #0
	beq _0801B7AE
	movs r0, #3
	strb r0, [r5]
_0801B7AE:
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r1, r0, r6
	adds r0, r1, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0x2b
	bne _0801B7CC
	adds r0, r1, #0
	adds r0, #0xca
	ldrb r0, [r0]
	cmp r0, #1
	bne _0801B7CC
	movs r0, #2
	strb r0, [r5]
_0801B7CC:
	ldr r4, _0801B888 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x80
	ldrb r0, [r5]
	movs r1, #1
	bl sub_08016E5C
	cmp r0, #0
	beq _0801B7E6
	ldr r0, _0801B88C @ =0x0000015D
	adds r1, r4, r0
	movs r0, #3
	strb r0, [r1]
_0801B7E6:
	ldr r0, _0801B890 @ =0x03000590
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r1, r1, r0
	adds r0, r1, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0x2b
	bne _0801B808
	adds r0, r1, #0
	adds r0, #0xca
	ldrb r0, [r0]
	cmp r0, #2
	bne _0801B808
	ldr r2, _0801B88C @ =0x0000015D
	adds r1, r4, r2
	strb r0, [r1]
_0801B808:
	ldr r6, _0801B890 @ =0x03000590
	ldr r4, _0801B888 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x80
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r6
	adds r0, #0x71
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801B826
	ldr r3, _0801B88C @ =0x0000015D
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_0801B826:
	ldrb r0, [r5]
	movs r1, #2
	bl sub_08016E5C
	cmp r0, #0
	beq _0801B83C
	movs r0, #0xaf
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #3
	strb r0, [r1]
_0801B83C:
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r1, r0, r6
	adds r0, r1, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0x2b
	bne _0801B860
	adds r0, r1, #0
	adds r0, #0xca
	ldrb r0, [r0]
	cmp r0, #3
	bne _0801B860
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #2
	strb r0, [r1]
_0801B860:
	ldr r1, _0801B890 @ =0x03000590
	ldr r2, _0801B888 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801B880
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #1
	strb r0, [r1]
_0801B880:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801B888: .4byte 0x03001800
_0801B88C: .4byte 0x0000015D
_0801B890: .4byte 0x03000590
	.syntax divided
