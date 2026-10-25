	.syntax unified

	thumb_func_start dispatch_jump_table_29
	.global dispatch_jump_table_29
dispatch_jump_table_29: @ 0x080483E0
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	cmp r2, #0x1c
	bls _080483EC
	b _0804862E
_080483EC:
	lsls r1, r2, #2
	ldr r2, _080483F8 @ =_080483FC
	adds r1, r1, r2
	ldr r1, [r1]
	mov pc, r1
	.align 2, 0
_080483F8: .4byte _080483FC
_080483FC: @ jump table
	.4byte _08048470 @ case 0
	.4byte _08048494 @ case 1
	.4byte _080484AC @ case 2
	.4byte _080484C4 @ case 3
	.4byte _0804851C @ case 4
	.4byte _08048544 @ case 5
	.4byte _08048544 @ case 6
	.4byte _08048544 @ case 7
	.4byte _08048544 @ case 8
	.4byte _08048544 @ case 9
	.4byte _08048470 @ case 10
	.4byte _08048560 @ case 11
	.4byte _08048470 @ case 12
	.4byte _08048560 @ case 13
	.4byte _08048560 @ case 14
	.4byte _08048560 @ case 15
	.4byte _0804862E @ case 16
	.4byte _0804862E @ case 17
	.4byte _0804862E @ case 18
	.4byte _08048544 @ case 19
	.4byte _0804862E @ case 20
	.4byte _08048560 @ case 21
	.4byte _08048560 @ case 22
	.4byte _08048590 @ case 23
	.4byte _080485B0 @ case 24
	.4byte _080485DC @ case 25
	.4byte _08048560 @ case 26
	.4byte _0804862E @ case 27
	.4byte _08048544 @ case 28
_08048470:
	ldr r1, _08048490 @ =0x030057E0
	movs r2, #0xc3
	lsls r2, r2, #4
	adds r4, r1, r2
	ldrb r1, [r4]
	cmp r1, #0xff
	bne _08048480
	b _0804862E
_08048480:
	bl sub_080483AC
	adds r2, r0, #0
	ldrb r1, [r4]
	cmp r1, r2
	bne _0804848E
	b _0804862E
_0804848E:
	b _08048574
	.align 2, 0
_08048490: .4byte 0x030057E0
_08048494:
	ldr r0, _080484A8 @ =0x030057E0
	movs r6, #0xc3
	lsls r6, r6, #4
	adds r0, r0, r6
	strb r3, [r0]
	adds r0, r3, #0
	bl sub_08047BB4
	b _0804862E
	.align 2, 0
_080484A8: .4byte 0x030057E0
_080484AC:
	ldr r0, _080484C0 @ =0x030057E0
	movs r1, #0xc3
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0
	bl sub_08047BB4
	b _0804862E
	.align 2, 0
_080484C0: .4byte 0x030057E0
_080484C4:
	ldr r4, _080484F4 @ =0x030057E0
	movs r2, #0xc3
	lsls r2, r2, #4
	adds r5, r4, r2
	ldrb r2, [r5]
	adds r1, r2, #0
	cmp r1, #0xff
	beq _080484FC
	movs r1, #0x80
	ands r1, r3
	cmp r1, #0
	bne _08048506
	movs r1, #0x7f
	adds r0, r3, #0
	ands r0, r1
	ldr r2, _080484F8 @ =0x00000C31
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r3, #0
	bl sub_08047BB4
	movs r1, #0xff
	strb r1, [r5]
	b _0804862E
	.align 2, 0
_080484F4: .4byte 0x030057E0
_080484F8: .4byte 0x00000C31
_080484FC:
	movs r1, #0x80
	ands r1, r3
	cmp r1, #0
	bne _08048506
	b _0804862E
_08048506:
	movs r1, #0x7f
	ands r3, r1
	ldr r6, _08048518 @ =0x00000C31
	adds r1, r4, r6
	strb r3, [r1]
	movs r1, #0xff
	orrs r1, r2
	strb r1, [r5]
	b _0804862E
	.align 2, 0
