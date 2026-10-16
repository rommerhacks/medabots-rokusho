	.syntax unified

	thumb_func_start decompress_sprite_to_vram_08043C08
	.global decompress_sprite_to_vram_08043C08
decompress_sprite_to_vram_08043C08: @ 0x08043C08
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r1, #0
	ldr r7, _08043C64 @ =0x083B24A8
	lsls r1, r0, #2
	adds r6, r1, r0
	lsls r0, r6, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ldr r1, _08043C68 @ =0x06008000
	bl lz_decompress_dispatch
	adds r0, r6, #3
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	ldr r0, _08043C6C @ =0x0400000C
	ldrh r3, [r0]
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	adds r0, r6, #4
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	ldr r0, _08043C70 @ =0x0400000E
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	cmp r5, #0
	beq _08043C78
	adds r0, r6, #2
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ldr r1, _08043C74 @ =0x0202FA00
	movs r2, #0x40
	bl CpuFastSet
	b _08043C8A
	.align 2, 0
_08043C64: .4byte 0x083B24A8
_08043C68: .4byte 0x06008000
_08043C6C: .4byte 0x0400000C
_08043C70: .4byte 0x0400000E
_08043C74: .4byte 0x0202FA00
_08043C78:
	adds r0, r6, #2
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x40
	bl CpuFastSet
_08043C8A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
