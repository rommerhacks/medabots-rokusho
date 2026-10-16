	.syntax unified

	thumb_func_start battle_update_action_counters
battle_update_action_counters: @ 0x0806A87C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r6, #0
	ldr r0, _0806A8F4 @ =0x08485CE3
	mov sl, r0
	ldr r0, _0806A8F8 @ =0x03006FD0
	mov sb, r0
	ldr r0, _0806A8FC @ =0x03002C30
	mov r8, r0
	ldr r0, _0806A900 @ =0x08485CC4
	mov ip, r0
	movs r5, #0
	movs r7, #0
	ldr r4, _0806A904 @ =0x03006FE0
_0806A89E:
	ldr r0, _0806A908 @ =0x03006F8C
	adds r3, r6, r0
	ldrb r0, [r3]
	cmp r0, #2
	bhi _0806A8DC
	adds r2, r0, #0
	adds r2, r2, r5
	add r2, sb
	ldr r0, _0806A90C @ =0x03006F84
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	ldrb r2, [r2]
	adds r0, r0, r2
	add r0, sl
	ldrb r1, [r0]
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	cmp r1, r0
	bgt _0806A8DC
	ldrb r0, [r3]
	adds r0, r0, r5
	add r0, ip
	ldrb r1, [r0]
	lsls r1, r1, #6
	add r1, r8
	ldrh r0, [r1, #0x1a]
	adds r0, #1
	strh r0, [r1, #0x1a]
	str r7, [r4]
_0806A8DC:
	adds r5, #3
	adds r4, #4
	adds r6, #1
	cmp r6, #2
	ble _0806A89E
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806A8F4: .4byte 0x08485CE3
_0806A8F8: .4byte 0x03006FD0
_0806A8FC: .4byte 0x03002C30
_0806A900: .4byte 0x08485CC4
_0806A904: .4byte 0x03006FE0
_0806A908: .4byte 0x03006F8C
_0806A90C: .4byte 0x03006F84
	.syntax divided
