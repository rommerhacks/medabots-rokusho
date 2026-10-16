	.syntax unified

	thumb_func_start sub_08060804
sub_08060804: @ 0x08060804
	push {r4, lr}
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _08060860 @ =0x03006F74
	ldr r1, [r2]
	movs r4, #0
	movs r0, #8
	strb r0, [r1]
	ldr r3, _08060864 @ =0x04000054
	ldr r1, [r2]
	ldrb r0, [r1]
	lsls r0, r0, #1
	strh r0, [r3]
	strh r4, [r1, #0x3a]
	ldr r1, _08060868 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08060860: .4byte 0x03006F74
_08060864: .4byte 0x04000054
_08060868: .4byte 0x0300137C
	.syntax divided
