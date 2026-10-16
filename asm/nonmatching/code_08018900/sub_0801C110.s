	.syntax unified

	thumb_func_start sub_0801C110
sub_0801C110: @ 0x0801C110
	push {r4, lr}
	ldr r4, _0801C134 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0xa2
	ldrb r0, [r0]
	bl sub_0801AC24
	cmp r0, #0
	beq _0801C12C
	adds r1, r4, #0
	adds r1, #0xa1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801C12C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C134: .4byte 0x03001800
	.syntax divided
