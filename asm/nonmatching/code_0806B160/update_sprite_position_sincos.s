	.syntax unified

	thumb_func_start update_sprite_position_sincos
update_sprite_position_sincos: @ 0x0806B160
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, _0806B1E0 @ =0x03002C30
	mov sb, r0
	mov r1, r8
	lsls r0, r1, #6
	mov r2, sb
	adds r7, r0, r2
	ldr r3, [r7, #0xc]
	asrs r1, r3, #8
	ldr r4, _0806B1E4 @ =0x083D69A0
	movs r5, #0x23
	adds r5, r5, r7
	mov ip, r5
	ldrb r0, [r5]
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r1, r1, r0
	lsls r1, r1, #8
	adds r6, r2, #0
	ands r6, r3
	orrs r6, r1
	str r6, [r7, #0xc]
	ldr r3, [r7, #0x10]
	asrs r1, r3, #8
	mov r5, ip
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r1, r1, r0
	lsls r1, r1, #8
	ands r2, r3
	orrs r2, r1
	str r2, [r7, #0x10]
	mov r5, sb
	mov r0, r8
	cmp r0, #0xb
	bls _0806B1E8
	asrs r0, r6, #8
	cmp r0, #0
	bge _0806B1CC
	adds r0, #0xff
_0806B1CC:
	asrs r0, r0, #8
	adds r0, #0x20
	strh r0, [r7, #2]
	asrs r1, r2, #8
	cmp r1, #0
	bge _0806B1DA
	adds r1, #0xff
_0806B1DA:
	asrs r1, r1, #8
	b _0806B200
	.align 2, 0
_0806B1E0: .4byte 0x03002C30
_0806B1E4: .4byte 0x083D69A0
_0806B1E8:
	asrs r0, r6, #8
	cmp r0, #0
	bge _0806B1F0
	adds r0, #0x7f
_0806B1F0:
	asrs r0, r0, #7
	adds r0, #0x20
	strh r0, [r7, #2]
	asrs r1, r2, #8
	cmp r1, #0
	bge _0806B1FE
	adds r1, #0x7f
_0806B1FE:
	asrs r1, r1, #7
_0806B200:
	movs r0, #0x10
	subs r0, r0, r1
	strh r0, [r7, #4]
	mov r1, r8
	lsls r0, r1, #6
	adds r5, r0, r5
	ldrh r0, [r5, #0x1a]
	cmp r0, #8
	bls _0806B22E
	ldr r2, _0806B23C @ =0x083F7FF4
	ldr r0, _0806B240 @ =0x03001780
	ldr r0, [r0]
	add r0, r8
	movs r1, #0xff
	ands r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	lsrs r0, r0, #3
	strh r0, [r5, #0x1a]
	adds r1, r5, #0
	adds r1, #0x20
	movs r0, #9
	strb r0, [r1]
_0806B22E:
	movs r0, #1
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0806B23C: .4byte 0x083F7FF4
_0806B240: .4byte 0x03001780
	.syntax divided
