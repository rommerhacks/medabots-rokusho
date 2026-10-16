	.syntax unified

	thumb_func_start draw_battle_gauge_bar
draw_battle_gauge_bar: @ 0x0803EA38
	push {r4, r5, r6, lr}
	sub sp, #8
	movs r6, #0
	ldr r0, _0803EAC8 @ =0x03001800
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	lsrs r4, r0, #3
	movs r5, #0
	cmp r5, r4
	bhs _0803EA6E
_0803EA50:
	adds r2, r6, #7
	ldr r0, _0803EACC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0803EAD0 @ =0x000053D8
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	movs r3, #0x12
	bl fill_tilemap_rect_08042698
	adds r6, #1
	adds r5, #1
	cmp r5, r4
	blo _0803EA50
_0803EA6E:
	ldr r0, _0803EAC8 @ =0x03001800
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r4, [r0]
	movs r0, #7
	ands r4, r0
	cmp r4, #0
	beq _0803EA9C
	adds r2, r6, #7
	ldr r0, _0803EACC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r1, _0803EAD4 @ =0x000053D0
	adds r0, r1, #0
	orrs r4, r0
	str r4, [sp, #4]
	movs r0, #1
	movs r1, #1
	movs r3, #0x12
	bl fill_tilemap_rect_08042698
	adds r6, #1
_0803EA9C:
	adds r5, r6, #0
	cmp r5, #0xb
	bhi _0803EAC0
_0803EAA2:
	adds r2, r6, #7
	ldr r0, _0803EACC @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _0803EAD4 @ =0x000053D0
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	movs r3, #0x12
	bl fill_tilemap_rect_08042698
	adds r6, #1
	adds r5, #1
	cmp r5, #0xb
	bls _0803EAA2
_0803EAC0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803EAC8: .4byte 0x03001800
_0803EACC: .4byte 0x0400000A
_0803EAD0: .4byte 0x000053D8
_0803EAD4: .4byte 0x000053D0
	.syntax divided
