	.syntax unified

	thumb_func_start setup_bg_layers_and_decompress
setup_bg_layers_and_decompress: @ 0x08003394
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0xc
	bl sub_080415BC
	movs r6, #0x80
	lsls r6, r6, #0x13
	ldrh r1, [r6]
	ldr r0, _0800345C @ =0x0000F1FF
	ands r0, r1
	strh r0, [r6]
	ldr r5, _08003460 @ =0x0400000A
	ldr r1, _08003464 @ =0x00001805
	adds r0, r1, #0
	strh r0, [r5]
	ldr r2, _08003468 @ =0x0400000C
	mov r8, r2
	ldr r1, _0800346C @ =0x00001906
	adds r0, r1, #0
	strh r0, [r2]
	adds r2, #2
	mov sb, r2
	ldr r1, _08003470 @ =0x00001A07
	adds r0, r1, #0
	strh r0, [r2]
	ldr r0, _08003474 @ =0x084E30D8
	ldr r1, _08003478 @ =0x06004000
	bl lz_decompress_dispatch
	bl sub_08003904
	ldr r2, _0800347C @ =0x084EF6A0
	ldrh r3, [r5]
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08003480 @ =0x084F023C
	mov r0, r8
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08003484 @ =0x084F0F2C
	mov r1, sb
	ldrh r3, [r1]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r1, _08003488 @ =0x040000D4
	ldr r0, _0800348C @ =0x084F24E0
	str r0, [r1]
	ldr r0, _08003490 @ =0x0202FA00
	str r0, [r1, #4]
	ldr r0, _08003494 @ =0x84000060
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08003498 @ =0x083B4AE0
	movs r2, #0x90
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [sp]
	ldrh r0, [r5]
	str r0, [sp, #4]
	str r4, [sp, #8]
	movs r0, #4
	movs r1, #4
	movs r2, #5
	movs r3, #9
	bl write_tilemap_rect
	ldrh r0, [r6]
	movs r2, #0xfb
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r6]
	ldr r0, _0800349C @ =0x03000440
	adds r0, #0x84
	strb r4, [r0]
	ldr r1, _080034A0 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800345C: .4byte 0x0000F1FF
_08003460: .4byte 0x0400000A
_08003464: .4byte 0x00001805
_08003468: .4byte 0x0400000C
_0800346C: .4byte 0x00001906
_08003470: .4byte 0x00001A07
_08003474: .4byte 0x084E30D8
_08003478: .4byte 0x06004000
_0800347C: .4byte 0x084EF6A0
_08003480: .4byte 0x084F023C
_08003484: .4byte 0x084F0F2C
_08003488: .4byte 0x040000D4
_0800348C: .4byte 0x084F24E0
_08003490: .4byte 0x0202FA00
_08003494: .4byte 0x84000060
_08003498: .4byte 0x083B4AE0
_0800349C: .4byte 0x03000440
_080034A0: .4byte 0x0300137C
	.syntax divided
