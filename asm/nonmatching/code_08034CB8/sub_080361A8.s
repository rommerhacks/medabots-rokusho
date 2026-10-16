	.syntax unified

	thumb_func_start sub_080361A8
	.global sub_080361A8
sub_080361A8: @ 0x080361A8
	ldr r2, _080361BC @ =0x03001800
	movs r1, #0x89
	lsls r1, r1, #1
	adds r3, r2, r1
	movs r1, #0x29
	strb r1, [r3]
	ldr r3, _080361C0 @ =0x00000113
	adds r2, r2, r3
	strb r1, [r2]
	bx lr
	.align 2, 0
_080361BC: .4byte 0x03001800
_080361C0: .4byte 0x00000113
	.syntax divided
