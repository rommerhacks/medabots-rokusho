	.syntax unified

	thumb_func_start sub_08011BB8
sub_08011BB8: @ 0x08011BB8
	push {r4, lr}
	sub sp, #8
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	bl sub_08043CA8
	ldr r0, _08011C58 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _08011C5C @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _08011C60 @ =0x0400000C
	ldrh r0, [r0]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _08011C64 @ =0x0400000E
	ldrh r0, [r0]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _08011C68 @ =0x030057E0
	ldr r2, _08011C6C @ =0x00000C2D
	adds r1, r0, r2
	strb r4, [r1]
	adds r2, #1
	adds r1, r0, r2
	strb r4, [r1]
	ldr r1, _08011C70 @ =0x00000C2F
	adds r0, r0, r1
	strb r4, [r0]
	ldr r1, _08011C74 @ =0x030017F0
	ldr r0, _08011C78 @ =0x08000841
	str r0, [r1]
	movs r0, #3
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	ldr r1, _08011C7C @ =0x0300178C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08011C80 @ =0x03002B8C
	movs r0, #8
	str r0, [r1]
	ldr r0, _08011C84 @ =0x0300137C
	str r4, [r0]
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08011C58: .4byte 0x04000008
_08011C5C: .4byte 0x0400000A
_08011C60: .4byte 0x0400000C
_08011C64: .4byte 0x0400000E
_08011C68: .4byte 0x030057E0
_08011C6C: .4byte 0x00000C2D
_08011C70: .4byte 0x00000C2F
_08011C74: .4byte 0x030017F0
_08011C78: .4byte 0x08000841
_08011C7C: .4byte 0x0300178C
_08011C80: .4byte 0x03002B8C
_08011C84: .4byte 0x0300137C
	.syntax divided
