	.syntax unified

	thumb_func_start sub_0800CBA8
sub_0800CBA8: @ 0x0800CBA8
	push {lr}
	ldr r1, _0800CBC0 @ =0x083AC97C
	ldr r0, _0800CBC4 @ =0x03000440
	adds r0, #0x33
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0800CBC0: .4byte 0x083AC97C
_0800CBC4: .4byte 0x03000440
	.syntax divided
