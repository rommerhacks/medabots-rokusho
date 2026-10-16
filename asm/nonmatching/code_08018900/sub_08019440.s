	.syntax unified

	thumb_func_start sub_08019440
	.global sub_08019440
sub_08019440: @ 0x08019440
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	ldr r1, _080194A4 @ =0x03000590
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
	bhi _080194D6
	adds r0, r3, #0
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080194AC
	ldr r0, _080194A8 @ =0x03002C30
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
	ble _08019534
	movs r0, #0x68
	b _0801952A
	.align 2, 0
_080194A4: .4byte 0x03000590
_080194A8: .4byte 0x03002C30
_080194AC:
	ldr r0, _080194CC @ =0x03002C30
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
	bgt _080194D0
	movs r0, #0x28
	b _0801952A
	.align 2, 0
_080194CC: .4byte 0x03002C30
_080194D0:
	ldrh r0, [r1, #2]
	subs r0, r0, r2
	b _08019538
_080194D6:
	adds r0, r3, #0
	adds r0, #0xbd
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0801950E
	ldr r0, _08019504 @ =0x03002C30
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
	bgt _08019508
	movs r0, #0x88
	b _0801952A
	.align 2, 0
_08019504: .4byte 0x03002C30
_08019508:
	ldrh r0, [r1, #2]
	subs r0, r0, r2
	b _08019538
_0801950E:
	ldr r0, _08019530 @ =0x03002C30
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
	ble _08019534
	movs r0, #0xc8
_0801952A:
	strh r0, [r1, #2]
	movs r5, #1
	b _0801953A
	.align 2, 0
_08019530: .4byte 0x03002C30
_08019534:
	ldrh r0, [r1, #2]
	adds r0, r0, r2
_08019538:
	strh r0, [r1, #2]
_0801953A:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
