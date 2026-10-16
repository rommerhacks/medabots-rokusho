	.syntax unified

	thumb_func_start get_battle_state_value_div10
get_battle_state_value_div10: @ 0x0806D204
	push {r4, r5, r6, lr}
	sub sp, #4
	movs r6, #0xc4
	lsls r6, r6, #8
	ldr r5, _0806D254 @ =0x03001800
	movs r0, #0xe
	ldrsb r0, [r5, r0]
	movs r1, #0xa
	bl sub_0807CBBC
	adds r2, r0, #0
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0x21
	movs r4, #3
	str r4, [sp]
	movs r0, #0xb
	adds r1, r6, #0
	movs r3, #8
	bl init_battle_sprite_entry_08048818
	movs r0, #0xe
	ldrsb r0, [r5, r0]
	movs r1, #0xa
	bl sub_0807CC88
	adds r2, r0, #0
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0x21
	str r4, [sp]
	movs r0, #0xc
	adds r1, r6, #0
	movs r3, #8
	bl init_battle_sprite_entry_08048818
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0806D254: .4byte 0x03001800
	.syntax divided
