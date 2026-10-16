	.syntax unified

	thumb_func_start battle_resolve_action_target
battle_resolve_action_target: @ 0x0801F1C8
	push {r4, r5, lr}
	ldr r4, _0801F200 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x88
	ldrb r0, [r5]
	bl clear_ewram_buffer_02023000_b
	cmp r0, #0
	beq _0801F204
	subs r0, #1
	adds r1, r4, #0
	adds r1, #0xd0
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x8b
	strb r0, [r2]
	ldrb r0, [r5]
	ldrb r1, [r1]
	adds r2, #0x61
	movs r3, #0
	ldrsh r2, [r2, r3]
	bl battle_calc_damage_split
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0x3e
	b _0801F20C
	.align 2, 0
_0801F200: .4byte 0x03001800
_0801F204:
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
_0801F20C:
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
