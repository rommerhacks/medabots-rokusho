	.syntax unified

	thumb_func_start sub_08002190
	.global sub_08002190
sub_08002190: @ 0x08002190
	ldr r1, _080021A0 @ =0x03005170
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800219C
	movs r0, #1
	strb r0, [r1, #6]
_0800219C:
	bx lr
	.align 2, 0
_080021A0: .4byte 0x03005170
	.syntax divided
