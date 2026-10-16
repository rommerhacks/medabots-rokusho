	.syntax unified

	thumb_func_start sub_08016438
	.global sub_08016438
sub_08016438: @ 0x08016438
	push {r4, r5, r6, r7, lr}
	movs r1, #1
	mov ip, r1
	ldr r1, _080164A0 @ =0x083AD382
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r7, [r0]
	movs r6, #0
	cmp r6, r7
	bhs _080164EA
	ldr r0, _080164A4 @ =0x03002C30
	movs r4, #0xf0
	lsls r4, r4, #4
	adds r3, r0, r4
	ldr r1, _080164A8 @ =0x00000F21
	adds r2, r0, r1
_08016458:
	ldrb r0, [r2, #3]
	movs r5, #0x16
	cmp r0, #0
	beq _08016462
	movs r5, #0x12
_08016462:
	ldrb r1, [r2]
	adds r1, #1
	strb r1, [r2]
	movs r4, #3
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08016486
	ldrb r0, [r2, #1]
	adds r0, #1
	ands r0, r4
	strb r0, [r2, #1]
	movs r4, #0xc0
	lsls r4, r4, #3
	adds r1, r4, #0
	orrs r0, r1
	adds r0, r5, r0
	strh r0, [r3, #6]
_08016486:
	ldrb r0, [r2, #5]
	ldrb r1, [r2, #3]
	cmp r0, r1
	beq _080164E0
	movs r0, #0
	mov ip, r0
	ldrb r0, [r2, #6]
	cmp r0, #0
	beq _080164AC
	subs r0, #1
	strb r0, [r2, #6]
	b _080164E0
	.align 2, 0
_080164A0: .4byte 0x083AD382
_080164A4: .4byte 0x03002C30
_080164A8: .4byte 0x00000F21
_080164AC:
	cmp r1, #0
	bne _080164C6
	ldrb r0, [r2, #4]
	cmp r0, #0
	beq _080164BE
	ldrh r0, [r3, #2]
	adds r0, #4
	strh r0, [r3, #2]
	b _080164CC
_080164BE:
	ldrh r0, [r3, #2]
	subs r0, #4
	strh r0, [r3, #2]
	b _080164CC
_080164C6:
	ldrh r0, [r3, #4]
	adds r0, #4
	strh r0, [r3, #4]
_080164CC:
	ldrb r0, [r2, #7]
	adds r0, #1
	strb r0, [r2, #7]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080164E0
	ldrb r0, [r2, #3]
	adds r0, #1
	strb r0, [r2, #3]
_080164E0:
	adds r3, #0x40
	adds r2, #0x40
	adds r6, #1
	cmp r6, r7
	blo _08016458
_080164EA:
	mov r0, ip
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
