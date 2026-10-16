	.syntax unified

	thumb_func_start sub_08042B80
	.global sub_08042B80
sub_08042B80: @ 0x08042B80
	adds r1, r0, #0
	cmp r1, #7
	bhi _08042BBE
	lsls r0, r1, #2
	ldr r1, _08042B90 @ =_08042B94
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08042B90: .4byte _08042B94
_08042B94: @ jump table
	.4byte _08042BB4 @ case 0
	.4byte _08042BB4 @ case 1
	.4byte _08042BB8 @ case 2
	.4byte _08042BB8 @ case 3
	.4byte _08042BB4 @ case 4
	.4byte _08042BB4 @ case 5
	.4byte _08042BB8 @ case 6
	.4byte _08042BBC @ case 7
_08042BB4:
	movs r0, #0
	b _08042BBE
_08042BB8:
	movs r0, #1
	b _08042BBE
_08042BBC:
	movs r0, #1
_08042BBE:
	bx lr
	.syntax divided
