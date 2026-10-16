	.syntax unified

	thumb_func_start sub_0803A444
sub_0803A444: @ 0x0803A444
	push {lr}
	sub sp, #8
	ldr r1, _0803A470 @ =0x04000008
	movs r2, #0x8a
	lsls r2, r2, #7
	adds r0, r2, #0
	strh r0, [r1]
	ldrh r0, [r1]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x40
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl tilemap_fill_rect
	bl battle_advance_sequence_counter
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0803A470: .4byte 0x04000008
	.syntax divided
