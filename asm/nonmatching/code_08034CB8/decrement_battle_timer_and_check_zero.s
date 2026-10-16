	.syntax unified

	thumb_func_start decrement_battle_timer_and_check_zero
	.global decrement_battle_timer_and_check_zero
decrement_battle_timer_and_check_zero: @ 0x0803725C
	push {r4, lr}
	ldr r4, _08037274 @ =0x030018E8
	adds r0, r4, #0
	movs r1, #0x20
	bl sub_08035754
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08037278
	movs r0, #1
	b _0803727A
	.align 2, 0
_08037274: .4byte 0x030018E8
_08037278:
	movs r0, #0
_0803727A:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
