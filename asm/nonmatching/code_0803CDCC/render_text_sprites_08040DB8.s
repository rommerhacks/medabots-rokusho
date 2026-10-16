	.syntax unified

	thumb_func_start render_text_sprites_08040DB8
	.global render_text_sprites_08040DB8
render_text_sprites_08040DB8: @ 0x08040DB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	adds r5, r2, #0
	mov ip, r3
	ldr r0, [sp, #0x20]
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x28]
	ldr r4, [sp, #0x2c]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov sb, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r8, r4
	lsls r5, r5, #3
	mov r0, ip
	lsls r0, r0, #3
	mov ip, r0
	movs r2, #0
	ldrb r0, [r6]
	cmp r0, #0xfe
	beq _08040E14
	ldr r4, _08040E2C @ =0x083B4C88
	adds r1, r6, #0
_08040DFE:
	ldrb r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrb r0, [r0]
	adds r0, r2, r0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r1, #1
	ldrb r0, [r1]
	cmp r0, #0xfe
	bne _08040DFE
_08040E14:
	lsls r0, r7, #0x1b
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r2, r0
	bhi _08040E4A
	cmp r3, #1
	beq _08040E70
	cmp r3, #1
	bgt _08040E30
	cmp r3, #0
	beq _08040E36
	b _08040E70
	.align 2, 0
_08040E2C: .4byte 0x083B4C88
_08040E30:
	cmp r3, #2
	beq _08040E40
	b _08040E70
_08040E36:
	subs r0, r0, r2
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	b _08040E42
_08040E40:
	subs r0, r0, r2
_08040E42:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r5, r5, r2
	b _08040E70
_08040E4A:
	cmp r3, #1
	beq _08040E70
	cmp r3, #1
	bgt _08040E58
	cmp r3, #0
	beq _08040E5E
	b _08040E70
_08040E58:
	cmp r3, #2
	beq _08040E68
	b _08040E70
_08040E5E:
	subs r0, r2, r0
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	b _08040E6A
_08040E68:
	subs r0, r2, r1
_08040E6A:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	subs r5, r5, r2
_08040E70:
	ldrb r0, [r6]
	cmp r0, #0xfe
	beq _08040ECA
	ldr r1, _08040ED8 @ =0x03002C30
	mov r3, r8
	lsls r2, r3, #0xa
	ldr r4, _08040EDC @ =0xFFFFC004
	adds r0, r4, #0
	movs r7, #0
	orrs r2, r0
	adds r3, r6, #0
	mov r4, sl
	lsls r0, r4, #6
	adds r1, r0, r1
	movs r0, #3
	mov r4, r8
	bics r0, r4
	lsls r0, r0, #6
	adds r4, r0, #0
	adds r4, #0x3f
	ldr r6, _08040EE0 @ =0x083B4C88
_08040E9A:
	ldrb r0, [r3]
	cmp r0, #0
	beq _08040EB6
	strh r2, [r1]
	strh r5, [r1, #2]
	mov r0, ip
	strh r0, [r1, #4]
	mov r0, sb
	strb r0, [r1, #0xa]
	strb r7, [r1, #0x1c]
	strb r4, [r1, #0xb]
	ldrb r0, [r3]
	subs r0, #1
	strh r0, [r1, #6]
_08040EB6:
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	adds r5, r5, r0
	adds r3, #1
	adds r1, #0x40
	ldrb r0, [r3]
	cmp r0, #0xfe
	bne _08040E9A
_08040ECA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08040ED8: .4byte 0x03002C30
_08040EDC: .4byte 0xFFFFC004
_08040EE0: .4byte 0x083B4C88
	.syntax divided
