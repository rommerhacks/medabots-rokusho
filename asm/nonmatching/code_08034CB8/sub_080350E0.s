	.syntax unified

	thumb_func_start sub_080350E0
sub_080350E0: @ 0x080350E0
	ldr r3, _08035128 @ =0x03002C30
	lsls r0, r0, #2
	mov ip, r0
	mov r1, ip
	adds r1, #0x5a
	lsls r1, r1, #6
	adds r1, r1, r3
	mov r2, ip
	adds r2, #0x5d
	lsls r2, r2, #6
	adds r2, r2, r3
	ldrh r0, [r2, #2]
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	subs r0, #8
	strh r0, [r1, #4]
	mov r1, ip
	adds r1, #0x5b
	lsls r1, r1, #6
	adds r1, r1, r3
	ldrh r0, [r2, #2]
	subs r0, #8
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	strh r0, [r1, #4]
	mov r1, ip
	adds r1, #0x5c
	lsls r1, r1, #6
	adds r1, r1, r3
	ldrh r0, [r2, #2]
	adds r0, #8
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	strh r0, [r1, #4]
	bx lr
	.align 2, 0
_08035128: .4byte 0x03002C30
	.syntax divided
