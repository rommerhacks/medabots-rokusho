	.syntax unified

	thumb_func_start sub_08009174
sub_08009174: @ 0x08009174
	push {r4, r5, lr}
	sub sp, #4
	bl sub_080093F8
	bl update_battle_sprite_visibility
	ldr r2, _080091C8 @ =0x03002C30
	adds r4, r2, #0
	adds r4, #0x40
	ldrh r3, [r4]
	ldr r1, _080091CC @ =0x0000BFFF
	adds r0, r1, #0
	ands r0, r3
	movs r5, #0
	strh r0, [r4]
	adds r2, #0x80
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	ldr r2, _080091D0 @ =0x084889F8
	ldr r0, _080091D4 @ =0x04000008
	ldrh r3, [r0]
	movs r0, #0xd4
	lsls r0, r0, #2
	str r0, [sp]
	movs r0, #0x12
	movs r1, #0xc
	bl set_tilemap_and_decompress_bg
	ldr r0, _080091D8 @ =0x03000440
	adds r0, #0x4a
	strb r5, [r0]
	bl init_battle_cursor_sprite_0800B668
	ldr r1, _080091DC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080091C8: .4byte 0x03002C30
_080091CC: .4byte 0x0000BFFF
_080091D0: .4byte 0x084889F8
_080091D4: .4byte 0x04000008
_080091D8: .4byte 0x03000440
_080091DC: .4byte 0x0300137C
	.syntax divided
