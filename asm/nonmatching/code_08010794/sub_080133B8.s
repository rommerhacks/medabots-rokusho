	.syntax unified

	thumb_func_start sub_080133B8
sub_080133B8: @ 0x080133B8
	push {r4, lr}
	bl update_all_battle_status_sprites
	ldr r4, _0801342C @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	bl sub_08017048
	bl sub_08017084
	ldr r0, _08013430 @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x84
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bne _08013426
	bl sub_080170D4
	bl sub_08017104
	movs r0, #1
	bl sub_08017178
	movs r0, #1
	bl sub_080171C0
	movs r0, #1
	bl sub_08017208
	movs r0, #1
	bl sub_08017130
	bl sub_08017268
	movs r0, #0
	bl sub_080173B4
	movs r0, #0
	strb r0, [r4]
	ldr r1, _08013434 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08013426:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801342C: .4byte 0x03001800
_08013430: .4byte 0x03000440
_08013434: .4byte 0x0300137C
	.syntax divided
