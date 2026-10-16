	.syntax unified

	thumb_func_start render_text_string_to_sprites
	.global render_text_string_to_sprites
render_text_string_to_sprites: @ 0x08041020
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r2, #0
	mov ip, r3
	ldr r0, [sp, #0x24]
	ldr r2, [sp, #0x28]
	ldr r3, [sp, #0x2c]
	ldr r4, [sp, #0x30]
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
	beq _0804107E
	ldr r4, _08041098 @ =0x083B4C88
	adds r1, r6, #0
_08041068:
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
	bne _08041068
_0804107E:
	lsls r0, r7, #0x1b
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r2, r0
	bhi _080410B6
	cmp r3, #1
	beq _080410DC
	cmp r3, #1
	bgt _0804109C
	cmp r3, #0
	beq _080410A2
	b _080410DC
	.align 2, 0
_08041098: .4byte 0x083B4C88
_0804109C:
	cmp r3, #2
	beq _080410AC
	b _080410DC
_080410A2:
	subs r0, r0, r2
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	b _080410AE
_080410AC:
	subs r0, r0, r2
_080410AE:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r5, r5, r2
	b _080410DC
_080410B6:
	cmp r3, #1
	beq _080410DC
	cmp r3, #1
	bgt _080410C4
	cmp r3, #0
	beq _080410CA
	b _080410DC
_080410C4:
	cmp r3, #2
	beq _080410D4
	b _080410DC
_080410CA:
	subs r0, r2, r0
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	b _080410D6
_080410D4:
	subs r0, r2, r1
_080410D6:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	subs r5, r5, r2
_080410DC:
	ldrb r0, [r6]
	cmp r0, #0xfe
	beq _08041142
	ldr r1, _08041154 @ =0x03002C30
	mov r3, r8
	lsls r2, r3, #0xa
	ldr r4, _08041158 @ =0xFFFFC004
	adds r0, r4, #0
	movs r3, #0
	mov r7, sp
	strh r3, [r7]
	orrs r2, r0
	adds r3, r6, #0
	mov r4, sl
	lsls r0, r4, #6
	adds r1, r0, r1
	movs r0, #3
	mov r7, r8
	bics r0, r7
	lsls r0, r0, #6
	adds r4, r0, #0
	adds r4, #0x3f
	ldr r6, _0804115C @ =0x083B4C88
_0804110A:
	ldrb r0, [r3]
	cmp r0, #0
	beq _0804112E
	strh r2, [r1]
	strh r5, [r1, #2]
	mov r0, ip
	strh r0, [r1, #4]
	mov r7, sb
	strb r7, [r1, #0xa]
	mov r0, sp
	ldrb r0, [r0]
	strb r0, [r1, #0x1c]
	strb r4, [r1, #0xb]
	ldr r7, _08041160 @ =0x000085FF
	adds r0, r7, #0
	ldrb r7, [r3]
	adds r0, r0, r7
	strh r0, [r1, #6]
_0804112E:
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	adds r5, r5, r0
	adds r3, #1
	adds r1, #0x40
	ldrb r0, [r3]
	cmp r0, #0xfe
	bne _0804110A
_08041142:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08041154: .4byte 0x03002C30
_08041158: .4byte 0xFFFFC004
_0804115C: .4byte 0x083B4C88
_08041160: .4byte 0x000085FF
	.syntax divided
