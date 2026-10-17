	.syntax unified

	thumb_func_start sub_08023FB8
sub_08023FB8: @ 0x08023FB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08024070 @ =0x03000590
	ldr r7, _08024074 @ =0x03001800
	adds r5, r7, #0
	adds r5, #0x88
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r0, #0xc9
	movs r1, #0
	mov sl, r1
	movs r2, #0x29
	mov sb, r2
	mov r1, sb
	strb r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r0, #0xca
	mov r2, sl
	strb r2, [r0]
	movs r0, #0xe8
	adds r0, r0, r7
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_08036E54
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r1, r1, r4
	adds r1, #0xcb
	strb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xec
	movs r2, #0
	ldrsh r0, [r6, r2]
	bl sub_08036E54
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r1, r1, r4
	adds r1, #0xcc
	strb r0, [r1]
	subs r5, #1
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r0, #0xc4
	mov r1, sb
	strb r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r0, #0xc5
	mov r2, sl
	strb r2, [r0]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl sub_08036E54
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r1, r1, r4
	adds r1, #0xc6
	strb r0, [r1]
	movs r1, #0
	ldrsh r0, [r6, r1]
	bl sub_08036E54
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r1, r1, r4
	adds r1, #0xc7
	strb r0, [r1]
	adds r1, r7, #0
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
_08024070: .4byte 0x03000590
_08024074: .4byte 0x03001800
	.syntax divided
