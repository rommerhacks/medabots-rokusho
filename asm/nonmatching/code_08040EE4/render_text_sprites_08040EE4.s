	.syntax unified

	thumb_func_start render_text_sprites_08040EE4
	.global render_text_sprites_08040EE4
render_text_sprites_08040EE4: @ 0x08040EE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov ip, r0
	adds r7, r2, #0
	mov r8, r3
	ldr r0, [sp, #0x24]
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	ldr r4, [sp, #0x30]
	ldr r5, [sp, #0x34]
	ldr r6, [sp, #0x38]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov sl, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r0, r7, #3
	adds r7, r0, r5
	mov r1, r8
	lsls r0, r1, #3
	adds r0, r0, r6
	mov r8, r0
	movs r5, #0
	mov r2, ip
	ldrb r0, [r2]
	cmp r0, #0xfe
	beq _08040F4C
	ldr r6, _08040F68 @ =0x083B4C88
	mov r1, ip
_08040F36:
	ldrb r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	adds r0, r5, r0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r1, #1
	ldrb r0, [r1]
	cmp r0, #0xfe
	bne _08040F36
_08040F4C:
	mov r1, sb
	lsls r0, r1, #0x1b
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r5, r0
	bhi _08040F86
	cmp r3, #1
	beq _08040FAC
	cmp r3, #1
	bgt _08040F6C
	cmp r3, #0
	beq _08040F72
	b _08040FAC
	.align 2, 0
_08040F68: .4byte 0x083B4C88
_08040F6C:
	cmp r3, #2
	beq _08040F7C
	b _08040FAC
_08040F72:
	subs r0, r0, r5
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	b _08040F7E
_08040F7C:
	subs r0, r0, r5
_08040F7E:
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r7, r7, r5
	b _08040FAC
_08040F86:
	cmp r3, #1
	beq _08040FAC
	cmp r3, #1
	bgt _08040F94
	cmp r3, #0
	beq _08040F9A
	b _08040FAC
_08040F94:
	cmp r3, #2
	beq _08040FA4
	b _08040FAC
_08040F9A:
	subs r0, r5, r0
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	b _08040FA6
_08040FA4:
	subs r0, r5, r1
_08040FA6:
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	subs r7, r7, r5
_08040FAC:
	mov r2, ip
	ldrb r0, [r2]
	cmp r0, #0xfe
	beq _08041004
	ldr r1, _08041014 @ =0x03002C30
	lsls r5, r4, #0xa
	ldr r2, _08041018 @ =0xFFFFC004
	adds r0, r2, #0
	movs r6, #0
	orrs r5, r0
	mov r3, ip
	ldr r2, [sp]
	lsls r0, r2, #6
	adds r1, r0, r1
	movs r0, #3
	bics r0, r4
	lsls r0, r0, #6
	adds r4, r0, #0
	adds r4, #0x3f
	ldr r2, _0804101C @ =0x083B4C88
_08040FD4:
	ldrb r0, [r3]
	cmp r0, #0
	beq _08040FF0
	strh r5, [r1]
	strh r7, [r1, #2]
	mov r0, r8
	strh r0, [r1, #4]
	mov r0, sl
	strb r0, [r1, #0xa]
	strb r6, [r1, #0x1c]
	strb r4, [r1, #0xb]
	ldrb r0, [r3]
	subs r0, #1
	strh r0, [r1, #6]
_08040FF0:
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	adds r7, r7, r0
	adds r3, #1
	adds r1, #0x40
	ldrb r0, [r3]
	cmp r0, #0xfe
	bne _08040FD4
_08041004:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08041014: .4byte 0x03002C30
_08041018: .4byte 0xFFFFC004
_0804101C: .4byte 0x083B4C88
	.syntax divided
