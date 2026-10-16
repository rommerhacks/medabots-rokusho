	.syntax unified

	thumb_func_start sub_0805BCC0
sub_0805BCC0: @ 0x0805BCC0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	ldr r0, _0805BD68 @ =0x03001788
	ldrb r0, [r0]
	add r1, sp, #4
	strb r0, [r1]
	ldr r0, _0805BD6C @ =0x03001360
	ldrb r2, [r0]
	mov r0, sp
	adds r0, #5
	strb r2, [r0]
	ldr r0, _0805BD70 @ =0x03000B94
	ldrb r2, [r0]
	mov r0, sp
	adds r0, #6
	strb r2, [r0]
	mov r0, sp
	movs r2, #3
	bl memcpy_optimized
	movs r0, #0
	mov ip, r0
	movs r1, #0x80
	lsls r1, r1, #8
	mov sb, r1
_0805BD00:
	movs r5, #0
	mov r0, ip
	lsls r1, r0, #1
	adds r0, #1
	str r0, [sp, #0x10]
	add r1, ip
	adds r0, r1, #0
	adds r0, #0xb
	lsls r0, r0, #6
	lsls r1, r1, #1
	str r1, [sp, #0xc]
	ldr r1, _0805BD74 @ =0x0600000E
	adds r1, r1, r0
	mov sl, r1
	mov r7, sp
	add r7, ip
_0805BD20:
	ldr r0, _0805BD78 @ =0x04000008
	ldrh r0, [r0]
	lsrs r0, r0, #8
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #0xb
	mov r1, sl
	adds r3, r0, r1
	lsls r0, r5, #1
	ldr r1, [sp, #0xc]
	adds r0, r0, r1
	ldr r1, _0805BD7C @ =0x080AF740
	adds r0, r0, r1
	ldrh r4, [r0]
	adds r0, r5, #1
	mov r8, r0
	movs r6, #0xf
_0805BD42:
	adds r0, r4, #0
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _0805BD9C
	ldrh r0, [r3]
	ldr r1, _0805BD80 @ =0x00000FFF
	ands r1, r0
	adds r2, r1, #0
	ldr r0, [sp, #8]
	cmp r0, ip
	bne _0805BD88
	ldrb r0, [r7]
	cmp r0, r5
	bne _0805BD84
	movs r0, #0xa0
	lsls r0, r0, #8
	b _0805BD92
	.align 2, 0
_0805BD68: .4byte 0x03001788
_0805BD6C: .4byte 0x03001360
_0805BD70: .4byte 0x03000B94
_0805BD74: .4byte 0x0600000E
_0805BD78: .4byte 0x04000008
_0805BD7C: .4byte 0x080AF740
_0805BD80: .4byte 0x00000FFF
_0805BD84:
	mov r0, sb
	b _0805BD92
_0805BD88:
	ldrb r0, [r7]
	cmp r0, r5
	bne _0805BD96
	movs r0, #0x90
	lsls r0, r0, #8
_0805BD92:
	orrs r0, r1
	b _0805BD9A
_0805BD96:
	mov r0, sb
	orrs r0, r2
_0805BD9A:
	strh r0, [r3]
_0805BD9C:
	lsls r0, r4, #0x11
	lsrs r4, r0, #0x10
	adds r3, #2
	subs r6, #1
	cmp r6, #0
	bge _0805BD42
	mov r5, r8
	cmp r5, #2
	ble _0805BD20
	ldr r1, [sp, #0x10]
	mov ip, r1
	cmp r1, #2
	ble _0805BD00
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
