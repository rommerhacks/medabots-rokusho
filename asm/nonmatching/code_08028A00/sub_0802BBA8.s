	.syntax unified

	thumb_func_start sub_0802BBA8
sub_0802BBA8: @ 0x0802BBA8
	push {r4, r5, r6, r7, lr}
	movs r3, #0
	ldr r7, _0802BC0C @ =0x03001800
	ldr r6, _0802BC10 @ =0x03000440
	adds r5, r7, #0
	adds r5, #0xd2
	movs r0, #0x86
	adds r0, r0, r6
	mov ip, r0
	ldr r0, _0802BC14 @ =0x03002C30
	ldr r1, _0802BC18 @ =0x00000844
	adds r2, r0, r1
	movs r4, #1
_0802BBC2:
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BBDC
	mov r0, ip
	ldrh r1, [r0]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _0802BBDC
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_0802BBDC:
	adds r2, #0x40
	adds r3, #1
	cmp r3, #2
	bls _0802BBC2
	adds r1, r6, #0
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bne _0802BC04
	movs r0, #0x3c
	strh r0, [r1]
	adds r1, r7, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802BC04:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802BC0C: .4byte 0x03001800
_0802BC10: .4byte 0x03000440
_0802BC14: .4byte 0x03002C30
_0802BC18: .4byte 0x00000844
	.syntax divided
