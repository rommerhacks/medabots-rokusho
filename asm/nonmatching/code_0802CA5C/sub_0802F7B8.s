	.syntax unified

	thumb_func_start sub_0802F7B8
sub_0802F7B8: @ 0x0802F7B8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	movs r0, #0
	mov r8, r0
	movs r3, #0
	movs r5, #0
	ldr r7, _0802F858 @ =0x03001800
	movs r1, #0x60
	adds r1, r1, r7
	mov sb, r1
_0802F7D2:
	adds r0, r7, #0
	adds r0, #0xd2
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802F82C
	adds r3, #1
	adds r4, r5, #0
	adds r4, #0x21
	ldr r6, _0802F85C @ =0x03002C30
	mov r1, sb
	ldrb r0, [r1]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r6
	ldrh r2, [r0, #4]
	subs r1, r2, #4
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r2, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	adds r0, r4, #0
	str r3, [sp]
	bl sprite_move_toward_target
	ldr r3, [sp]
	cmp r0, #0
	beq _0802F82C
	lsls r0, r4, #6
	adds r2, r0, r6
	adds r0, r2, #0
	adds r0, #0x27
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r1, r2, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	add r8, r0
_0802F82C:
	adds r5, #1
	cmp r5, #2
	bls _0802F7D2
	cmp r8, r3
	bne _0802F848
	ldr r0, _0802F860 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _0802F858 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802F848:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802F858: .4byte 0x03001800
_0802F85C: .4byte 0x03002C30
_0802F860: .4byte 0x03000440
	.syntax divided
