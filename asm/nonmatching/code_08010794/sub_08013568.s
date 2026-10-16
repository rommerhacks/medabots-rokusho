	.syntax unified

	thumb_func_start sub_08013568
sub_08013568: @ 0x08013568
	push {r4, r5, lr}
	sub sp, #8
	bl update_all_battle_status_sprites
	ldr r4, _080135F8 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	ldr r4, _080135FC @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x84
	ldrb r0, [r1]
	movs r5, #0
	adds r0, #2
	strb r0, [r1]
	bl sub_0801767C
	movs r0, #1
	bl sub_080173B4
	adds r4, #0x86
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bne _080135EE
	movs r0, #0
	movs r1, #0x46
	bl clear_battle_sprite_slot
	ldr r0, _08013600 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x1e
	movs r1, #8
	movs r2, #0
	movs r3, #0xc
	bl vram_fill_tilemap_rect
	ldr r0, _08013604 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x1e
	movs r1, #8
	movs r2, #0
	movs r3, #0xc
	bl vram_fill_tilemap_rect
	ldr r0, _08013608 @ =0x084E2F38
	ldr r1, _0801360C @ =0x05000340
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08013610 @ =0x0300137C
	movs r0, #0xd
	str r0, [r1]
_080135EE:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080135F8: .4byte 0x03001800
_080135FC: .4byte 0x03000440
_08013600: .4byte 0x04000008
_08013604: .4byte 0x0400000A
_08013608: .4byte 0x084E2F38
_0801360C: .4byte 0x05000340
_08013610: .4byte 0x0300137C
	.syntax divided
