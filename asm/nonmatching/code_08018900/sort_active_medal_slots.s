	.syntax unified

	thumb_func_start sort_active_medal_slots
	.global sort_active_medal_slots
sort_active_medal_slots: @ 0x0801A5D8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r0, #5
	mov r8, r0
_0801A5E4:
	movs r1, #0
	movs r3, #1
	rsbs r3, r3, #0
	add r3, r8
	mov sb, r3
	cmp r1, r8
	bhs _0801A628
	ldr r0, _0801A63C @ =0x03001845
	mov ip, r0
_0801A5F6:
	lsls r2, r1, #1
	adds r0, r2, #1
	mov r3, ip
	adds r6, r0, r3
	adds r7, r1, #1
	lsls r1, r7, #1
	adds r0, r1, #1
	adds r5, r0, r3
	ldrb r0, [r6]
	ldrb r3, [r5]
	cmp r0, r3
	bhs _0801A622
	add r1, ip
	ldrb r3, [r1]
	ldrb r4, [r5]
	add r2, ip
	ldrb r0, [r2]
	strb r0, [r1]
	ldrb r0, [r6]
	strb r0, [r5]
	strb r3, [r2]
	strb r4, [r6]
_0801A622:
	adds r1, r7, #0
	cmp r1, r8
	blo _0801A5F6
_0801A628:
	mov r8, sb
	mov r0, r8
	cmp r0, #0
	bne _0801A5E4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A63C: .4byte 0x03001845
	.syntax divided
