	.syntax unified

	thumb_func_start dma_load_obj_palettes_08048664
	.global dma_load_obj_palettes_08048664
dma_load_obj_palettes_08048664: @ 0x08048664
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r4, _08048670 @ =0x040000D4
	ldr r6, _08048674 @ =0x05000200
	b _080486A2
	.align 2, 0
_08048670: .4byte 0x040000D4
_08048674: .4byte 0x05000200
_08048678:
	adds r0, r5, #0
	bl resolve_tile_from_battle_state
	adds r1, r0, #0
	ldr r2, _080486B4 @ =0x083F8634
	lsls r0, r1, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _0804868E
	movs r1, #1
_0804868E:
	lsls r0, r1, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r4]
	str r6, [r4, #4]
	ldr r0, _080486B8 @ =0x84000008
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	adds r6, #0x20
	adds r5, #1
_080486A2:
	adds r0, r5, #0
	bl resolve_tile_from_battle_state
	adds r1, r0, #0
	cmp r1, #0xff
	bne _08048678
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080486B4: .4byte 0x083F8634
_080486B8: .4byte 0x84000008
	.syntax divided
