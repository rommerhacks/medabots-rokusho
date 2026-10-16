	.syntax unified

	thumb_func_start sub_0800D168
sub_0800D168: @ 0x0800D168
	push {lr}
	ldr r1, _0800D180 @ =0x083AC994
	ldr r0, _0800D184 @ =0x03000440
	adds r0, #0x33
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0800D180: .4byte 0x083AC994
_0800D184: .4byte 0x03000440
	.syntax divided
