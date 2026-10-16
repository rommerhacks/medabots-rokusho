	.syntax unified

	thumb_func_start sub_0801A6B0
	.global sub_0801A6B0
sub_0801A6B0: @ 0x0801A6B0
	push {r4, lr}
	movs r3, #0
	ldr r0, _0801A6D4 @ =0x03000590
	adds r2, r0, #0
	adds r2, #0xbf
	adds r1, r0, #0
	adds r1, #0x40
	movs r4, #0x80
	lsls r4, r4, #1
_0801A6C2:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801A6D8
	ldrb r0, [r2]
	cmp r0, #0
	beq _0801A6D8
	movs r0, #1
	b _0801A6E4
	.align 2, 0
_0801A6D4: .4byte 0x03000590
_0801A6D8:
	adds r2, r2, r4
	adds r1, r1, r4
	adds r3, #1
	cmp r3, #5
	bls _0801A6C2
	movs r0, #0
_0801A6E4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
