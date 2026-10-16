	.syntax unified

	thumb_func_start sub_080182AC
	.global sub_080182AC
sub_080182AC: @ 0x080182AC
	ldr r0, _080182C8 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080182C6
	ldr r0, _080182CC @ =0x03001C04
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_080182C6:
	bx lr
	.align 2, 0
_080182C8: .4byte 0x03001780
_080182CC: .4byte 0x03001C04
	.syntax divided
