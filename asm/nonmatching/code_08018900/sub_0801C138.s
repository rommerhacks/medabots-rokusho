	.syntax unified

	thumb_func_start sub_0801C138
sub_0801C138: @ 0x0801C138
	push {lr}
	bl sub_0801AC6C
	cmp r0, #0
	beq _0801C14C
	ldr r1, _0801C150 @ =0x03001800
	adds r1, #0xa1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801C14C:
	pop {r0}
	bx r0
	.align 2, 0
_0801C150: .4byte 0x03001800
	.syntax divided
