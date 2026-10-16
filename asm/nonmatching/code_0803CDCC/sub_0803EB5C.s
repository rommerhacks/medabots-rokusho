	.syntax unified

	thumb_func_start sub_0803EB5C
sub_0803EB5C: @ 0x0803EB5C
	ldr r1, _0803EB84 @ =0x03001800
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	lsrs r0, r0, #4
	movs r3, #0xd1
	lsls r3, r3, #1
	adds r2, r1, r3
	strb r0, [r2]
	ldrb r0, [r2]
	adds r2, r1, #0
	cmp r0, #6
	bhi _0803EBEC
	lsls r0, r0, #2
	ldr r1, _0803EB88 @ =_0803EB8C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803EB84: .4byte 0x03001800
_0803EB88: .4byte _0803EB8C
_0803EB8C: @ jump table
	.4byte _0803EBA8 @ case 0
	.4byte _0803EBB2 @ case 1
	.4byte _0803EBBC @ case 2
	.4byte _0803EBC6 @ case 3
	.4byte _0803EBD0 @ case 4
	.4byte _0803EBDA @ case 5
	.4byte _0803EBE2 @ case 6
_0803EBA8:
	movs r0, #0xd1
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #5
	b _0803EBEA
_0803EBB2:
	movs r3, #0xd1
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #4
	b _0803EBEA
_0803EBBC:
	movs r0, #0xd1
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #3
	b _0803EBEA
_0803EBC6:
	movs r3, #0xd1
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #2
	b _0803EBEA
_0803EBD0:
	movs r0, #0xd1
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #1
	b _0803EBEA
_0803EBDA:
	movs r3, #0xd1
	lsls r3, r3, #1
	adds r1, r2, r3
	b _0803EBE8
_0803EBE2:
	movs r0, #0xd1
	lsls r0, r0, #1
	adds r1, r2, r0
_0803EBE8:
	movs r0, #0
_0803EBEA:
	strb r0, [r1]
_0803EBEC:
	movs r1, #0xd1
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, #0x18
	ldr r3, _0803EC00 @ =0x000001A3
	adds r1, r2, r3
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803EC00: .4byte 0x000001A3
	.syntax divided
