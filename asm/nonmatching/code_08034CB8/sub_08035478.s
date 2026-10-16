	.syntax unified

	thumb_func_start sub_08035478
	.global sub_08035478
sub_08035478: @ 0x08035478
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	cmp r0, #2
	bhi _080354CC
	movs r5, #0xff
	movs r2, #5
	movs r6, #5
	ldr r1, _080354C0 @ =0x03000590
	mov ip, r1
	lsls r0, r0, #8
	mov r8, r0
	ldr r0, _080354C4 @ =0x03002C30
	movs r3, #0xe2
	lsls r3, r3, #5
	adds r1, r0, r3
	movs r3, #0xa8
	lsls r3, r3, #3
	add r3, ip
	ldr r4, _080354C8 @ =0xFFFFFF00
_080354A0:
	ldrb r0, [r3]
	cmp r0, #0
	beq _080354B2
	movs r7, #2
	ldrsh r0, [r1, r7]
	cmp r0, r5
	bhs _080354B2
	adds r5, r0, #0
	adds r6, r2, #0
_080354B2:
	adds r1, r1, r4
	adds r3, r3, r4
	subs r2, #1
	cmp r2, #2
	bgt _080354A0
	b _08035506
	.align 2, 0
_080354C0: .4byte 0x03000590
_080354C4: .4byte 0x03002C30
_080354C8: .4byte 0xFFFFFF00
_080354CC:
	movs r5, #0
	movs r2, #2
	movs r6, #2
	ldr r1, _0803551C @ =0x03000590
	mov ip, r1
	lsls r0, r0, #8
	mov r8, r0
	ldr r0, _08035520 @ =0x03002C30
	movs r3, #0xca
	lsls r3, r3, #5
	adds r1, r0, r3
	movs r3, #0x90
	lsls r3, r3, #2
	add r3, ip
	ldr r4, _08035524 @ =0xFFFFFF00
_080354EA:
	ldrb r0, [r3]
	cmp r0, #0
	beq _080354FC
	movs r7, #2
	ldrsh r0, [r1, r7]
	cmp r0, r5
	bls _080354FC
	adds r5, r0, #0
	adds r6, r2, #0
_080354FC:
	adds r1, r1, r4
	adds r3, r3, r4
	subs r2, #1
	cmp r2, #0
	bge _080354EA
_08035506:
	mov r0, r8
	add r0, ip
	adds r1, r6, #1
	adds r0, #0xe0
	strb r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803551C: .4byte 0x03000590
_08035520: .4byte 0x03002C30
_08035524: .4byte 0xFFFFFF00
	.syntax divided
