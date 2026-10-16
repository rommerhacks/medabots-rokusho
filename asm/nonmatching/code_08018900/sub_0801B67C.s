	.syntax unified

	thumb_func_start sub_0801B67C
	.global sub_0801B67C
sub_0801B67C: @ 0x0801B67C
	cmp r0, #2
	bhi _0801B68C
	ldr r0, _0801B688 @ =0x03001800
	adds r0, #0xf8
	movs r1, #0
	b _0801B692
	.align 2, 0
_0801B688: .4byte 0x03001800
_0801B68C:
	ldr r0, _0801B698 @ =0x03001800
	adds r0, #0xf8
	movs r1, #3
_0801B692:
	strb r1, [r0]
	bx lr
	.align 2, 0
_0801B698: .4byte 0x03001800
	.syntax divided
