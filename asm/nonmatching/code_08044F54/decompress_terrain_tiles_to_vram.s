	.syntax unified

	thumb_func_start decompress_terrain_tiles_to_vram
	.global decompress_terrain_tiles_to_vram
decompress_terrain_tiles_to_vram: @ 0x08048280
	push {r4, r5, r6, r7, lr}
	bl sub_080481C4
	adds r4, r0, #0
	ldr r7, _080482B8 @ =0x083F80F4
	ldr r6, _080482BC @ =0x06010000
	movs r5, #0xb
_0804828E:
	lsls r0, r4, #2
	adds r0, r0, r7
	ldr r0, [r0]
	cmp r0, #0
	bne _0804829A
	movs r4, #1
_0804829A:
	lsls r0, r4, #2
	adds r0, r0, r7
	ldr r0, [r0]
	adds r1, r6, #0
	bl LZ77UnCompVram
	movs r0, #0x90
	lsls r0, r0, #4
	adds r6, r6, r0
	subs r5, #1
	cmp r5, #0
	bge _0804828E
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080482B8: .4byte 0x083F80F4
_080482BC: .4byte 0x06010000
	.syntax divided
