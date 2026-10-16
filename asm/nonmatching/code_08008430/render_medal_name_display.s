	.syntax unified

	thumb_func_start render_medal_name_display
	.global render_medal_name_display
render_medal_name_display: @ 0x080096BC
	push {r4, r5, lr}
	sub sp, #0x10
	ldr r4, _0800971C @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x40
	lsls r0, r0, #1
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r5, r4, #0
	adds r5, #0x3d
	strb r0, [r5]
	movs r0, #0x46
	movs r1, #0xa
	bl clear_sprite_table_mask
	ldr r3, _08009720 @ =0x03000BE0
	ldrb r0, [r5]
	lsls r2, r0, #6
	adds r0, r2, r3
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _08009724
	adds r0, r3, #0
	adds r0, #0xa
	adds r0, r2, r0
	movs r1, #0xa
	str r1, [sp]
	movs r1, #9
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #2
	str r1, [sp, #0xc]
	movs r1, #0x46
	movs r2, #0x13
	movs r3, #3
	bl render_text_sprites_08040DB8
	b _08009748
	.align 2, 0
_0800971C: .4byte 0x03000440
_08009720: .4byte 0x03000BE0
_08009724:
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #0xa
	bl fill_text_blank
	movs r0, #0xa
	str r0, [sp]
	movs r0, #9
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x46
	movs r2, #0x13
	movs r3, #3
	bl render_text_sprites_08040DB8
_08009748:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
