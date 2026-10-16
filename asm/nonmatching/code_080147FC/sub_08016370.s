	.syntax unified

	thumb_func_start sub_08016370
	.global sub_08016370
sub_08016370: @ 0x08016370
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	ldr r2, _08016424 @ =0x083AD382
	lsls r1, r0, #2
	adds r0, r1, r2
	ldrb r6, [r0]
	adds r0, r1, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	mov sl, r0
	adds r0, r1, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	mov sb, r0
	adds r1, #3
	adds r1, r1, r2
	ldrb r1, [r1]
	mov r8, r1
	movs r0, #0x3c
	movs r1, #0xa
	bl clear_battle_sprite_slot
	movs r4, #0
	cmp r4, r6
	bhs _08016412
	ldr r0, _08016428 @ =0x03002C30
	movs r5, #0
	ldr r1, _0801642C @ =0x0000C404
	mov ip, r1
	movs r7, #0xf0
	lsls r7, r7, #4
	adds r3, r0, r7
	ldr r1, _08016430 @ =0x00000F0A
	adds r2, r0, r1
_080163BE:
	mov r7, ip
	strh r7, [r3]
	strb r5, [r2, #0x12]
	mov r0, sb
	strh r0, [r3, #2]
	mov r1, r8
	strh r1, [r3, #4]
	movs r0, #8
	strb r0, [r2]
	movs r0, #0x80
	strb r0, [r2, #1]
	movs r0, #3
	adds r1, r4, #0
	ands r1, r0
	ldr r7, _08016434 @ =0x00000616
	adds r0, r1, r7
	strh r0, [r3, #6]
	mov r0, sl
	strb r0, [r2, #0x1b]
	subs r0, r6, #1
	subs r0, r0, r4
	strb r0, [r2, #0x1c]
	strb r5, [r2, #0x1a]
	lsls r0, r4, #1
	strb r0, [r2, #0x1d]
	strb r5, [r2, #0x1e]
	strb r5, [r2, #0x17]
	strb r1, [r2, #0x18]
	ldr r1, [sp]
	cmp r1, #2
	bls _08016408
	ldrh r0, [r3]
	movs r7, #0x80
	lsls r7, r7, #5
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r3]
_08016408:
	adds r3, #0x40
	adds r2, #0x40
	adds r4, #1
	cmp r4, r6
	blo _080163BE
_08016412:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08016424: .4byte 0x083AD382
_08016428: .4byte 0x03002C30
_0801642C: .4byte 0x0000C404
_08016430: .4byte 0x00000F0A
_08016434: .4byte 0x00000616
	.syntax divided
