	.syntax unified

	thumb_func_start sub_080130D8
sub_080130D8: @ 0x080130D8
	push {r4, lr}
	bl update_all_battle_status_sprites
	ldr r4, _08013158 @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	bl sub_080166F0
	bl sub_0801672C
	ldr r0, _0801315C @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x84
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bne _08013150
	bl sub_08016DA4
	bl sub_0801677C
	movs r0, #1
	bl sub_080167BC
	movs r0, #1
	bl sub_08016804
	movs r0, #1
	bl sub_0801684C
	movs r0, #1
	bl sub_08016894
	bl sub_08016A3C
	bl sub_08016AD8
	bl sub_08016D18
	bl sub_08016DCC
	bl sub_0801B894
	movs r0, #0
	strb r0, [r4]
	ldr r1, _08013160 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08013150:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08013158: .4byte 0x03001800
_0801315C: .4byte 0x03000440
_08013160: .4byte 0x0300137C
	.syntax divided
