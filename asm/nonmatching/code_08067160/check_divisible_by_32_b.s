	.syntax unified

	thumb_func_start check_divisible_by_32_b
check_divisible_by_32_b: @ 0x08068B34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08068B50 @ =0x03000000
	ldr r1, _08068B54 @ =0x03000005
	ldrb r5, [r1]
	lsls r1, r5, #5
	ldr r4, [r0]
	cmp r4, r1
	bne _08068B58
	movs r0, #1
	b _08068C16
	.align 2, 0
_08068B50: .4byte 0x03000000
_08068B54: .4byte 0x03000005
_08068B58:
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_0807CC88
	cmp r0, #0
	bne _08068C14
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_0807CBBC
	adds r5, r0, #0
	movs r0, #0x20
	subs r7, r0, r5
	cmp r5, #0
	bgt _08068B8C
	ldr r1, _08068B84 @ =0x040000D4
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r1]
	ldr r0, _08068B88 @ =0x0300002C
	ldr r0, [r0]
	b _08068C0C
	.align 2, 0
_08068B84: .4byte 0x040000D4
_08068B88: .4byte 0x0300002C
_08068B8C:
	movs r6, #0
	movs r0, #0x1f
	mov sl, r0
	movs r2, #0xf8
	lsls r2, r2, #2
	mov sb, r2
	movs r0, #0xf8
	lsls r0, r0, #7
	mov r8, r0
	ldr r2, _08068C24 @ =0x0202FC00
	mov ip, r2
_08068BA2:
	lsls r0, r6, #1
	ldr r2, _08068C28 @ =0x0300002C
	ldr r1, [r2]
	adds r0, r0, r1
	ldrh r4, [r0]
	mov r0, sl
	ands r0, r4
	adds r2, r0, #0
	muls r2, r7, r2
	ldr r0, _08068C2C @ =0x03000028
	ldrh r3, [r0]
	mov r0, sl
	ands r0, r3
	muls r0, r5, r0
	adds r2, r2, r0
	asrs r2, r2, #5
	mov r0, sb
	ands r0, r4
	adds r1, r0, #0
	muls r1, r7, r1
	mov r0, sb
	ands r0, r3
	muls r0, r5, r0
	adds r1, r1, r0
	asrs r1, r1, #5
	mov r0, sb
	ands r1, r0
	adds r2, r2, r1
	mov r0, r8
	ands r0, r4
	adds r1, r0, #0
	muls r1, r7, r1
	mov r0, r8
	ands r0, r3
	muls r0, r5, r0
	adds r1, r1, r0
	asrs r1, r1, #5
	mov r0, r8
	ands r1, r0
	adds r2, r2, r1
	mov r0, ip
	strh r2, [r0]
	movs r2, #2
	add ip, r2
	adds r6, #1
	ldr r0, _08068C30 @ =0x000001FF
	cmp r6, r0
	ble _08068BA2
	ldr r1, _08068C34 @ =0x040000D4
	ldr r2, _08068C24 @ =0x0202FC00
	str r2, [r1]
	movs r0, #0xa0
	lsls r0, r0, #0x13
_08068C0C:
	str r0, [r1, #4]
	ldr r0, _08068C38 @ =0x84000100
	str r0, [r1, #8]
	ldr r0, [r1, #8]
_08068C14:
	movs r0, #0
_08068C16:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08068C24: .4byte 0x0202FC00
_08068C28: .4byte 0x0300002C
_08068C2C: .4byte 0x03000028
_08068C30: .4byte 0x000001FF
_08068C34: .4byte 0x040000D4
_08068C38: .4byte 0x84000100
	.syntax divided
