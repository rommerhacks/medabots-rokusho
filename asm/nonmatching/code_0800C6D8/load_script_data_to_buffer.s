	.syntax unified

	thumb_func_start load_script_data_to_buffer
load_script_data_to_buffer: @ 0x0800F844
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0x28
	movs r1, #0xf
	bl clear_sprite_table_mask
	ldr r1, _0800F898 @ =0x083BB9CC
	ldr r4, _0800F89C @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	adds r2, r4, #0
	adds r2, #0x3e
	lsls r0, r0, #2
	ldrb r2, [r2]
	adds r0, r0, r2
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
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x28
	movs r2, #0xb
	movs r3, #3
	bl render_text_sprites_08040DB8
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800F898: .4byte 0x083BB9CC
_0800F89C: .4byte 0x03000440
	.syntax divided
