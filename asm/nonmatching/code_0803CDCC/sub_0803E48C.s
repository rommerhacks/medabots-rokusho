	.syntax unified

	thumb_func_start sub_0803E48C
sub_0803E48C: @ 0x0803E48C
	push {lr}
	bl sub_0803E894
	bl draw_battle_bg1_tilemap_row
	ldr r1, _0803E4AC @ =0x03000440
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _0803E4B0 @ =0x0300137C
	movs r0, #0x3e
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803E4AC: .4byte 0x03000440
_0803E4B0: .4byte 0x0300137C
	.syntax divided
