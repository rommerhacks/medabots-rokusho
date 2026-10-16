	.syntax unified

	thumb_func_start clear_battle_bot_array
	.global clear_battle_bot_array
clear_battle_bot_array: @ 0x08014E7C
	push {lr}
	ldr r0, _08014E90 @ =0x03000590
	movs r1, #0xc0
	lsls r1, r1, #3
	movs r2, #0
	bl sub_0803F624
	pop {r0}
	bx r0
	.align 2, 0
_08014E90: .4byte 0x03000590
	.syntax divided
