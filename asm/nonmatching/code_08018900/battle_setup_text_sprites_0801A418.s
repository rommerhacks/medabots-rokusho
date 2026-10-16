	.syntax unified

	thumb_func_start battle_setup_text_sprites_0801A418
	.global battle_setup_text_sprites_0801A418
battle_setup_text_sprites_0801A418: @ 0x0801A418
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov sl, r2
	movs r5, #0
	ldr r0, _0801A4A0 @ =0x03002C30
	mov r8, r0
	lsls r1, r1, #2
	str r1, [sp]
	movs r1, #0
	mov ip, r1
	ldr r0, [sp]
	adds r0, #0x5d
	lsls r0, r0, #6
	mov sb, r0
	movs r4, #0
_0801A440:
	adds r1, r6, r5
	ldrb r0, [r1]
	cmp r0, #0xfe
	beq _0801A4E0
	ldr r0, [sp]
	add r0, sl
	adds r0, r0, r5
	lsls r0, r0, #6
	mov r2, r8
	adds r3, r0, r2
	ldr r7, _0801A4A4 @ =0xFFFFC224
	strh r7, [r3]
	mov r0, ip
	strb r0, [r3, #0x1c]
	mov r2, sb
	add r2, r8
	ldrh r0, [r2, #4]
	adds r0, #4
	strh r0, [r3, #4]
	movs r0, #0x90
	strb r0, [r3, #0xb]
	ldrb r0, [r1]
	movs r7, #0xa2
	lsls r7, r7, #7
	adds r1, r7, #0
	adds r0, r0, r1
	strh r0, [r3, #6]
	lsls r1, r5, #2
	adds r0, r3, #0
	adds r0, #0x20
	strb r1, [r0]
	adds r0, #1
	mov r1, ip
	strb r1, [r0]
	movs r0, #0x40
	strb r0, [r3, #9]
	strb r0, [r3, #8]
	movs r0, #0xc
	strb r0, [r3, #0xa]
	ldrb r0, [r6, #6]
	cmp r0, #2
	beq _0801A4B6
	cmp r0, #2
	bgt _0801A4A8
	cmp r0, #1
	beq _0801A4B2
	b _0801A4D8
	.align 2, 0
_0801A4A0: .4byte 0x03002C30
_0801A4A4: .4byte 0xFFFFC224
_0801A4A8:
	cmp r0, #3
	beq _0801A4C0
	cmp r0, #4
	beq _0801A4CC
	b _0801A4D8
_0801A4B2:
	ldrh r0, [r2, #2]
	b _0801A4D4
_0801A4B6:
	ldr r7, _0801A4BC @ =0x0000FFFC
	b _0801A4CE
	.align 2, 0
_0801A4BC: .4byte 0x0000FFFC
_0801A4C0:
	ldr r1, _0801A4C8 @ =0x0000FFF8
	adds r0, r1, #0
	b _0801A4D0
	.align 2, 0
_0801A4C8: .4byte 0x0000FFF8
_0801A4CC:
	ldr r7, _0801A4F0 @ =0x0000FFF4
_0801A4CE:
	adds r0, r7, #0
_0801A4D0:
	ldrh r2, [r2, #2]
	adds r0, r0, r2
_0801A4D4:
	adds r0, r0, r4
	strh r0, [r3, #2]
_0801A4D8:
	adds r4, #8
	adds r5, #1
	cmp r5, #4
	bls _0801A440
_0801A4E0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A4F0: .4byte 0x0000FFF4
	.syntax divided
