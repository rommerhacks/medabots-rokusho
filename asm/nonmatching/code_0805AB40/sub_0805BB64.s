	.syntax unified

	thumb_func_start sub_0805BB64
sub_0805BB64: @ 0x0805BB64
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov ip, r1
	movs r5, #0
	ldr r0, _0805BBC4 @ =0x00000FFF
	mov sl, r0
	movs r2, #0xc0
	lsls r2, r2, #7
	mov sb, r2
_0805BB86:
	movs r6, #6
	lsls r0, r5, #1
	adds r0, r0, r5
	adds r4, r0, #0
	adds r4, #0xa
	movs r3, #0
	adds r7, r5, #1
_0805BB94:
	ldr r0, _0805BBC8 @ =0x04000008
	ldrh r1, [r0]
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	lsls r0, r6, #1
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r0, r0, r2
	adds r1, r1, r0
	lsls r0, r4, #6
	adds r1, r1, r0
	ldrh r0, [r1]
	mov r2, sl
	ands r2, r0
	cmp r8, r5
	bne _0805BBCC
	cmp r3, ip
	bge _0805BBCC
	movs r0, #0xe0
	lsls r0, r0, #7
	b _0805BBCE
	.align 2, 0
_0805BBC4: .4byte 0x00000FFF
_0805BBC8: .4byte 0x04000008
_0805BBCC:
	mov r0, sb
_0805BBCE:
	orrs r2, r0
	strh r2, [r1]
	cmp r3, #1
	bgt _0805BBDA
	adds r4, #1
	b _0805BBDC
_0805BBDA:
	adds r6, #1
_0805BBDC:
	adds r3, #1
	cmp r3, #0x13
	ble _0805BB94
	adds r5, r7, #0
	cmp r5, #2
	ble _0805BB86
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
