	.syntax unified

	thumb_func_start sub_0801BF78
	.global sub_0801BF78
sub_0801BF78: @ 0x0801BF78
	push {r4, lr}
	ldr r3, _0801BFB0 @ =0x03000440
	lsls r2, r2, #3
	adds r2, r2, r3
	mov ip, r2
	adds r2, #0x64
	movs r3, #0
	strb r3, [r2]
	mov r4, ip
	adds r4, #0x65
	movs r2, #2
	strb r2, [r4]
	mov r2, ip
	adds r2, #0x66
	strb r3, [r2]
	ldrh r3, [r0]
	adds r2, #2
	strh r3, [r2]
	ldrh r0, [r0, #2]
	adds r2, #2
	strh r0, [r2]
	mov r0, ip
	adds r0, #0x67
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801BFB0: .4byte 0x03000440
	.syntax divided
