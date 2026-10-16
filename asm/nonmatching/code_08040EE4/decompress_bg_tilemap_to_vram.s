	.syntax unified

	thumb_func_start decompress_bg_tilemap_to_vram
decompress_bg_tilemap_to_vram: @ 0x0804169C
	push {r4, lr}
	sub sp, #4
	ldr r0, _080416F8 @ =0x084878EC
	ldr r1, _080416FC @ =0x06002600
	bl lz_decompress_dispatch
	ldr r0, _08041700 @ =0x0848796C
	ldr r1, _08041704 @ =0x060026E0
	bl lz_decompress_dispatch
	ldr r0, _08041708 @ =0x084C7318
	ldr r1, _0804170C @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r2, _08041710 @ =0x084886D0
	ldr r4, _08041714 @ =0x04000008
	ldrh r3, [r4]
	movs r0, #0x98
	lsls r0, r0, #1
	str r0, [sp]
	movs r0, #0
	movs r1, #0x15
	bl set_tilemap_and_decompress_bg
	ldr r2, _08041718 @ =0x08488718
	ldrh r3, [r4]
	ldr r0, _0804171C @ =0x00000137
	str r0, [sp]
	movs r0, #2
	movs r1, #0x16
	bl set_tilemap_and_decompress_bg
	ldr r0, _08041720 @ =0x084E2E58
	ldr r1, _08041724 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08041728 @ =0x03000440
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080416F8: .4byte 0x084878EC
_080416FC: .4byte 0x06002600
_08041700: .4byte 0x0848796C
_08041704: .4byte 0x060026E0
_08041708: .4byte 0x084C7318
_0804170C: .4byte 0x06017E00
_08041710: .4byte 0x084886D0
_08041714: .4byte 0x04000008
_08041718: .4byte 0x08488718
_0804171C: .4byte 0x00000137
_08041720: .4byte 0x084E2E58
_08041724: .4byte 0x050003C0
_08041728: .4byte 0x03000440
	.syntax divided
