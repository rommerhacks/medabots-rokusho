	.syntax unified

	thumb_func_start copy_battle_bot_data_to_state
	.global copy_battle_bot_data_to_state
copy_battle_bot_data_to_state: @ 0x08017D90
	push {r4, r5, lr}
	sub sp, #0x10
	movs r0, #0x16
	movs r1, #0xa
	bl clear_sprite_table_mask
	ldr r3, _08017DF4 @ =0x083B6410
	ldr r2, _08017DF8 @ =0x03000590
	ldr r4, _08017DFC @ =0x03000440
	movs r0, #0x3d
	adds r0, r0, r4
	mov ip, r0
	adds r0, r4, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	mov r1, ip
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r0, r0, r2
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	adds r0, r0, r3
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
	movs r1, #0x16
	movs r2, #0xd
	movs r3, #2
	bl render_text_sprites_08040DB8
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08017DF4: .4byte 0x083B6410
_08017DF8: .4byte 0x03000590
_08017DFC: .4byte 0x03000440
	.syntax divided
