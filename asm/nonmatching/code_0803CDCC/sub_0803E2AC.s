	.syntax unified

	thumb_func_start sub_0803E2AC
sub_0803E2AC: @ 0x0803E2AC
	push {lr}
	bl sub_0803E894
	bl draw_battle_bg1_tilemap_row
	ldr r1, _0803E2D4 @ =0x03000440
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #8
	bl sound_stop_all_with_fade_guard
	ldr r1, _0803E2D8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803E2D4: .4byte 0x03000440
_0803E2D8: .4byte 0x0300137C
	.syntax divided
