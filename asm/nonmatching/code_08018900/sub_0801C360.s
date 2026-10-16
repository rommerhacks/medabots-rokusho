	.syntax unified

	thumb_func_start sub_0801C360
sub_0801C360: @ 0x0801C360
	push {r4, lr}
	ldr r4, _0801C384 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08016438
	cmp r0, #0
	beq _0801C37C
	adds r1, r4, #0
	adds r1, #0x9c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801C37C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C384: .4byte 0x03001800
	.syntax divided
