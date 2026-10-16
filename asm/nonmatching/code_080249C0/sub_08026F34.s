	.syntax unified

	thumb_func_start sub_08026F34
sub_08026F34: @ 0x08026F34
	push {r4, lr}
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r4, _08026F68 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0xd0
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
_08026F68: .4byte 0x03001800
	.syntax divided
