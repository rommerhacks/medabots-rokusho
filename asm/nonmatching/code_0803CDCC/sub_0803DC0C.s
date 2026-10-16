	.syntax unified

	thumb_func_start sub_0803DC0C
sub_0803DC0C: @ 0x0803DC0C
	push {lr}
	bl update_scroll_movement_a
	ldr r0, _0803DC2C @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #8
	bne _0803DC34
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0803DC30 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0803DC38
	.align 2, 0
_0803DC2C: .4byte 0x03000440
_0803DC30: .4byte 0x0300137C
_0803DC34:
	adds r0, #1
	strh r0, [r1]
_0803DC38:
	pop {r0}
	bx r0
	.syntax divided
