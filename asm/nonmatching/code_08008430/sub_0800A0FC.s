	.syntax unified

	thumb_func_start sub_0800A0FC
	.global sub_0800A0FC
sub_0800A0FC: @ 0x0800A0FC
	push {r4, r5, lr}
	ldr r0, _0800A16C @ =0x03000440
	adds r0, #0x41
	ldrb r0, [r0]
	cmp r0, #1
	bls _0800A164
	ldr r0, _0800A170 @ =0x03002C30
	mov ip, r0
	adds r0, #0x40
	movs r5, #0
	ldr r4, _0800A174 @ =0x0000C804
	strh r4, [r0]
	mov r1, ip
	adds r1, #0x42
	movs r0, #4
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x44
	movs r3, #0x20
	strh r3, [r0]
	adds r1, #4
	ldr r0, _0800A178 @ =0x00000302
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x4a
	movs r2, #0xe
	strb r2, [r0]
	adds r0, #0x12
	strb r5, [r0]
	subs r0, #0x11
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #0x35
	strh r4, [r0]
	mov r4, ip
	adds r4, #0x82
	movs r0, #0x7c
	strh r0, [r4]
	mov r0, ip
	adds r0, #0x84
	strh r3, [r0]
	mov r3, ip
	adds r3, #0x86
	ldr r0, _0800A17C @ =0x00000303
	strh r0, [r3]
	mov r0, ip
	adds r0, #0x8a
	strb r2, [r0]
	adds r0, #0x12
	strb r5, [r0]
	subs r0, #0x11
	strb r1, [r0]
_0800A164:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800A16C: .4byte 0x03000440
_0800A170: .4byte 0x03002C30
_0800A174: .4byte 0x0000C804
_0800A178: .4byte 0x00000302
_0800A17C: .4byte 0x00000303
	.syntax divided
