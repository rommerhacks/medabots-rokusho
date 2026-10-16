	.syntax unified

	thumb_func_start sub_08013AE4
sub_08013AE4: @ 0x08013AE4
	push {r4, r5, lr}
	sub sp, #8
	bl update_all_battle_status_sprites
	ldr r5, _08013B14 @ =0x03001800
	adds r4, r5, #0
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	ldrb r0, [r4]
	cmp r0, #1
	beq _08013B28
	cmp r0, #1
	bgt _08013B18
	cmp r0, #0
	beq _08013B1E
	b _08013B3E
	.align 2, 0
_08013B14: .4byte 0x03001800
_08013B18:
	cmp r0, #2
	beq _08013B32
	b _08013B3E
_08013B1E:
	adds r2, r5, #0
	adds r2, #0x44
	ldrb r1, [r2]
	movs r0, #1
	b _08013B3A
_08013B28:
	adds r2, r5, #0
	adds r2, #0x44
	ldrb r1, [r2]
	movs r0, #2
	b _08013B3A
_08013B32:
	adds r2, r5, #0
	adds r2, #0x44
	ldrb r1, [r2]
	movs r0, #4
_08013B3A:
	orrs r0, r1
	strb r0, [r2]
_08013B3E:
	movs r0, #0
	movs r1, #0x46
	bl clear_battle_sprite_slot
	ldr r0, _08013B80 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #0x1e
	movs r1, #8
	movs r2, #0
	movs r3, #0xc
	bl vram_fill_tilemap_rect
	ldr r0, _08013B84 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x1e
	movs r1, #8
	movs r2, #0
	movs r3, #0xc
	bl vram_fill_tilemap_rect
	ldr r1, _08013B88 @ =0x0300137C
	movs r0, #0xd
	str r0, [r1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08013B80: .4byte 0x04000008
_08013B84: .4byte 0x0400000A
_08013B88: .4byte 0x0300137C
	.syntax divided
