	.syntax unified

	thumb_func_start sub_080408D0
sub_080408D0: @ 0x080408D0
	push {lr}
	ldr r2, _080408EC @ =0x083B27C0
	ldr r1, _080408F0 @ =0x03000440
	ldrh r0, [r1, #0xc]
	ldr r1, [r1, #8]
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_080408EC: .4byte 0x083B27C0
_080408F0: .4byte 0x03000440
	.syntax divided
