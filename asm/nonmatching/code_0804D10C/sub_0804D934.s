	.syntax unified

	thumb_func_start sub_0804D934
	.global sub_0804D934
sub_0804D934: @ 0x0804D934
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	ldr r1, _0804D9A0 @ =0x084045A8
	ldr r2, _0804D9A4 @ =0x030057E0
	ldr r3, _0804D9A8 @ =0x000007FE
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldrb r0, [r4]
	ldrb r1, [r4, #1]
	movs r6, #0x80
	lsls r6, r6, #4
	adds r2, r2, r6
	ldrh r2, [r2]
	lsrs r2, r2, #1
	muls r2, r1, r2
	adds r2, r2, r0
	adds r3, r3, r2
	ldrb r2, [r3]
	bl set_tile_data
	ldrb r1, [r4, #4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804D990
	lsls r0, r1, #0x1b
	lsrs r0, r0, #3
	movs r1, #0xc4
	lsls r1, r1, #0x16
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	bl clear_battle_sprite_entry
	ldrb r0, [r4, #4]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #3
	movs r3, #0xb6
	lsls r3, r3, #0x17
	adds r0, r0, r3
	lsrs r0, r0, #0x18
	bl clear_battle_sprite_entry
_0804D990:
	adds r0, r5, #0
	movs r1, #8
	bl sub_080496C8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804D9A0: .4byte 0x084045A8
_0804D9A4: .4byte 0x030057E0
_0804D9A8: .4byte 0x000007FE
	.syntax divided
