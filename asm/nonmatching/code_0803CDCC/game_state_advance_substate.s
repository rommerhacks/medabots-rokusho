	.syntax unified

	thumb_func_start game_state_advance_substate
game_state_advance_substate: @ 0x0803FB6C
	push {r4, r5, lr}
	ldr r5, _0803FB84 @ =0x03000440
	ldrb r4, [r5]
	cmp r4, #0
	bne _0803FB88
	bl copy_obj_palette_to_buffer
	strb r4, [r5, #0x1c]
	ldrb r0, [r5, #4]
	adds r0, #1
	b _0803FB8A
	.align 2, 0
_0803FB84: .4byte 0x03000440
_0803FB88:
	movs r0, #2
_0803FB8A:
	strb r0, [r5, #4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
