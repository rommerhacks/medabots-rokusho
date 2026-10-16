	.syntax unified

	thumb_func_start sub_0802B4D8
sub_0802B4D8: @ 0x0802B4D8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r5, #0
	ldr r4, _0802B51C @ =0x03001800
	mov sb, r4
	movs r0, #0x60
	adds r0, r0, r4
	mov r8, r0
	movs r6, #5
	movs r7, #0
_0802B4F0:
	mov r0, sb
	adds r0, #0xd2
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802B580
	bl rng_next_080424B8
	adds r1, r4, #0
	adds r1, #0xd6
	adds r4, r7, r1
	movs r1, #7
	ands r0, r1
	strh r0, [r4]
	ldrh r0, [r4]
	cmp r0, #1
	beq _0802B534
	cmp r0, #1
	bgt _0802B520
	cmp r0, #0
	beq _0802B52A
	b _0802B55A
	.align 2, 0
_0802B51C: .4byte 0x03001800
_0802B520:
	cmp r0, #2
	beq _0802B53E
	cmp r0, #3
	beq _0802B548
	b _0802B55A
_0802B52A:
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r0, r5
	movs r1, #0xd
	b _0802B550
_0802B534:
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r0, r5
	movs r1, #0x11
	b _0802B550
_0802B53E:
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r0, r5
	movs r1, #0x13
	b _0802B550
_0802B548:
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r0, r5
	movs r1, #0x10
_0802B550:
	bl sub_08036D64
	cmp r0, #0
	beq _0802B55A
	strh r6, [r4]
_0802B55A:
	ldr r0, _0802B5A4 @ =0x03002C30
	adds r1, r5, #0
	adds r1, #0x21
	lsls r1, r1, #6
	adds r1, r1, r0
	mov r3, sb
	adds r3, #0xd6
	adds r2, r7, r3
	movs r4, #0xde
	lsls r4, r4, #7
	adds r0, r4, #0
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r2, #0
	strh r0, [r1, #6]
	adds r1, #0x23
	strb r2, [r1]
	adds r4, r3, #0
	subs r4, #0xd6
_0802B580:
	adds r7, #2
	adds r5, #1
	cmp r5, #2
	bls _0802B4F0
	movs r0, #0x5b
	bl play_sound_effect
	ldr r1, _0802B5A8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802B5A4: .4byte 0x03002C30
_0802B5A8: .4byte 0x03001800
	.syntax divided
