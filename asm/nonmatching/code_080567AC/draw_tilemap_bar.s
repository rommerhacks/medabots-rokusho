	.syntax unified

	thumb_func_start draw_tilemap_bar
	.global draw_tilemap_bar
draw_tilemap_bar: @ 0x08059F80
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	ldr r4, [sp, #0x48]
	ldr r5, [sp, #0x4c]
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x10]
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp, #0x14]
	lsls r5, r5, #0x18
	lsrs r2, r5, #0x18
	str r6, [sp, #0x18]
	ldr r0, _0805A000 @ =0x03006F74
	ldr r0, [r0]
	ldrh r0, [r0, #0x36]
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	lsls r1, r1, #0x18
	mov r8, r1
	asrs r3, r1, #0x18
	cmp r3, #0
	bne _08059FC4
	b _0805A17E
_08059FC4:
	cmp r3, #0
	ble _0805A098
	lsls r0, r2, #0xb
	ldr r2, [sp, #0x10]
	adds r1, r2, r3
	lsls r1, r1, #1
	ldr r4, _0805A004 @ =0x05FFFFFE
	adds r1, r1, r4
	adds r1, r0, r1
	lsls r2, r7, #6
	adds r5, r1, r2
	movs r4, #0
	mov sl, r8
	str r0, [sp, #0x24]
	mov r0, sb
	adds r0, #0xa
	str r0, [sp, #0x20]
	adds r1, r7, #1
	str r1, [sp, #0x1c]
	cmp r4, r3
	bge _0805A02E
	ldr r2, [sp, #0x14]
	lsls r7, r2, #0xc
_08059FF2:
	cmp r4, #0
	beq _0805A008
	cmp r6, #0
	bne _0805A008
	strh r7, [r5]
	subs r5, #2
	b _0805A024
	.align 2, 0
_0805A000: .4byte 0x03006F74
_0805A004: .4byte 0x05FFFFFE
_0805A008:
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CDD0
	add r0, sb
	orrs r0, r7
	strh r0, [r5]
	subs r5, #2
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_0805A024:
	adds r4, #1
	mov r3, sl
	asrs r0, r3, #0x18
	cmp r4, r0
	blt _08059FF2
_0805A02E:
	ldr r6, [sp, #0x18]
	ldr r4, [sp, #0x20]
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	mov r0, sl
	asrs r2, r0, #0x18
	ldr r1, [sp, #0x10]
	adds r0, r1, r2
	lsls r0, r0, #1
	ldr r3, _0805A06C @ =0x05FFFFFE
	adds r0, r0, r3
	ldr r4, [sp, #0x24]
	adds r0, r4, r0
	ldr r3, [sp, #0x1c]
	lsls r1, r3, #6
	adds r5, r0, r1
	movs r4, #0
	cmp r4, r2
	blt _0805A058
	b _0805A246
_0805A058:
	ldr r0, [sp, #0x14]
	lsls r7, r0, #0xc
_0805A05C:
	cmp r4, #0
	beq _0805A070
	cmp r6, #0
	bne _0805A070
	strh r7, [r5]
	subs r5, #2
	b _0805A08C
	.align 2, 0
_0805A06C: .4byte 0x05FFFFFE
_0805A070:
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CDD0
	add r0, sb
	orrs r0, r7
	strh r0, [r5]
	subs r5, #2
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_0805A08C:
	adds r4, #1
	mov r1, sl
	asrs r0, r1, #0x18
	cmp r4, r0
	blt _0805A05C
	b _0805A246
_0805A098:
	rsbs r0, r3, #0
	lsls r0, r0, #0x18
	lsls r2, r2, #0xb
	lsrs r3, r0, #0x18
	str r3, [sp, #0xc]
	asrs r3, r0, #0x18
	ldr r4, [sp, #0x10]
	adds r0, r4, r3
	lsls r0, r0, #1
	ldr r1, _0805A0E0 @ =0x05FFFFFE
	adds r0, r0, r1
	adds r0, r2, r0
	lsls r1, r7, #6
	adds r5, r0, r1
	movs r4, #0
	str r2, [sp, #0x24]
	mov r2, sb
	adds r2, #0xa
	str r2, [sp, #0x20]
	adds r0, r7, #1
	str r0, [sp, #0x1c]
	cmp r4, r3
	bge _0805A108
	ldr r1, [sp, #0x14]
	lsls r1, r1, #0xc
	mov r8, r1
	mov r7, sb
	orrs r7, r1
	mov sl, r3
_0805A0D2:
	cmp r4, #0
	beq _0805A0E4
	cmp r6, #0
	bne _0805A0E4
	strh r7, [r5]
	subs r5, #2
	b _0805A102
	.align 2, 0
_0805A0E0: .4byte 0x05FFFFFE
_0805A0E4:
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CDD0
	add r0, sb
	mov r2, r8
	orrs r0, r2
	strh r0, [r5]
	subs r5, #2
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_0805A102:
	adds r4, #1
	cmp r4, sl
	blt _0805A0D2
_0805A108:
	ldr r6, [sp, #0x18]
	ldr r3, [sp, #0x20]
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	ldr r4, [sp, #0xc]
	lsls r2, r4, #0x18
	asrs r3, r2, #0x18
	ldr r1, [sp, #0x10]
	adds r0, r1, r3
	lsls r0, r0, #1
	ldr r4, _0805A150 @ =0x05FFFFFE
	adds r0, r0, r4
	ldr r1, [sp, #0x24]
	adds r0, r1, r0
	ldr r4, [sp, #0x1c]
	lsls r1, r4, #6
	adds r5, r0, r1
	movs r4, #0
	mov sl, r2
	cmp r4, r3
	blt _0805A136
	b _0805A246
_0805A136:
	ldr r0, [sp, #0x14]
	lsls r0, r0, #0xc
	mov r8, r0
	mov r7, sb
	orrs r7, r0
_0805A140:
	cmp r4, #0
	beq _0805A154
	cmp r6, #0
	bne _0805A154
	strh r7, [r5]
	subs r5, #2
	b _0805A172
	.align 2, 0
_0805A150: .4byte 0x05FFFFFE
_0805A154:
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CDD0
	add r0, sb
	mov r1, r8
	orrs r0, r1
	strh r0, [r5]
	subs r5, #2
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_0805A172:
	adds r4, #1
	mov r2, sl
	asrs r0, r2, #0x18
	cmp r4, r0
	blt _0805A140
	b _0805A246
_0805A17E:
	lsls r2, r2, #0xb
	ldr r4, [sp, #0x10]
	lsls r3, r4, #1
	movs r0, #0xc0
	lsls r0, r0, #0x13
	adds r0, r3, r0
	adds r0, r2, r0
	lsls r1, r7, #6
	adds r5, r0, r1
	movs r4, #0
	str r2, [sp, #0x24]
	adds r0, r7, #1
	str r0, [sp, #0x1c]
	mov r8, r3
	mov r7, sp
_0805A19C:
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CDD0
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805A1B0
	cmp r4, #0
	bne _0805A1C4
_0805A1B0:
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r7, #2
	adds r4, #1
	cmp r4, #4
	ble _0805A19C
_0805A1C4:
	subs r4, #1
	cmp r4, #0
	blt _0805A1E6
	ldr r1, [sp, #0x14]
	lsls r2, r1, #0xc
	lsls r0, r4, #1
	mov r3, sp
	adds r1, r0, r3
_0805A1D4:
	ldrh r0, [r1]
	add r0, sb
	orrs r0, r2
	strh r0, [r5]
	adds r5, #2
	subs r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0805A1D4
_0805A1E6:
	movs r0, #0xc0
	lsls r0, r0, #0x13
	add r0, r8
	ldr r4, [sp, #0x24]
	adds r0, r4, r0
	ldr r2, [sp, #0x1c]
	lsls r1, r2, #6
	adds r5, r0, r1
	ldr r6, [sp, #0x18]
	movs r4, #0
	mov r7, sp
_0805A1FC:
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CDD0
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0805A210
	cmp r4, #0
	bne _0805A224
_0805A210:
	adds r0, r6, #0
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r7, #2
	adds r4, #1
	cmp r4, #4
	ble _0805A1FC
_0805A224:
	subs r4, #1
	cmp r4, #0
	blt _0805A246
	ldr r3, [sp, #0x14]
	lsls r2, r3, #0xc
	lsls r0, r4, #1
	mov r3, sp
	adds r1, r0, r3
_0805A234:
	ldrh r0, [r1]
	add r0, sb
	orrs r0, r2
	strh r0, [r5]
	adds r5, #2
	subs r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0805A234
_0805A246:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
