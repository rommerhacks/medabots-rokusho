	.syntax unified

	thumb_func_start sub_0803DBE0
sub_0803DBE0: @ 0x0803DBE0
	push {lr}
	bl update_scroll_movement_a
	bl sub_0803E79C
	cmp r0, #0
	beq _0803DBFE
	ldr r0, _0803DC04 @ =0x03000440
	adds r0, #0x86
	movs r1, #0
	strh r1, [r0]
	ldr r1, _0803DC08 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DBFE:
	pop {r0}
	bx r0
	.align 2, 0
_0803DC04: .4byte 0x03000440
_0803DC08: .4byte 0x0300137C
	.syntax divided
