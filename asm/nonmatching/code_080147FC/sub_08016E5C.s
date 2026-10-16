	.syntax unified

	thumb_func_start sub_08016E5C
	.global sub_08016E5C
sub_08016E5C: @ 0x08016E5C
	ldr r3, _08016E80 @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r2, r2, r3
	adds r2, #0x49
	ldrb r0, [r2]
	cmp r0, #0x28
	beq _08016E88
	cmp r0, #0x28
	bgt _08016E84
	cmp r0, #0x1a
	bgt _08016E8C
	cmp r0, #0x18
	blt _08016E8C
	b _08016E88
	.align 2, 0
_08016E80: .4byte 0x03000590
_08016E84:
	cmp r0, #0x35
	bne _08016E8C
_08016E88:
	movs r0, #1
	b _08016E8E
_08016E8C:
	movs r0, #0
_08016E8E:
	bx lr
	.syntax divided
