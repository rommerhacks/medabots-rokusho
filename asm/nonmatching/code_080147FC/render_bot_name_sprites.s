	.syntax unified

	thumb_func_start render_bot_name_sprites
	.global render_bot_name_sprites
render_bot_name_sprites: @ 0x08015B3C
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	cmp r4, #2
	bhi _08015B74
	movs r0, #0xa
	movs r1, #0xa
	bl clear_sprite_table_mask
	lsls r0, r4, #8
	ldr r1, _08015B70 @ =0x0300059A
	adds r0, r0, r1
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xf
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r1, #0xa
	movs r2, #1
	movs r3, #0xe
	bl render_text_sprites_08040DB8
	b _08015B9C
	.align 2, 0
_08015B70: .4byte 0x0300059A
_08015B74:
	movs r0, #0x14
	movs r1, #0xd
	bl clear_sprite_table_mask
	lsls r0, r4, #8
	ldr r1, _08015BA4 @ =0x0300059A
	adds r0, r0, r1
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xf
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r1, #0x14
	movs r2, #0x13
	movs r3, #0xe
	bl render_text_sprites_08040DB8
_08015B9C:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08015BA4: .4byte 0x0300059A
	.syntax divided
