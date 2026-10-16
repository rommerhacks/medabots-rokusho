	.syntax unified

	thumb_func_start sub_08033F9C
sub_08033F9C: @ 0x08033F9C
	push {r4, r5, lr}
	ldr r5, _08034000 @ =0x03000590
	ldr r3, _08034004 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r4, r0, #8
	adds r2, r4, r5
	adds r0, r2, #0
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08033FF6
	adds r0, r2, #0
	adds r0, #0xde
	ldrb r0, [r0]
	subs r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r4
	adds r1, r1, r5
	adds r1, #0x59
	ldrb r0, [r1]
	cmp r0, #0
	beq _08033FF6
	adds r4, r3, #0
	adds r4, #0xb7
	ldrb r0, [r4]
	cmp r0, #0
	bne _08033FF6
	adds r0, r3, #0
	adds r0, #0xec
	adds r1, r2, #0
	adds r1, #0xd8
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r2, r0
	ble _08033FF6
	movs r0, #3
	strb r0, [r4]
_08033FF6:
	bl sub_08034F08
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08034000: .4byte 0x03000590
_08034004: .4byte 0x03001800
	.syntax divided
