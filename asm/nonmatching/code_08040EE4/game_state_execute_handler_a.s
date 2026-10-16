	.syntax unified

	thumb_func_start game_state_execute_handler_a
	.global game_state_execute_handler_a
game_state_execute_handler_a: @ 0x08041CA4
	push {r4, lr}
	ldr r4, _08041CC4 @ =0x03000440
	movs r0, #0
	strb r0, [r4, #4]
	ldr r1, _08041CC8 @ =0x083B284C
	ldrb r0, [r4, #0x1b]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldrb r0, [r4, #4]
	cmp r0, #7
	bhi _08041CCC
	movs r0, #0
	b _08041CCE
	.align 2, 0
_08041CC4: .4byte 0x03000440
_08041CC8: .4byte 0x083B284C
_08041CCC:
	movs r0, #1
_08041CCE:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
