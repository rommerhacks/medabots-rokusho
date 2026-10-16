	.syntax unified

	thumb_func_start update_bg_scroll_offsets_b
	.global update_bg_scroll_offsets_b
update_bg_scroll_offsets_b: @ 0x080530BC
	push {r4, r5, lr}
	ldr r3, _080530FC @ =0x03002C30
	ldr r1, _08053100 @ =0x030057E0
	ldr r2, _08053104 @ =0x00000C6E
	adds r0, r1, r2
	ldr r4, _08053108 @ =0x03004C30
	ldrh r2, [r0]
	ldrh r0, [r4]
	subs r2, r2, r0
	ldr r5, _0805310C @ =0x00000C02
	adds r0, r3, r5
	strh r2, [r0]
	movs r0, #0xc7
	lsls r0, r0, #4
	adds r1, r1, r0
	ldrh r1, [r1]
	ldrh r0, [r4, #2]
	subs r1, r1, r0
	ldr r4, _08053110 @ =0x00000C04
	adds r0, r3, r4
	strh r1, [r0]
	ldr r5, _08053114 @ =0x00001682
	adds r0, r3, r5
	strh r2, [r0]
	subs r1, #5
	ldr r0, _08053118 @ =0x00001684
	adds r3, r3, r0
	strh r1, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080530FC: .4byte 0x03002C30
_08053100: .4byte 0x030057E0
_08053104: .4byte 0x00000C6E
_08053108: .4byte 0x03004C30
_0805310C: .4byte 0x00000C02
_08053110: .4byte 0x00000C04
_08053114: .4byte 0x00001682
_08053118: .4byte 0x00001684
	.syntax divided
