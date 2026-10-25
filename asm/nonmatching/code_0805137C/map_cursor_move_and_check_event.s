	.syntax unified

	thumb_func_start map_cursor_move_and_check_event
	.global map_cursor_move_and_check_event
map_cursor_move_and_check_event: @ 0x08052238
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, _0805226C @ =0x03005DBC
	movs r1, #0
	ldr r2, _08052270 @ =0x0000067A
	adds r0, r4, r2
	ldrb r7, [r0]
	adds r2, #1
	adds r0, r4, r2
	ldrb r6, [r0]
	ldr r0, _08052274 @ =0x03002C30
	movs r2, #0xbe
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _0805228C
	cmp r0, #1
	bgt _08052278
	cmp r0, #0
	beq _08052282
	b _080522C4
	.align 2, 0
_0805226C: .4byte 0x03005DBC
_08052270: .4byte 0x0000067A
_08052274: .4byte 0x03002C30
_08052278:
	cmp r0, #2
	beq _080522A4
	cmp r0, #3
	beq _080522AE
	b _080522C4
_08052282:
	lsls r0, r6, #0x18
	cmp r0, #0
	beq _080522BE
	subs r6, #1
	b _080522C4
_0805228C:
	ldr r2, _080522A0 @ =0x00000226
	adds r0, r4, r2
	ldrh r0, [r0]
	lsrs r0, r0, #1
	subs r0, #1
	cmp r6, r0
	beq _080522BE
	adds r6, #1
	b _080522C4
	.align 2, 0
_080522A0: .4byte 0x00000226
_080522A4:
	lsls r0, r7, #0x18
	cmp r0, #0
	beq _080522BE
	subs r7, #1
	b _080522C4
_080522AE:
	movs r2, #0x89
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	lsrs r0, r0, #1
	subs r0, #1
	cmp r7, r0
	bne _080522C2
_080522BE:
	movs r1, #1
	b _080522C4
_080522C2:
	adds r7, #1
_080522C4:
	cmp r1, #1
	bne _080522CC
	movs r0, #0
	b _08052384
_080522CC:
	movs r0, #0
	mov r8, r0
	movs r3, #0
	ldr r5, _08052300 @ =0x030057E0
	movs r1, #1
	mov sl, r1
	movs r2, #0xf0
	lsls r2, r2, #8
	mov sb, r2
_080522DE:
	ldrb r0, [r4]
	cmp r0, r7
	bne _08052374
	ldrb r0, [r4, #1]
	cmp r0, r6
	bne _08052374
	ldrh r0, [r4, #2]
	mov r1, sb
	ands r0, r1
	lsrs r0, r0, #0xc
	cmp r0, #4
	beq _08052308
	cmp r0, #4
	bgt _08052304
	cmp r0, #0
	beq _08052308
	b _08052346
	.align 2, 0
_08052300: .4byte 0x030057E0
_08052304:
	cmp r0, #6
	bne _08052346
_08052308:
	ldr r2, _08052394 @ =0x00000C88
	adds r0, r5, r2
	mov r1, sl
	strb r1, [r0]
	ldrh r1, [r4, #2]
	ldr r2, _08052398 @ =0x00000FFF
	adds r0, r2, #0
	ands r1, r0
	ldr r2, _0805239C @ =0x00000C8E
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	ldr r1, _080523A0 @ =0x00000C89
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	adds r1, #1
	adds r0, r5, r1
	movs r2, #0
	strh r2, [r0]
	ldr r0, _080523A4 @ =0x03006494
	strb r3, [r0]
	ldr r0, _080523A8 @ =0x03002C30
	subs r1, #0xa5
	adds r0, r0, r1
	mov r2, sl
	strb r2, [r0]
	movs r0, #1
	mov r8, r0
_08052346:
	ldrh r0, [r4, #2]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	bne _08052374
	ldrb r0, [r4, #4]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #3
	movs r2, #0xc4
	lsls r2, r2, #0x16
	adds r0, r0, r2
	lsrs r0, r0, #0x18
	ldr r1, _080523AC @ =0x083D2903
	mov ip, r1
	ldr r2, _080523B0 @ =0x03003810
	ldrb r1, [r2]
	add r1, ip
	ldrb r1, [r1]
	adds r2, r4, #0
	str r3, [sp]
	bl set_sprite_anim_and_store
	ldr r3, [sp]
_08052374:
	adds r4, #8
	mov r0, r8
	cmp r0, #1
	beq _08052382
	adds r3, #1
	cmp r3, #0x3f
	ble _080522DE
_08052382:
	mov r0, r8
_08052384:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08052394: .4byte 0x00000C88
_08052398: .4byte 0x00000FFF
_0805239C: .4byte 0x00000C8E
_080523A0: .4byte 0x00000C89
_080523A4: .4byte 0x03006494
_080523A8: .4byte 0x03002C30
_080523AC: .4byte gUnk_083D2903
_080523B0: .4byte 0x03003810
	.syntax divided
