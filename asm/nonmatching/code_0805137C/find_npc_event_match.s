	.syntax unified

	thumb_func_start find_npc_event_match
	.global find_npc_event_match
find_npc_event_match: @ 0x080523B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r5, #0
	ldr r2, _08052454 @ =0x03005DBC
	movs r4, #0
	ldr r0, _08052458 @ =0xFFFFFA24
	adds r0, r0, r2
	mov ip, r0
	mov r3, ip
	ldr r0, _0805245C @ =0x00000C56
	add r0, ip
	ldrb r0, [r0]
	mov r8, r0
	movs r6, #1
	ldr r1, _08052460 @ =0x00000C57
	add r1, ip
	mov sl, r1
	ldr r7, _08052464 @ =0x03002C30
	mov sb, r7
_080523E0:
	ldrb r0, [r2]
	cmp r0, r8
	bne _08052434
	ldrb r0, [r2, #1]
	mov r1, sl
	ldrb r1, [r1]
	cmp r0, r1
	bne _08052434
	ldrh r1, [r2, #2]
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r0, r1
	lsrs r0, r0, #0xc
	cmp r0, #8
	bne _08052434
	ldr r5, _08052468 @ =0x00000C88
	adds r0, r3, r5
	strb r6, [r0]
	ldrh r0, [r2, #2]
	ldr r1, _0805246C @ =0x00000FFF
	ands r1, r0
	ldr r7, _08052470 @ =0x00000C8E
	adds r0, r3, r7
	strh r1, [r0]
	adds r5, #8
	adds r0, r3, r5
	strh r1, [r0]
	subs r7, #5
	adds r0, r3, r7
	movs r1, #0
	strb r1, [r0]
	subs r5, #6
	adds r0, r3, r5
	movs r7, #0
	strh r7, [r0]
	ldr r1, _08052474 @ =0x00000CB4
	adds r0, r3, r1
	strb r4, [r0]
	ldr r0, _08052478 @ =0x00000BE5
	add r0, sb
	strb r6, [r0]
	movs r5, #1
_08052434:
	adds r2, #8
	cmp r5, #0
	bne _08052440
	adds r4, #1
	cmp r4, #0x3f
	ble _080523E0
_08052440:
	ldr r0, _08052468 @ =0x00000C88
	add r0, ip
	ldrb r0, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08052454: .4byte 0x03005DBC
_08052458: .4byte 0xFFFFFA24
_0805245C: .4byte 0x00000C56
_08052460: .4byte 0x00000C57
_08052464: .4byte 0x03002C30
_08052468: .4byte 0x00000C88
_0805246C: .4byte 0x00000FFF
_08052470: .4byte 0x00000C8E
_08052474: .4byte 0x00000CB4
_08052478: .4byte 0x00000BE5
	.syntax divided
