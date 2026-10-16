	.syntax unified

	thumb_func_start sub_0801C6C4
sub_0801C6C4: @ 0x0801C6C4
	push {lr}
	ldr r0, _0801C6DC @ =0x03001800
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #1
	beq _0801C704
	cmp r0, #1
	bgt _0801C6E0
	cmp r0, #0
	beq _0801C6EA
	b _0801C752
	.align 2, 0
_0801C6DC: .4byte 0x03001800
_0801C6E0:
	cmp r0, #2
	beq _0801C71C
	cmp r0, #3
	beq _0801C740
	b _0801C752
_0801C6EA:
	ldr r0, _0801C6F8 @ =0x084C907C
	ldr r1, _0801C6FC @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0801C700 @ =0x0850E058
	b _0801C726
	.align 2, 0
_0801C6F8: .4byte 0x084C907C
_0801C6FC: .4byte 0x06014800
_0801C700: .4byte 0x0850E058
_0801C704:
	ldr r0, _0801C710 @ =0x084C9288
	ldr r1, _0801C714 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0801C718 @ =0x0850E078
	b _0801C726
	.align 2, 0
_0801C710: .4byte 0x084C9288
_0801C714: .4byte 0x06014800
_0801C718: .4byte 0x0850E078
_0801C71C:
	ldr r0, _0801C730 @ =0x084C9624
	ldr r1, _0801C734 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0801C738 @ =0x0850E098
_0801C726:
	ldr r1, _0801C73C @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	b _0801C752
	.align 2, 0
_0801C730: .4byte 0x084C9624
_0801C734: .4byte 0x06014800
_0801C738: .4byte 0x0850E098
_0801C73C: .4byte 0x050002C0
_0801C740:
	ldr r0, _0801C760 @ =0x084C978C
	ldr r1, _0801C764 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0801C768 @ =0x0850E0B8
	ldr r1, _0801C76C @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
_0801C752:
	ldr r1, _0801C770 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0801C760: .4byte 0x084C978C
_0801C764: .4byte 0x06014800
_0801C768: .4byte 0x0850E0B8
_0801C76C: .4byte 0x050002C0
_0801C770: .4byte 0x03001800
	.syntax divided
