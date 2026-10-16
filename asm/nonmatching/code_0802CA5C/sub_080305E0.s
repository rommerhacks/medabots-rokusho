	.syntax unified

	thumb_func_start sub_080305E0
sub_080305E0: @ 0x080305E0
	push {r4, lr}
	ldr r4, _08030604 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0xa6
	ldrb r0, [r0]
	bl sub_0801C0BC
	cmp r0, #0
	beq _080305FC
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080305FC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08030604: .4byte 0x03001800
	.syntax divided
