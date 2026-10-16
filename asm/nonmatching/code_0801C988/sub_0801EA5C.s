	.syntax unified

	thumb_func_start sub_0801EA5C
sub_0801EA5C: @ 0x0801EA5C
	push {r4, lr}
	ldr r4, _0801EA80 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0xd1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801EA84
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	bl sub_08035194
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #3
	b _0801EA8C
	.align 2, 0
_0801EA80: .4byte 0x03001800
_0801EA84:
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
_0801EA8C:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
