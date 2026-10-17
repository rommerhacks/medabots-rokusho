	.syntax unified

	thumb_func_start sub_0805C190
sub_0805C190: @ 0x0805C190
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r7, #0x80
	lsls r7, r7, #2
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r7, #0x80
	lsls r7, r7, #5
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _0805C1F4 @ =0x03001784
	ldrb r1, [r4]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4]
	bl load_save_with_retries
	adds r1, r0, #0
	cmp r1, #0
	beq _0805C274
	cmp r1, #0
	bge _0805C200
	ldr r1, _0805C1F8 @ =0x03002B8C
	movs r0, #9
	str r0, [r1]
	ldr r1, _0805C1FC @ =0x0300137C
	movs r0, #0
	b _0805C2A8
	.align 2, 0
_0805C1F4: .4byte 0x03001784
_0805C1F8: .4byte 0x03002B8C
_0805C1FC: .4byte 0x0300137C
_0805C200:
	movs r2, #0
	ldr r6, _0805C258 @ =0x03006F74
	ldr r0, _0805C25C @ =0x03001788
	mov sl, r0
	ldr r3, _0805C260 @ =0x03001360
	mov ip, r3
	ldr r7, _0805C264 @ =0x03000B94
	mov r8, r7
	ldr r0, _0805C268 @ =0x03001780
	mov sb, r0
	ldr r5, _0805C26C @ =0x04000008
	movs r3, #0
	movs r4, #0x1f
_0805C21A:
	ldrh r0, [r5]
	lsrs r0, r0, #8
	ands r0, r4
	lsls r0, r0, #0xb
	adds r2, #1
	lsls r1, r2, #6
	ldr r7, _0805C270 @ =0x06000012
	adds r1, r1, r7
	adds r0, r0, r1
	movs r1, #0xb
_0805C22E:
	strh r3, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0805C22E
	cmp r2, #1
	ble _0805C21A
	ldr r0, [r6]
	movs r1, #0
	movs r2, #1
	strb r2, [r0, #5]
	ldr r0, [r6]
	strb r2, [r0, #4]
	mov r0, sl
	strb r1, [r0]
	mov r2, ip
	strb r1, [r2]
	mov r3, r8
	strb r1, [r3]
	b _0805C28C
	.align 2, 0
_0805C258: .4byte 0x03006F74
_0805C25C: .4byte 0x03001788
_0805C260: .4byte 0x03001360
_0805C264: .4byte 0x03000B94
_0805C268: .4byte 0x03001780
_0805C26C: .4byte 0x04000008
_0805C270: .4byte 0x06000012
_0805C274:
	ldr r2, _0805C2B8 @ =0x03006F74
	ldr r0, [r2]
	strb r1, [r0, #5]
	ldr r0, [r2]
	strb r1, [r0, #4]
	ldrb r0, [r4]
	movs r1, #1
	orrs r0, r1
	strb r0, [r4]
	adds r6, r2, #0
	ldr r7, _0805C2BC @ =0x03001780
	mov sb, r7
_0805C28C:
	ldr r0, [r6]
	ldrb r0, [r0, #5]
	mov r2, sb
	ldr r1, [r2]
	movs r2, #0x1f
	ands r1, r2
	bl sub_0805BEA0
	movs r0, #3
	bl sub_0805BCC0
	ldr r1, _0805C2C0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
_0805C2A8:
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805C2B8: .4byte 0x03006F74
_0805C2BC: .4byte 0x03001780
_0805C2C0: .4byte 0x0300137C
	.syntax divided
