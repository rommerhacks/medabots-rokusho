	.syntax unified

	thumb_func_start sub_08010D58
sub_08010D58: @ 0x08010D58
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl setup_battle_result_sprite
	ldr r0, _08010D90 @ =0x083C65C4
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08010DA2
	ldr r0, _08010D94 @ =0x03001800
	movs r1, #0xb5
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08010D9C
	ldr r1, _08010D98 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08010DA0
	.align 2, 0
_08010D90: .4byte 0x083C65C4
_08010D94: .4byte 0x03001800
_08010D98: .4byte 0x0300137C
_08010D9C:
	ldr r1, _08010DA8 @ =0x0300137C
	movs r0, #0x3c
_08010DA0:
	str r0, [r1]
_08010DA2:
	pop {r0}
	bx r0
	.align 2, 0
_08010DA8: .4byte 0x0300137C
	.syntax divided
