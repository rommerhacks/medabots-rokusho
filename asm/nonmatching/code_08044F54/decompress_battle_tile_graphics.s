	.syntax unified

	thumb_func_start decompress_battle_tile_graphics
	.global decompress_battle_tile_graphics
decompress_battle_tile_graphics: @ 0x0804823C
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _08048244 @ =0x06010000
	b _0804826A
	.align 2, 0
_08048244: .4byte 0x06010000
_08048248:
	ldr r2, _0804827C @ =0x083F80F4
	lsls r0, r1, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _08048256
	movs r1, #1
_08048256:
	lsls r0, r1, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r1, r4, #0
	bl LZ77UnCompVram
	movs r0, #0x90
	lsls r0, r0, #4
	adds r4, r4, r0
	adds r5, #1
_0804826A:
	adds r0, r5, #0
	bl resolve_tile_from_battle_state
	adds r1, r0, #0
	cmp r1, #0xff
	bne _08048248
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804827C: .4byte 0x083F80F4
	.syntax divided