_08048518: .4byte 0x00000C31
_0804851C:
	ldr r0, _0804853C @ =0x030057E0
	movs r1, #0xc3
	lsls r1, r1, #4
	adds r5, r0, r1
	ldrb r4, [r5]
	movs r0, #0
	strb r0, [r5]
	bl sub_080483AC
	adds r2, r0, #0
	cmp r4, r2
	beq _08048540
	strb r2, [r5]
	bl sub_08047BB4
	b _0804862E
	.align 2, 0
_0804853C: .4byte 0x030057E0
_08048540:
	strb r2, [r5]
	b _0804862E
_08048544:
	bl sub_080483AC
	adds r2, r0, #0
	ldr r0, _0804855C @ =0x030057E0
	movs r6, #0xc3
	lsls r6, r6, #4
	adds r0, r0, r6
	strb r2, [r0]
	adds r0, r2, #0
	bl sub_08047BB4
	b _0804862E
	.align 2, 0
_0804855C: .4byte 0x030057E0
_08048560:
	ldr r1, _0804857C @ =0x030057E0
	movs r0, #0xc3
	lsls r0, r0, #4
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #0xff
	beq _08048580
	bl sub_080483AC
	adds r2, r0, #0
_08048574:
	strb r2, [r4]
	bl sub_08047BB4
	b _0804862E
	.align 2, 0
_0804857C: .4byte 0x030057E0
_08048580:
	ldr r2, _0804858C @ =0x00000C31
	adds r0, r1, r2
	ldrb r0, [r0]
	bl sub_08047BB4
	b _0804862E
	.align 2, 0
_0804858C: .4byte 0x00000C31
_08048590:
	ldr r2, _080485A8 @ =0x083D29B6
	ldr r1, _080485AC @ =0x03006D38
	ldrb r1, [r1, #1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r1, [r1]
	cmp r1, #0
	beq _0804862E
	movs r0, #0x1e
	bl sub_08047BC0
	b _0804862E
	.align 2, 0
_080485A8: .4byte gUnk_083D29B6
_080485AC: .4byte 0x03006D38
_080485B0:
	ldr r3, _080485D0 @ =0x083D29B6
	ldr r1, _080485D4 @ =0x03006D38
	ldrb r1, [r1, #1]
	lsls r2, r1, #2
	adds r1, r2, r3
	ldrb r1, [r1]
	cmp r1, #0
	beq _0804862E
	adds r0, r2, #1
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r0, _080485D8 @ =0x030057E0
	movs r6, #0xc3
	lsls r6, r6, #4
	adds r0, r0, r6
	b _0804860A
	.align 2, 0
_080485D0: .4byte gUnk_083D29B6
_080485D4: .4byte 0x03006D38
_080485D8: .4byte 0x030057E0
_080485DC:
	ldr r3, _080485F4 @ =0x083D29B6
	ldr r1, _080485F8 @ =0x03006D38
	ldrb r1, [r1, #1]
	lsls r2, r1, #2
	adds r1, r2, #2
	adds r1, r1, r3
	ldrb r1, [r1]
	cmp r1, #1
	beq _080485FC
	cmp r1, #2
	beq _08048618
	b _0804862E
	.align 2, 0
_080485F4: .4byte gUnk_083D29B6
_080485F8: .4byte 0x03006D38
_080485FC:
	adds r0, r2, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r0, _08048614 @ =0x030057E0
	movs r2, #0xc3
	lsls r2, r2, #4
	adds r0, r0, r2
_0804860A:
	strb r1, [r0]
	adds r0, r1, #0
	bl sub_08047BB4
	b _0804862E
	.align 2, 0
_08048614: .4byte 0x030057E0
_08048618:
	bl sub_080483AC
	adds r1, r0, #0
	ldr r0, _08048634 @ =0x030057E0
	movs r6, #0xc3
	lsls r6, r6, #4
	adds r0, r0, r6
	strb r1, [r0]
	adds r0, r1, #0
	bl sub_08047BB4
_0804862E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08048634: .4byte 0x030057E0
	.syntax divided
