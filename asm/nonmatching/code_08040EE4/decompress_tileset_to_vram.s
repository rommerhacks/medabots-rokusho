	.syntax unified

	thumb_func_start decompress_tileset_to_vram
	.global decompress_tileset_to_vram
decompress_tileset_to_vram: @ 0x08043B7C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r1, #0
	ldr r7, _08043BD8 @ =0x083B23F8
	lsls r6, r0, #2
	lsls r0, r0, #4
	adds r0, r0, r7
	ldr r0, [r0]
	ldr r1, _08043BDC @ =0x06008000
	bl lz_decompress_dispatch
	adds r0, r6, #2
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	ldr r0, _08043BE0 @ =0x0400000C
	ldrh r3, [r0]
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	adds r0, r6, #3
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	ldr r0, _08043BE4 @ =0x0400000E
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	cmp r5, #0
	beq _08043BEC
	adds r0, r6, #1
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ldr r1, _08043BE8 @ =0x0202FA00
	movs r2, #0x40
	bl CpuFastSet
	b _08043BFE
	.align 2, 0
_08043BD8: .4byte 0x083B23F8
_08043BDC: .4byte 0x06008000
_08043BE0: .4byte 0x0400000C
_08043BE4: .4byte 0x0400000E
_08043BE8: .4byte 0x0202FA00
_08043BEC:
	adds r0, r6, #1
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x40
	bl CpuFastSet
_08043BFE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
