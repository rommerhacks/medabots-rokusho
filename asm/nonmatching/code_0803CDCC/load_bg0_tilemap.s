	.syntax unified

	thumb_func_start load_bg0_tilemap
	.global load_bg0_tilemap
load_bg0_tilemap: @ 0x0803F480
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0xc
	adds r4, r0, #0
	mov r8, r2
	mov sb, r3
	ldr r5, [sp, #0x24]
	movs r3, #0x80
	lsls r3, r3, #0x13
	ldrh r0, [r3]
	movs r6, #0x80
	lsls r6, r6, #1
	adds r2, r6, #0
	orrs r0, r2
	strh r0, [r3]
	ldr r6, _0803F504 @ =0x04000008
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r2, #0
	strh r0, [r6]
	ldr r2, _0803F508 @ =0x083AFD08
	lsls r0, r4, #3
	adds r0, r0, r4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r1, _0803F50C @ =0x06000F80
	bl lz_decompress_dispatch
	ldr r0, _0803F510 @ =0x083B15C8
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r0, [r4]
	ldr r1, _0803F514 @ =0x050001A0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _0803F518 @ =0x083B4AE0
	lsls r0, r5, #3
	adds r0, r0, r5
	adds r0, #8
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp]
	ldrh r0, [r6]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #8
	movs r1, #8
	mov r2, r8
	mov r3, sb
	bl write_tilemap_rect
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803F504: .4byte 0x04000008
_0803F508: .4byte 0x083AFD08
_0803F50C: .4byte 0x06000F80
_0803F510: .4byte 0x083B15C8
_0803F514: .4byte 0x050001A0
_0803F518: .4byte 0x083B4AE0
	.syntax divided
