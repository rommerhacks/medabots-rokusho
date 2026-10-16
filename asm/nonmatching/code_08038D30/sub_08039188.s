	.syntax unified

	thumb_func_start sub_08039188
	.global sub_08039188
sub_08039188: @ 0x08039188
	ldr r1, _080391B4 @ =0x03000590
	ldr r2, _080391B8 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xbc
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080391BC
	adds r0, r2, #0
	adds r0, #0xab
	movs r1, #1
	strb r1, [r0]
	adds r0, #0xc
	b _080391C0
	.align 2, 0
_080391B4: .4byte 0x03000590
_080391B8: .4byte 0x03001800
_080391BC:
	adds r0, r2, #0
	adds r0, #0xab
_080391C0:
	strb r1, [r0]
	bx lr
	.syntax divided
