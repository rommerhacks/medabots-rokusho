	.syntax unified

	thumb_func_start sub_0804A8B4
sub_0804A8B4: @ 0x0804A8B4
	push {lr}
	ldr r0, _0804A8E4 @ =0x00007FFF
	bl run_blend_fade_transition
	cmp r0, #0
	beq _0804A8E0
	ldr r1, _0804A8E8 @ =0x03005310
	movs r0, #0
	strb r0, [r1, #1]
	bl init_battle_field_setup
	bl update_bg_scroll_offsets_a
	ldr r0, _0804A8EC @ =0x030057E0
	ldr r1, _0804A8F0 @ =0x00000C67
	adds r0, r0, r1
	ldrb r0, [r0]
	bl set_battle_entity_animation_attack
	ldr r1, _0804A8F4 @ =0x0300137C
	movs r0, #5
	str r0, [r1]
_0804A8E0:
	pop {r0}
	bx r0
	.align 2, 0
_0804A8E4: .4byte 0x00007FFF
_0804A8E8: .4byte 0x03005310
_0804A8EC: .4byte 0x030057E0
_0804A8F0: .4byte 0x00000C67
_0804A8F4: .4byte 0x0300137C
	.syntax divided
