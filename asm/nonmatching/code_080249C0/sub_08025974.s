	.syntax unified

	thumb_func_start sub_08025974
sub_08025974: @ 0x08025974
	push {r4, r5, r6, lr}
	movs r0, #0x21
	movs r1, #1
	bl clear_sprite_table_mask
	ldr r2, _080259F4 @ =0x03002C30
	movs r0, #0x88
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r5, #0
	ldr r0, _080259F8 @ =0x0000C404
	strh r0, [r1]
	ldr r1, _080259FC @ =0x0000089C
	adds r0, r2, r1
	strb r5, [r0]
	ldr r4, _08025A00 @ =0x03001800
	adds r3, r4, #0
	adds r3, #0x88
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r6, #0xba
	lsls r6, r6, #5
	adds r0, r0, r6
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	ldr r6, _08025A04 @ =0x00000882
	adds r0, r2, r6
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r3, _08025A08 @ =0x00000884
	adds r1, r2, r3
	strh r0, [r1]
	adds r6, #8
	adds r1, r2, r6
	movs r0, #7
	strb r0, [r1]
	ldr r0, _08025A0C @ =0x0000088B
	adds r1, r2, r0
	movs r0, #0xe0
	strb r0, [r1]
	ldr r1, _08025A10 @ =0x000008A3
	adds r0, r2, r1
	strb r5, [r0]
	adds r3, #2
	adds r2, r2, r3
	ldr r0, _08025A14 @ =0x00005201
	strh r0, [r2]
	movs r0, #0x6a
	bl play_sound_effect
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080259F4: .4byte 0x03002C30
_080259F8: .4byte 0x0000C404
_080259FC: .4byte 0x0000089C
_08025A00: .4byte 0x03001800
_08025A04: .4byte 0x00000882
_08025A08: .4byte 0x00000884
_08025A0C: .4byte 0x0000088B
_08025A10: .4byte 0x000008A3
_08025A14: .4byte 0x00005201
	.syntax divided
