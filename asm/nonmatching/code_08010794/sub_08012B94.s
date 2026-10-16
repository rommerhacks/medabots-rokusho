	.syntax unified

	thumb_func_start sub_08012B94
sub_08012B94: @ 0x08012B94
	push {lr}
	bl update_all_battle_status_sprites
	ldr r0, _08012BB8 @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	beq _08012BAA
	movs r0, #3
	bl battle_process_bot_actions_for_side
_08012BAA:
	ldr r1, _08012BBC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08012BB8: .4byte 0x03000440
_08012BBC: .4byte 0x0300137C
	.syntax divided
