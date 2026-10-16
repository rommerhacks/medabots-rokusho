	.syntax unified

	thumb_func_start sub_08016894
	.global sub_08016894
sub_08016894: @ 0x08016894
	ldr r1, _080168E4 @ =0x03002C30
	mov ip, r1
	movs r2, #0x80
	lsls r2, r2, #1
	add r2, ip
	movs r3, #0
	ldr r1, _080168E8 @ =0x0000C404
	strh r1, [r2]
	movs r1, #0x8e
	lsls r1, r1, #1
	add r1, ip
	strb r3, [r1]
	movs r2, #0x81
	lsls r2, r2, #1
	add r2, ip
	movs r1, #0x78
	strh r1, [r2]
	movs r2, #0x82
	lsls r2, r2, #1
	add r2, ip
	movs r1, #0x84
	strh r1, [r2]
	movs r2, #0x85
	lsls r2, r2, #1
	add r2, ip
	movs r1, #0xa
	strb r1, [r2]
	ldr r2, _080168EC @ =0x0000010B
	add r2, ip
	movs r1, #0xc0
	strb r1, [r2]
	lsls r0, r0, #2
	ldr r1, _080168F0 @ =0x00000607
	adds r0, r0, r1
	movs r1, #0x83
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	bx lr
	.align 2, 0
_080168E4: .4byte 0x03002C30
_080168E8: .4byte 0x0000C404
_080168EC: .4byte 0x0000010B
_080168F0: .4byte 0x00000607
	.syntax divided
