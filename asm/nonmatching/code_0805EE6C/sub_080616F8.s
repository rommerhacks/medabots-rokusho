	.syntax unified

	thumb_func_start sub_080616F8
sub_080616F8: @ 0x080616F8
	push {r4, lr}
	ldr r4, _08061720 @ =0x03006F74
	ldr r0, [r4]
	ldrb r0, [r0, #0x19]
	ldr r1, _08061724 @ =0x03001780
	ldr r1, [r1]
	lsls r1, r1, #1
	bl battle_menu_highlight_icons
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0x48
	ldrb r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	beq _08061728
	subs r0, #1
	strb r0, [r1]
	b _0806173E
	.align 2, 0
_08061720: .4byte 0x03006F74
_08061724: .4byte 0x03001780
_08061728:
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _0806173E
	ldr r0, _08061744 @ =0x03000440
	adds r0, #0x84
	strb r4, [r0]
	ldr r1, _08061748 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0806173E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08061744: .4byte 0x03000440
_08061748: .4byte 0x0300137C
	.syntax divided
