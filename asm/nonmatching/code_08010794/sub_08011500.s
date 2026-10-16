	.syntax unified

	thumb_func_start sub_08011500
sub_08011500: @ 0x08011500
	push {r4, lr}
	sub sp, #8
	movs r0, #1
	bl play_song
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	bl sub_08043CA8
	ldr r0, _08011590 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _08011594 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _08011598 @ =0x0400000C
	ldrh r0, [r0]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _0801159C @ =0x0400000E
	ldrh r0, [r0]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x20
	movs r1, #0x20
	movs r2, #0
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldr r0, _080115A0 @ =0x030057E0
	ldr r2, _080115A4 @ =0x00000C2D
	adds r1, r0, r2
	strb r4, [r1]
	adds r2, #1
	adds r1, r0, r2
	strb r4, [r1]
	ldr r1, _080115A8 @ =0x00000C2F
	adds r0, r0, r1
	strb r4, [r0]
	ldr r1, _080115AC @ =0x030017F0
	ldr r0, _080115B0 @ =0x08000841
	str r0, [r1]
	movs r0, #0
	bl sub_0804765C
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08011590: .4byte 0x04000008
_08011594: .4byte 0x0400000A
_08011598: .4byte 0x0400000C
_0801159C: .4byte 0x0400000E
_080115A0: .4byte 0x030057E0
_080115A4: .4byte 0x00000C2D
_080115A8: .4byte 0x00000C2F
_080115AC: .4byte 0x030017F0
_080115B0: .4byte 0x08000841
	.syntax divided
