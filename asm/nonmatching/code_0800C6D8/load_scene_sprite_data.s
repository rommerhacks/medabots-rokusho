	.syntax unified

	thumb_func_start load_scene_sprite_data
load_scene_sprite_data: @ 0x0800F77C
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0x19
	movs r1, #0xf
	bl clear_sprite_table_mask
	ldr r1, _0800F7C8 @ =0x083B656C
	ldr r4, _0800F7CC @ =0x03000440
	adds r0, r4, #0
	adds r0, #0xee
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, #0x9e
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	movs r0, #8
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #2
	movs r3, #0xb
	bl render_text_sprites_08040DB8
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800F7C8: .4byte 0x083B656C
_0800F7CC: .4byte 0x03000440
	.syntax divided
