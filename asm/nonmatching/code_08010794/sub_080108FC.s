	.syntax unified

	thumb_func_start sub_080108FC
sub_080108FC: @ 0x080108FC
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r0, _08010928 @ =0x083B53F8
	ldr r0, [r0, #0x50]
	bl run_message
	cmp r0, #0
	beq _08010924
	movs r0, #1
	movs r1, #0x16
	movs r2, #7
	bl open_choice_menu
	ldr r1, _0801092C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08010924:
	pop {r0}
	bx r0
	.align 2, 0
_08010928: .4byte 0x083B53F8
_0801092C: .4byte 0x0300137C
	.syntax divided
