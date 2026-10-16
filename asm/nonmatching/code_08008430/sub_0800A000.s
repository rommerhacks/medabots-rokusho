	.syntax unified

	thumb_func_start sub_0800A000
	.global sub_0800A000
sub_0800A000: @ 0x0800A000
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0x1e
	movs r1, #0xf
	bl clear_sprite_table_mask
	ldr r2, _0800A050 @ =0x083B656C
	ldr r1, _0800A054 @ =0x03000BE0
	ldr r4, _0800A058 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r0, [r0, #4]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xb
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x1e
	movs r2, #0xa
	movs r3, #7
	bl render_text_sprites_08040DB8
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800A050: .4byte 0x083B656C
_0800A054: .4byte 0x03000BE0
_0800A058: .4byte 0x03000440
	.syntax divided
