	.syntax unified

	thumb_func_start sub_08013650
sub_08013650: @ 0x08013650
	push {r4, lr}
	bl update_all_battle_status_sprites
	ldr r4, _0801369C @ =0x03001800
	adds r4, #0x80
	ldrb r0, [r4]
	bl animate_battle_sprites
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, #0x5a
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
	ldr r2, _080136A0 @ =0x083B70AC
	ldr r1, _080136A4 @ =0x03000590
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r1
	ldrb r0, [r0, #6]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08013694
	ldr r1, _080136A8 @ =0x03000440
	movs r0, #0
	strb r0, [r1, #0x1b]
	ldr r1, _080136AC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08013694:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801369C: .4byte 0x03001800
_080136A0: .4byte 0x083B70AC
_080136A4: .4byte 0x03000590
_080136A8: .4byte 0x03000440
_080136AC: .4byte 0x0300137C
	.syntax divided
