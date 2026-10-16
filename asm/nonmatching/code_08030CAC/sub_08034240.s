	.syntax unified

	thumb_func_start sub_08034240
sub_08034240: @ 0x08034240
	push {lr}
	bl sub_0801FA40
	ldr r0, _08034264 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034260
	ldr r0, _08034268 @ =0x03000440
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	bl sub_08034F08
_08034260:
	pop {r0}
	bx r0
	.align 2, 0
_08034264: .4byte 0x03001800
_08034268: .4byte 0x03000440
	.syntax divided
