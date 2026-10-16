	.syntax unified

	thumb_func_start sub_080235AC
sub_080235AC: @ 0x080235AC
	push {lr}
	ldr r0, _080235DC @ =0x083B5F80
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x4d
	bl play_sound_effect
	ldr r0, _080235E0 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _080235E4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080235DC: .4byte 0x083B5F80
_080235E0: .4byte 0x03000440
_080235E4: .4byte 0x03001800
	.syntax divided
