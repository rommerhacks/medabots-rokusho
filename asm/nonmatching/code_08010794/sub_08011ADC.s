	.syntax unified

	thumb_func_start sub_08011ADC
sub_08011ADC: @ 0x08011ADC
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r0, _08011B0C @ =0x083C65C4
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08011B06
	ldr r1, _08011B10 @ =0x03000440
	movs r0, #0
	strb r0, [r1, #0x1b]
	ldr r1, _08011B14 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08011B06:
	pop {r0}
	bx r0
	.align 2, 0
_08011B0C: .4byte 0x083C65C4
_08011B10: .4byte 0x03000440
_08011B14: .4byte 0x0300137C
	.syntax divided
