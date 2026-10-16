	.syntax unified

	thumb_func_start draw_battle_bg1_tilemap_row
draw_battle_bg1_tilemap_row: @ 0x0803ED6C
	push {r4, lr}
	sub sp, #8
	ldr r0, _0803EDBC @ =0x03000440
	adds r0, #0x86
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0803EDC8
	ldr r1, _0803EDC0 @ =0x03001800
	movs r0, #0xd1
	lsls r0, r0, #1
	adds r2, r1, r0
	ldrb r3, [r2]
	lsls r3, r3, #1
	adds r3, #2
	ldr r0, _0803EDC4 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r0, r1, r4
	ldrb r2, [r2]
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #0x11
	movs r1, #0xce
	lsls r1, r1, #0x16
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #7
	movs r1, #2
	movs r2, #4
	bl fill_tilemap_rect_08042698
	b _0803EE00
	.align 2, 0
_0803EDBC: .4byte 0x03000440
_0803EDC0: .4byte 0x03001800
_0803EDC4: .4byte 0x0400000A
_0803EDC8:
	ldr r1, _0803EE08 @ =0x03001800
	movs r4, #0xd1
	lsls r4, r4, #1
	adds r2, r1, r4
	ldrb r3, [r2]
	lsls r3, r3, #1
	adds r3, #2
	ldr r0, _0803EE0C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	subs r4, #8
	adds r0, r1, r4
	ldrb r2, [r2]
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #0x11
	movs r1, #0x87
	lsls r1, r1, #0x17
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #7
	movs r1, #2
	movs r2, #4
	bl fill_tilemap_rect_08042698
_0803EE00:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803EE08: .4byte 0x03001800
_0803EE0C: .4byte 0x0400000A
	.syntax divided
