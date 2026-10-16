	.syntax unified

	thumb_func_start sub_0803E170
sub_0803E170: @ 0x0803E170
	push {lr}
	bl sub_0803E894
	bl draw_battle_bg1_tilemap_row
	ldr r1, _0803E19C @ =0x03000440
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl text_window_init
	ldr r1, _0803E1A0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803E19C: .4byte 0x03000440
_0803E1A0: .4byte 0x0300137C
	.syntax divided
