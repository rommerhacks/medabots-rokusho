	.syntax unified

	thumb_func_start sub_0800944C
	.global sub_0800944C
sub_0800944C: @ 0x0800944C
	push {r4, r5, lr}
	ldr r1, _0800947C @ =0x03000440
	adds r1, #0x41
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	movs r5, #0x80
	adds r4, r1, #0
	ldr r2, _08009480 @ =0x03000BE0
_0800945E:
	ldrb r1, [r2]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0800946E
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0800946E:
	adds r2, #0x40
	adds r3, #1
	cmp r3, #0x1d
	bls _0800945E
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800947C: .4byte 0x03000440
_08009480: .4byte 0x03000BE0
	.syntax divided
