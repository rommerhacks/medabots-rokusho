	.syntax unified

	thumb_func_start sub_080208E8
sub_080208E8: @ 0x080208E8
	push {r4, lr}
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r4, _08020924 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x8b
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0xd0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	ldrb r1, [r1]
	adds r2, r4, #0
	adds r2, #0xec
	movs r3, #0
	ldrsh r2, [r2, r3]
	bl battle_calc_damage_split
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020924: .4byte 0x03001800
	.syntax divided
