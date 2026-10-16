	.syntax unified

	thumb_func_start check_sprite_done_and_advance_battle
check_sprite_done_and_advance_battle: @ 0x080715CC
	push {lr}
	ldr r0, _080715F0 @ =0x03002C30
	ldr r1, _080715F4 @ =0x000002A2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080715EC
	movs r0, #0x20
	bl sound_stop_all_with_fade_guard
	ldr r1, _080715F8 @ =0x03001800
	movs r0, #0x11
	strh r0, [r1, #4]
	ldr r1, _080715FC @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_080715EC:
	pop {r0}
	bx r0
	.align 2, 0
_080715F0: .4byte 0x03002C30
_080715F4: .4byte 0x000002A2
_080715F8: .4byte 0x03001800
_080715FC: .4byte 0x0300137C
	.syntax divided
