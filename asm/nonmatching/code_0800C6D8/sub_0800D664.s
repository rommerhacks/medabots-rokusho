	.syntax unified

	thumb_func_start sub_0800D664
sub_0800D664: @ 0x0800D664
	push {lr}
	ldr r1, _0800D67C @ =0x083AC9B8
	ldr r0, _0800D680 @ =0x03000440
	adds r0, #0x33
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0800D67C: .4byte 0x083AC9B8
_0800D680: .4byte 0x03000440
	.syntax divided
