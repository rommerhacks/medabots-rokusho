	.syntax unified

	thumb_func_start set_battle_state_cancel_flag
	.global set_battle_state_cancel_flag
set_battle_state_cancel_flag: @ 0x08051920
	push {lr}
	ldr r0, _08051934 @ =0x030057E0
	ldr r1, _08051938 @ =0x00000C59
	adds r0, r0, r1
	movs r1, #0xff
	strb r1, [r0]
	bl sub_08051E8C
	pop {r0}
	bx r0
	.align 2, 0
_08051934: .4byte 0x030057E0
_08051938: .4byte 0x00000C59
	.syntax divided
