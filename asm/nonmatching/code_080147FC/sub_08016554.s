	.syntax unified

	thumb_func_start sub_08016554
	.global sub_08016554
sub_08016554: @ 0x08016554
	push {r4, lr}
	ldr r4, _08016594 @ =0x03002C30
	ldr r0, _08016598 @ =0x03001800
	adds r3, r0, #0
	adds r3, #0x81
	ldrb r1, [r3]
	lsls r1, r1, #6
	adds r1, r1, r4
	ldrh r2, [r1]
	movs r0, #0x20
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x22
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #6
	adds r2, r0, r4
	adds r0, r2, #0
	adds r0, #0x22
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0801659C
	movs r1, #0x60
	b _0801659E
	.align 2, 0
_08016594: .4byte 0x03002C30
_08016598: .4byte 0x03001800
_0801659C:
	movs r1, #0x40
_0801659E:
	strb r1, [r2, #9]
	ldrb r0, [r3]
	lsls r0, r0, #6
	adds r0, r0, r4
	strb r1, [r0, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
