	.syntax unified

	thumb_func_start render_medal_desc_text
	.global render_medal_desc_text
render_medal_desc_text: @ 0x08005F68
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0x3a
	movs r1, #0xe
	bl clear_sprite_table_mask
	ldr r4, _08005FB4 @ =0x03000440
	adds r2, r4, #0
	adds r2, #0x9a
	ldrb r0, [r2]
	cmp r0, #0x77
	bhi _08005FBC
	ldr r1, _08005FB8 @ =0x083BB9CC
	lsls r0, r0, #2
	adds r0, #2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #0xf
	bl memcpy_bytes_08041D04
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x3a
	movs r2, #0x12
	movs r3, #0xf
	bl render_text_sprites_08040DB8
	b _08005FE2
	.align 2, 0
_08005FB4: .4byte 0x03000440
_08005FB8: .4byte 0x083BB9CC
_08005FBC:
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #0xd
	bl sub_08042678
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x3a
	movs r2, #0x12
	movs r3, #0xf
	bl render_text_sprites_08040DB8
_08005FE2:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
