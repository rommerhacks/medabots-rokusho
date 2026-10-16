	.syntax unified

	thumb_func_start sub_08044100
	.global sub_08044100
sub_08044100: @ 0x08044100
	push {lr}
	bl update_scroll_movement_b
	ldr r0, _08044114 @ =0x03001800
	adds r0, #0x38
	ldrb r0, [r0]
	bl advance_battle_animation_frame
	pop {r0}
	bx r0
	.align 2, 0
_08044114: .4byte 0x03001800
	.syntax divided
