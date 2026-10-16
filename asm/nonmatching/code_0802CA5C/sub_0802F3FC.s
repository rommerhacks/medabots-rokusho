	.syntax unified

	thumb_func_start sub_0802F3FC
sub_0802F3FC: @ 0x0802F3FC
	push {r4, r5, lr}
	ldr r2, _0802F454 @ =0x03002C30
	ldr r3, _0802F458 @ =0x03001800
	movs r0, #0x87
	adds r0, r0, r3
	mov ip, r0
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	movs r4, #0x87
	lsls r4, r4, #4
	adds r0, r2, r4
	movs r4, #0
	strh r1, [r0]
	mov r5, ip
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r5, _0802F45C @ =0x00000872
	adds r1, r2, r5
	strh r0, [r1]
	ldr r0, _0802F460 @ =0x00000864
	adds r1, r2, r0
	movs r0, #4
	strb r0, [r1]
	ldr r1, _0802F464 @ =0x00000863
	adds r2, r2, r1
	strb r4, [r2]
	adds r3, #0xaa
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802F454: .4byte 0x03002C30
_0802F458: .4byte 0x03001800
_0802F45C: .4byte 0x00000872
_0802F460: .4byte 0x00000864
_0802F464: .4byte 0x00000863
	.syntax divided
