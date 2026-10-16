	.syntax unified

	thumb_func_start sub_0805FAF0
sub_0805FAF0: @ 0x0805FAF0
	push {lr}
	ldr r1, _0805FB1C @ =0x08483CA4
	ldr r0, _0805FB20 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _0805FB24 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805FB16
	ldr r1, _0805FB28 @ =0x03001C04
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
_0805FB16:
	pop {r0}
	bx r0
	.align 2, 0
_0805FB1C: .4byte 0x08483CA4
_0805FB20: .4byte 0x0300137C
_0805FB24: .4byte 0x03001780
_0805FB28: .4byte 0x03001C04
	.syntax divided
