	.syntax unified

	thumb_func_start sub_08013508
sub_08013508: @ 0x08013508
	push {r4, lr}
	bl update_all_battle_status_sprites
	ldr r4, _08013554 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	bl save_restore_bg0_tilemap_region
	bl sub_08017948
	ldr r1, _08013558 @ =0x03000440
	adds r1, #0x84
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bne _0801354E
	ldr r0, _0801355C @ =0x084E2F38
	ldr r1, _08013560 @ =0x05000340
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08013564 @ =0x0300137C
	movs r0, #0xb
	str r0, [r1]
_0801354E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08013554: .4byte 0x03001800
_08013558: .4byte 0x03000440
_0801355C: .4byte 0x084E2F38
_08013560: .4byte 0x05000340
_08013564: .4byte 0x0300137C
	.syntax divided
