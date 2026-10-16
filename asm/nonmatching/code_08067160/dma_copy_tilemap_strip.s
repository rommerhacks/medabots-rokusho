	.syntax unified

	thumb_func_start dma_copy_tilemap_strip
dma_copy_tilemap_strip: @ 0x08069288
	push {r4, r5, r6, r7, lr}
	sub sp, #0x30
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r2, #0
	ldr r7, _080692E0 @ =0x0300057C
	lsls r0, r3, #3
	ldr r1, _080692E4 @ =0xFFFF9200
	adds r6, r0, r1
	ldr r1, _080692E8 @ =0xFFFFA240
	adds r5, r0, r1
	ldr r1, _080692EC @ =0xFFFFB280
	adds r4, r0, r1
	mov r1, sp
_080692A4:
	adds r0, r6, r2
	strh r0, [r1]
	adds r0, r5, r2
	strh r0, [r1, #0x10]
	adds r0, r4, r2
	strh r0, [r1, #0x20]
	adds r1, #2
	adds r2, #1
	cmp r2, #7
	ble _080692A4
	ldr r1, _080692F0 @ =0x040000D4
	mov r2, sp
	str r2, [r1]
	lsls r0, r3, #6
	ldr r2, _080692F4 @ =0x0600F000
	adds r0, r0, r2
	str r0, [r1, #4]
	ldr r0, _080692F8 @ =0x80000018
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xc
	subs r0, r0, r3
	lsls r0, r0, #3
	rsbs r0, r0, #0
	strh r0, [r7, #2]
	add sp, #0x30
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080692E0: .4byte 0x0300057C
_080692E4: .4byte 0xFFFF9200
_080692E8: .4byte 0xFFFFA240
_080692EC: .4byte 0xFFFFB280
_080692F0: .4byte 0x040000D4
_080692F4: .4byte 0x0600F000
_080692F8: .4byte 0x80000018
	.syntax divided
