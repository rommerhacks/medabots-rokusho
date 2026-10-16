	.syntax unified

	thumb_func_start sub_08006F14
sub_08006F14: @ 0x08006F14
	push {lr}
	ldr r0, _08006F30 @ =0x03000440
	adds r0, #0x53
	ldrb r0, [r0]
	cmp r0, #0
	beq _08006F2A
	movs r0, #6
	movs r1, #0
	movs r2, #0
	bl update_battle_sprite_orbiting_positions
_08006F2A:
	pop {r0}
	bx r0
	.align 2, 0
_08006F30: .4byte 0x03000440
	.syntax divided
