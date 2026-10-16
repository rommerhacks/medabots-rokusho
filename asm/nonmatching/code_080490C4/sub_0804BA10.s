	.syntax unified

	thumb_func_start sub_0804BA10
sub_0804BA10: @ 0x0804BA10
	push {r4, r5, r6, lr}
	bl read_map_script_byte
	ldr r6, _0804BA44 @ =0x030057E0
	ldr r1, _0804BA48 @ =0x00000C94
	adds r6, r6, r1
	strb r0, [r6]
	ldr r5, _0804BA4C @ =0x03002C30
	subs r1, #0xb3
	adds r4, r5, r1
	strb r0, [r4]
	ldrb r1, [r4]
	movs r0, #0x2f
	bl sub_080493D4
	ldrb r0, [r4]
	movs r1, #0xbe
	lsls r1, r1, #4
	adds r5, r5, r1
	strb r0, [r5]
	ldrb r0, [r6]
	bl set_battle_entity_animation_attack
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804BA44: .4byte 0x030057E0
_0804BA48: .4byte 0x00000C94
_0804BA4C: .4byte 0x03002C30
	.syntax divided
