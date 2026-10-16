	.syntax unified

	thumb_func_start sub_0801684C
	.global sub_0801684C
sub_0801684C: @ 0x0801684C
	ldr r1, _08016888 @ =0x03002C30
	mov ip, r1
	mov r2, ip
	adds r2, #0xc0
	movs r3, #0
	ldr r1, _0801688C @ =0x0000C404
	strh r1, [r2]
	mov r1, ip
	adds r1, #0xdc
	strb r3, [r1]
	adds r2, #2
	movs r1, #0x84
	strh r1, [r2]
	adds r2, #2
	movs r1, #0x78
	strh r1, [r2]
	adds r2, #6
	movs r1, #0xa
	strb r1, [r2]
	adds r2, #1
	movs r1, #0xc0
	strb r1, [r2]
	lsls r0, r0, #2
	ldr r1, _08016890 @ =0x00000606
	adds r0, r0, r1
	mov r1, ip
	adds r1, #0xc6
	strh r0, [r1]
	bx lr
	.align 2, 0
_08016888: .4byte 0x03002C30
_0801688C: .4byte 0x0000C404
_08016890: .4byte 0x00000606
	.syntax divided
