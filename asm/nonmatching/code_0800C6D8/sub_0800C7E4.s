	.syntax unified

	thumb_func_start sub_0800C7E4
sub_0800C7E4: @ 0x0800C7E4
	push {lr}
	ldr r1, _0800C7FC @ =0x083AC970
	ldr r0, _0800C800 @ =0x03000440
	adds r0, #0x33
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0800C7FC: .4byte 0x083AC970
_0800C800: .4byte 0x03000440
	.syntax divided
