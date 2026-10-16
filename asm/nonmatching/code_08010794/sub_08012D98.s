	.syntax unified

	thumb_func_start sub_08012D98
sub_08012D98: @ 0x08012D98
	push {r4, lr}
	bl update_all_battle_status_sprites
	ldr r4, _08012DE8 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	bl sub_08016554
	ldr r0, _08012DEC @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x84
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	bne _08012DE0
	movs r0, #0x1e
	movs r1, #0xb
	bl clear_battle_sprite_slot
	movs r0, #0
	strb r0, [r4]
	ldr r1, _08012DF0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08012DE0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08012DE8: .4byte 0x03001800
_08012DEC: .4byte 0x03000440
_08012DF0: .4byte 0x0300137C
	.syntax divided
