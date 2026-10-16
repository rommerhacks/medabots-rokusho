	.syntax unified

	thumb_func_start sub_08030E14
sub_08030E14: @ 0x08030E14
	push {r4, r5, lr}
	movs r0, #0
	bl dispatch_battle_action_substate
	ldr r4, _08030E4C @ =0x03001800
	adds r4, #0x87
	ldrb r0, [r4]
	bl battle_increment_bot_level
	adds r5, r0, #0
	ldrb r0, [r4]
	bl sub_0801B0E8
	adds r5, r5, r0
	cmp r5, #2
	bne _08030E44
	bl clear_battle_ui_tilemaps
	bl sub_0801AEB4
	ldr r1, _08030E50 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08030E44:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08030E4C: .4byte 0x03001800
_08030E50: .4byte 0x0300137C
	.syntax divided
