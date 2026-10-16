	.syntax unified

	thumb_func_start battle_menu_highlight_icons
battle_menu_highlight_icons: @ 0x08060A7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	mov ip, r1
	ldr r0, _08060B58 @ =0x03006F74
	ldr r0, [r0]
	ldr r2, [sp]
	lsls r1, r2, #2
	ldrh r0, [r0, #0x38]
	adds r1, r1, r0
	adds r1, #5
	ldr r3, _08060B5C @ =0xFFFFC000
	adds r0, r3, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	ldr r4, _08060B60 @ =0x0400000C
	ldrh r0, [r4]
	lsrs r0, r0, #8
	movs r3, #0x1f
	ands r0, r3
	lsls r0, r0, #0xb
	ldr r2, _08060B64 @ =0x06000152
	adds r0, r0, r2
	lsrs r2, r1, #0x10
	movs r5, #0x80
	lsls r5, r5, #9
	adds r1, r1, r5
	strh r2, [r0]
	ldrh r0, [r4]
	lsrs r0, r0, #8
	ands r0, r3
	lsls r0, r0, #0xb
	ldr r2, _08060B68 @ =0x06000154
	adds r0, r0, r2
	lsrs r2, r1, #0x10
	adds r1, r1, r5
	strh r2, [r0]
	ldrh r0, [r4]
	lsrs r0, r0, #8
	ands r0, r3
	lsls r0, r0, #0xb
	ldr r2, _08060B6C @ =0x06000192
	adds r0, r0, r2
	lsrs r2, r1, #0x10
	adds r1, r1, r5
	lsrs r1, r1, #0x10
	strh r2, [r0]
	ldrh r0, [r4]
	lsrs r0, r0, #8
	ands r0, r3
	lsls r0, r0, #0xb
	ldr r2, _08060B70 @ =0x06000194
	adds r0, r0, r2
	strh r1, [r0]
	movs r5, #0
	mov sb, r4
	mov r8, r3
	ldr r0, _08060B74 @ =0x080AFA08
	mov sl, r0
	movs r0, #8
	mov r1, ip
	ands r1, r0
	mov ip, r1
_08060B02:
	mov r2, sb
	ldrh r1, [r2]
	lsrs r1, r1, #8
	mov r3, r8
	ands r1, r3
	lsls r1, r1, #0xb
	lsls r2, r5, #1
	mov r3, sl
	adds r0, r2, r3
	ldrb r3, [r0]
	lsls r3, r3, #1
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r3, r3, r0
	adds r1, r1, r3
	ldr r0, _08060B78 @ =0x080AFA09
	adds r2, r2, r0
	ldrb r2, [r2]
	lsls r0, r2, #6
	adds r4, r1, r0
	mov r1, sb
	ldrh r0, [r1]
	lsrs r0, r0, #8
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #0xb
	adds r0, r0, r3
	adds r2, #1
	lsls r2, r2, #6
	adds r2, r0, r2
	mov r3, ip
	cmp r3, #0
	beq _08060B7C
	movs r0, #0xa0
	lsls r0, r0, #7
	ldr r1, [sp]
	cmp r5, r1
	bne _08060B52
	movs r0, #0xc0
	lsls r0, r0, #7
_08060B52:
	adds r3, r0, #0
	b _08060B80
	.align 2, 0
_08060B58: .4byte 0x03006F74
_08060B5C: .4byte 0xFFFFC000
_08060B60: .4byte 0x0400000C
_08060B64: .4byte 0x06000152
_08060B68: .4byte 0x06000154
_08060B6C: .4byte 0x06000192
_08060B70: .4byte 0x06000194
_08060B74: .4byte 0x080AFA08
_08060B78: .4byte 0x080AFA09
_08060B7C:
	movs r3, #0xa0
	lsls r3, r3, #7
_08060B80:
	adds r7, r5, #1
	ldr r6, _08060BBC @ =0x00000FFF
	movs r5, #7
_08060B86:
	ldrh r1, [r4]
	adds r0, r6, #0
	ands r0, r1
	orrs r0, r3
	strh r0, [r4]
	adds r4, #2
	ldrh r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	orrs r0, r3
	strh r0, [r2]
	adds r2, #2
	subs r5, #1
	cmp r5, #0
	bge _08060B86
	adds r5, r7, #0
	cmp r5, #3
	ble _08060B02
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08060BBC: .4byte 0x00000FFF
	.syntax divided
