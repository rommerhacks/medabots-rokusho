	.syntax unified

	thumb_func_start battle_setup_text_sprites_0801A4F4
	.global battle_setup_text_sprites_0801A4F4
battle_setup_text_sprites_0801A4F4: @ 0x0801A4F4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r5, #0
	ldr r4, _0801A56C @ =0x03002C30
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r0, #0
	mov ip, r0
	ldr r0, _0801A570 @ =0x0000C224
	mov sb, r0
	adds r6, r3, #0
	movs r7, #0x40
	lsls r2, r2, #6
	adds r0, r4, #2
	adds r3, r2, r0
	adds r2, r2, r4
_0801A51A:
	mov r4, r8
	adds r1, r4, r5
	ldrb r0, [r1]
	cmp r0, #0xfe
	beq _0801A560
	mov r0, sb
	strh r0, [r2]
	mov r4, ip
	strb r4, [r3, #0x1a]
	mov r0, sp
	ldrh r0, [r0, #0x1c]
	strh r0, [r3, #2]
	strh r6, [r3]
	movs r0, #0x90
	strb r0, [r3, #9]
	ldrb r0, [r1]
	movs r4, #0xa2
	lsls r4, r4, #7
	adds r1, r4, #0
	adds r0, r0, r1
	strh r0, [r3, #4]
	lsls r0, r5, #2
	strb r0, [r3, #0x1e]
	mov r0, ip
	strb r0, [r3, #0x1f]
	strb r7, [r3, #7]
	strb r7, [r3, #6]
	movs r0, #0xc
	strb r0, [r3, #8]
	adds r6, #8
	adds r3, #0x40
	adds r2, #0x40
	adds r5, #1
	cmp r5, #4
	bls _0801A51A
_0801A560:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A56C: .4byte 0x03002C30
_0801A570: .4byte 0x0000C224
	.syntax divided
