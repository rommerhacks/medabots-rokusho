	.syntax unified

	thumb_func_start sub_08016DA4
	.global sub_08016DA4
sub_08016DA4: @ 0x08016DA4
	ldr r1, _08016DC4 @ =0x03000590
	ldr r2, _08016DC8 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xdd
	ldrb r1, [r0]
	cmp r1, #3
	bls _08016DBC
	movs r1, #0
_08016DBC:
	adds r0, r2, #0
	adds r0, #0x82
	strb r1, [r0]
	bx lr
	.align 2, 0
_08016DC4: .4byte 0x03000590
_08016DC8: .4byte 0x03001800
	.syntax divided
