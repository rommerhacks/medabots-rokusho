	.syntax unified

	thumb_func_start sub_0801BF64
	.global sub_0801BF64
sub_0801BF64: @ 0x0801BF64
	adds r2, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r2]
	cmp r0, r1
	beq _0801BF74
	adds r0, #1
	strh r0, [r2]
_0801BF74:
	bx lr
	.align 2, 0
	.syntax divided
