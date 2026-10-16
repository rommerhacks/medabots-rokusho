	.syntax unified

	thumb_func_start sub_08009374
sub_08009374: @ 0x08009374
	push {lr}
	bl sub_080093F8
	bl update_battle_sprite_visibility
	ldr r1, _080093A0 @ =0x083CF3B0
	ldr r0, _080093A4 @ =0x03000440
	adds r0, #0x84
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _0800939A
	ldr r1, _080093A8 @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_0800939A:
	pop {r0}
	bx r0
	.align 2, 0
_080093A0: .4byte 0x083CF3B0
_080093A4: .4byte 0x03000440
_080093A8: .4byte 0x0300137C
	.syntax divided
