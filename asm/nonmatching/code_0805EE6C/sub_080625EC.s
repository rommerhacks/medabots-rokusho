	.syntax unified

	thumb_func_start sub_080625EC
sub_080625EC: @ 0x080625EC
	push {lr}
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _0806262E
	ldr r0, _08062620 @ =0x03000440
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne _08062628
	movs r0, #0x61
	movs r1, #7
	bl clear_sprite_table_mask
	movs r0, #0xd
	movs r1, #0x34
	bl clear_sprite_table_mask
	movs r0, #0x45
	movs r1, #0x1c
	bl clear_sprite_table_mask
	ldr r1, _08062624 @ =0x0300137C
	movs r0, #5
	b _0806262C
	.align 2, 0
_08062620: .4byte 0x03000440
_08062624: .4byte 0x0300137C
_08062628:
	ldr r1, _08062634 @ =0x0300137C
	movs r0, #4
_0806262C:
	str r0, [r1]
_0806262E:
	pop {r0}
	bx r0
	.align 2, 0
_08062634: .4byte 0x0300137C
	.syntax divided
