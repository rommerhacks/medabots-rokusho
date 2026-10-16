	.syntax unified

	thumb_func_start sub_080351E8
	.global sub_080351E8
sub_080351E8: @ 0x080351E8
	ldr r1, _08035230 @ =0x03000590
	lsls r0, r0, #8
	adds r2, r0, r1
	adds r0, r2, #0
	adds r0, #0xa1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803522C
	adds r0, r2, #0
	adds r0, #0x95
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x96
	ldrb r0, [r0]
	adds r1, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x97
	ldrb r1, [r0]
	adds r0, #0xd
	strb r1, [r0]
	subs r0, #0xc
	ldrb r0, [r0]
	adds r1, r2, #0
	adds r1, #0xa5
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x99
	ldrb r1, [r0]
	adds r0, #0xd
	strb r1, [r0]
_0803522C:
	bx lr
	.align 2, 0
_08035230: .4byte 0x03000590
	.syntax divided
