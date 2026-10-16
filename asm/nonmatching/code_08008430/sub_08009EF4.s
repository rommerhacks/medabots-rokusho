	.syntax unified

	thumb_func_start sub_08009EF4
	.global sub_08009EF4
sub_08009EF4: @ 0x08009EF4
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0xa
	movs r1, #0xa
	bl clear_sprite_table_mask
	ldr r2, _08009F44 @ =0x083B6410
	ldr r1, _08009F48 @ =0x03000BE0
	ldr r4, _08009F4C @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3d
	ldrb r0, [r0]
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
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #4
	movs r3, #3
	bl render_text_sprites_08040DB8
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08009F44: .4byte 0x083B6410
_08009F48: .4byte 0x03000BE0
_08009F4C: .4byte 0x03000440
	.syntax divided
