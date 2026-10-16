	.syntax unified

	thumb_func_start sub_08034048
sub_08034048: @ 0x08034048
	push {lr}
	ldr r0, _0803406C @ =0x03000440
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bl sub_0801DEE4
	ldr r0, _08034070 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034068
	bl sub_08034F08
_08034068:
	pop {r0}
	bx r0
	.align 2, 0
_0803406C: .4byte 0x03000440
_08034070: .4byte 0x03001800
	.syntax divided
