	.syntax unified

	thumb_func_start sub_08030D74
sub_08030D74: @ 0x08030D74
	push {lr}
	movs r0, #0
	bl dispatch_battle_action_substate
	cmp r0, #0
	beq _08030D88
	ldr r1, _08030D8C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08030D88:
	pop {r0}
	bx r0
	.align 2, 0
_08030D8C: .4byte 0x0300137C
	.syntax divided
