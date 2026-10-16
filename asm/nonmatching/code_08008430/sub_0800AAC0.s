	.syntax unified

	thumb_func_start sub_0800AAC0
sub_0800AAC0: @ 0x0800AAC0
	ldr r2, _0800AB00 @ =0x083B7EBC
	ldr r1, _0800AB04 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x43
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r0, _0800AB08 @ =0x03002C30
	mov ip, r0
	adds r1, #0x44
	ldrb r0, [r1]
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r2, r0
	ldrb r0, [r0]
	lsls r0, r0, #3
	movs r3, #0xc1
	lsls r3, r3, #1
	add r3, ip
	strh r0, [r3]
	ldrb r0, [r1]
	adds r0, #1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0, #1]
	lsls r0, r0, #3
	movs r1, #0xc2
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	bx lr
	.align 2, 0
_0800AB00: .4byte 0x083B7EBC
_0800AB04: .4byte 0x03000440
_0800AB08: .4byte 0x03002C30
	.syntax divided
