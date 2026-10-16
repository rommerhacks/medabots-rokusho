	.syntax unified

	thumb_func_start init_active_medal_battle_sprites
	.global init_active_medal_battle_sprites
init_active_medal_battle_sprites: @ 0x08009D30
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	ldr r2, _08009D88 @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x40
	lsls r0, r0, #1
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x3d
	movs r6, #0
	strb r0, [r1]
	ldrb r0, [r1]
	bl get_medal_active_slot
	adds r3, r0, #0
	cmp r3, #0xff
	beq _08009D90
	ldr r0, _08009D8C @ =0x030017A0
	lsls r3, r3, #3
	adds r3, r3, r0
	ldrb r0, [r3, #3]
	ldrb r1, [r3, #4]
	ldrb r2, [r3, #5]
	ldrb r3, [r3, #6]
	movs r5, #2
	str r5, [sp]
	movs r4, #0x64
	str r4, [sp, #4]
	movs r4, #0xe0
	str r4, [sp, #8]
	movs r4, #0x78
	str r4, [sp, #0xc]
	str r6, [sp, #0x10]
	str r5, [sp, #0x14]
	str r6, [sp, #0x18]
	bl init_battle_medabot_sprites
	b _08009D98
	.align 2, 0
_08009D88: .4byte 0x03000440
_08009D8C: .4byte 0x030017A0
_08009D90:
	movs r0, #0x64
	movs r1, #4
	bl clear_sprite_table_mask
_08009D98:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
