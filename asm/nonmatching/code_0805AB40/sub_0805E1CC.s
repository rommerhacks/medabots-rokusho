	.syntax unified

	thumb_func_start sub_0805E1CC
sub_0805E1CC: @ 0x0805E1CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	ldr r2, _0805E264 @ =0x0400000A
	ldrh r0, [r2, #0]
	lsrs r0, r0, #8
	movs r4, #0x1f
	ands r0, r4
	lsls r0, r0, #0xb
	ldr r1, _0805E268 @ =0x060000CA
	adds r3, r0, r1
	ldrh r0, [r2, #0]
	lsrs r0, r0, #8
	ands r0, r4
	lsls r0, r0, #0xb
	adds r1, #0x40
	adds r7, r0, r1
	mov sl, r4
	movs r0, #9
	mov r9, r0
_0805E1FC:
	mov r1, r8
	ldrb r5, [r1, #0]
	adds r0, r5, #0
	cmp r0, #0
	beq _0805E274
	subs r5, #1
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r2, _0805E264 @ =0x0400000A
	ldrh r4, [r2, #0]
	lsrs r4, r4, #8
	mov r0, sl
	ands r4, r0
	adds r0, r5, #0
	movs r1, #0x1a
	str r3, [sp, #0]
	bl sub_0807CDD0
	adds r6, r0, #0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	adds r0, r5, #0
	movs r1, #0x1a
	bl sub_0807CD58
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0xb
	lsls r6, r6, #1
	adds r4, r4, r6
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #6
	adds r4, r4, r1
	ldr r2, _0805E26C @ =0x06000204
	adds r4, r4, r2
	ldrh r0, [r4, #0]
	ldr r3, [sp, #0]
	strh r0, [r3, #0]
	adds r3, #2
	ldr r2, _0805E264 @ =0x0400000A
	ldrh r0, [r2, #0]
	lsrs r0, r0, #8
	mov r2, sl
	ands r0, r2
	lsls r0, r0, #0xb
	adds r0, r0, r6
	adds r0, r0, r1
	ldr r1, _0805E270 @ =0x06000244
	adds r0, r0, r1
	ldrh r0, [r0, #0]
	b _0805E278
_0805E264: .4byte 0x0400000A
_0805E268: .4byte 0x060000CA
_0805E26C: .4byte 0x06000204
_0805E270: .4byte 0x06000244
_0805E274:
	strh r0, [r3, #0]
	adds r3, #2
_0805E278:
	strh r0, [r7, #0]
	adds r7, #2
	movs r2, #1
	add r8, r2
	movs r0, #1
	rsbs r0, r0, #0
	add r9, r0
	mov r1, r9
	cmp r1, #0
	bge _0805E1FC
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
