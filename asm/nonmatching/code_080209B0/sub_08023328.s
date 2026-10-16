	.syntax unified

	thumb_func_start sub_08023328
sub_08023328: @ 0x08023328
	push {r4, lr}
	ldr r0, _08023348 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x86
	ldrh r0, [r1]
	cmp r0, #0x14
	bne _08023350
	movs r0, #0x3c
	strh r0, [r1]
	ldr r1, _0802334C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802337A
	.align 2, 0
_08023348: .4byte 0x03000440
_0802334C: .4byte 0x03001800
_08023350:
	adds r0, #1
	strh r0, [r1]
	movs r3, #0
	ldr r0, _08023380 @ =0x03002C30
	movs r4, #0x80
	lsls r4, r4, #8
	movs r1, #0x84
	lsls r1, r1, #4
	adds r2, r0, r1
_08023362:
	ldrh r1, [r2]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08023372
	ldrh r0, [r2, #4]
	subs r0, #1
	strh r0, [r2, #4]
_08023372:
	adds r2, #0x40
	adds r3, #1
	cmp r3, #2
	bls _08023362
_0802337A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08023380: .4byte 0x03002C30
	.syntax divided
