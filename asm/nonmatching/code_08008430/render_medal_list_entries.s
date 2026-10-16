	.syntax unified

	thumb_func_start render_medal_list_entries
	.global render_medal_list_entries
render_medal_list_entries: @ 0x08009540
	push {r4, r5, r6, lr}
	sub sp, #0x10
	movs r4, #0
	movs r0, #0xa
	movs r1, #0x3c
	bl clear_sprite_table_mask
	ldr r2, _080095B8 @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r1, #1
	lsls r1, r1, #0x19
	lsrs r5, r1, #0x18
	adds r0, #6
	cmp r5, r0
	bge _08009614
	adds r6, r2, #0
	adds r6, #0x9e
_0800956A:
	ldr r1, _080095BC @ =0x03000BE0
	lsls r0, r5, #6
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080095C4
	ldr r1, _080095C0 @ =0x083B6410
	ldrb r0, [r2, #1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r6, #0
	movs r2, #0xb
	bl memcpy_bytes_0803F63C
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #0x19
	movs r0, #0xa0
	lsls r0, r0, #0x14
	adds r1, r1, r0
	lsrs r1, r1, #0x18
	lsls r3, r4, #1
	adds r3, #4
	movs r0, #7
	str r0, [sp]
	movs r0, #8
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	adds r0, r6, #0
	movs r2, #6
	bl render_text_sprites_08040DB8
	b _080095F6
	.align 2, 0
_080095B8: .4byte 0x03000440
_080095BC: .4byte 0x03000BE0
_080095C0: .4byte 0x083B6410
_080095C4:
	adds r0, r6, #0
	movs r1, #9
	bl fill_text_blank
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #0x19
	movs r0, #0xa0
	lsls r0, r0, #0x14
	adds r1, r1, r0
	lsrs r1, r1, #0x18
	lsls r3, r4, #1
	adds r3, #4
	movs r0, #7
	str r0, [sp]
	movs r0, #8
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	adds r0, r6, #0
	movs r2, #6
	bl render_text_sprites_08040DB8
_080095F6:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _0800961C @ =0x03000440
	adds r0, #0x3f
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r0, #6
	cmp r5, r0
	blt _0800956A
_08009614:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800961C: .4byte 0x03000440
	.syntax divided
