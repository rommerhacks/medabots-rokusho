	.syntax unified

	thumb_func_start sub_0802E7A0
sub_0802E7A0: @ 0x0802E7A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r3, #0
	ldr r5, _0802E814 @ =0x03001800
	movs r0, #0xd2
	adds r0, r0, r5
	mov r8, r0
	ldr r4, _0802E818 @ =0x03002C30
	movs r7, #0x87
	adds r7, r7, r5
	mov ip, r7
	movs r6, #0
	ldr r0, _0802E81C @ =0x000002A3
	adds r1, r4, r0
	movs r7, #0xac
	lsls r7, r7, #2
	adds r2, r4, r7
_0802E7C4:
	mov r7, r8
	adds r0, r3, r7
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E7F6
	mov r7, ip
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r4
	ldrh r0, [r0, #2]
	strh r0, [r2]
	mov r7, ip
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r4
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r2, #2]
	strb r6, [r1]
_0802E7F6:
	adds r1, #0x40
	adds r2, #0x40
	adds r3, #1
	cmp r3, #2
	bls _0802E7C4
	adds r1, r5, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802E814: .4byte 0x03001800
_0802E818: .4byte 0x03002C30
_0802E81C: .4byte 0x000002A3
	.syntax divided
