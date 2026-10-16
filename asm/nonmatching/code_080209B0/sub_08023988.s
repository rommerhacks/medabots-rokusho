	.syntax unified

	thumb_func_start sub_08023988
sub_08023988: @ 0x08023988
	push {lr}
	ldr r0, _080239B4 @ =0x03000440
	adds r0, #0x84
	movs r1, #0x43
	strb r1, [r0]
	ldr r0, _080239B8 @ =0x083B5F80
	adds r1, #0xc9
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x4e
	bl play_sound_effect
	ldr r1, _080239BC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080239B4: .4byte 0x03000440
_080239B8: .4byte 0x083B5F80
_080239BC: .4byte 0x03001800
	.syntax divided
