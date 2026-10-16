	.syntax unified

	thumb_func_start sub_08031614
sub_08031614: @ 0x08031614
	push {lr}
	bl sub_0801AEB4
	ldr r1, _08031634 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803163C
	adds r1, #0xa6
	movs r0, #0x79
	strb r0, [r1]
	ldr r1, _08031638 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _080316F8
	.align 2, 0
_08031634: .4byte 0x03001800
_08031638: .4byte 0x0300137C
_0803163C:
	adds r0, r1, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	ldr r2, _08031668 @ =0x03000590
	cmp r0, #0
	bne _08031670
	adds r0, r1, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r2
	ldrb r0, [r0, #5]
	cmp r0, #9
	bhi _08031670
	adds r1, #0xa6
	movs r0, #0x36
	strb r0, [r1]
	ldr r1, _0803166C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _080316F8
	.align 2, 0
_08031668: .4byte 0x03000590
_0803166C: .4byte 0x0300137C
_08031670:
	ldr r1, _0803169C @ =0x03001800
	adds r0, r1, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #1
	bne _080316A4
	adds r0, r1, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r2
	ldrb r0, [r0, #5]
	cmp r0, #0x1d
	bhi _080316A4
	adds r1, #0xa6
	movs r0, #0x36
	strb r0, [r1]
	ldr r1, _080316A0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _080316F8
	.align 2, 0
_0803169C: .4byte 0x03001800
_080316A0: .4byte 0x0300137C
_080316A4:
	adds r0, r1, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #2
	bne _080316D0
	adds r0, r1, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r2
	ldrb r0, [r0, #5]
	cmp r0, #0x3b
	bhi _080316D0
	adds r1, #0xa6
	movs r0, #0x36
	strb r0, [r1]
	ldr r1, _080316CC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _080316F8
	.align 2, 0
_080316CC: .4byte 0x0300137C
_080316D0:
	adds r0, r1, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xc1
	ldrb r0, [r0]
	cmp r0, #0x50
	beq _080316F4
	adds r1, #0xa6
	movs r0, #0x37
	strb r0, [r1]
	ldr r1, _080316F0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _080316F8
	.align 2, 0
_080316F0: .4byte 0x0300137C
_080316F4:
	ldr r1, _08031700 @ =0x0300137C
	movs r0, #0x34
_080316F8:
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08031700: .4byte 0x0300137C
	.syntax divided
