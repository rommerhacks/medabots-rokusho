	.syntax unified

	thumb_func_start sub_0803DEF0
sub_0803DEF0: @ 0x0803DEF0
	push {r4, r5, lr}
	bl sub_0803E894
	ldr r5, _0803DF34 @ =0x03000440
	adds r0, r5, #0
	adds r0, #0x9c
	ldrb r4, [r0]
	cmp r4, #1
	bne _0803DF44
	bl sub_0803EA18
	bl draw_battle_gauge_bar
	ldr r0, _0803DF38 @ =0x0300058C
	ldrb r0, [r0]
	ands r4, r0
	cmp r4, #0
	beq _0803DF82
	movs r0, #4
	bl play_sound_effect
	ldr r2, _0803DF3C @ =0x03005010
	ldr r0, _0803DF40 @ =0x03001800
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r1, r3, #0
	adds r0, r0, r1
	movs r1, #0
	strh r0, [r2, #6]
	b _0803DF74
	.align 2, 0
_0803DF34: .4byte 0x03000440
_0803DF38: .4byte 0x0300058C
_0803DF3C: .4byte 0x03005010
_0803DF40: .4byte 0x03001800
_0803DF44:
	ldr r1, _0803DF88 @ =0x03005010
	ldr r0, _0803DF8C @ =0x03000B90
	ldrb r2, [r0]
	movs r0, #1
	eors r0, r2
	lsls r0, r0, #2
	adds r1, #0xa
	adds r0, r0, r1
	ldrh r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r4
	cmp r0, #0
	beq _0803DF82
	movs r0, #4
	bl play_sound_effect
	ldr r0, _0803DF90 @ =0x03001800
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	strb r4, [r0]
	strb r1, [r5, #0x1b]
_0803DF74:
	adds r0, r5, #0
	adds r0, #0x86
	strh r1, [r0]
	ldr r1, _0803DF94 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DF82:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803DF88: .4byte 0x03005010
_0803DF8C: .4byte 0x03000B90
_0803DF90: .4byte 0x03001800
_0803DF94: .4byte 0x0300137C
	.syntax divided
