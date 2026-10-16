	.syntax unified

	thumb_func_start render_medal_name_text
	.global render_medal_name_text
render_medal_name_text: @ 0x08005E00
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0x2c
	movs r1, #0xe
	bl clear_sprite_table_mask
	ldr r4, _08005E4C @ =0x03000440
	adds r2, r4, #0
	adds r2, #0x99
	ldrb r0, [r2]
	cmp r0, #0x77
	bhi _08005E54
	ldr r1, _08005E50 @ =0x083BB9CC
	lsls r0, r0, #2
	adds r0, #1
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
	movs r1, #0x2c
	movs r2, #0x12
	movs r3, #0xd
	bl render_text_sprites_08040DB8
	b _08005E7A
	.align 2, 0
_08005E4C: .4byte 0x03000440
_08005E50: .4byte 0x083BB9CC
_08005E54:
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #0xd
	bl fill_text_blank
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x2c
	movs r2, #0x12
	movs r3, #0xd
	bl render_text_sprites_08040DB8
_08005E7A:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
