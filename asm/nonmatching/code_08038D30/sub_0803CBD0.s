	.syntax unified

	thumb_func_start sub_0803CBD0
sub_0803CBD0: @ 0x0803CBD0
	push {r4, r5, lr}
	ldr r4, _0803CBF0 @ =0x03002C30
	ldr r0, _0803CBF4 @ =0x03000440
	ldr r1, _0803CBF8 @ =0x0000012F
	adds r5, r0, r1
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r3, r0, r4
	adds r1, r3, #0
	adds r1, #0x2b
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803CBFC
	subs r0, #1
	strb r0, [r1]
	b _0803CC36
	.align 2, 0
_0803CBF0: .4byte 0x03002C30
_0803CBF4: .4byte 0x03000440
_0803CBF8: .4byte 0x0000012F
_0803CBFC:
	adds r0, r3, #0
	adds r0, #0x2e
	ldrb r1, [r0]
	lsls r2, r1, #6
	adds r2, r2, r4
	ldrb r0, [r3, #0xa]
	strb r0, [r2, #0xa]
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x2d
	ldrb r0, [r0]
	adds r3, r2, #0
	adds r3, #0x2d
	strb r0, [r3]
	adds r2, #0x29
	movs r0, #0x21
	strb r0, [r2]
	ldr r2, _0803CC3C @ =0x083B5F80
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl init_battle_sprite_entry_08040B90
	ldrb r0, [r5]
	movs r1, #1
	bl clear_battle_sprite_slot
_0803CC36:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803CC3C: .4byte 0x083B5F80
	.syntax divided
