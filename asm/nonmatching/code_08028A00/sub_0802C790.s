	.syntax unified

	thumb_func_start sub_0802C790
sub_0802C790: @ 0x0802C790
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r6, #0
	bl sub_0803836C
	ldr r4, _0802C800 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r0, _0802C804 @ =0x03000590
	mov r8, r0
	adds r7, r4, #0
	adds r7, #0xd2
_0802C7B8:
	adds r0, r4, #0
	adds r0, #0x60
	ldrb r0, [r0]
	adds r2, r0, r5
	lsls r0, r2, #8
	mov r3, r8
	adds r1, r0, r3
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C7EC
	adds r0, r1, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802C7EC
	adds r0, r2, #0
	bl sub_080331F8
	cmp r0, #0
	beq _0802C7EC
	adds r1, r5, r7
	movs r0, #1
	strb r0, [r1]
	movs r6, #1
_0802C7EC:
	adds r5, #1
	cmp r5, #2
	bls _0802C7B8
	cmp r6, #0
	bne _0802C808
	ldr r1, _0802C800 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _0802C810
	.align 2, 0
_0802C800: .4byte 0x03001800
_0802C804: .4byte 0x03000590
_0802C808:
	ldr r1, _0802C81C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #3
_0802C810:
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C81C: .4byte 0x03001800
	.syntax divided
