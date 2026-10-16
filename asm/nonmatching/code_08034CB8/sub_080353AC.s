	.syntax unified

	thumb_func_start sub_080353AC
	.global sub_080353AC
sub_080353AC: @ 0x080353AC
	adds r1, r0, #0
	movs r2, #2
	ands r1, r2
	cmp r1, #0
	beq _080353C0
	ldr r0, _080353BC @ =0x03001C04
	strh r2, [r0, #2]
	b _080353C4
	.align 2, 0
_080353BC: .4byte 0x03001C04
_080353C0:
	ldr r0, _080353C8 @ =0x03001C04
	strh r1, [r0, #2]
_080353C4:
	bx lr
	.align 2, 0
_080353C8: .4byte 0x03001C04
	.syntax divided
