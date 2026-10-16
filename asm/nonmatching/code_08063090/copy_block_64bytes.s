	.syntax unified

	thumb_func_start copy_block_64bytes
copy_block_64bytes: @ 0x08066858
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	movs r2, #0
_08066860:
	lsls r0, r2, #4
	adds r4, r2, #1
	adds r1, r0, r5
	adds r3, r0, r6
	movs r2, #3
_0806686A:
	ldm r1!, {r0}
	stm r3!, {r0}
	subs r2, #1
	cmp r2, #0
	bge _0806686A
	adds r2, r4, #0
	cmp r2, #3
	ble _08066860
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
