	.syntax unified

	thumb_func_start decompress_indexed_asset
	.global decompress_indexed_asset
decompress_indexed_asset: @ 0x0803F41C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r3, #0
	ldr r4, [sp, #0x10]
	ldr r3, _0803F454 @ =0x083AFD08
	lsls r0, r5, #3
	adds r0, r0, r5
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	adds r1, r2, #0
	bl lz_decompress_dispatch
	cmp r4, #0
	beq _0803F460
	ldr r1, _0803F458 @ =0x083B15C8
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r1, r6, #5
	ldr r2, _0803F45C @ =0x0202FA00
	adds r1, r1, r2
	movs r2, #8
	bl CpuFastSet
	b _0803F476
	.align 2, 0
_0803F454: .4byte 0x083AFD08
_0803F458: .4byte 0x083B15C8
_0803F45C: .4byte 0x0202FA00
_0803F460:
	ldr r1, _0803F47C @ =0x083B15C8
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r1, r6, #5
	movs r2, #0xa0
	lsls r2, r2, #0x13
	adds r1, r1, r2
	movs r2, #8
	bl CpuFastSet
_0803F476:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803F47C: .4byte 0x083B15C8
	.syntax divided
