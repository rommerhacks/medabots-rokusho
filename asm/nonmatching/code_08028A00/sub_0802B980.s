	.syntax unified

	thumb_func_start sub_0802B980
sub_0802B980: @ 0x0802B980
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r2, #0
	movs r7, #0
	movs r4, #0
	ldr r6, _0802B9EC @ =0x03001800
	ldr r0, _0802B9F0 @ =0x083B611C
	mov sl, r0
	movs r1, #0x60
	adds r1, r1, r6
	mov sb, r1
	ldr r3, _0802B9F4 @ =0x03002C30
	mov r8, r3
	movs r5, #0x84
	lsls r5, r5, #4
	add r5, r8
_0802B9A8:
	adds r0, r6, #0
	adds r0, #0xd2
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BA02
	adds r7, #1
	mov r1, sl
	ldr r0, [r1]
	adds r1, r4, #0
	adds r1, #0x21
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r2, [sp]
	bl process_sprite_anim_commands
	movs r3, #4
	ldrsh r1, [r5, r3]
	mov r3, sb
	ldrb r0, [r3]
	adds r0, r0, r4
	lsls r0, r0, #8
	movs r3, #0xba
	lsls r3, r3, #5
	adds r0, r0, r3
	add r0, r8
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r0, #4
	ldr r2, [sp]
	cmp r1, r0
	bne _0802B9F8
	adds r2, #1
	b _0802BA02
	.align 2, 0
_0802B9EC: .4byte 0x03001800
_0802B9F0: .4byte 0x083B611C
_0802B9F4: .4byte 0x03002C30
_0802B9F8:
	ldrh r0, [r5, #4]
	adds r0, #1
	movs r1, #0xff
	ands r0, r1
	strh r0, [r5, #4]
_0802BA02:
	adds r5, #0x40
	adds r4, #1
	cmp r4, #2
	bls _0802B9A8
	cmp r2, r7
	bne _0802BA18
	ldr r1, _0802BA28 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802BA18:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802BA28: .4byte 0x03001800
	.syntax divided
