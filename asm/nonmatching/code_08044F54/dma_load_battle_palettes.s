	.syntax unified

	thumb_func_start dma_load_battle_palettes
	.global dma_load_battle_palettes
dma_load_battle_palettes: @ 0x080486BC
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r4, _080486C8 @ =0x040000D4
	ldr r6, _080486CC @ =0x0202F800
	b _080486FA
	.align 2, 0
_080486C8: .4byte 0x040000D4
_080486CC: .4byte 0x0202F800
_080486D0:
	adds r0, r5, #0
	bl resolve_tile_from_battle_state
	adds r1, r0, #0
	ldr r2, _0804871C @ =0x083F8634
	lsls r0, r1, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _080486E6
	movs r1, #1
_080486E6:
	lsls r0, r1, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r4]
	str r6, [r4, #4]
	ldr r0, _08048720 @ =0x84000008
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	adds r6, #0x20
	adds r5, #1
_080486FA:
	adds r0, r5, #0
	bl resolve_tile_from_battle_state
	adds r1, r0, #0
	cmp r1, #0xff
	bne _080486D0
	ldr r1, _08048724 @ =0x040000D4
	ldr r0, _08048728 @ =0x085FA0E4
	str r0, [r1]
	ldr r0, _0804872C @ =0x0202F9C0
	str r0, [r1, #4]
	ldr r0, _08048720 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804871C: .4byte 0x083F8634
_08048720: .4byte 0x84000008
_08048724: .4byte 0x040000D4
_08048728: .4byte 0x085FA0E4
_0804872C: .4byte 0x0202F9C0
	.syntax divided
