	.syntax unified

	thumb_func_start sub_0801A744
	.global sub_0801A744
sub_0801A744: @ 0x0801A744
	cmp r0, #2
	bhi _0801A780
	cmp r0, #1
	beq _0801A764
	cmp r0, #1
	blo _0801A756
	cmp r0, #2
	beq _0801A774
	b _0801A780
_0801A756:
	ldr r0, _0801A760 @ =0x03001800
	adds r0, #0x44
	ldrb r2, [r0]
	movs r1, #0xfe
	b _0801A77C
	.align 2, 0
_0801A760: .4byte 0x03001800
_0801A764:
	ldr r0, _0801A770 @ =0x03001800
	adds r0, #0x44
	ldrb r2, [r0]
	movs r1, #0xfd
	b _0801A77C
	.align 2, 0
_0801A770: .4byte 0x03001800
_0801A774:
	ldr r0, _0801A784 @ =0x03001800
	adds r0, #0x44
	ldrb r2, [r0]
	movs r1, #0xfb
_0801A77C:
	ands r1, r2
	strb r1, [r0]
_0801A780:
	bx lr
	.align 2, 0
_0801A784: .4byte 0x03001800
	.syntax divided
