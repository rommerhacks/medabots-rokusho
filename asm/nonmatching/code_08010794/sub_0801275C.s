	.syntax unified

	thumb_func_start sub_0801275C
sub_0801275C: @ 0x0801275C
	ldr r0, _08012778 @ =0x03001800
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r2, r0, r1
	subs r1, #1
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_08012778: .4byte 0x03001800
	.syntax divided
