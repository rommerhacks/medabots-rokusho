	.syntax unified

	thumb_func_start sub_0802E010
sub_0802E010: @ 0x0802E010
	push {r4, r5, r6, lr}
	movs r5, #0
	bl sub_0803836C
	ldr r4, _0802E080 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r2, #0
	ldr r6, _0802E084 @ =0x03000590
	mov ip, r4
	adds r3, r4, #0
	adds r3, #0xd2
_0802E034:
	mov r0, ip
	adds r0, #0x60
	ldrb r0, [r0]
	adds r0, r0, r2
	lsls r0, r0, #8
	adds r1, r0, r6
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E06A
	adds r0, r1, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E06A
	adds r0, r1, #0
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0802E06A
	adds r1, r2, r3
	movs r0, #1
	strb r0, [r1]
	movs r5, #1
_0802E06A:
	adds r2, #1
	cmp r2, #2
	bls _0802E034
	cmp r5, #0
	bne _0802E088
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _0802E090
	.align 2, 0
_0802E080: .4byte 0x03001800
_0802E084: .4byte 0x03000590
_0802E088:
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #2
_0802E090:
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
