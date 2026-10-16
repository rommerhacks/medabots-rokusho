	.syntax unified

	thumb_func_start sub_08016804
	.global sub_08016804
sub_08016804: @ 0x08016804
	ldr r1, _08016840 @ =0x03002C30
	mov ip, r1
	mov r2, ip
	adds r2, #0x80
	movs r3, #0
	ldr r1, _08016844 @ =0x0000C404
	strh r1, [r2]
	mov r1, ip
	adds r1, #0x9c
	strb r3, [r1]
	adds r2, #2
	movs r1, #0x6c
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
	ldr r1, _08016848 @ =0x00000605
	adds r0, r0, r1
	mov r1, ip
	adds r1, #0x86
	strh r0, [r1]
	bx lr
	.align 2, 0
_08016840: .4byte 0x03002C30
_08016844: .4byte 0x0000C404
_08016848: .4byte 0x00000605
	.syntax divided
