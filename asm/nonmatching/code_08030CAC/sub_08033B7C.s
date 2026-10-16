	.syntax unified

	thumb_func_start sub_08033B7C
sub_08033B7C: @ 0x08033B7C
	push {r4, r5, lr}
	ldr r3, _08033BDC @ =0x03000590
	ldr r2, _08033BE0 @ =0x03001800
	movs r0, #0xa7
	adds r0, r0, r2
	mov ip, r0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r5, r2, #0
	adds r5, #0x87
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r3
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033BA8
	cmp r0, #1
	bne _08033BE4
_08033BA8:
	adds r1, r1, r3
	adds r1, #0xbc
	ldrb r2, [r1]
	movs r0, #2
	movs r4, #0
	orrs r0, r2
	strb r0, [r1]
	mov r0, ip
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r3
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #1
	bne _08033BF4
	adds r0, r1, r3
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r2, #1
	b _08033BF0
	.align 2, 0
_08033BDC: .4byte 0x03000590
_08033BE0: .4byte 0x03001800
_08033BE4:
	cmp r0, #3
	bne _08033BF4
	adds r0, r1, r3
	adds r0, #0xbc
	ldrb r2, [r0]
	movs r1, #1
_08033BF0:
	orrs r1, r2
	strb r1, [r0]
_08033BF4:
	bl sub_08034F08
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
