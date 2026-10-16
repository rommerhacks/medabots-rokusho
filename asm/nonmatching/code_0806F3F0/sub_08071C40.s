	.syntax unified

	thumb_func_start sub_08071C40
sub_08071C40: @ 0x08071C40
	lsls r1, r1, #0x18
	ldr r3, _08071C60 @ =0x03002C30
	lsrs r1, r1, #0x12
	adds r1, r1, r3
	mov ip, r1
	adds r1, #0x20
	movs r3, #0
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x21
	strb r3, [r0]
	mov r0, ip
	strh r2, [r0, #0x34]
	strh r3, [r0, #0x1a]
	bx lr
	.align 2, 0
_08071C60: .4byte 0x03002C30
	.syntax divided
