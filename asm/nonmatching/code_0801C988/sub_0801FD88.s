	.syntax unified

	thumb_func_start sub_0801FD88
sub_0801FD88: @ 0x0801FD88
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, _0801FDD4 @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x84
	ldrb r0, [r6]
	movs r3, #9
	subs r3, r3, r0
	ldr r5, _0801FDD8 @ =0x04000008
	ldrh r0, [r5]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #0x1e
	movs r1, #1
	movs r2, #0
	bl vram_fill_tilemap_rect
	ldrb r3, [r6]
	adds r3, #0xa
	ldrh r0, [r5]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x1e
	movs r1, #1
	movs r2, #0
	bl vram_fill_tilemap_rect
	ldrb r0, [r6]
	cmp r0, #9
	bne _0801FDE0
	ldr r1, _0801FDDC @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0801FDE4
	.align 2, 0
_0801FDD4: .4byte 0x03000440
_0801FDD8: .4byte 0x04000008
_0801FDDC: .4byte 0x03001800
_0801FDE0:
	adds r0, #1
	strb r0, [r6]
_0801FDE4:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.syntax divided
