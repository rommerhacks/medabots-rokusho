	.syntax unified

	thumb_func_start sub_08012DF4
sub_08012DF4: @ 0x08012DF4
	push {r4, lr}
	bl update_all_battle_status_sprites
	ldr r4, _08012E38 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	bl sub_080165D0
	bl sub_08016614
	bl sub_08016660
	ldr r1, _08012E3C @ =0x03000440
	adds r1, #0x84
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bne _08012E32
	bl sub_080165B0
_08012E32:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08012E38: .4byte 0x03001800
_08012E3C: .4byte 0x03000440
	.syntax divided
