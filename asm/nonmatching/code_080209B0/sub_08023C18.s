	.syntax unified

	thumb_func_start sub_08023C18
sub_08023C18: @ 0x08023C18
	push {lr}
	ldr r0, _08023C44 @ =0x03000440
	adds r0, #0x84
	movs r1, #0x46
	strb r1, [r0]
	ldr r0, _08023C48 @ =0x083B5F80
	adds r1, #0xd2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x4e
	bl play_sound_effect
	ldr r1, _08023C4C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08023C44: .4byte 0x03000440
_08023C48: .4byte 0x083B5F80
_08023C4C: .4byte 0x03001800
	.syntax divided
