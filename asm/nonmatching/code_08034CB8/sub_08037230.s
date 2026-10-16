	.syntax unified

	thumb_func_start sub_08037230
	.global sub_08037230
sub_08037230: @ 0x08037230
	ldr r3, _08037254 @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r0, r0, #8
	adds r2, r2, r0
	adds r0, r2, r3
	adds r1, r0, #0
	adds r1, #0x59
	ldrb r1, [r1]
	cmp r1, #0
	beq _08037258
	adds r0, #0x4c
	ldrb r0, [r0]
	cmp r1, r0
	beq _08037258
	movs r0, #0
	b _0803725A
	.align 2, 0
_08037254: .4byte 0x03000590
_08037258:
	movs r0, #1
_0803725A:
	bx lr
	.syntax divided
