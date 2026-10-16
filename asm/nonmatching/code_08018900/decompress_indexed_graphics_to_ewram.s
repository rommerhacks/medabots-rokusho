	.syntax unified

	thumb_func_start decompress_indexed_graphics_to_ewram
	.global decompress_indexed_graphics_to_ewram
decompress_indexed_graphics_to_ewram: @ 0x0801BC5C
	push {r4, r5, r6, lr}
	ldr r1, _0801BC98 @ =0x083CE480
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r5, #0x80
	lsls r5, r5, #0x12
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801BC90
	ldr r6, _0801BC9C @ =0x083B2584
	adds r4, r1, #0
_0801BC74:
	ldrh r0, [r4, #2]
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r0, [r0]
	adds r1, r5, #0
	bl sub_08044B28
	ldrh r0, [r4]
	lsls r0, r0, #5
	adds r5, r5, r0
	adds r4, #4
	ldrh r0, [r4]
	cmp r0, #0
	bne _0801BC74
_0801BC90:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801BC98: .4byte 0x083CE480
_0801BC9C: .4byte 0x083B2584
	.syntax divided
