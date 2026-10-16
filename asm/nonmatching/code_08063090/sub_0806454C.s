	.syntax unified

	thumb_func_start sub_0806454C
sub_0806454C: @ 0x0806454C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	bl sub_080415BC
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r2, _080646AC @ =0x00002060
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #0xc
	ldr r3, _080646B0 @ =0x0000DB06
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _080646B4 @ =0x00001F07
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _080646B8 @ =0x087A88CC
	ldr r4, _080646BC @ =0x02030000
	adds r1, r4, #0
	bl dma3_copy_or_decompress
	ldr r6, _080646C0 @ =0x0600D800
	movs r5, #0x1f
_08064588:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x10
	bl CpuFastSet
	adds r6, #0x40
	adds r4, #0x80
	subs r5, #1
	cmp r5, #0
	bge _08064588
	ldr r4, _080646C4 @ =0x02030040
	movs r5, #0x1f
_080645A0:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x10
	bl CpuFastSet
	adds r6, #0x40
	adds r4, #0x80
	subs r5, #1
	cmp r5, #0
	bge _080645A0
	ldr r4, _080646C8 @ =0x02031000
	movs r5, #0x1f
_080645B8:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x10
	bl CpuFastSet
	adds r6, #0x40
	adds r4, #0x80
	subs r5, #1
	cmp r5, #0
	bge _080645B8
	ldr r4, _080646CC @ =0x02031040
	movs r5, #0x1f
_080645D0:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x10
	bl CpuFastSet
	adds r6, #0x40
	adds r4, #0x80
	subs r5, #1
	cmp r5, #0
	bge _080645D0
	ldr r0, _080646D0 @ =0x087A1084
	ldr r1, _080646D4 @ =0x0400000E
	ldrh r1, [r1]
	bl decompress_and_write_tilemap
	ldr r0, _080646D8 @ =0x087A92D4
	ldr r6, _080646BC @ =0x02030000
	adds r1, r6, #0
	bl dma3_copy_or_decompress
	adds r5, r0, #0
	ldr r4, _080646DC @ =0x06004000
	lsrs r2, r5, #1
	ldr r3, _080646E0 @ =0x001FFFFF
	mov r8, r3
	ands r2, r3
	adds r0, r6, #0
	adds r1, r4, #0
	bl CpuSet
	ldr r0, _080646E4 @ =0x087A046C
	adds r1, r6, #0
	bl dma3_copy_or_decompress
	adds r2, r0, #0
	adds r4, r5, r4
	lsrs r2, r2, #1
	mov r0, r8
	ands r2, r0
	adds r0, r6, #0
	adds r1, r4, #0
	bl CpuSet
	lsrs r5, r5, #5
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x1f
	bl tilemap_offset_tiles_and_palette
	ldr r0, _080646E8 @ =0x087A034C
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x48
	bl CpuFastSet
	movs r2, #0x80
	lsls r2, r2, #0x13
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
	ldr r1, _080646EC @ =0x04000040
	movs r0, #0xf0
	strh r0, [r1]
	adds r1, #4
	ldr r2, _080646F0 @ =0x00004858
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #4
	ldr r3, _080646F4 @ =0x00003F3F
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _080646F8 @ =0x00003B3B
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _080646FC @ =0x0300057C
	movs r2, #0
	movs r0, #0x58
	strh r0, [r1, #2]
	ldr r0, _08064700 @ =0x03006F74
	ldr r0, [r0]
	strh r2, [r0, #0x3a]
	adds r0, #0x50
	movs r3, #1
	rsbs r3, r3, #0
	movs r1, #0xc0
	str r1, [sp]
	movs r1, #0x10
	bl init_blend_effect
	ldr r1, _08064704 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080646AC: .4byte 0x00002060
_080646B0: .4byte 0x0000DB06
_080646B4: .4byte 0x00001F07
_080646B8: .4byte 0x087A88CC
_080646BC: .4byte 0x02030000
_080646C0: .4byte 0x0600D800
_080646C4: .4byte 0x02030040
_080646C8: .4byte 0x02031000
_080646CC: .4byte 0x02031040
_080646D0: .4byte 0x087A1084
_080646D4: .4byte 0x0400000E
_080646D8: .4byte 0x087A92D4
_080646DC: .4byte 0x06004000
_080646E0: .4byte 0x001FFFFF
_080646E4: .4byte 0x087A046C
_080646E8: .4byte 0x087A034C
_080646EC: .4byte 0x04000040
_080646F0: .4byte 0x00004858
_080646F4: .4byte 0x00003F3F
_080646F8: .4byte 0x00003B3B
_080646FC: .4byte 0x0300057C
_08064700: .4byte 0x03006F74
_08064704: .4byte 0x0300137C
	.syntax divided
