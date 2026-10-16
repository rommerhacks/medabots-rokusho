	.syntax unified

	thumb_func_start sub_08063FB4
sub_08063FB4: @ 0x08063FB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	bl animate_battle_scroll_tiles
	ldr r4, _08063FFC @ =0x03006F74
	ldr r3, [r4]
	ldrh r0, [r3, #0x3c]
	adds r0, #1
	strh r0, [r3, #0x3c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	bgt _08063FD8
	b _0806428C
_08063FD8:
	ldr r0, _08064000 @ =0x0300137C
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	adds r0, r3, #0
	adds r0, #0x7a
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _0806400C
	ldr r2, _08064004 @ =0x03002C30
	ldrh r1, [r2]
	ldr r0, _08064008 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	b _080642CC
	.align 2, 0
_08063FFC: .4byte 0x03006F74
_08064000: .4byte 0x0300137C
_08064004: .4byte 0x03002C30
_08064008: .4byte 0x0000BFFF
_0806400C:
	ldr r2, _0806413C @ =0x03002C30
	ldrh r0, [r2]
	movs r5, #0x80
	lsls r5, r5, #7
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08064140 @ =0x00000235
	adds r0, r3, r1
	ldrb r0, [r0]
	mov sl, r0
	ldr r2, _08064144 @ =0x0000023A
	adds r0, r3, r2
	movs r1, #0xa
	str r1, [sp]
	movs r1, #2
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r1, #0x20
	movs r2, #4
	movs r3, #4
	bl render_text_sprites_08040DB8
	movs r2, #0
	ldr r6, _08064148 @ =0x030004DE
	ldr r5, _0806414C @ =0x083B6410
	ldr r3, _08064150 @ =0x00000231
_08064048:
	adds r1, r2, r6
	ldr r0, [r4]
	adds r0, r0, r3
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, #1
	cmp r2, #9
	ble _08064048
	ldr r0, _08064148 @ =0x030004DE
	movs r1, #0xa
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #0x10
	movs r2, #5
	movs r3, #8
	bl render_text_sprites_08040DB8
	ldr r2, _08064154 @ =0x0400000C
	ldrh r1, [r2]
	lsrs r1, r1, #8
	movs r7, #0x1f
	ands r1, r7
	lsls r1, r1, #0xb
	ldr r0, _08064158 @ =0x06000218
	adds r1, r1, r0
	ldr r3, _0806415C @ =0x03006F74
	mov sb, r3
	ldr r0, [r3]
	adds r0, #0x40
	ldrh r0, [r0]
	strh r0, [r1]
	ldrh r1, [r2]
	lsrs r1, r1, #8
	ands r1, r7
	lsls r1, r1, #0xb
	ldr r0, _08064160 @ =0x0600021A
	adds r1, r1, r0
	ldr r0, [r3]
	adds r0, #0x42
	ldrh r0, [r0]
	strh r0, [r1]
	ldrh r1, [r2]
	lsrs r1, r1, #8
	ands r1, r7
	lsls r1, r1, #0xb
	ldr r0, _08064164 @ =0x06000258
	adds r1, r1, r0
	ldr r0, [r3]
	adds r0, #0x44
	ldrh r0, [r0]
	strh r0, [r1]
	ldrh r1, [r2]
	lsrs r1, r1, #8
	ands r1, r7
	lsls r1, r1, #0xb
	ldr r0, _08064168 @ =0x0600025A
	adds r1, r1, r0
	ldr r0, [r3]
	adds r0, #0x46
	ldrh r0, [r0]
	strh r0, [r1]
	mov r4, sl
	cmp r4, #0x64
	bne _08064174
	subs r2, #2
	ldrh r0, [r2]
	lsrs r0, r0, #8
	ands r0, r7
	lsls r0, r0, #0xb
	ldr r5, _08064160 @ =0x0600021A
	adds r0, r0, r5
	ldr r1, [r3]
	ldrh r1, [r1, #0x36]
	adds r1, #0x14
	movs r4, #0xe0
	lsls r4, r4, #7
	adds r3, r4, #0
	orrs r1, r3
	strh r1, [r0]
	ldrh r1, [r2]
	lsrs r1, r1, #8
	ands r1, r7
	lsls r1, r1, #0xb
	adds r5, #0x40
	adds r1, r1, r5
	mov r4, sb
	ldr r0, [r4]
	ldrh r0, [r0, #0x36]
	adds r0, #0x15
	orrs r0, r3
	strh r0, [r1]
	ldrh r1, [r2]
	lsrs r1, r1, #8
	ands r1, r7
	lsls r1, r1, #0xb
	ldr r0, _0806416C @ =0x0600021C
	adds r1, r1, r0
	ldr r0, [r4]
	ldrh r0, [r0, #0x36]
	adds r0, #0x16
	orrs r0, r3
	strh r0, [r1]
	ldrh r1, [r2]
	lsrs r1, r1, #8
	ands r1, r7
	lsls r1, r1, #0xb
	ldr r0, _08064170 @ =0x0600025C
	adds r1, r1, r0
	ldr r0, [r4]
	ldrh r0, [r0, #0x36]
	adds r0, #0x17
	orrs r0, r3
	strh r0, [r1]
	b _080641FC
	.align 2, 0
_0806413C: .4byte 0x03002C30
_08064140: .4byte 0x00000235
_08064144: .4byte 0x0000023A
_08064148: .4byte 0x030004DE
_0806414C: .4byte 0x083B6410
_08064150: .4byte 0x00000231
_08064154: .4byte 0x0400000C
_08064158: .4byte 0x06000218
_0806415C: .4byte 0x03006F74
_08064160: .4byte 0x0600021A
_08064164: .4byte 0x06000258
_08064168: .4byte 0x0600025A
_0806416C: .4byte 0x0600021C
_08064170: .4byte 0x0600025C
_08064174:
	ldr r5, _08064258 @ =0x0400000A
	mov r8, r5
	ldrh r4, [r5]
	lsrs r4, r4, #8
	ands r4, r7
	lsls r4, r4, #0xb
	ldr r0, _0806425C @ =0x0600021A
	adds r4, r4, r0
	mov r1, sb
	ldr r5, [r1]
	mov r0, sl
	movs r1, #0xa
	bl sub_0807CD58
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	ldrh r1, [r5, #0x36]
	adds r1, r1, r0
	movs r2, #0xe0
	lsls r2, r2, #7
	adds r6, r2, #0
	orrs r1, r6
	strh r1, [r4]
	mov r3, r8
	ldrh r2, [r3]
	lsrs r2, r2, #8
	ands r2, r7
	lsls r2, r2, #0xb
	ldr r4, _08064260 @ =0x0600025A
	adds r2, r2, r4
	mov r5, sb
	ldr r1, [r5]
	ldrh r1, [r1, #0x36]
	adds r1, r1, r0
	adds r1, #1
	orrs r1, r6
	strh r1, [r2]
	ldrh r4, [r3]
	lsrs r4, r4, #8
	ands r4, r7
	lsls r4, r4, #0xb
	ldr r0, _08064264 @ =0x0600021C
	adds r4, r4, r0
	ldr r5, [r5]
	mov r0, sl
	movs r1, #0xa
	bl sub_0807CDD0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	ldrh r1, [r5, #0x36]
	adds r1, r1, r0
	orrs r1, r6
	strh r1, [r4]
	mov r1, r8
	ldrh r2, [r1]
	lsrs r2, r2, #8
	ands r2, r7
	lsls r2, r2, #0xb
	ldr r1, _08064268 @ =0x0600025C
	adds r2, r2, r1
	mov r3, sb
	ldr r1, [r3]
	ldrh r1, [r1, #0x36]
	adds r1, r1, r0
	adds r1, #1
	orrs r1, r6
	strh r1, [r2]
_080641FC:
	ldr r4, _0806426C @ =0x03006F74
	ldr r2, [r4]
	ldr r5, _08064270 @ =0x00000231
	adds r0, r2, r5
	ldrb r0, [r0]
	lsls r0, r0, #7
	ldr r1, _08064274 @ =0x084C21BC
	adds r0, r0, r1
	ldrh r1, [r2, #0x36]
	lsls r1, r1, #5
	ldr r2, _08064278 @ =0x06003F80
	adds r1, r1, r2
	movs r2, #0x20
	bl CpuFastSet
	ldr r0, [r4]
	ldrh r0, [r0, #0x36]
	subs r0, #4
	lsls r0, r0, #0x10
	movs r2, #0xc0
	lsls r2, r2, #0x17
	orrs r2, r0
	lsrs r2, r2, #0x10
	ldr r0, _08064258 @ =0x0400000A
	ldrh r0, [r0]
	lsrs r0, r0, #8
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #0xb
	ldr r1, _0806427C @ =0x06000206
	adds r3, r0, r1
	strh r2, [r3]
	ldr r4, _08064280 @ =0x06000208
	adds r3, r0, r4
	adds r1, r2, #1
	strh r1, [r3]
	ldr r5, _08064284 @ =0x06000246
	adds r3, r0, r5
	adds r1, r2, #2
	strh r1, [r3]
	ldr r1, _08064288 @ =0x06000248
	adds r3, r0, r1
	adds r2, #3
	strh r2, [r3]
	b _080642CC
	.align 2, 0
_08064258: .4byte 0x0400000A
_0806425C: .4byte 0x0600021A
_08064260: .4byte 0x0600025A
_08064264: .4byte 0x0600021C
_08064268: .4byte 0x0600025C
_0806426C: .4byte 0x03006F74
_08064270: .4byte 0x00000231
_08064274: .4byte 0x084C21BC
_08064278: .4byte 0x06003F80
_0806427C: .4byte 0x06000206
_08064280: .4byte 0x06000208
_08064284: .4byte 0x06000246
_08064288: .4byte 0x06000248
_0806428C:
	cmp r0, #7
	bgt _080642A4
	ldr r2, _080642A0 @ =0x03002C30
	movs r4, #0x3c
	ldrsh r1, [r3, r4]
	lsls r1, r1, #3
	movs r0, #0x40
	subs r0, r0, r1
	strb r0, [r2, #8]
	b _080642AC
	.align 2, 0
_080642A0: .4byte 0x03002C30
_080642A4:
	ldr r1, _080642DC @ =0x03002C30
	movs r0, #1
	strb r0, [r1, #8]
	adds r2, r1, #0
_080642AC:
	ldr r0, _080642E0 @ =0x03006F74
	ldr r1, [r0]
	movs r5, #0x3c
	ldrsh r0, [r1, r5]
	cmp r0, #1
	ble _080642CC
	lsls r0, r0, #2
	adds r0, #0x38
	strb r0, [r2, #9]
	movs r4, #0x3c
	ldrsh r1, [r1, r4]
	subs r1, #2
	lsls r1, r1, #3
	movs r0, #0x38
	subs r0, r0, r1
	strh r0, [r2, #4]
_080642CC:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080642DC: .4byte 0x03002C30
_080642E0: .4byte 0x03006F74
	.syntax divided
