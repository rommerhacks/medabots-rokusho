	.syntax unified

	thumb_func_start draw_tilemap_line
	.global draw_tilemap_line
draw_tilemap_line: @ 0x08059E0C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov sb, r4
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _08059E7C @ =0x03006F74
	ldr r0, [r0]
	ldrh r0, [r0, #0x36]
	adds r0, #0x16
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	lsls r1, r1, #0x18
	asrs r2, r1, #0x18
	cmp r2, #0
	beq _08059F0E
	cmp r2, #0
	ble _08059EA8
	lsls r0, r5, #0xb
	mov r4, r8
	adds r1, r4, r2
	lsls r1, r1, #1
	ldr r4, _08059E80 @ =0x05FFFFFE
	adds r1, r1, r4
	adds r0, r0, r1
	lsls r1, r3, #6
	adds r5, r0, r1
	movs r4, #0
	cmp r4, r2
	blt _08059E68
	b _08059F6E
_08059E68:
	mov r0, sb
	lsls r7, r0, #0xc
	mov r8, r2
_08059E6E:
	cmp r4, #0
	beq _08059E84
	cmp r6, #0
	bne _08059E84
	strh r7, [r5]
	subs r5, #2
	b _08059EA0
	.align 2, 0
_08059E7C: .4byte 0x03006F74
_08059E80: .4byte 0x05FFFFFE
_08059E84:
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CDD0
	add r0, sl
	orrs r0, r7
	strh r0, [r5]
	subs r5, #2
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_08059EA0:
	adds r4, #1
	cmp r4, r8
	blt _08059E6E
	b _08059F6E
_08059EA8:
	rsbs r0, r2, #0
	lsls r1, r5, #0xb
	lsls r0, r0, #0x18
	asrs r7, r0, #0x18
	mov r2, r8
	adds r0, r2, r7
	lsls r0, r0, #1
	ldr r4, _08059EE4 @ =0x05FFFFFE
	adds r0, r0, r4
	adds r1, r1, r0
	lsls r0, r3, #6
	adds r5, r1, r0
	movs r4, #0
	cmp r4, r7
	bge _08059F6E
	mov r0, sb
	lsls r0, r0, #0xc
	mov sb, r0
	mov r8, sl
	mov r1, r8
	orrs r1, r0
	mov r8, r1
_08059ED4:
	cmp r4, #0
	beq _08059EE8
	cmp r6, #0
	bne _08059EE8
	mov r2, r8
	strh r2, [r5]
	subs r5, #2
	b _08059F06
	.align 2, 0
_08059EE4: .4byte 0x05FFFFFE
_08059EE8:
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CDD0
	add r0, sl
	mov r3, sb
	orrs r0, r3
	strh r0, [r5]
	subs r5, #2
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_08059F06:
	adds r4, #1
	cmp r4, r7
	blt _08059ED4
	b _08059F6E
_08059F0E:
	lsls r2, r5, #0xb
	mov r4, r8
	lsls r0, r4, #1
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	adds r2, r2, r0
	lsls r0, r3, #6
	adds r5, r2, r0
	movs r4, #0
	mov r7, sp
	b _08059F36
_08059F26:
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r7, #2
	adds r4, #1
_08059F36:
	cmp r4, #4
	bgt _08059F4C
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CDD0
	strh r0, [r7]
	cmp r6, #0
	bne _08059F26
	cmp r4, #0
	beq _08059F26
_08059F4C:
	subs r4, #1
	cmp r4, #0
	blt _08059F6E
	mov r0, sb
	lsls r2, r0, #0xc
	lsls r0, r4, #1
	mov r3, sp
	adds r1, r0, r3
_08059F5C:
	ldrh r0, [r1]
	add r0, sl
	orrs r0, r2
	strh r0, [r5]
	adds r5, #2
	subs r1, #2
	subs r4, #1
	cmp r4, #0
	bge _08059F5C
_08059F6E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
