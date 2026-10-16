	.syntax unified

	thumb_func_start sub_08008234
sub_08008234: @ 0x08008234
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	movs r5, #0x80
	lsls r5, r5, #0x13
	ldrh r1, [r5]
	ldr r0, _08008398 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r5]
	ldr r4, _0800839C @ =0x04000008
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r1, #0
	strh r0, [r4]
	ldr r6, _080083A0 @ =0x0400000A
	ldr r2, _080083A4 @ =0x00001801
	adds r0, r2, #0
	strh r0, [r6]
	ldr r0, _080083A8 @ =0x0400000C
	mov r8, r0
	ldr r1, _080083AC @ =0x00001902
	adds r0, r1, #0
	mov r2, r8
	strh r0, [r2]
	ldr r0, _080083B0 @ =0x0400000E
	mov sb, r0
	ldr r1, _080083B4 @ =0x00001A03
	adds r0, r1, #0
	mov r2, sb
	strh r0, [r2]
	ldr r0, _080083B8 @ =0x084E9E68
	ldr r1, _080083BC @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _080083C0 @ =0x084C3208
	ldr r1, _080083C4 @ =0x06006280
	bl lz_decompress_dispatch
	ldr r0, _080083C8 @ =0x084C37A4
	ldr r1, _080083CC @ =0x06006800
	bl lz_decompress_dispatch
	ldr r0, _080083D0 @ =0x084C3990
	ldr r1, _080083D4 @ =0x06006C00
	bl lz_decompress_dispatch
	ldr r0, _080083D8 @ =0x084C48B4
	ldr r1, _080083DC @ =0x06007400
	bl lz_decompress_dispatch
	ldr r0, _080083E0 @ =0x084C4A34
	ldr r1, _080083E4 @ =0x06007600
	bl lz_decompress_dispatch
	ldr r0, _080083E8 @ =0x084C7318
	ldr r1, _080083EC @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r2, _080083F0 @ =0x084EF46C
	ldrh r3, [r4]
	movs r4, #0x80
	lsls r4, r4, #2
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _080083F4 @ =0x084EFD74
	ldrh r3, [r6]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _080083F8 @ =0x084F08F0
	mov r0, r8
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _080083FC @ =0x084F1A10
	mov r1, sb
	ldrh r3, [r1]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r0, _08008400 @ =0x084F30E0
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x70
	bl CpuFastSet
	ldr r0, _08008404 @ =0x0850DEF8
	ldr r1, _08008408 @ =0x05000200
	movs r2, #0x40
	bl CpuFastSet
	ldr r4, _0800840C @ =0x0850DD18
	ldr r1, _08008410 @ =0x05000380
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r4, #0x20
	ldr r1, _08008414 @ =0x050003A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08008418 @ =0x084E2E58
	ldr r1, _0800841C @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	movs r4, #0
	str r4, [sp, #4]
	ldr r1, _08008420 @ =0x03002C30
	ldr r2, _08008424 @ =0x01000800
	add r0, sp, #4
	bl CpuFastSet
	ldrh r0, [r5]
	movs r2, #0xfb
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	ldr r5, _08008428 @ =0x03000440
	adds r0, r5, #0
	adds r0, #0x44
	strb r4, [r0]
	adds r0, #2
	strb r4, [r0]
	bl sub_08009E4C
	bl sub_08009EF4
	bl sub_08009F50
	bl sub_08009F90
	bl sub_0800A0FC
	bl sub_0800AB0C
	bl sub_0800ABA4
	bl sub_0800AED0
	bl sub_0800AF0C
	bl sub_0800AF64
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	adds r0, r5, #0
	adds r0, #0x84
	strb r4, [r0]
	ldr r1, _0800842C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08008398: .4byte 0x0000F0FF
_0800839C: .4byte 0x04000008
_080083A0: .4byte 0x0400000A
_080083A4: .4byte 0x00001801
_080083A8: .4byte 0x0400000C
_080083AC: .4byte 0x00001902
_080083B0: .4byte 0x0400000E
_080083B4: .4byte 0x00001A03
_080083B8: .4byte 0x084E9E68
_080083BC: .4byte 0x06004000
_080083C0: .4byte 0x084C3208
_080083C4: .4byte 0x06006280
_080083C8: .4byte 0x084C37A4
_080083CC: .4byte 0x06006800
_080083D0: .4byte 0x084C3990
_080083D4: .4byte 0x06006C00
_080083D8: .4byte 0x084C48B4
_080083DC: .4byte 0x06007400
_080083E0: .4byte 0x084C4A34
_080083E4: .4byte 0x06007600
_080083E8: .4byte 0x084C7318
_080083EC: .4byte 0x06017E00
_080083F0: .4byte 0x084EF46C
_080083F4: .4byte 0x084EFD74
_080083F8: .4byte 0x084F08F0
_080083FC: .4byte 0x084F1A10
_08008400: .4byte 0x084F30E0
_08008404: .4byte 0x0850DEF8
_08008408: .4byte 0x05000200
_0800840C: .4byte 0x0850DD18
_08008410: .4byte 0x05000380
_08008414: .4byte 0x050003A0
_08008418: .4byte 0x084E2E58
_0800841C: .4byte 0x050003C0
_08008420: .4byte 0x03002C30
_08008424: .4byte 0x01000800
_08008428: .4byte 0x03000440
_0800842C: .4byte 0x0300137C
	.syntax divided
