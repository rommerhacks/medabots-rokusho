	.syntax unified

	thumb_func_start sub_0801303C
sub_0801303C: @ 0x0801303C
	push {r4, lr}
	sub sp, #8
	bl update_all_battle_status_sprites
	ldr r4, _080130B4 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	ldr r0, _080130B8 @ =0x084E2F58
	ldr r1, _080130BC @ =0x05000340
	movs r2, #8
	bl CpuFastSet
	ldr r0, _080130C0 @ =0x084E3038
	ldr r1, _080130C4 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	movs r0, #0
	movs r1, #6
	bl clear_battle_sprite_slot
	movs r0, #0x1e
	movs r1, #0xb
	bl clear_battle_sprite_slot
	bl sub_080166AC
	bl determine_battle_part_action_priority
	ldr r0, _080130C8 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _080130CC @ =0x02020800
	str r0, [sp, #4]
	movs r0, #0xc
	movs r1, #4
	movs r2, #9
	movs r3, #0x15
	bl read_vram_tilemap_rect
	ldr r0, _080130D0 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _080130D4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080130B4: .4byte 0x03001800
_080130B8: .4byte 0x084E2F58
_080130BC: .4byte 0x05000340
_080130C0: .4byte 0x084E3038
_080130C4: .4byte 0x050002C0
_080130C8: .4byte 0x04000008
_080130CC: .4byte 0x02020800
_080130D0: .4byte 0x03000440
_080130D4: .4byte 0x0300137C
	.syntax divided
