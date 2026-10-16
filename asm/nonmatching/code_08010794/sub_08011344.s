	.syntax unified

	thumb_func_start sub_08011344
sub_08011344: @ 0x08011344
	push {r4, r5, r6, lr}
	sub sp, #0xc
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	bl sub_08043CA8
	ldr r0, _08011460 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _08011464 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _08011468 @ =0x0400000C
	ldrh r0, [r0]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _0801146C @ =0x0400000E
	ldrh r0, [r0]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	ldr r1, _08011470 @ =0x030017F0
	ldr r0, _08011474 @ =0x08000841
	str r0, [r1]
	str r4, [sp, #8]
	ldr r0, _08011478 @ =0x040000D4
	add r1, sp, #8
	str r1, [r0]
	ldr r1, _0801147C @ =0x05000200
	str r1, [r0, #4]
	ldr r2, _08011480 @ =0x85000080
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	str r4, [sp, #8]
	add r4, sp, #8
	str r4, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	ldr r4, _08011484 @ =0x03001800
	movs r6, #0xc3
	lsls r6, r6, #1
	adds r5, r4, r6
	ldrb r0, [r5]
	lsls r0, r0, #3
	movs r2, #0xb7
	lsls r2, r2, #1
	adds r1, r4, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl find_medal_slot_by_id
	ldr r2, _08011488 @ =0x03000440
	subs r0, #1
	subs r6, #0x53
	adds r3, r2, r6
	strb r0, [r3]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r6, #0x3d
	adds r1, r4, r6
	adds r0, r0, r1
	ldrb r1, [r0]
	subs r6, #0x3c
	adds r0, r2, r6
	strb r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r6, #0x3d
	adds r1, r4, r6
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r6, #0x3c
	adds r1, r2, r6
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r6, #0x3d
	adds r1, r4, r6
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r6, #0x3c
	adds r1, r2, r6
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r6, #0x3d
	adds r1, r4, r6
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r4, _0801148C @ =0x00000137
	adds r1, r2, r4
	strb r0, [r1]
	ldrb r0, [r3]
	bl sub_08067A48
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08011460: .4byte 0x04000008
_08011464: .4byte 0x0400000A
_08011468: .4byte 0x0400000C
_0801146C: .4byte 0x0400000E
_08011470: .4byte 0x030017F0
_08011474: .4byte 0x08000841
_08011478: .4byte 0x040000D4
_0801147C: .4byte 0x05000200
_08011480: .4byte 0x85000080
_08011484: .4byte 0x03001800
_08011488: .4byte 0x03000440
_0801148C: .4byte 0x00000137
	.syntax divided
