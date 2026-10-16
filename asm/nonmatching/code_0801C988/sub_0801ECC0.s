	.syntax unified

	thumb_func_start sub_0801ECC0
sub_0801ECC0: @ 0x0801ECC0
	push {r4, r5, lr}
	ldr r4, _0801ED0C @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	bl calc_bot_evasion_modifier
	ldrb r0, [r5]
	bl sub_080355C4
	adds r3, r4, #0
	adds r3, #0x8b
	ldrb r1, [r3]
	adds r0, r4, #0
	adds r0, #0xd0
	strb r1, [r0]
	ldr r2, _0801ED10 @ =0x03000590
	subs r0, #0x29
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0x30
	bne _0801ED14
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	ldrb r1, [r3]
	bl sub_08036B84
	b _0801ED3A
	.align 2, 0
_0801ED0C: .4byte 0x03001800
_0801ED10: .4byte 0x03000590
_0801ED14:
	adds r0, r1, r2
	adds r0, #0xd6
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	adds r2, r4, #0
	adds r2, #0xca
	cmp r0, #0
	beq _0801ED2C
	ldrh r0, [r2]
	adds r0, #0xa
	strh r0, [r2]
_0801ED2C:
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	ldrb r1, [r3]
	ldrh r2, [r2]
	bl battle_set_damage_vs_armor
_0801ED3A:
	ldr r1, _0801ED4C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801ED4C: .4byte 0x03001800
	.syntax divided
