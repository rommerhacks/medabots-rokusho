	.syntax unified

	thumb_func_start lz_decompress_custom_08000B14
lz_decompress_custom_08000B14: @ 0x08000B14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r2, r0, #0
	ldrb r0, [r2]
	cmp r0, #0x4c
	bne _08000B2E
	ldrb r0, [r2, #1]
	cmp r0, #0x65
	beq _08000B32
_08000B2E:
	movs r0, #0
	b _08000DF4
_08000B32:
	ldrb r0, [r2, #2]
	str r0, [sp]
	ldrb r0, [r2, #3]
	lsls r0, r0, #8
	ldr r3, [sp]
	orrs r3, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x10
	orrs r3, r0
	str r3, [sp]
	str r3, [sp, #4]
	adds r7, r1, #0
	adds r2, #6
	mov ip, r2
	cmp r3, #0
	bne _08000B54
	b _08000DF2
_08000B54:
	mov r4, ip
	ldrb r3, [r4]
	movs r5, #1
	add ip, r5
	movs r4, #0
	ldr r0, [sp, #4]
	cmp r0, #0
	bne _08000B66
	b _08000DF2
_08000B66:
	adds r0, r3, #0
	movs r1, #3
	ands r0, r1
	cmp r0, #1
	beq _08000C3A
	cmp r0, #1
	bgt _08000B7A
	cmp r0, #0
	beq _08000B88
	b _08000DCE
_08000B7A:
	cmp r0, #2
	bne _08000B80
	b _08000D90
_08000B80:
	cmp r0, #3
	bne _08000B86
	b _08000CE2
_08000B86:
	b _08000DCE
_08000B88:
	mov r2, ip
	ldrb r1, [r2]
	ldrb r0, [r2, #1]
	lsls r0, r0, #8
	adds r6, r1, r0
	movs r5, #2
	add ip, r5
	ldr r0, _08000BF4 @ =0x00000FFF
	ands r0, r6
	adds r0, #5
	subs r0, r7, r0
	mov r8, r0
	lsrs r0, r6, #0xc
	adds r6, r0, #3
	ldr r1, [sp, #4]
	subs r1, r1, r6
	str r1, [sp, #4]
	adds r6, r0, #2
	adds r4, #1
	mov sl, r4
	lsrs r3, r3, #2
	mov sb, r3
	movs r2, #1
	rsbs r2, r2, #0
	cmp r6, r2
	bne _08000BBE
	b _08000DD6
_08000BBE:
	adds r5, r7, #0
	movs r3, #2
	rsbs r3, r3, #0
	ands r5, r3
	mov r0, r8
	ands r0, r3
	ldrh r1, [r0]
	str r1, [sp, #8]
	ldrh r2, [r5]
	adds r3, r2, #0
	mov r0, r8
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _08000C02
	adds r0, r7, #0
	ands r0, r4
	cmp r0, #0
	beq _08000BF8
	movs r0, #0xff
	ands r2, r0
	movs r3, #0xff
	lsls r3, r3, #8
	ands r1, r3
	orrs r2, r1
	strh r2, [r5]
	b _08000C28
	.align 2, 0
_08000BF4: .4byte 0x00000FFF
_08000BF8:
	movs r4, #0xff
	lsls r4, r4, #8
	ands r2, r4
	lsrs r0, r1, #8
	b _08000C12
_08000C02:
	adds r0, r7, #0
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _08000C18
	movs r0, #0xff
	ands r2, r0
	lsls r0, r1, #8
_08000C12:
	orrs r2, r0
	strh r2, [r5]
	b _08000C28
_08000C18:
	movs r1, #0xff
	lsls r1, r1, #8
	ands r3, r1
	ldr r2, [sp, #8]
	movs r4, #0xff
	ands r2, r4
	orrs r3, r2
	strh r3, [r5]
_08000C28:
	adds r7, #1
	movs r5, #1
	add r8, r5
	subs r6, #1
	movs r0, #1
	rsbs r0, r0, #0
	cmp r6, r0
	bne _08000BBE
	b _08000DD6
_08000C3A:
	mov r1, ip
	ldrb r6, [r1]
	movs r2, #1
	add ip, r2
	adds r0, r6, #0
	movs r5, #3
	ands r0, r5
	adds r0, #1
	subs r0, r7, r0
	mov r8, r0
	lsrs r0, r6, #2
	adds r6, r0, #2
	ldr r1, [sp, #4]
	subs r1, r1, r6
	str r1, [sp, #4]
	adds r6, r0, #1
	adds r4, #1
	mov sl, r4
	lsrs r3, r3, #2
	mov sb, r3
	subs r2, #2
	cmp r6, r2
	bne _08000C6A
	b _08000DD6
_08000C6A:
	adds r5, r7, #0
	movs r3, #2
	rsbs r3, r3, #0
	ands r5, r3
	mov r0, r8
	ands r0, r3
	ldrh r1, [r0]
	str r1, [sp, #8]
	ldrh r2, [r5]
	adds r3, r2, #0
	mov r0, r8
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _08000CAA
	adds r0, r7, #0
	ands r0, r4
	cmp r0, #0
	beq _08000CA0
	movs r0, #0xff
	ands r2, r0
	movs r3, #0xff
	lsls r3, r3, #8
	ands r1, r3
	orrs r2, r1
	strh r2, [r5]
	b _08000CD0
_08000CA0:
	movs r4, #0xff
	lsls r4, r4, #8
	ands r2, r4
	lsrs r0, r1, #8
	b _08000CBA
_08000CAA:
	adds r0, r7, #0
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _08000CC0
	movs r0, #0xff
	ands r2, r0
	lsls r0, r1, #8
_08000CBA:
	orrs r2, r0
	strh r2, [r5]
	b _08000CD0
_08000CC0:
	movs r1, #0xff
	lsls r1, r1, #8
	ands r3, r1
	ldr r2, [sp, #8]
	movs r4, #0xff
	ands r2, r4
	orrs r3, r2
	strh r3, [r5]
_08000CD0:
	adds r7, #1
	movs r5, #1
	add r8, r5
	subs r6, #1
	movs r0, #1
	rsbs r0, r0, #0
	cmp r6, r0
	bne _08000C6A
	b _08000DD6
_08000CE2:
	adds r2, r7, #0
	movs r1, #2
	rsbs r1, r1, #0
	ands r2, r1
	ldrh r1, [r2]
	adds r0, r7, #0
	movs r5, #1
	ands r0, r5
	cmp r0, #0
	beq _08000D06
	movs r0, #0xff
	ands r1, r0
	mov r5, ip
	ldrb r0, [r5]
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r2]
	b _08000D14
_08000D06:
	movs r0, #0xff
	lsls r0, r0, #8
	ands r1, r0
	mov r5, ip
	ldrb r0, [r5]
	orrs r0, r1
	strh r0, [r2]
_08000D14:
	adds r7, #1
	movs r0, #1
	add ip, r0
	adds r2, r7, #0
	movs r1, #2
	rsbs r1, r1, #0
	ands r2, r1
	ldrh r1, [r2]
	adds r0, r7, #0
	movs r5, #1
	ands r0, r5
	cmp r0, #0
	beq _08000D3E
	movs r0, #0xff
	ands r1, r0
	mov r5, ip
	ldrb r0, [r5]
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r2]
	b _08000D4C
_08000D3E:
	movs r0, #0xff
	lsls r0, r0, #8
	ands r1, r0
	mov r5, ip
	ldrb r0, [r5]
	orrs r0, r1
	strh r0, [r2]
_08000D4C:
	adds r7, #1
	movs r0, #1
	add ip, r0
	adds r2, r7, #0
	movs r1, #2
	rsbs r1, r1, #0
	ands r2, r1
	ldrh r1, [r2]
	adds r0, r7, #0
	movs r5, #1
	ands r0, r5
	cmp r0, #0
	beq _08000D76
	movs r0, #0xff
	ands r1, r0
	mov r5, ip
	ldrb r0, [r5]
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r2]
	b _08000D84
_08000D76:
	movs r0, #0xff
	lsls r0, r0, #8
	ands r1, r0
	mov r5, ip
	ldrb r0, [r5]
	orrs r0, r1
	strh r0, [r2]
_08000D84:
	adds r7, #1
	movs r0, #1
	add ip, r0
	ldr r1, [sp, #4]
	subs r1, #3
	b _08000DCC
_08000D90:
	adds r2, r7, #0
	movs r5, #2
	rsbs r5, r5, #0
	ands r2, r5
	ldrh r1, [r2]
	adds r0, r7, #0
	movs r5, #1
	ands r0, r5
	cmp r0, #0
	beq _08000DB4
	movs r0, #0xff
	ands r1, r0
	mov r5, ip
	ldrb r0, [r5]
	lsls r0, r0, #8
	orrs r1, r0
	strh r1, [r2]
	b _08000DC2
_08000DB4:
	movs r0, #0xff
	lsls r0, r0, #8
	ands r1, r0
	mov r5, ip
	ldrb r0, [r5]
	orrs r0, r1
	strh r0, [r2]
_08000DC2:
	adds r7, #1
	movs r0, #1
	add ip, r0
	ldr r1, [sp, #4]
	subs r1, #1
_08000DCC:
	str r1, [sp, #4]
_08000DCE:
	adds r4, #1
	mov sl, r4
	lsrs r3, r3, #2
	mov sb, r3
_08000DD6:
	mov r4, sl
	mov r2, sb
	lsls r0, r2, #0x18
	lsrs r3, r0, #0x18
	cmp r4, #3
	bhi _08000DEA
	ldr r5, [sp, #4]
	cmp r5, #0
	beq _08000DEA
	b _08000B66
_08000DEA:
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _08000DF2
	b _08000B54
_08000DF2:
	ldr r0, [sp]
_08000DF4:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
