	.syntax unified

	thumb_func_start sub_0802503C
sub_0802503C: @ 0x0802503C
	push {r4, r5, lr}
	ldr r4, _080250D8 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	ldr r3, _080250DC @ =0x03002C30
	cmp r0, #0
	beq _0802505E
	movs r0, #0x84
	lsls r0, r0, #4
	adds r2, r3, r0
	ldrh r1, [r2]
	ldr r0, _080250E0 @ =0x0000EFFF
	ands r0, r1
	strh r0, [r2]
_0802505E:
	ldr r1, _080250E4 @ =0x00000848
	adds r0, r3, r1
	movs r2, #0
	movs r1, #0x40
	strb r1, [r0]
	ldr r5, _080250E8 @ =0x00000849
	adds r0, r3, r5
	strb r1, [r0]
	ldr r1, _080250EC @ =0x00000858
	adds r0, r3, r1
	strh r2, [r0]
	ldr r2, _080250F0 @ =0x0000084A
	adds r1, r3, r2
	movs r0, #7
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x88
	ldrb r0, [r2]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r3
	ldrh r1, [r0, #2]
	ldr r5, _080250F4 @ =0x00000842
	adds r0, r3, r5
	strh r1, [r0]
	ldrb r0, [r2]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	subs r0, #0xc
	ldr r2, _080250F8 @ =0x00000844
	adds r1, r3, r2
	strh r0, [r1]
	ldr r0, _080250FC @ =0x03000440
	adds r0, #0x84
	movs r1, #0x47
	strb r1, [r0]
	ldr r0, _08025100 @ =0x083B5F80
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x4f
	bl play_sound_effect
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080250D8: .4byte 0x03001800
_080250DC: .4byte 0x03002C30
_080250E0: .4byte 0x0000EFFF
_080250E4: .4byte 0x00000848
_080250E8: .4byte 0x00000849
_080250EC: .4byte 0x00000858
_080250F0: .4byte 0x0000084A
_080250F4: .4byte 0x00000842
_080250F8: .4byte 0x00000844
_080250FC: .4byte 0x03000440
_08025100: .4byte 0x083B5F80
	.syntax divided
