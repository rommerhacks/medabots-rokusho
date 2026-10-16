	.syntax unified

	thumb_func_start sub_08035194
	.global sub_08035194
sub_08035194: @ 0x08035194
	ldr r1, _080351E4 @ =0x03000590
	lsls r0, r0, #8
	adds r2, r0, r1
	adds r0, r2, #0
	adds r0, #0xa1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080351E2
	adds r0, r2, #0
	adds r0, #0x95
	ldrb r0, [r0]
	lsrs r0, r0, #1
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x96
	ldrb r0, [r0]
	lsrs r0, r0, #1
	adds r1, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x97
	ldrb r0, [r0]
	lsrs r0, r0, #1
	adds r1, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x98
	ldrb r0, [r0]
	lsrs r0, r0, #1
	adds r1, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x99
	ldrb r0, [r0]
	lsrs r0, r0, #1
	adds r1, #1
	strb r0, [r1]
_080351E2:
	bx lr
	.align 2, 0
_080351E4: .4byte 0x03000590
	.syntax divided
