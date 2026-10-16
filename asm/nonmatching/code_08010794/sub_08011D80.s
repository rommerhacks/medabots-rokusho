	.syntax unified

	thumb_func_start sub_08011D80
sub_08011D80: @ 0x08011D80
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r0, _08011DA8 @ =0x083C65C4
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08011DA2
	ldr r1, _08011DAC @ =0x0300137C
	movs r0, #0x72
	str r0, [r1]
_08011DA2:
	pop {r0}
	bx r0
	.align 2, 0
_08011DA8: .4byte 0x083C65C4
_08011DAC: .4byte 0x0300137C
	.syntax divided
