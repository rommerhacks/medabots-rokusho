	.syntax unified

	thumb_func_start sub_08017208
	.global sub_08017208
sub_08017208: @ 0x08017208
	ldr r1, _08017258 @ =0x03002C30
	mov ip, r1
	movs r2, #0x80
	lsls r2, r2, #1
	add r2, ip
	movs r3, #0
	ldr r1, _0801725C @ =0x0000C404
	strh r1, [r2]
	movs r1, #0x8e
	lsls r1, r1, #1
	add r1, ip
	strb r3, [r1]
	movs r2, #0x81
	lsls r2, r2, #1
	add r2, ip
	movs r1, #0x84
	strh r1, [r2]
	movs r2, #0x82
	lsls r2, r2, #1
	add r2, ip
	movs r1, #0x78
	strh r1, [r2]
	movs r2, #0x85
	lsls r2, r2, #1
	add r2, ip
	movs r1, #0xa
	strb r1, [r2]
	ldr r2, _08017260 @ =0x0000010B
	add r2, ip
	movs r1, #0xc0
	strb r1, [r2]
	lsls r0, r0, #2
	ldr r1, _08017264 @ =0x0000061D
	adds r0, r0, r1
	movs r1, #0x83
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	bx lr
	.align 2, 0
_08017258: .4byte 0x03002C30
_0801725C: .4byte 0x0000C404
_08017260: .4byte 0x0000010B
_08017264: .4byte 0x0000061D
	.syntax divided
