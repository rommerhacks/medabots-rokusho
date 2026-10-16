	.syntax unified

	thumb_func_start write_tilemap_to_vram_0803F1C8
	.global write_tilemap_to_vram_0803F1C8
write_tilemap_to_vram_0803F1C8: @ 0x0803F1C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov ip, r0
	str r1, [sp]
	mov sl, r2
	ldr r1, [sp, #0x2c]
	ldr r0, [sp, #0x30]
	ldr r4, _0803F260 @ =0x03000580
	strh r0, [r4]
	ldr r6, [sp, #0x28]
	cmp r2, #0x1f
	bhi _0803F2D4
	cmp r3, #0x1f
	bhi _0803F264
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	lsls r0, r2, #1
	movs r2, #0xc0
	lsls r2, r2, #0x13
	adds r0, r0, r2
	adds r1, r1, r0
	lsls r0, r3, #6
	adds r7, r1, r0
	movs r0, #0x20
	subs r5, r0, r3
	movs r2, #0
	ldr r3, [sp]
	cmp r2, r3
	blo _0803F210
	b _0803F392
_0803F210:
	movs r0, #0x20
	mov r1, sl
	subs r3, r0, r1
	lsls r0, r2, #6
	adds r1, r7, r0
	movs r4, #0
	subs r5, #1
	str r5, [sp, #4]
	adds r2, #1
	cmp r4, ip
	bhs _0803F24C
	ldr r5, _0803F260 @ =0x03000580
	mov sb, r5
	movs r0, #0xf8
	lsls r0, r0, #3
	mov r8, r0
_0803F230:
	mov r5, sb
	ldrh r0, [r5]
	ldrh r5, [r6]
	adds r0, r0, r5
	strh r0, [r1]
	adds r6, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bne _0803F246
	add r1, r8
_0803F246:
	adds r4, #1
	cmp r4, ip
	blo _0803F230
_0803F24C:
	ldr r5, [sp, #4]
	cmp r5, #0
	bne _0803F258
	movs r0, #0x80
	lsls r0, r0, #4
	adds r7, r7, r0
_0803F258:
	ldr r1, [sp]
	cmp r2, r1
	blo _0803F210
	b _0803F392
	.align 2, 0
_0803F260: .4byte 0x03000580
_0803F264:
	subs r3, #0x20
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	mov r2, sl
	lsls r0, r2, #1
	movs r5, #0xc0
	lsls r5, r5, #0x13
	adds r0, r0, r5
	adds r1, r1, r0
	lsls r0, r3, #6
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #5
	adds r7, r1, r0
	movs r2, #0
	ldr r1, [sp]
	cmp r2, r1
	blo _0803F28E
	b _0803F392
_0803F28E:
	movs r0, #0x20
	mov r5, sl
	subs r3, r0, r5
	lsls r0, r2, #6
	adds r1, r7, r0
	movs r4, #0
	adds r2, #1
	cmp r4, ip
	bhs _0803F2C6
	ldr r0, _0803F2D0 @ =0x03000580
	mov r8, r0
	movs r5, #0xf8
	lsls r5, r5, #3
	mov sb, r5
_0803F2AA:
	mov r5, r8
	ldrh r0, [r5]
	ldrh r5, [r6]
	adds r0, r0, r5
	strh r0, [r1]
	adds r6, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bne _0803F2C0
	add r1, sb
_0803F2C0:
	adds r4, #1
	cmp r4, ip
	blo _0803F2AA
_0803F2C6:
	ldr r0, [sp]
	cmp r2, r0
	blo _0803F28E
	b _0803F392
	.align 2, 0
_0803F2D0: .4byte 0x03000580
_0803F2D4:
	cmp r3, #0x1f
	bhi _0803F344
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	mov r2, sl
	lsls r0, r2, #1
	ldr r5, _0803F33C @ =0x05FFFFC0
	adds r0, r0, r5
	adds r1, r1, r0
	lsls r0, r3, #6
	adds r1, r1, r0
	movs r4, #0x80
	lsls r4, r4, #4
	adds r7, r1, r4
	movs r0, #0x20
	subs r5, r0, r3
	movs r2, #0
	ldr r0, [sp]
	cmp r2, r0
	bhs _0803F392
	mov r8, r4
_0803F302:
	lsls r0, r2, #6
	adds r1, r7, r0
	movs r4, #0
	subs r5, #1
	str r5, [sp, #4]
	adds r2, #1
	cmp r4, ip
	bhs _0803F32A
	ldr r3, _0803F340 @ =0x03000580
	mov sb, r3
_0803F316:
	mov r5, sb
	ldrh r0, [r5]
	ldrh r3, [r6]
	adds r0, r0, r3
	strh r0, [r1]
	adds r6, #2
	adds r1, #2
	adds r4, #1
	cmp r4, ip
	blo _0803F316
_0803F32A:
	ldr r5, [sp, #4]
	cmp r5, #0
	bne _0803F332
	add r7, r8
_0803F332:
	ldr r0, [sp]
	cmp r2, r0
	blo _0803F302
	b _0803F392
	.align 2, 0
_0803F33C: .4byte 0x05FFFFC0
_0803F340: .4byte 0x03000580
_0803F344:
	subs r3, #0x20
	lsrs r1, r1, #8
	movs r0, #0x1f
	ands r1, r0
	lsls r1, r1, #0xb
	mov r2, sl
	lsls r0, r2, #1
	ldr r5, _0803F3A4 @ =0x05FFFFC0
	adds r0, r0, r5
	adds r1, r1, r0
	lsls r0, r3, #6
	adds r1, r1, r0
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r7, r1, r0
	movs r2, #0
	ldr r1, [sp]
	cmp r2, r1
	bhs _0803F392
	mov r8, r4
_0803F36C:
	lsls r0, r2, #6
	adds r1, r7, r0
	movs r4, #0
	adds r2, #1
	cmp r4, ip
	bhs _0803F38C
	mov r3, r8
_0803F37A:
	ldrh r0, [r3]
	ldrh r5, [r6]
	adds r0, r0, r5
	strh r0, [r1]
	adds r6, #2
	adds r1, #2
	adds r4, #1
	cmp r4, ip
	blo _0803F37A
_0803F38C:
	ldr r0, [sp]
	cmp r2, r0
	blo _0803F36C
_0803F392:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803F3A4: .4byte 0x05FFFFC0
	.syntax divided
