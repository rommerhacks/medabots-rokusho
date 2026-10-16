	.syntax unified

	thumb_func_start advance_substate_with_fade
advance_substate_with_fade: @ 0x0805C954
	push {lr}
	sub sp, #4
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _0805C97C
	ldr r1, _0805C984 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, _0805C988 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x50
	movs r1, #0xc0
	str r1, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl init_blend_effect
_0805C97C:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0805C984: .4byte 0x0300137C
_0805C988: .4byte 0x03006F74
	.syntax divided
