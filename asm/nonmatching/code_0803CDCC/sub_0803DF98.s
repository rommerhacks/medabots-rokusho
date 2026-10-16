	.syntax unified

	thumb_func_start sub_0803DF98
sub_0803DF98: @ 0x0803DF98
	push {r4, lr}
	bl sub_0803E894
	ldr r4, _0803DFD4 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803DFE0
	ldr r2, _0803DFD8 @ =0x03005010
	ldr r0, _0803DFDC @ =0x03001800
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #8
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r2, #6]
	bl update_battle_gauge_display
	adds r1, r4, #0
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _0803DFF6
	.align 2, 0
_0803DFD4: .4byte 0x03000440
_0803DFD8: .4byte 0x03005010
_0803DFDC: .4byte 0x03001800
_0803DFE0:
	bl update_battle_gauge_display
	adds r4, #0x86
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _0803E00C
	ldrh r0, [r4]
_0803DFF6:
	cmp r0, #0x3c
	bne _0803E00C
	movs r0, #0x39
	bl play_sound_effect
	bl draw_battle_gauge_bar
	ldr r1, _0803E014 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803E00C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803E014: .4byte 0x0300137C
	.syntax divided
