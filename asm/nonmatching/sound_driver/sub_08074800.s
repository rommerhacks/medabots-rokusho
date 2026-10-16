	.syntax unified

	thumb_func_start sub_08074800
sub_08074800: @ 0x08074800
	adds r2, r0, #0
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _0807483C
	ldr r0, [r2]
	cmp r0, #0
	bne _0807483C
	ldr r0, _08074824 @ =0x03007014
	ldr r0, [r0]
	ldr r1, _08074828 @ =0x000005E4
	adds r3, r0, r1
	ldr r0, [r3]
	cmp r0, #0
	bne _0807482C
	str r2, [r2, #4]
	str r2, [r2]
	b _0807483A
	.align 2, 0
_08074824: .4byte 0x03007014
_08074828: .4byte 0x000005E4
_0807482C:
	ldr r0, [r0]
	str r0, [r2]
	ldr r1, [r3]
	str r1, [r2, #4]
	str r2, [r0, #4]
	ldr r0, [r2, #4]
	str r2, [r0]
_0807483A:
	str r2, [r3]
_0807483C:
	bx lr
	.align 2, 0
	.syntax divided
