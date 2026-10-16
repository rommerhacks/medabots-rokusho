	.syntax unified

	thumb_func_start reduce_bot_part_stat
	.global reduce_bot_part_stat
reduce_bot_part_stat: @ 0x08035164
	push {r4, lr}
	adds r4, r2, #0
	ldr r3, _08035184 @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r2, r2, r3
	adds r2, #0x59
	ldrb r0, [r2]
	cmp r0, r4
	bge _08035188
	movs r0, #0
	b _0803518A
	.align 2, 0
_08035184: .4byte 0x03000590
_08035188:
	subs r0, r0, r4
_0803518A:
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
