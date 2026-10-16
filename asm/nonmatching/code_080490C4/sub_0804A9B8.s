	.syntax unified

	thumb_func_start sub_0804A9B8
sub_0804A9B8: @ 0x0804A9B8
	push {lr}
	movs r0, #0
	bl run_blend_fade_transition
	cmp r0, #0
	beq _0804A9E4
	ldr r1, _0804A9E8 @ =0x03005310
	movs r0, #0
	strb r0, [r1, #1]
	bl init_battle_field_setup
	bl update_bg_scroll_offsets_a
	ldr r0, _0804A9EC @ =0x030057E0
	ldr r1, _0804A9F0 @ =0x00000C67
	adds r0, r0, r1
	ldrb r0, [r0]
	bl field_set_player_facing
	ldr r1, _0804A9F4 @ =0x0300137C
	movs r0, #5
	str r0, [r1]
_0804A9E4:
	pop {r0}
	bx r0
	.align 2, 0
_0804A9E8: .4byte 0x03005310
_0804A9EC: .4byte 0x030057E0
_0804A9F0: .4byte 0x00000C67
_0804A9F4: .4byte 0x0300137C
	.syntax divided
