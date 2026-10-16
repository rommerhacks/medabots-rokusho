	.syntax unified

	thumb_func_start sub_0801C23C
sub_0801C23C: @ 0x0801C23C
	push {r4, lr}
	ldr r0, _0801C28C @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0801C286
	ldr r2, _0801C290 @ =0x03002C30
	adds r1, r2, #0
	adds r1, #0xc4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	ldrsh r1, [r1, r0]
	ldr r3, _0801C294 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r4, #0xba
	lsls r4, r4, #5
	adds r0, r0, r4
	adds r0, r0, r2
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r0, #4
	cmp r1, r0
	bne _0801C286
	adds r1, r3, #0
	adds r1, #0x9d
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801C286:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C28C: .4byte 0x03001780
_0801C290: .4byte 0x03002C30
_0801C294: .4byte 0x03001800
	.syntax divided
