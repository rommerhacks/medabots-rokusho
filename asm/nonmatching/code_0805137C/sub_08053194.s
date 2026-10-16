	.syntax unified

	thumb_func_start sub_08053194
	.global sub_08053194
sub_08053194: @ 0x08053194
	lsls r2, r0, #0x10
	lsrs r0, r2, #0x10
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080531B8
	ldr r0, _080531B4 @ =0x030057D8
	ldr r0, [r0]
	lsrs r1, r2, #0x11
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1b
	b _080531CA
	.align 2, 0
_080531B4: .4byte 0x030057D8
_080531B8:
	ldr r0, _080531CC @ =0x030057D8
	ldr r0, [r0]
	lsrs r1, r2, #0x11
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x1f
_080531CA:
	bx lr
	.align 2, 0
_080531CC: .4byte 0x030057D8
	.syntax divided
