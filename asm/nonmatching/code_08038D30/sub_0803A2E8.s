	.syntax unified

	thumb_func_start sub_0803A2E8
sub_0803A2E8: @ 0x0803A2E8
	push {lr}
	bl load_battle_sequence_commands
	ldr r1, _0803A30C @ =0x03001800
	movs r2, #0x81
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, #2
	adds r1, r1, r2
	ldrb r1, [r1]
	bl clear_battle_sprite_slot
	bl battle_advance_sequence_counter
	pop {r0}
	bx r0
	.align 2, 0
_0803A30C: .4byte 0x03001800
	.syntax divided
