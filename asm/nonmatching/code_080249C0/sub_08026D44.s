	.syntax unified

	thumb_func_start sub_08026D44
sub_08026D44: @ 0x08026D44
	push {r4, r5, r6, lr}
	ldr r4, _08026D84 @ =0x03001800
	adds r6, r4, #0
	adds r6, #0xca
	ldrh r0, [r6]
	cmp r0, #0
	beq _08026D88
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	bl calc_bot_evasion_modifier
	ldrb r0, [r5]
	bl sub_080355C4
	adds r2, r4, #0
	adds r2, #0x8b
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xd0
	strb r1, [r0]
	subs r0, #0x48
	ldrb r0, [r0]
	ldrb r1, [r2]
	ldrh r2, [r6]
	bl battle_set_damage_vs_armor
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #3
	b _08026D90
	.align 2, 0
_08026D84: .4byte 0x03001800
_08026D88:
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
_08026D90:
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
