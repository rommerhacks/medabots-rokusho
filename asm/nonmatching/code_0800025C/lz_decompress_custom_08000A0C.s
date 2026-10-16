	.syntax unified

	thumb_func_start lz_decompress_custom_08000A0C
lz_decompress_custom_08000A0C: @ 0x08000A0C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r2
	mov r7, sl
	adds r3, r1, #0
	adds r4, r0, #6
	mov r0, sl
	cmp r0, #0
	beq _08000B02
_08000A24:
	ldrb r5, [r4]
	adds r4, #1
	movs r6, #0
	cmp r7, #0
	beq _08000B02
	movs r1, #3
	mov sb, r1
	movs r2, #1
	rsbs r2, r2, #0
	mov r8, r2
_08000A38:
	adds r0, r5, #0
	mov r1, sb
	ands r0, r1
	cmp r0, #1
	beq _08000A94
	cmp r0, #1
	bgt _08000A4C
	cmp r0, #0
	beq _08000A56
	b _08000AEE
_08000A4C:
	cmp r0, #2
	beq _08000AE4
	cmp r0, #3
	beq _08000AC8
	b _08000AEE
_08000A56:
	ldrb r1, [r4]
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r4, #2
	ldr r0, _08000A90 @ =0x00000FFF
	ands r0, r1
	adds r0, #5
	subs r2, r3, r0
	lsrs r0, r1, #0xc
	adds r1, r0, #3
	subs r7, r7, r1
	adds r1, r0, #2
	adds r6, #1
	lsrs r5, r5, #2
	cmp r1, r8
	beq _08000AF2
	movs r0, #1
	rsbs r0, r0, #0
	mov ip, r0
_08000A7E:
	ldrb r0, [r2]
	strb r0, [r3]
	adds r2, #1
	adds r3, #1
	subs r1, #1
	cmp r1, ip
	bne _08000A7E
	b _08000AF2
	.align 2, 0
_08000A90: .4byte 0x00000FFF
_08000A94:
	ldrb r1, [r4]
	adds r4, #1
	adds r0, r1, #0
	mov r2, sb
	ands r0, r2
	adds r0, #1
	subs r2, r3, r0
	lsrs r0, r1, #2
	adds r1, r0, #2
	subs r7, r7, r1
	adds r1, r0, #1
	adds r6, #1
	lsrs r5, r5, #2
	cmp r1, r8
	beq _08000AF2
	movs r0, #1
	rsbs r0, r0, #0
	mov ip, r0
_08000AB8:
	ldrb r0, [r2]
	strb r0, [r3]
	adds r2, #1
	adds r3, #1
	subs r1, #1
	cmp r1, ip
	bne _08000AB8
	b _08000AF2
_08000AC8:
	ldrb r0, [r4]
	strb r0, [r3]
	adds r4, #1
	adds r3, #1
	ldrb r0, [r4]
	strb r0, [r3]
	adds r4, #1
	adds r3, #1
	ldrb r0, [r4]
	strb r0, [r3]
	adds r4, #1
	adds r3, #1
	subs r7, #3
	b _08000AEE
_08000AE4:
	ldrb r0, [r4]
	strb r0, [r3]
	adds r4, #1
	adds r3, #1
	subs r7, #1
_08000AEE:
	adds r6, #1
	lsrs r5, r5, #2
_08000AF2:
	lsls r0, r5, #0x18
	lsrs r5, r0, #0x18
	cmp r6, #3
	bhi _08000AFE
	cmp r7, #0
	bne _08000A38
_08000AFE:
	cmp r7, #0
	bne _08000A24
_08000B02:
	mov r0, sl
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
