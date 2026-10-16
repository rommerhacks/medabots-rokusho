	.syntax unified

	thumb_func_start set_game_state_params
	.global set_game_state_params
set_game_state_params: @ 0x08018074
	push {r4, lr}
	ldr r4, _08018094 @ =0x03000440
	mov ip, r4
	adds r4, #0x98
	strb r0, [r4]
	mov r0, ip
	adds r0, #0x99
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08018094: .4byte 0x03000440
	.syntax divided
