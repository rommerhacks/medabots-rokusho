	.syntax unified

	thumb_func_start sub_0803E2DC
sub_0803E2DC: @ 0x0803E2DC
	push {r4, r5, lr}
	bl sub_0803E894
	bl draw_battle_bg1_tilemap_row
	ldr r4, _0803E30C @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	bl copy_obj_palette_to_buffer
	adds r4, #0x84
	strb r5, [r4]
	ldr r1, _0803E310 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803E30C: .4byte 0x03000440
_0803E310: .4byte 0x0300137C
	.syntax divided
