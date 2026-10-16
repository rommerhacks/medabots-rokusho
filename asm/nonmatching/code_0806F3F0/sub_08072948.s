	.syntax unified

	thumb_func_start sub_08072948
sub_08072948: @ 0x08072948
	mov ip, r0
	mov r1, ip
	adds r1, #0x48
	movs r3, #0
	movs r2, #0
	movs r0, #0xff
	strh r0, [r1]
	adds r1, #0x24
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x46
	strh r2, [r0]
	mov r0, ip
	ldr r1, [r0, #0x14]
	ldrb r0, [r1]
	adds r0, #1
	mov r2, ip
	str r0, [r2, #0x28]
	adds r1, #1
	str r1, [r2, #0x14]
	mov r0, ip
	adds r0, #0x66
	strb r3, [r0]
	adds r2, #0x50
	ldrb r1, [r2]
	movs r0, #0x52
	orrs r0, r1
	strb r0, [r2]
	bx lr
	.align 2, 0
	.syntax divided
