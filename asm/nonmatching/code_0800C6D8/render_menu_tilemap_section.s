	.syntax unified

	thumb_func_start render_menu_tilemap_section
render_menu_tilemap_section: @ 0x0800F7D0
	push {lr}
	sub sp, #8
	ldr r1, _0800F808 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0800F814
	adds r0, r1, #0
	adds r0, #0xf0
	ldrb r0, [r0]
	bl sub_08042B80
	lsls r0, r0, #0x12
	ldr r1, _0800F80C @ =0x83900000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	ldr r1, _0800F810 @ =0x0400000A
	ldrh r1, [r1]
	str r1, [sp]
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xb
	movs r3, #9
	bl fill_tilemap_rect_08042698
	b _0800F836
	.align 2, 0
_0800F808: .4byte 0x03000440
_0800F80C: .4byte 0x83900000
_0800F810: .4byte 0x0400000A
_0800F814:
	ldr r0, _0800F83C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r1, #0
	adds r0, #0xef
	ldrb r0, [r0]
	lsls r0, r0, #0x12
	ldr r1, _0800F840 @ =0xA2080000
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xb
	movs r3, #9
	bl fill_tilemap_rect_08042698
_0800F836:
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0800F83C: .4byte 0x0400000A
_0800F840: .4byte 0xA2080000
	.syntax divided
