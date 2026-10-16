	.syntax unified

	thumb_func_start sub_080373D4
	.global sub_080373D4
sub_080373D4: @ 0x080373D4
	push {r4, lr}
	ldr r3, _08037420 @ =0x03002C30
	lsls r0, r0, #2
	mov ip, r0
	adds r0, #0x5a
	lsls r0, r0, #6
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r4, #0x80
	lsls r4, r4, #8
	adds r2, r4, #0
	orrs r1, r2
	strh r1, [r0]
	mov r1, ip
	adds r1, #0x5b
	lsls r1, r1, #6
	adds r1, r1, r3
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	mov r1, ip
	adds r1, #0x5c
	lsls r1, r1, #6
	adds r1, r1, r3
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x5d
	lsls r0, r0, #6
	adds r0, r0, r3
	ldrh r1, [r0]
	orrs r2, r1
	strh r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08037420: .4byte 0x03002C30
	.syntax divided
