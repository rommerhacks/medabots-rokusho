	.syntax unified

	thumb_func_start sub_08017178
	.global sub_08017178
sub_08017178: @ 0x08017178
	ldr r1, _080171B4 @ =0x03002C30
	mov ip, r1
	mov r2, ip
	adds r2, #0x80
	movs r3, #0
	ldr r1, _080171B8 @ =0x0000C404
	strh r1, [r2]
	mov r1, ip
	adds r1, #0x9c
	strb r3, [r1]
	adds r2, #2
	movs r1, #0x78
	strh r1, [r2]
	adds r2, #2
	movs r1, #0x6c
	strh r1, [r2]
	adds r2, #6
	movs r1, #0xa
	strb r1, [r2]
	adds r2, #1
	movs r1, #0xc0
	strb r1, [r2]
	lsls r0, r0, #2
	ldr r1, _080171BC @ =0x0000061B
	adds r0, r0, r1
	mov r1, ip
	adds r1, #0x86
	strh r0, [r1]
	bx lr
	.align 2, 0
_080171B4: .4byte 0x03002C30
_080171B8: .4byte 0x0000C404
_080171BC: .4byte 0x0000061B
	.syntax divided
