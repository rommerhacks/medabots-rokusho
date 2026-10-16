	.syntax unified

	thumb_func_start sub_0801A6EC
	.global sub_0801A6EC
sub_0801A6EC: @ 0x0801A6EC
	adds r1, r0, #0
	cmp r1, #2
	bhi _0801A742
	cmp r1, #1
	beq _0801A710
	cmp r1, #1
	blo _0801A700
	cmp r1, #2
	beq _0801A728
	b _0801A742
_0801A700:
	ldr r0, _0801A70C @ =0x03001800
	adds r0, #0x44
	ldrb r1, [r0]
	movs r0, #1
	b _0801A718
	.align 2, 0
_0801A70C: .4byte 0x03001800
_0801A710:
	ldr r0, _0801A724 @ =0x03001800
	adds r0, #0x44
	ldrb r1, [r0]
	movs r0, #2
_0801A718:
	ands r0, r1
	cmp r0, #0
	bne _0801A736
	movs r0, #0
	b _0801A742
	.align 2, 0
_0801A724: .4byte 0x03001800
_0801A728:
	ldr r0, _0801A73C @ =0x03001800
	adds r0, #0x44
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0801A740
_0801A736:
	movs r0, #1
	b _0801A742
	.align 2, 0
_0801A73C: .4byte 0x03001800
_0801A740:
	movs r0, #0
_0801A742:
	bx lr
	.syntax divided
