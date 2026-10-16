	.syntax unified

	thumb_func_start sprite_move_toward_target
	.global sprite_move_toward_target
sprite_move_toward_target: @ 0x0803526C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	ldr r3, _080352C0 @ =0x03002C30
	lsls r0, r5, #6
	adds r4, r0, r3
	movs r0, #0x25
	adds r0, r0, r4
	mov ip, r0
	ldr r2, _080352C4 @ =0x083AF210
	ldrh r0, [r4, #0x30]
	adds r0, r0, r2
	ldrb r0, [r0]
	mov r2, ip
	ldrb r2, [r2]
	adds r0, r0, r2
	mov r7, ip
	strb r0, [r7]
	ldrb r2, [r7]
	movs r0, #3
	ands r0, r2
	strb r0, [r7]
	lsrs r2, r2, #2
	ldrh r0, [r4, #4]
	adds r2, r2, r0
	movs r0, #0xff
	ands r2, r0
	strh r2, [r4, #4]
	lsrs r7, r1, #0x10
	asrs r1, r1, #0x10
	cmp r2, r1
	blt _080352C8
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	bgt _080352C8
	strh r7, [r4, #4]
	movs r0, #1
	b _080352E6
	.align 2, 0
_080352C0: .4byte 0x03002C30
_080352C4: .4byte 0x083AF210
_080352C8:
	lsls r0, r5, #6
	adds r3, r0, r3
	adds r0, r3, #0
	adds r0, #0x24
	ldrb r1, [r0]
	ldrh r0, [r3, #0x30]
	adds r0, r0, r1
	strh r0, [r3, #0x30]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	bls _080352E4
	movs r0, #0xff
	strh r0, [r3, #0x30]
_080352E4:
	movs r0, #0
_080352E6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
