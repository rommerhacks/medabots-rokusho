	.syntax unified

	thumb_func_start dispatch_game_substate_handler_08068C3C
dispatch_game_substate_handler_08068C3C: @ 0x08068C3C
	push {lr}
	ldr r0, _08068C60 @ =0x03006F90
	ldrb r0, [r0]
	cmp r0, #0
	bne _08068C4A
	bl sub_0806B310
_08068C4A:
	ldr r1, _08068C64 @ =0x08485C90
	ldr r0, _08068C68 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_08068C60: .4byte 0x03006F90
_08068C64: .4byte 0x08485C90
_08068C68: .4byte 0x0300137C
	.syntax divided
