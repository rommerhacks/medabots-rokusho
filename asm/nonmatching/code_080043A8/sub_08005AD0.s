	.syntax unified

	thumb_func_start sub_08005AD0
	.global sub_08005AD0
sub_08005AD0: @ 0x08005AD0
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0xa
	movs r1, #0xa
	bl clear_sprite_table_mask
	ldr r4, _08005B0C @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x97
	ldrb r0, [r1]
	cmp r0, #0x1d
	bhi _08005B14
	lsls r0, r0, #6
	ldr r1, _08005B10 @ =0x03000BEA
	adds r0, r0, r1
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xf
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #2
	str r1, [sp, #0xc]
	movs r1, #0xa
	movs r2, #1
	movs r3, #0xd
	bl render_text_sprites_08040DB8
	b _08005B3A
	.align 2, 0
_08005B0C: .4byte 0x03000440
_08005B10: .4byte 0x03000BEA
_08005B14:
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #0xa
	bl fill_text_blank
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #1
	movs r3, #0xd
	bl render_text_sprites_08040DB8
_08005B3A:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
