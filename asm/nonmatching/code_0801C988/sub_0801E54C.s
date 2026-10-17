	.syntax unified

	thumb_func_start sub_0801E54C
sub_0801E54C: @ 0x0801E54C
	push {lr}
	movs r0, #0xa
	bl sub_080353CC
	cmp r0, #0
	beq _0801E56A
	ldr r0, _0801E570 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _0801E574 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801E56A:
	pop {r0}
	bx r0
	.align 2, 0
_0801E570: .4byte 0x03000440
_0801E574: .4byte 0x03001800
	.syntax divided
