	.syntax unified

	thumb_func_start poll_choice_menu
	.global poll_choice_menu
poll_choice_menu: @ 0x08041674
	push {r4, lr}
	ldr r1, _08041694 @ =0x083B2814
	ldr r4, _08041698 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	adds r4, #0x28
	ldrb r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08041694: .4byte 0x083B2814
_08041698: .4byte 0x03000440
	.syntax divided
