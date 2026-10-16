	.syntax unified

	thumb_func_start sub_0800519C
	.global sub_0800519C
sub_0800519C: @ 0x0800519C
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0x3c
	movs r1, #0xa
	bl clear_sprite_table_mask
	ldr r0, _080051F0 @ =0x030017A0
	ldr r4, _080051F4 @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x51
	ldrb r1, [r1]
	lsls r1, r1, #3
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #1
	bls _080051FC
	ldr r1, _080051F8 @ =0x083B6410
	ldrb r0, [r2, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #0xb
	bl memcpy_bytes_0803F63C
	movs r0, #7
	str r0, [sp]
	movs r0, #0xe
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x3c
	movs r2, #4
	movs r3, #0x10
	bl render_text_sprites_08040DB8
	b _08005222
	.align 2, 0
_080051F0: .4byte 0x030017A0
_080051F4: .4byte 0x03000440
_080051F8: .4byte 0x083B6410
_080051FC:
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #9
	bl sub_08042678
	movs r0, #7
	str r0, [sp]
	movs r0, #0xe
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x3c
	movs r2, #4
	movs r3, #0x10
	bl render_text_sprites_08040DB8
_08005222:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
