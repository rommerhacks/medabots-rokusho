	.syntax unified

	thumb_func_start dma_load_sprite_tiles
dma_load_sprite_tiles: @ 0x08044F54
	push {r4, r5, r6, r7, lr}
	adds r4, r2, #0
	adds r6, r3, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r7, r5, #0
	cmp r0, #0
	beq _08044FA4
	adds r1, r4, #0
	bl dma3_copy_or_decompress
	adds r3, r0, #0
	cmp r6, #0
	beq _08044F8C
	lsls r1, r5, #5
	ldr r0, _08044F88 @ =0x06010000
	adds r1, r1, r0
	lsls r2, r3, #9
	lsrs r2, r2, #0xb
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r4, #0
	bl CpuSet
	b _08044FA4
	.align 2, 0
_08044F88: .4byte 0x06010000
_08044F8C:
	ldr r2, _08044FAC @ =0x040000B0
	str r4, [r2]
	lsls r0, r7, #5
	ldr r1, _08044FB0 @ =0x06010000
	adds r0, r0, r1
	str r0, [r2, #4]
	lsrs r0, r3, #2
	movs r1, #0x94
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
_08044FA4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08044FAC: .4byte 0x040000B0
_08044FB0: .4byte 0x06010000
	.syntax divided
