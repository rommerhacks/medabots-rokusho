	.syntax unified

	thumb_func_start apply_battle_bot_damage_reduction
	.global apply_battle_bot_damage_reduction
apply_battle_bot_damage_reduction: @ 0x08035814
	push {lr}
	ldr r1, _0803583C @ =0x03000590
	lsls r0, r0, #8
	adds r1, r0, r1
	adds r0, r1, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	subs r0, #0xd
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08035836
	ldr r0, _08035840 @ =0x030018E8
	adds r1, #0xcc
	ldrb r1, [r1]
	bl sub_08035754
_08035836:
	pop {r0}
	bx r0
	.align 2, 0
_0803583C: .4byte 0x03000590
_08035840: .4byte 0x030018E8
	.syntax divided
