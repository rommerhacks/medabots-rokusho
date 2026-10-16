	.syntax unified

	thumb_func_start sub_08039134
sub_08039134: @ 0x08039134
	movs r3, #0
	movs r2, #0
	ldr r1, _08039154 @ =0x03000590
	lsls r0, r0, #8
	adds r1, #0x59
	adds r1, r0, r1
_08039140:
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039148
	adds r3, #1
_08039148:
	adds r1, #0x18
	adds r2, #1
	cmp r2, #3
	bls _08039140
	adds r0, r3, #0
	bx lr
	.align 2, 0
_08039154: .4byte 0x03000590
	.syntax divided
