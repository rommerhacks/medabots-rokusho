	.syntax unified

	thumb_func_start sub_08005C10
	.global sub_08005C10
sub_08005C10: @ 0x08005C10
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0x14
	movs r1, #0xa
	bl clear_sprite_table_mask
	ldr r4, _08005C60 @ =0x03000440
	adds r3, r4, #0
	adds r3, #0x97
	ldrb r0, [r3]
	cmp r0, #0x1d
	bhi _08005C6C
	ldr r2, _08005C64 @ =0x083B6410
	ldr r1, _08005C68 @ =0x03000BE0
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #0xb
	bl memcpy_bytes_0803F63C
	movs r0, #7
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x12
	movs r3, #9
	bl render_text_sprites_08040DB8
	b _08005C92
	.align 2, 0
_08005C60: .4byte 0x03000440
_08005C64: .4byte 0x083B6410
_08005C68: .4byte 0x03000BE0
_08005C6C:
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #9
	bl fill_text_blank
	movs r0, #7
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x12
	movs r3, #9
	bl render_text_sprites_08040DB8
_08005C92:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
