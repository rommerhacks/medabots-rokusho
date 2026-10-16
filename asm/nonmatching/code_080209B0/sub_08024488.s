	.syntax unified

	thumb_func_start sub_08024488
sub_08024488: @ 0x08024488
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r3, #0
	ldr r0, _0802451C @ =0x03001800
	mov sb, r0
	ldr r7, _08024520 @ =0x083ADEE0
	mov r8, r7
	ldr r0, _08024524 @ =0x03000440
	mov sl, r0
	ldr r4, _08024528 @ =0x03002C30
	movs r7, #0
	mov ip, r7
	mov r5, sb
	adds r5, #0x88
	ldr r0, _0802452C @ =0x000009A4
	adds r2, r4, r0
	movs r7, #0x98
	lsls r7, r7, #4
	adds r1, r4, r7
	ldr r6, _08024530 @ =0x00004D01
_080244B6:
	ldr r0, _08024534 @ =0xFFFFC404
	strh r0, [r1]
	mov r7, ip
	strb r7, [r1, #0x1c]
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r7, #0xb4
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r4
	ldrh r0, [r0, #2]
	strh r0, [r1, #2]
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, r0, r4
	ldrh r0, [r0, #4]
	adds r0, #4
	strh r0, [r1, #4]
	movs r0, #7
	strb r0, [r1, #0xa]
	movs r0, #0xf0
	strb r0, [r1, #0xb]
	movs r0, #6
	strb r0, [r2]
	mov r7, r8
	adds r0, r3, r7
	ldrb r0, [r0]
	strb r0, [r2, #1]
	strh r6, [r1, #6]
	adds r2, #0x40
	adds r1, #0x40
	adds r3, #1
	cmp r3, #3
	bls _080244B6
	movs r1, #0
	mov r0, sl
	adds r0, #0x84
	strb r1, [r0]
	mov r1, sb
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802451C: .4byte 0x03001800
_08024520: .4byte 0x083ADEE0
_08024524: .4byte 0x03000440
_08024528: .4byte 0x03002C30
_0802452C: .4byte 0x000009A4
_08024530: .4byte 0x00004D01
_08024534: .4byte 0xFFFFC404
	.syntax divided
