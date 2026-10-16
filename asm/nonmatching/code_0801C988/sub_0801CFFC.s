	.syntax unified

	thumb_func_start sub_0801CFFC
sub_0801CFFC: @ 0x0801CFFC
	push {lr}
	ldr r0, _0801D014 @ =0x03001800
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #1
	beq _0801D02C
	cmp r0, #1
	bgt _0801D018
	cmp r0, #0
	beq _0801D022
	b _0801D050
	.align 2, 0
_0801D014: .4byte 0x03001800
_0801D018:
	cmp r0, #2
	beq _0801D034
	cmp r0, #3
	beq _0801D048
	b _0801D050
_0801D022:
	ldr r0, _0801D028 @ =0x084C907C
	b _0801D036
	.align 2, 0
_0801D028: .4byte 0x084C907C
_0801D02C:
	ldr r0, _0801D030 @ =0x084C9288
	b _0801D036
	.align 2, 0
_0801D030: .4byte 0x084C9288
_0801D034:
	ldr r0, _0801D040 @ =0x084C9624
_0801D036:
	ldr r1, _0801D044 @ =0x06015400
	bl lz_decompress_dispatch
	b _0801D050
	.align 2, 0
_0801D040: .4byte 0x084C9624
_0801D044: .4byte 0x06015400
_0801D048:
	ldr r0, _0801D060 @ =0x084C978C
	ldr r1, _0801D064 @ =0x06015400
	bl lz_decompress_dispatch
_0801D050:
	ldr r1, _0801D068 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0801D060: .4byte 0x084C978C
_0801D064: .4byte 0x06015400
_0801D068: .4byte 0x03001800
	.syntax divided
