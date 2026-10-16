	.syntax unified

	thumb_func_start sub_080167BC
	.global sub_080167BC
sub_080167BC: @ 0x080167BC
	ldr r1, _080167F8 @ =0x03002C30
	mov ip, r1
	mov r2, ip
	adds r2, #0x40
	movs r3, #0
	ldr r1, _080167FC @ =0x0000C404
	strh r1, [r2]
	mov r1, ip
	adds r1, #0x5c
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
	ldr r1, _08016800 @ =0x00000604
	adds r0, r0, r1
	mov r1, ip
	adds r1, #0x46
	strh r0, [r1]
	bx lr
	.align 2, 0
_080167F8: .4byte 0x03002C30
_080167FC: .4byte 0x0000C404
_08016800: .4byte 0x00000604
	.syntax divided
