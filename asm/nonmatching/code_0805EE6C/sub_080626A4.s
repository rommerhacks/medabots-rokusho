	.syntax unified

	thumb_func_start sub_080626A4
sub_080626A4: @ 0x080626A4
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r0, _080627CC @ =0x03006F74
	ldr r0, [r0]
	ldrb r0, [r0, #0x19]
	movs r1, #8
	bl battle_menu_highlight_icons
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r0, _080627D0 @ =0x03002C30
	ldr r4, _080627D4 @ =0x0000BFFF
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r3, #3
_080626C8:
	ldrh r1, [r2]
	adds r0, r4, #0
	ands r0, r1
	strh r0, [r2]
	adds r2, #0x40
	subs r3, #1
	cmp r3, #0
	bge _080626C8
	movs r6, #0
	ldr r4, _080627D8 @ =0x084E2E58
	ldr r1, _080627DC @ =0x0202F800
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _080627E0 @ =0x084E2E38
	ldr r1, _080627E4 @ =0x0202F9E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _080627E8 @ =0x0202F9C0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _080627EC @ =0x08488AA4
	ldr r1, _080627F0 @ =0x0202F820
	movs r2, #8
	bl CpuFastSet
	ldr r0, _080627F4 @ =0x0879671C
	ldr r1, _080627F8 @ =0x0202FA00
	movs r2, #0x80
	bl CpuFastSet
	ldr r4, _080627FC @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x84
	strb r6, [r0]
	ldr r0, _080627CC @ =0x03006F74
	ldr r0, [r0]
	movs r5, #1
	strb r5, [r0, #6]
	ldr r1, _08062800 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _080627D0 @ =0x03002C30
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0xc0
	lsls r0, r0, #8
	strh r0, [r1]
	movs r3, #0xee
	lsls r3, r3, #1
	adds r1, r2, r3
	movs r0, #2
	strb r0, [r1]
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r2, r1
	strb r5, [r0]
	subs r3, #0x16
	adds r1, r2, r3
	movs r0, #0x1a
	strh r0, [r1]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0x98
	strh r0, [r1]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r2, r1
	strh r6, [r0]
	adds r4, #0x9e
	ldr r0, _08062804 @ =0x03002B70
	ldr r1, [r0]
	adds r0, r4, #0
	bl divide_by_10000
	movs r0, #7
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	str r5, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x15
	movs r3, #1
	bl render_text_sprites_08040DB8
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080627CC: .4byte 0x03006F74
_080627D0: .4byte 0x03002C30
_080627D4: .4byte 0x0000BFFF
_080627D8: .4byte 0x084E2E58
_080627DC: .4byte 0x0202F800
_080627E0: .4byte 0x084E2E38
_080627E4: .4byte 0x0202F9E0
_080627E8: .4byte 0x0202F9C0
_080627EC: .4byte 0x08488AA4
_080627F0: .4byte 0x0202F820
_080627F4: .4byte 0x0879671C
_080627F8: .4byte 0x0202FA00
_080627FC: .4byte 0x03000440
_08062800: .4byte 0x0300137C
_08062804: .4byte 0x03002B70
	.syntax divided
