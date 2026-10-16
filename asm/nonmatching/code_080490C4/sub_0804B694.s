	.syntax unified

	thumb_func_start sub_0804B694
sub_0804B694: @ 0x0804B694
	push {lr}
	bl battle_sequence_dispatch
	cmp r0, #4
	beq _0804B6A2
	movs r0, #0
	b _0804B6A4
_0804B6A2:
	movs r0, #1
_0804B6A4:
	pop {r1}
	bx r1
	.syntax divided
