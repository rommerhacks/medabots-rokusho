	.syntax unified

	thumb_func_start copy_text_with_lookup
copy_text_with_lookup: @ 0x08060BC0
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r7, _08060BFC @ =0x080AFA10
	ldr r6, _08060C00 @ =0x03002420
	adds r2, r3, r5
_08060BCC:
	adds r0, r4, r3
	ldrb r1, [r2]
	strb r1, [r0]
	adds r2, #1
	adds r3, #1
	ldrb r0, [r2]
	cmp r0, #0xff
	bne _08060BCC
	adds r1, r4, r3
	adds r0, r5, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, #1
	adds r1, r4, r3
	adds r0, r5, r3
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r6]
	adds r0, r0, r7
	ldrb r0, [r0]
	strb r0, [r4, #2]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08060BFC: .4byte 0x080AFA10
_08060C00: .4byte 0x03002420
	.syntax divided
