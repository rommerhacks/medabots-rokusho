	.syntax unified

	thumb_func_start sub_0800E328
sub_0800E328: @ 0x0800E328
	push {lr}
	bl sub_0800EBFC
	bl load_medapart_sprite_by_slot
	bl toggle_sprite_hflip_by_frame
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	ldr r1, _0800E34C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800E34C: .4byte 0x0300137C
	.syntax divided
