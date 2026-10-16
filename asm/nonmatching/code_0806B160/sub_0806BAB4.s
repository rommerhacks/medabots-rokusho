	.syntax unified

	thumb_func_start sub_0806BAB4
sub_0806BAB4: @ 0x0806BAB4
	push {lr}
	ldr r0, _0806BAD0 @ =0x03002C30
	ldr r1, _0806BAD4 @ =0x000007A1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806BAD8
	bl sub_0806BE58
	bl sub_0806C084
	bl sub_0806BD84
	b _0806BADC
	.align 2, 0
_0806BAD0: .4byte 0x03002C30
_0806BAD4: .4byte 0x000007A1
_0806BAD8:
	bl sub_0806C500
_0806BADC:
	bl sub_0806BEF0
	bl sub_0806C20C
	bl sub_0806C4CC
	bl get_battle_state_value_div10
	bl sub_0806CDE8
	bl update_battle_sprite_direction
	bl sub_0806CD48
	bl sub_0806CAEC
	pop {r0}
	bx r0
	.syntax divided
