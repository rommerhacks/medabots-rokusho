	.syntax unified

	thumb_func_start sub_08013330
sub_08013330: @ 0x08013330
	push {r4, lr}
	sub sp, #8
	bl update_all_battle_status_sprites
	ldr r4, _0801339C @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	ldr r0, _080133A0 @ =0x084E2F78
	ldr r1, _080133A4 @ =0x05000340
	movs r2, #8
	bl CpuFastSet
	movs r0, #0
	movs r1, #6
	bl clear_battle_sprite_slot
	movs r0, #0x1e
	movs r1, #0xb
	bl clear_battle_sprite_slot
	bl sub_08017004
	ldr r0, _080133A8 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _080133AC @ =0x02020800
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #4
	movs r2, #9
	movs r3, #0x15
	bl read_vram_tilemap_rect
	ldr r0, _080133B0 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _080133B4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801339C: .4byte 0x03001800
_080133A0: .4byte 0x084E2F78
_080133A4: .4byte 0x05000340
_080133A8: .4byte 0x04000008
_080133AC: .4byte 0x02020800
_080133B0: .4byte 0x03000440
_080133B4: .4byte 0x0300137C
	.syntax divided
