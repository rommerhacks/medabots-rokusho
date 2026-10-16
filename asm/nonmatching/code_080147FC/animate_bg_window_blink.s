	.syntax unified

	thumb_func_start animate_bg_window_blink
	.global animate_bg_window_blink
animate_bg_window_blink: @ 0x08017CE8
	push {lr}
	ldr r0, _08017D04 @ =0x03000440
	adds r0, #0x86
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	movs r0, #8
	ands r1, r0
	cmp r1, #0
	beq _08017D08
	movs r0, #0
	bl draw_bg_window_rect
	b _08017D0E
	.align 2, 0
_08017D04: .4byte 0x03000440
_08017D08:
	movs r0, #1
	bl draw_bg_window_rect
_08017D0E:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
