	.syntax unified

	thumb_func_start init_oam_sprite_entry
init_oam_sprite_entry: @ 0x08045D34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	mov sl, r1
	str r3, [sp, #4]
	lsls r2, r2, #0x18
	movs r0, #0
	mov ip, r0
	mov r1, ip
	strb r1, [r7]
	mov r3, sl
	ldrb r5, [r3, #0x15]
	lsls r1, r5, #0x1d
	lsrs r1, r1, #0x1e
	ldrb r4, [r7, #1]
	subs r0, #4
	ands r0, r4
	orrs r0, r1
	lsls r1, r5, #0x1b
	lsrs r1, r1, #0x1e
	lsls r1, r1, #2
	movs r4, #0xd
	rsbs r4, r4, #0
	ands r0, r4
	orrs r0, r1
	movs r1, #0x11
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	lsls r1, r5, #0x1f
	lsrs r1, r1, #0x1f
	lsls r1, r1, #5
	movs r3, #0x21
	rsbs r3, r3, #0
	mov sb, r3
	ands r0, r3
	orrs r0, r1
	movs r6, #0x3f
	ands r0, r6
	strb r0, [r7, #1]
	ldrh r1, [r7, #2]
	ldr r0, _08045E64 @ =0xFFFFFE00
	ands r0, r1
	strh r0, [r7, #2]
	ldrb r1, [r7, #3]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r1
	lsls r1, r5, #0x1a
	lsrs r1, r1, #0x1f
	lsls r1, r1, #4
	mov r3, r8
	ands r0, r3
	orrs r0, r1
	lsls r5, r5, #0x19
	lsrs r5, r5, #0x1f
	lsls r5, r5, #5
	mov r1, sb
	ands r0, r1
	orrs r0, r5
	ands r0, r6
	strb r0, [r7, #3]
	ldr r0, [sp, #4]
	lsls r3, r0, #0x16
	lsrs r3, r3, #0x16
	ldrh r1, [r7, #4]
	ldr r0, _08045E68 @ =0xFFFFFC00
	ands r0, r1
	orrs r0, r3
	strh r0, [r7, #4]
	ldrb r0, [r7, #5]
	ands r4, r0
	movs r0, #8
	orrs r4, r0
	lsrs r2, r2, #0x18
	mov r1, sl
	ldrb r1, [r1, #0x11]
	adds r2, r2, r1
	lsls r2, r2, #4
	movs r0, #0xf
	ands r4, r0
	orrs r4, r2
	strb r4, [r7, #5]
	mov r2, ip
	strh r2, [r7, #6]
	mov r1, sp
	mov r3, sl
	ldrb r0, [r3, #0x12]
	strh r0, [r1]
	ldrb r0, [r3, #0x14]
	lsls r1, r0, #0x1c
	lsrs r0, r1, #0x1c
	cmp r0, #1
	bls _08045E06
	mov r0, sp
	ldrh r0, [r0]
	lsrs r1, r1, #0x1c
	bl Div
	mov r1, sp
	strh r0, [r1]
_08045E06:
	mov r1, sp
	mov r2, sl
	ldrb r0, [r2, #0x13]
	strh r0, [r1, #2]
	ldrb r0, [r2, #0x14]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x1c
	cmp r0, #1
	bls _08045E26
	mov r0, sp
	ldrh r0, [r0, #2]
	lsrs r1, r1, #0x1c
	bl Div
	mov r1, sp
	strh r0, [r1, #2]
_08045E26:
	mov r0, sp
	ldrh r1, [r0]
	ldrh r2, [r0, #2]
	adds r0, r7, #0
	bl set_oam_sprite_shape_size
	mov r0, sp
	ldrh r1, [r0]
	lsrs r1, r1, #3
	ldrh r0, [r0, #2]
	lsrs r0, r0, #3
	muls r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	mov r3, sl
	ldrb r1, [r3, #0x15]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08045E52
	lsls r0, r2, #0x11
	lsrs r2, r0, #0x10
_08045E52:
	adds r0, r2, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08045E64: .4byte 0xFFFFFE00
_08045E68: .4byte 0xFFFFFC00
	.syntax divided
