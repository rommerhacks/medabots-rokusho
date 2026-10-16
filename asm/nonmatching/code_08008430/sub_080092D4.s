	.syntax unified

	thumb_func_start sub_080092D4
sub_080092D4: @ 0x080092D4
	push {r4, r5, lr}
	bl sub_080093F8
	bl update_battle_sprite_visibility
	ldr r1, _08009310 @ =0x03000BE0
	ldr r5, _08009314 @ =0x03000440
	adds r0, r5, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	lsls r0, r0, #6
	adds r2, r0, r1
	ldrb r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0800931C
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	adds r1, r5, #0
	adds r1, #0x84
	movs r0, #9
	strb r0, [r1]
	ldr r1, _08009318 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08009368
	.align 2, 0
_08009310: .4byte 0x03000BE0
_08009314: .4byte 0x03000440
_08009318: .4byte 0x0300137C
_0800931C:
	movs r4, #1
	ldrb r2, [r2, #1]
	lsls r4, r2
	ldr r0, _08009348 @ =0x03002B68
	ldr r0, [r0]
	ands r4, r0
	cmp r4, #0
	beq _08009350
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	adds r1, r5, #0
	adds r1, #0x84
	movs r0, #8
	strb r0, [r1]
	ldr r1, _0800934C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08009368
	.align 2, 0
_08009348: .4byte 0x03002B68
_0800934C: .4byte 0x0300137C
_08009350:
	movs r0, #5
	movs r1, #1
	bl clear_battle_sprite_slot
	movs r0, #8
	bl sound_stop_all_with_fade_guard
	adds r0, r5, #0
	adds r0, #0x3e
	strb r4, [r0]
	ldr r1, _08009370 @ =0x0300137C
	movs r0, #0x68
_08009368:
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08009370: .4byte 0x0300137C
	.syntax divided
