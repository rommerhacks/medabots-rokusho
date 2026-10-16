	.syntax unified

	thumb_func_start sub_080332B4
sub_080332B4: @ 0x080332B4
	ldr r1, _080332C8 @ =0x03000590
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0
	bne _080332CC
	movs r0, #0
	b _080332CE
	.align 2, 0
_080332C8: .4byte 0x03000590
_080332CC:
	movs r0, #1
_080332CE:
	bx lr
	.syntax divided
