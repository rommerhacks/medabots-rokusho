	.syntax unified

	thumb_func_start sub_0805BBF8
sub_0805BBF8: @ 0x0805BBF8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r4, #0
	ldr r0, _0805BC40 @ =0x00000FFF
	mov ip, r0
	movs r2, #0xe0
	lsls r2, r2, #7
	mov r8, r2
	movs r7, #0xc0
	lsls r7, r7, #7
_0805BC12:
	ldr r0, _0805BC44 @ =0x04000008
	ldrh r1, [r0]
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #6
	ldr r2, _0805BC48 @ =0x0600028E
	adds r0, r0, r2
	adds r1, r1, r0
	adds r5, r4, #1
	movs r3, #0xa
_0805BC2E:
	ldrh r2, [r1]
	mov r0, ip
	ands r2, r0
	cmp r4, r6
	bne _0805BC4C
	mov r0, r8
	orrs r0, r2
	b _0805BC52
	.align 2, 0
_0805BC40: .4byte 0x00000FFF
_0805BC44: .4byte 0x04000008
_0805BC48: .4byte 0x0600028E
_0805BC4C:
	orrs r2, r7
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
_0805BC52:
	strh r0, [r1]
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _0805BC2E
	adds r4, r5, #0
	cmp r4, #2
	ble _0805BC12
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
