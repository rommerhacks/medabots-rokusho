	.syntax unified

	thumb_func_start sub_08034120
sub_08034120: @ 0x08034120
	push {r4, r5, lr}
	bl init_battle_scene_backgrounds
	bl battle_advance_dialogue_text
	ldr r4, _08034164 @ =0x03001800
	ldr r2, _08034168 @ =0x0000015F
	adds r1, r4, r2
	movs r5, #0
	strb r0, [r1]
	bl battle_advance_action_text
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	adds r4, #0xb5
	strb r5, [r4]
	bl sub_080393BC
	ldrb r0, [r4]
	cmp r0, #0
	beq _0803415C
	ldr r0, _0803416C @ =0x03000440
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r0, r1
	strb r5, [r0]
	bl sub_08034F08
_0803415C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034164: .4byte 0x03001800
_08034168: .4byte 0x0000015F
_0803416C: .4byte 0x03000440
	.syntax divided
