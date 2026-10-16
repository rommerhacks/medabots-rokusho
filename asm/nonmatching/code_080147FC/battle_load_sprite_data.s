	.syntax unified

	thumb_func_start battle_load_sprite_data
	.global battle_load_sprite_data
battle_load_sprite_data: @ 0x08015F24
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0x1e
	movs r1, #0xb
	bl clear_sprite_table_mask
	ldr r1, _08015F6C @ =0x083C466C
	ldr r0, _08015F70 @ =0x03001800
	adds r0, #0x81
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, _08015F74 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #0xc
	bl memcpy_bytes_08041D04
	movs r0, #8
	str r0, [sp]
	movs r0, #0xe
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x1e
	movs r2, #0x15
	movs r3, #0x11
	bl render_text_sprites_08040DB8
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08015F6C: .4byte 0x083C466C
_08015F70: .4byte 0x03001800
_08015F74: .4byte 0x030004DE
	.syntax divided
