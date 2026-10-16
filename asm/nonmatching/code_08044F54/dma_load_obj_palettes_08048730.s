	.syntax unified

	thumb_func_start dma_load_obj_palettes_08048730
	.global dma_load_obj_palettes_08048730
dma_load_obj_palettes_08048730: @ 0x08048730
	push {r4, r5, r6, lr}
	movs r4, #0
	bl sub_080481C4
	adds r2, r0, #0
	ldr r5, _0804876C @ =0x083F8634
	ldr r1, _08048770 @ =0x040000D4
	ldr r6, _08048774 @ =0x84000008
	ldr r3, _08048778 @ =0x05000200
_08048742:
	lsls r0, r2, #2
	adds r0, r0, r5
	ldr r0, [r0]
	cmp r0, #0
	bne _0804874E
	movs r2, #1
_0804874E:
	lsls r0, r2, #2
	adds r0, r0, r5
	ldr r0, [r0]
	str r0, [r1]
	str r3, [r1, #4]
	str r6, [r1, #8]
	ldr r0, [r1, #8]
	adds r3, #0x20
	adds r4, #1
	cmp r4, #0xb
	ble _08048742
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804876C: .4byte 0x083F8634
_08048770: .4byte 0x040000D4
_08048774: .4byte 0x84000008
_08048778: .4byte 0x05000200
	.syntax divided
