	.syntax unified

	thumb_func_start sub_08036B84
	.global sub_08036B84
sub_08036B84: @ 0x08036B84
	ldr r2, _08036BB0 @ =0x03001800
	mov ip, r2
	ldr r3, _08036BB4 @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r2, r2, r3
	adds r2, #0x59
	ldrb r1, [r2]
	mov r0, ip
	adds r0, #0xc8
	strh r1, [r0]
	ldrb r1, [r2]
	adds r0, #4
	strh r1, [r0]
	mov r1, ip
	adds r1, #0xd1
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_08036BB0: .4byte 0x03001800
_08036BB4: .4byte 0x03000590
	.syntax divided
