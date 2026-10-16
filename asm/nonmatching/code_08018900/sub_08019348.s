	.syntax unified

	thumb_func_start sub_08019348
	.global sub_08019348
sub_08019348: @ 0x08019348
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080193A8 @ =0x03000590
	lsls r0, r4, #8
	adds r3, r0, r1
	adds r2, r3, #0
	adds r2, #0xd7
	ldrb r0, [r2]
	adds r0, #0x20
	adds r1, r3, #0
	adds r1, #0xbb
	ldrb r1, [r1]
	subs r0, r0, r1
	strb r0, [r2]
	ldrb r0, [r2]
	lsrs r0, r0, #4
	movs r1, #0xda
	adds r1, r1, r3
	mov ip, r1
	strb r0, [r1]
	ldrb r0, [r2]
	movs r1, #0xf
	ands r0, r1
	strb r0, [r2]
	cmp r4, #2
	bhi _080193DA
	adds r0, r3, #0
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _080193B0
	ldr r0, _080193AC @ =0x03002C30
	lsls r1, r4, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r1, r1, r2
	adds r1, r1, r0
	movs r3, #2
	ldrsh r0, [r1, r3]
	mov r3, ip
	ldrb r2, [r3]
	adds r0, r0, r2
	cmp r0, #0x68
	ble _08019434
	movs r0, #0x68
	b _08019438
	.align 2, 0
_080193A8: .4byte 0x03000590
_080193AC: .4byte 0x03002C30
_080193B0:
	ldr r0, _080193D0 @ =0x03002C30
	lsls r1, r4, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r1, r1, r2
	adds r1, r1, r0
	movs r3, #2
	ldrsh r0, [r1, r3]
	mov r3, ip
	ldrb r2, [r3]
	subs r0, r0, r2
	cmp r0, #0x27
	bgt _080193D4
	movs r0, #0x28
	b _08019438
	.align 2, 0
_080193D0: .4byte 0x03002C30
_080193D4:
	ldrh r0, [r1, #2]
	subs r0, r0, r2
	b _08019438
_080193DA:
	adds r0, r3, #0
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08019412
	ldr r0, _08019408 @ =0x03002C30
	lsls r1, r4, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r1, r1, r2
	adds r1, r1, r0
	movs r3, #2
	ldrsh r0, [r1, r3]
	mov r3, ip
	ldrb r2, [r3]
	subs r0, r0, r2
	cmp r0, #0x87
	bgt _0801940C
	movs r0, #0x88
	b _08019438
	.align 2, 0
_08019408: .4byte 0x03002C30
_0801940C:
	ldrh r0, [r1, #2]
	subs r0, r0, r2
	b _08019438
_08019412:
	ldr r0, _08019430 @ =0x03002C30
	lsls r1, r4, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r1, r1, r2
	adds r1, r1, r0
	movs r3, #2
	ldrsh r0, [r1, r3]
	mov r3, ip
	ldrb r2, [r3]
	adds r0, r0, r2
	cmp r0, #0xc8
	ble _08019434
	movs r0, #0xc8
	b _08019438
	.align 2, 0
_08019430: .4byte 0x03002C30
_08019434:
	ldrh r0, [r1, #2]
	adds r0, r0, r2
_08019438:
	strh r0, [r1, #2]
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
