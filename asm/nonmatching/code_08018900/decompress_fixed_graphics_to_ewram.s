	.syntax unified

	thumb_func_start decompress_fixed_graphics_to_ewram
	.global decompress_fixed_graphics_to_ewram
decompress_fixed_graphics_to_ewram: @ 0x0801BCA0
	push {r4, r5, r6, lr}
	ldr r0, _0801BCD8 @ =0x083CE480
	adds r0, #0xf0
	ldr r1, [r0]
	ldr r5, _0801BCDC @ =0x02016000
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801BCD0
	ldr r6, _0801BCE0 @ =0x083B2584
	adds r4, r1, #0
_0801BCB4:
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
	bne _0801BCB4
_0801BCD0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801BCD8: .4byte 0x083CE480
_0801BCDC: .4byte 0x02016000
_0801BCE0: .4byte 0x083B2584
	.syntax divided
