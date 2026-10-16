	.syntax unified

	thumb_func_start render_battle_text_sprites
	.global render_battle_text_sprites
render_battle_text_sprites: @ 0x0801A33C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov sl, r2
	movs r5, #0
	ldr r0, _0801A3C4 @ =0x03002C30
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
_0801A364:
	adds r1, r6, r5
	ldrb r0, [r1]
	cmp r0, #0xfe
	beq _0801A404
	ldr r0, [sp]
	add r0, sl
	adds r0, r0, r5
	lsls r0, r0, #6
	mov r2, r8
	adds r3, r0, r2
	ldr r7, _0801A3C8 @ =0xFFFFC224
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
	movs r7, #0x80
	lsls r7, r7, #4
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
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r3, #0xa]
	ldrb r0, [r6, #6]
	cmp r0, #2
	beq _0801A3DA
	cmp r0, #2
	bgt _0801A3CC
	cmp r0, #1
	beq _0801A3D6
	b _0801A3FC
	.align 2, 0
_0801A3C4: .4byte 0x03002C30
_0801A3C8: .4byte 0xFFFFC224
_0801A3CC:
	cmp r0, #3
	beq _0801A3E4
	cmp r0, #4
	beq _0801A3F0
	b _0801A3FC
_0801A3D6:
	ldrh r0, [r2, #2]
	b _0801A3F8
_0801A3DA:
	ldr r7, _0801A3E0 @ =0x0000FFFC
	b _0801A3F2
	.align 2, 0
_0801A3E0: .4byte 0x0000FFFC
_0801A3E4:
	ldr r1, _0801A3EC @ =0x0000FFF8
	adds r0, r1, #0
	b _0801A3F4
	.align 2, 0
_0801A3EC: .4byte 0x0000FFF8
_0801A3F0:
	ldr r7, _0801A414 @ =0x0000FFF4
_0801A3F2:
	adds r0, r7, #0
_0801A3F4:
	ldrh r2, [r2, #2]
	adds r0, r0, r2
_0801A3F8:
	adds r0, r0, r4
	strh r0, [r3, #2]
_0801A3FC:
	adds r4, #8
	adds r5, #1
	cmp r5, #4
	bls _0801A364
_0801A404:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A414: .4byte 0x0000FFF4
	.syntax divided
