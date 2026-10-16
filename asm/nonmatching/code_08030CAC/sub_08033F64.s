	.syntax unified

	thumb_func_start sub_08033F64
sub_08033F64: @ 0x08033F64
	push {lr}
	ldr r1, _08033F98 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0xde
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033F90
	adds r0, r1, #0
	adds r0, #0xdf
	ldrb r0, [r0]
	cmp r0, #0x1c
	bne _08033F90
	adds r2, r1, #0
	adds r2, #0xb8
	ldrb r0, [r2]
	cmp r0, #0
	bne _08033F90
	movs r0, #2
	strb r0, [r2]
	adds r1, #0xbe
	movs r0, #5
	strb r0, [r1]
_08033F90:
	bl sub_08034F08
	pop {r0}
	bx r0
	.align 2, 0
_08033F98: .4byte 0x03001800
	.syntax divided
