	.syntax unified

	thumb_func_start game_state_execute_handler_b
	.global game_state_execute_handler_b
game_state_execute_handler_b: @ 0x08041CD4
	push {r4, lr}
	ldr r4, _08041CF4 @ =0x03000440
	movs r0, #0
	strb r0, [r4, #4]
	ldr r1, _08041CF8 @ =0x083B2864
	ldrb r0, [r4, #0x1b]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldrb r0, [r4, #4]
	cmp r0, #7
	bhi _08041CFC
	movs r0, #0
	b _08041CFE
	.align 2, 0
_08041CF4: .4byte 0x03000440
_08041CF8: .4byte 0x083B2864
_08041CFC:
	movs r0, #1
_08041CFE:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
