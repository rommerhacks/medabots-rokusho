	.syntax unified

	thumb_func_start copy_tilemap_with_offset_08000F78
copy_tilemap_with_offset_08000F78: @ 0x08000F78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	adds r6, r1, #0
	ldr r0, [r6]
	mov r8, r0
	cmp r0, #0x20
	ble _08000F92
	movs r2, #0x20
	mov r8, r2
_08000F92:
	ldr r7, [r6, #4]
	mov sb, r7
	mov ip, sb
	mov r0, sb
	cmp r0, #0x20
	ble _08000FA2
	movs r2, #0x20
	mov ip, r2
_08000FA2:
	movs r4, #0
_08000FA4:
	cmp r4, ip
	bge _08000FDC
	ldr r0, [r6]
	muls r0, r4, r0
	lsls r0, r0, #1
	adds r0, #0x10
	adds r1, r6, r0
	lsls r0, r4, #6
	mov r7, sl
	adds r3, r7, r0
	adds r4, #1
	mov r0, r8
	cmp r0, #0
	ble _08000FA4
	ldr r5, _08000FD8 @ =0x03000580
	mov r2, r8
_08000FC4:
	ldrh r0, [r5]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r3]
	adds r1, #2
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bne _08000FC4
	b _08000FA4
	.align 2, 0
_08000FD8: .4byte 0x03000580
_08000FDC:
	movs r4, #0
	cmp r4, ip
	bge _0800101A
	ldr r5, [r6]
_08000FE4:
	adds r0, r4, #0
	muls r0, r5, r0
	lsls r0, r0, #1
	adds r0, #0x50
	adds r1, r6, r0
	lsls r0, r4, #6
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	mov r7, sl
	adds r3, r7, r0
	movs r2, #0x20
	adds r4, #1
	cmp r2, r5
	bhs _08001016
_08001002:
	ldr r7, _080010B0 @ =0x03000580
	ldrh r0, [r7]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r3]
	adds r1, #2
	adds r3, #2
	adds r2, #1
	cmp r2, r5
	blo _08001002
_08001016:
	cmp r4, ip
	blt _08000FE4
_0800101A:
	movs r4, #0x20
	cmp r4, sb
	bhs _0800105C
	ldr r0, _080010B0 @ =0x03000580
	mov ip, r0
_08001024:
	ldr r0, [r6]
	muls r0, r4, r0
	lsls r0, r0, #1
	adds r0, #0x10
	adds r1, r6, r0
	lsls r0, r4, #6
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r0, r2
	mov r7, sl
	adds r3, r7, r0
	adds r4, #1
	mov r0, r8
	cmp r0, #0
	ble _08001058
	mov r5, ip
	mov r2, r8
_08001046:
	ldrh r0, [r5]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r3]
	adds r1, #2
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bne _08001046
_08001058:
	cmp r4, sb
	blo _08001024
_0800105C:
	movs r4, #0x20
	cmp r4, sb
	bhs _080010A0
	ldr r5, [r6]
	ldr r0, _080010B0 @ =0x03000580
	mov r8, r0
_08001068:
	adds r0, r4, #0
	muls r0, r5, r0
	lsls r0, r0, #1
	adds r0, #0x50
	adds r1, r6, r0
	lsls r0, r4, #6
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r0, r2
	mov r7, sl
	adds r3, r7, r0
	movs r2, #0x20
	adds r4, #1
	cmp r2, r5
	bhs _0800109C
	mov ip, r8
_08001088:
	mov r7, ip
	ldrh r0, [r7]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r3]
	adds r1, #2
	adds r3, #2
	adds r2, #1
	cmp r2, r5
	blo _08001088
_0800109C:
	cmp r4, sb
	blo _08001068
_080010A0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080010B0: .4byte 0x03000580
	.syntax divided
