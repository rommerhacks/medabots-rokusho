	.syntax unified

	thumb_func_start sub_0804E738
sub_0804E738: @ 0x0804E738
	push {r4, lr}
	ldr r1, _0804E74C @ =0x030057E0
	ldr r0, _0804E750 @ =0x00000C93
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804E754
	cmp r0, #1
	beq _0804E774
	b _0804E786
	.align 2, 0
_0804E74C: .4byte 0x030057E0
_0804E750: .4byte 0x00000C93
_0804E754:
	ldr r0, _0804E76C @ =0x03006D20
	ldrb r0, [r0, #0xa]
	ldr r2, _0804E770 @ =0x00000C95
	adds r1, r1, r2
	ldrb r1, [r1]
	movs r2, #0
	bl setup_battle_sprite_terrain
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0804E786
	.align 2, 0
_0804E76C: .4byte 0x03006D20
_0804E770: .4byte 0x00000C95
_0804E774:
	ldr r0, _0804E78C @ =0x03006D20
	ldrb r0, [r0, #0xa]
	movs r1, #0
	bl update_battle_sprite_movement
	cmp r0, #0
	beq _0804E786
	bl sub_08050244
_0804E786:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804E78C: .4byte 0x03006D20

	.syntax divided
