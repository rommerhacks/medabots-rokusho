	.syntax unified

	thumb_func_start sub_08025DD4
sub_08025DD4: @ 0x08025DD4
	push {r4, r5, r6, lr}
	ldr r0, _08025E6C @ =0x03001800
	mov ip, r0
	adds r0, #0x64
	ldrb r0, [r0]
	mov r6, ip
	adds r6, #0x87
	movs r4, #0
	strb r0, [r6]
	mov r0, ip
	adds r0, #0x52
	ldrb r0, [r0]
	mov r1, ip
	adds r1, #0x51
	strb r0, [r1]
	ldr r2, _08025E70 @ =0x03002C30
	movs r1, #0x84
	lsls r1, r1, #4
	adds r3, r2, r1
	ldrh r1, [r3]
	movs r5, #0x88
	lsls r5, r5, #2
	adds r0, r5, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r3]
	ldr r1, _08025E74 @ =0x00000848
	adds r0, r2, r1
	movs r1, #0x40
	strb r1, [r0]
	ldr r3, _08025E78 @ =0x00000849
	adds r0, r2, r3
	strb r1, [r0]
	ldr r1, _08025E7C @ =0x00000858
	adds r0, r2, r1
	strh r4, [r0]
	adds r3, #1
	adds r1, r2, r3
	movs r0, #7
	strb r0, [r1]
	ldrb r0, [r6]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	adds r3, #0x26
	adds r0, r2, r3
	strh r1, [r0]
	ldrb r0, [r6]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	adds r3, #2
	adds r1, r2, r3
	strh r0, [r1]
	ldr r0, _08025E80 @ =0x00000864
	adds r1, r2, r0
	movs r0, #6
	strb r0, [r1]
	ldr r1, _08025E84 @ =0x00000863
	adds r2, r2, r1
	strb r5, [r2]
	mov r1, ip
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08025E6C: .4byte 0x03001800
_08025E70: .4byte 0x03002C30
_08025E74: .4byte 0x00000848
_08025E78: .4byte 0x00000849
_08025E7C: .4byte 0x00000858
_08025E80: .4byte 0x00000864
_08025E84: .4byte 0x00000863
	.syntax divided
