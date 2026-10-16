	.syntax unified

	thumb_func_start sub_0801FE14
sub_0801FE14: @ 0x0801FE14
	push {r4, r5, lr}
	movs r2, #0
	ldr r4, _0801FE48 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x51
	movs r3, #0
_0801FE20:
	adds r0, r4, #0
	adds r0, #0xe0
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801FE4C
	subs r0, #1
	strb r0, [r5]
	strb r3, [r1]
	bl load_all_bot_part_sprites
	bl iterate_bots_setup_battle_sprites
	ldrb r0, [r5]
	bl reset_battle_bot_state
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #2
	b _0801FE5A
	.align 2, 0
_0801FE48: .4byte 0x03001800
_0801FE4C:
	adds r2, #1
	cmp r2, #2
	bls _0801FE20
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
_0801FE5A:
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
