	.syntax unified

	thumb_func_start sub_0805738C
sub_0805738C: @ 0x0805738C
	push {r4, r5, r6, lr}
	sub sp, #0x18
	ldr r6, _080573E0 @ =0x030064A0
	adds r5, r6, #0
	adds r5, #0x67
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	bl update_cursor_sprite_position
	movs r0, #4
	bl handle_cursor_up_down_input
	ldr r0, _080573E4 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0805746C
	adds r0, r6, #0
	adds r0, #0x65
	ldrb r0, [r0]
	bl check_vehicle_usability
	adds r4, r0, #0
	cmp r4, #0
	beq _08057434
	movs r0, #0
	strb r0, [r5]
	bl update_cursor_sprite_position
	movs r0, #6
	bl sub_08047BA8
	subs r0, r4, #1
	cmp r0, #5
	bhi _0805748C
	lsls r0, r0, #2
	ldr r1, _080573E8 @ =_080573EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080573E0: .4byte 0x030064A0
_080573E4: .4byte 0x0300058C
_080573E8: .4byte _080573EC
_080573EC: @ jump table
	.4byte _0805748C @ case 0
	.4byte _08057404 @ case 1
	.4byte _0805741C @ case 2
	.4byte _08057428 @ case 3
	.4byte _08057428 @ case 4
	.4byte _08057428 @ case 5
_08057404:
	ldr r0, _08057414 @ =0x030064A0
	adds r0, #0x70
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08057418 @ =0x0300137C
	movs r0, #0xb
	str r0, [r1]
	b _0805748C
	.align 2, 0
_08057414: .4byte 0x030064A0
_08057418: .4byte 0x0300137C
_0805741C:
	ldr r1, _08057424 @ =0x0300137C
	movs r0, #0xd
	str r0, [r1]
	b _0805748C
	.align 2, 0
_08057424: .4byte 0x0300137C
_08057428:
	ldr r1, _08057430 @ =0x0300137C
	movs r0, #0xf
	str r0, [r1]
	b _0805748C
	.align 2, 0
_08057430: .4byte 0x0300137C
_08057434:
	ldr r0, _08057464 @ =0x06002800
	adds r1, r6, #0
	adds r1, #0x72
	movs r2, #0x1e
	str r2, [sp]
	movs r2, #0x14
	str r2, [sp, #4]
	movs r2, #0x20
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	str r4, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r2, #0
	movs r3, #0
	bl copy_tilemap_rect_with_offset
	movs r0, #4
	bl sub_08047BA8
	ldr r1, _08057468 @ =0x0300137C
	movs r0, #0xa
	str r0, [r1]
	b _0805748C
	.align 2, 0
_08057464: .4byte 0x06002800
_08057468: .4byte 0x0300137C
_0805746C:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0805748C
	movs r0, #5
	bl sub_08047BA8
	movs r0, #0x7f
	bl clear_battle_sprite_entry
	adds r1, r6, #0
	adds r1, #0x6f
	movs r0, #0x10
	strb r0, [r1]
	bl sub_0804A1C4
_0805748C:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
