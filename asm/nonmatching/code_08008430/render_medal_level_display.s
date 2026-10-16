	.syntax unified

	thumb_func_start render_medal_level_display
	.global render_medal_level_display
render_medal_level_display: @ 0x080097E0
	push {r4, r5, lr}
	sub sp, #0x10
	ldr r5, _0800982C @ =0x03000440
	adds r0, r5, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x40
	lsls r0, r0, #1
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r4, r5, #0
	adds r4, #0x3d
	strb r0, [r4]
	movs r0, #0x50
	movs r1, #6
	bl clear_sprite_table_mask
	ldr r1, _08009830 @ =0x03000BE0
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0800985C
	ldrb r0, [r2, #5]
	cmp r0, #0x64
	beq _08009834
	adds r4, #0x61
	ldrh r1, [r2, #2]
	adds r0, r4, #0
	bl divide_by_100000_08041370
	b _08009840
	.align 2, 0
_0800982C: .4byte 0x03000440
_08009830: .4byte 0x03000BE0
_08009834:
	adds r4, r5, #0
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #5
	bl fill_text_blank
_08009840:
	movs r0, #6
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x50
	movs r2, #0x13
	movs r3, #0x11
	bl render_text_sprites_08040DB8
	b _08009882
_0800985C:
	adds r4, r5, #0
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #5
	bl fill_text_blank
	movs r0, #6
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x50
	movs r2, #0x13
	movs r3, #0x11
	bl render_text_sprites_08040DB8
_08009882:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
