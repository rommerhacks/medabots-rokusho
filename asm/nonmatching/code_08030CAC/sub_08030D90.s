	.syntax unified

	thumb_func_start sub_08030D90
sub_08030D90: @ 0x08030D90
	push {lr}
	movs r0, #0
	bl dispatch_battle_action_substate
	movs r0, #1
	bl sub_0801C0BC
	cmp r0, #0
	beq _08030DAA
	ldr r1, _08030DB0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08030DAA:
	pop {r0}
	bx r0
	.align 2, 0
_08030DB0: .4byte 0x0300137C
	.syntax divided
