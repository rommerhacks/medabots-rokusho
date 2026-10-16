	.syntax unified

	thumb_func_start sub_080572F8
sub_080572F8: @ 0x080572F8
	push {r4, r5, lr}
	sub sp, #0x18
	ldr r4, _08057344 @ =0x030064A0
	adds r0, r4, #0
	adds r0, #0x66
	movs r5, #0
	strb r5, [r0]
	adds r2, r4, #0
	adds r2, #0x6f
	ldrb r0, [r2]
	cmp r0, #0xf
	bhi _08057350
	adds r0, #1
	strb r0, [r2]
	ldr r0, _08057348 @ =0x03006D14
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r1, _0805734C @ =0x06002800
	ldrb r2, [r2]
	movs r3, #0x1e
	subs r3, r3, r2
	str r2, [sp]
	movs r2, #0xa
	str r2, [sp, #4]
	movs r2, #0x20
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	str r5, [sp, #0x10]
	str r5, [sp, #0x14]
	movs r2, #2
	bl copy_tilemap_rect_with_offset
	movs r0, #0
	bl init_vehicle_menu_sprite
	b _08057370
	.align 2, 0
_08057344: .4byte 0x030064A0
_08057348: .4byte 0x03006D14
_0805734C: .4byte 0x06002800
_08057350:
	ldr r1, _08057378 @ =0x0000C004
	ldr r2, _0805737C @ =0x00000307
	str r5, [sp]
	movs r0, #0x7f
	movs r3, #0xc
	bl init_battle_sprite_entry_08048818
	bl update_cursor_sprite_position
	adds r0, r4, #0
	adds r0, #0x65
	strb r5, [r0]
	bl init_cursor_state
	bl sub_0804A1C4
_08057370:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08057378: .4byte 0x0000C004
_0805737C: .4byte 0x00000307
_08057380:
	.byte 0x00, 0xB5, 0xF2, 0xF7, 0x1F, 0xFF, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.syntax divided
