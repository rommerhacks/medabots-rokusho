	.syntax unified

	thumb_func_start sub_0800BE6C
sub_0800BE6C: @ 0x0800BE6C
	push {lr}
	ldr r1, _0800BE84 @ =0x083AC94C
	ldr r0, _0800BE88 @ =0x03000440
	adds r0, #0x33
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0800BE84: .4byte 0x083AC94C
_0800BE88: .4byte 0x03000440
	.syntax divided
