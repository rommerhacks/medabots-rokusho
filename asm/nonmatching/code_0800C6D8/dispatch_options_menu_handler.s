	.syntax unified

	thumb_func_start dispatch_options_menu_handler
dispatch_options_menu_handler: @ 0x0800C6D8
	push {lr}
	ldr r1, _0800C6F0 @ =0x083AC964
	ldr r0, _0800C6F4 @ =0x03000440
	adds r0, #0x33
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	bx r0
	.align 2, 0
_0800C6F0: .4byte 0x083AC964
_0800C6F4: .4byte 0x03000440
	.syntax divided
