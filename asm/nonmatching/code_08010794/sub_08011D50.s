	.syntax unified

	thumb_func_start sub_08011D50
sub_08011D50: @ 0x08011D50
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl sub_080440B4
	cmp r0, #0
	beq _08011D6C
	ldr r1, _08011D68 @ =0x0300137C
	movs r0, #0x40
	b _08011D76
	.align 2, 0
_08011D68: .4byte 0x0300137C
_08011D6C:
	bl sub_0803FB0C
	ldr r1, _08011D7C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
_08011D76:
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08011D7C: .4byte 0x0300137C
	.syntax divided
