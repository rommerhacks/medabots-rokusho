	.syntax unified

	thumb_func_start sub_08033F04
sub_08033F04: @ 0x08033F04
	push {r4, r5, lr}
	ldr r3, _08033F5C @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xde
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033F50
	adds r0, r3, #0
	adds r0, #0xdf
	ldrb r0, [r0]
	cmp r0, #0x1d
	bne _08033F50
	adds r4, r3, #0
	adds r4, #0xb8
	ldrb r0, [r4]
	cmp r0, #0
	bne _08033F50
	adds r2, r3, #0
	adds r2, #0xec
	ldr r1, _08033F60 @ =0x03000590
	adds r0, r3, #0
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xd8
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08033F50
	movs r0, #2
	strb r0, [r4]
	adds r1, r3, #0
	adds r1, #0xbe
	movs r0, #1
	strb r0, [r1]
_08033F50:
	bl sub_08034F08
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08033F5C: .4byte 0x03001800
_08033F60: .4byte 0x03000590
	.syntax divided
