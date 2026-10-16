	.syntax unified

	thumb_func_start update_sprite_deceleration
	.global update_sprite_deceleration
update_sprite_deceleration: @ 0x080352EC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r4, _08035340 @ =0x03002C30
	lsls r0, r7, #6
	adds r5, r0, r4
	movs r0, #0x25
	adds r0, r0, r5
	mov ip, r0
	ldr r3, _08035344 @ =0x083AF210
	ldrh r2, [r5, #0x30]
	movs r0, #0xff
	subs r0, r0, r2
	adds r0, r0, r3
	ldrb r0, [r0]
	mov r2, ip
	ldrb r2, [r2]
	adds r0, r0, r2
	mov r3, ip
	strb r0, [r3]
	ldrb r2, [r3]
	movs r0, #3
	ands r0, r2
	strb r0, [r3]
	ldrh r0, [r5, #4]
	lsrs r2, r2, #2
	subs r0, r0, r2
	strh r0, [r5, #4]
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r2, r0, #0x10
	cmp r0, r1
	blt _08035348
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	bgt _08035348
	strh r6, [r5, #4]
	movs r0, #1
	b _08035366
	.align 2, 0
_08035340: .4byte 0x03002C30
_08035344: .4byte 0x083AF210
_08035348:
	lsls r0, r7, #6
	adds r4, r0, r4
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r1, [r0]
	ldrh r0, [r4, #0x30]
	adds r0, r0, r1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	bls _08035364
	movs r0, #0xff
	strh r0, [r4, #0x30]
_08035364:
	movs r0, #0
_08035366:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
