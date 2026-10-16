	.syntax unified

	thumb_func_start sub_08053288
	.global sub_08053288
sub_08053288: @ 0x08053288
	lsls r2, r0, #0x10
	lsrs r0, r2, #0x10
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080532A8
	ldr r0, _080532A4 @ =0x030057D8
	ldr r0, [r0]
	lsrs r1, r2, #0x11
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #7
	ands r0, r1
	b _080532B8
	.align 2, 0
_080532A4: .4byte 0x030057D8
_080532A8:
	ldr r0, _080532BC @ =0x030057D8
	ldr r0, [r0]
	lsrs r1, r2, #0x11
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0x70
	ands r0, r1
	lsrs r0, r0, #4
_080532B8:
	bx lr
	.align 2, 0
_080532BC: .4byte 0x030057D8
	.syntax divided
