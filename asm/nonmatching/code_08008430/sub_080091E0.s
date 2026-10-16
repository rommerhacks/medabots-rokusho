	.syntax unified

	thumb_func_start sub_080091E0
sub_080091E0: @ 0x080091E0
	push {r4, lr}
	bl sub_080093F8
	bl update_battle_sprite_visibility
	ldr r0, _08009210 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #7
	movs r2, #0xa8
	bl sub_08041C14
	bl handle_menu_cursor_updown
	ldr r0, _08009214 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08009218
	movs r0, #4
	bl play_sound_effect
	b _0800922E
	.align 2, 0
_08009210: .4byte 0x03001780
_08009214: .4byte 0x0300058C
_08009218:
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0800923A
	movs r0, #5
	bl play_sound_effect
	ldr r0, _08009240 @ =0x03000440
	adds r0, #0x4a
	strb r4, [r0]
_0800922E:
	bl init_battle_cursor_sprite_0800B668
	ldr r1, _08009244 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800923A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08009240: .4byte 0x03000440
_08009244: .4byte 0x0300137C
	.syntax divided
