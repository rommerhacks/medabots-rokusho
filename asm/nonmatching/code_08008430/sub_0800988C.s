	.syntax unified

	thumb_func_start sub_0800988C
	.global sub_0800988C
sub_0800988C: @ 0x0800988C
	push {r4, r5, lr}
	ldr r0, _080098F0 @ =0x03002C30
	mov ip, r0
	adds r0, #0x40
	movs r5, #0
	ldr r4, _080098F4 @ =0x0000C804
	strh r4, [r0]
	mov r1, ip
	adds r1, #0x42
	movs r0, #0x24
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x44
	movs r3, #0x18
	strh r3, [r0]
	adds r1, #4
	ldr r0, _080098F8 @ =0x00000302
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
	ldr r0, _080098FC @ =0x00000303
	strh r0, [r3]
	mov r0, ip
	adds r0, #0x8a
	strb r2, [r0]
	adds r0, #0x12
	strb r5, [r0]
	subs r0, #0x11
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080098F0: .4byte 0x03002C30
_080098F4: .4byte 0x0000C804
_080098F8: .4byte 0x00000302
_080098FC: .4byte 0x00000303
	.syntax divided
