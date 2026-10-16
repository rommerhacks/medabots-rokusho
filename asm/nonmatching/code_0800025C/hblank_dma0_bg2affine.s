	.syntax unified

	thumb_func_start hblank_dma0_bg2affine
hblank_dma0_bg2affine: @ 0x08001278
	push {r4, lr}
	ldr r4, _080012C8 @ =0x040000B0
	ldr r3, _080012CC @ =0x04000020
	ldr r0, _080012D0 @ =0x03001780
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r2, _080012D4 @ =0x02030A00
	cmp r0, #0
	beq _0800128E
	ldr r2, _080012D8 @ =0x02030000
_0800128E:
	ldrh r0, [r2]
	strh r0, [r3]
	ldrh r0, [r2, #2]
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	strh r0, [r3, #4]
	ldrh r0, [r2, #6]
	strh r0, [r3, #6]
	ldrh r0, [r2, #8]
	strh r0, [r3, #8]
	ldrh r0, [r2, #0xa]
	strh r0, [r3, #0xa]
	ldrh r0, [r2, #0xc]
	strh r0, [r3, #0xc]
	ldrh r0, [r2, #0xe]
	strh r0, [r3, #0xe]
	ldr r1, _080012DC @ =0x040000BA
	movs r0, #0
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x10
	str r0, [r4]
	str r3, [r4, #4]
	ldr r0, _080012E0 @ =0xA2600008
	str r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080012C8: .4byte 0x040000B0
_080012CC: .4byte 0x04000020
_080012D0: .4byte 0x03001780
_080012D4: .4byte 0x02030A00
_080012D8: .4byte 0x02030000
_080012DC: .4byte 0x040000BA
_080012E0: .4byte 0xA2600008
_080012E4:
	.byte 0x01, 0x49, 0x00, 0x20, 0x08, 0x80, 0x70, 0x47, 0xBA, 0x00, 0x00, 0x04
	.syntax divided
