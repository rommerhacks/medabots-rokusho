	.syntax unified

	thumb_func_start sub_0800A05C
	.global sub_0800A05C
sub_0800A05C: @ 0x0800A05C
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0x2d
	movs r1, #0xd
	bl clear_sprite_table_mask
	ldr r2, _0800A0AC @ =0x083B6EC8
	ldr r1, _0800A0B0 @ =0x03000BE0
	ldr r4, _0800A0B4 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #6]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	movs r0, #0xa
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x2d
	movs r2, #0xa
	movs r3, #0xa
	bl render_text_sprites_08040DB8
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800A0AC: .4byte 0x083B6EC8
_0800A0B0: .4byte 0x03000BE0
_0800A0B4: .4byte 0x03000440
	.syntax divided
