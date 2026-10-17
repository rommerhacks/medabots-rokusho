	.syntax unified

	thumb_func_start sub_0801F3F0
sub_0801F3F0: @ 0x0801F3F0
	push {r4, r5, r6, lr}
	ldr r3, _0801F45C @ =0x03000590
	ldr r4, _0801F460 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r2, r0, #8
	adds r0, r2, r3
	adds r0, #0xd6
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0801F424
	adds r0, r4, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	adds r1, r1, r3
	adds r1, #0x4f
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801F464
_0801F424:
	adds r6, r4, #0
	adds r6, #0xca
	ldrh r0, [r6]
	cmp r0, #0
	beq _0801F464
	adds r5, r4, #0
	adds r5, #0x88
	ldrb r0, [r5]
	bl clear_ewram_buffer_02023000_b
	cmp r0, #0
	beq _0801F464
	subs r0, #1
	adds r1, r4, #0
	adds r1, #0xd0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x8b
	strb r0, [r2]
	ldrb r0, [r5]
	ldrb r1, [r1]
	ldrh r2, [r6]
	bl battle_calc_damage_split
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0x4a
	b _0801F46C
	.align 2, 0
_0801F45C: .4byte 0x03000590
_0801F460: .4byte 0x03001800
_0801F464:
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
_0801F46C:
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
