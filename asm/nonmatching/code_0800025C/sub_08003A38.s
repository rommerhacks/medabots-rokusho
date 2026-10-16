	.syntax unified

	thumb_func_start sub_08003A38
sub_08003A38: @ 0x08003A38
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r5, _08003A54 @ =0x03000440
	ldr r0, _08003A58 @ =0x00000139
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #1
	beq _08003B10
	cmp r0, #1
	bgt _08003A5C
	cmp r0, #0
	beq _08003A64
	b _08003D36
	.align 2, 0
_08003A54: .4byte 0x03000440
_08003A58: .4byte 0x00000139
_08003A5C:
	cmp r0, #2
	bne _08003A62
	b _08003CBC
_08003A62:
	b _08003D36
_08003A64:
	bl sub_08043CA8
	adds r0, r5, #0
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _08003A76
	bl setup_overworld_scene_from_position
_08003A76:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _08003AD4 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08003AD8 @ =0x04000008
	movs r2, #0xa0
	lsls r2, r2, #3
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _08003ADC @ =0x00001801
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _08003AE0 @ =0x00001902
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _08003AE4 @ =0x00001A03
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, _08003AE8 @ =0x084E5650
	ldr r1, _08003AEC @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _08003AF0 @ =0x084C48B4
	ldr r1, _08003AF4 @ =0x06006000
	bl lz_decompress_dispatch
	ldr r0, _08003AF8 @ =0x084C4A34
	ldr r1, _08003AFC @ =0x06006200
	bl lz_decompress_dispatch
	ldr r0, _08003B00 @ =0x084C7428
	ldr r1, _08003B04 @ =0x06016C00
	bl lz_decompress_dispatch
	ldr r0, _08003B08 @ =0x084C6A98
	ldr r1, _08003B0C @ =0x06017400
	bl lz_decompress_dispatch
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _08003D36
	.align 2, 0
_08003AD4: .4byte 0x0000F0FF
_08003AD8: .4byte 0x04000008
_08003ADC: .4byte 0x00001801
_08003AE0: .4byte 0x00001902
_08003AE4: .4byte 0x00001A03
_08003AE8: .4byte 0x084E5650
_08003AEC: .4byte 0x06004000
_08003AF0: .4byte 0x084C48B4
_08003AF4: .4byte 0x06006000
_08003AF8: .4byte 0x084C4A34
_08003AFC: .4byte 0x06006200
_08003B00: .4byte 0x084C7428
_08003B04: .4byte 0x06016C00
_08003B08: .4byte 0x084C6A98
_08003B0C: .4byte 0x06017400
_08003B10:
	adds r6, r5, #0
	adds r6, #0x56
	ldrb r0, [r6]
	cmp r0, #1
	bne _08003B1E
	bl setup_overworld_scene_from_position
_08003B1E:
	ldr r2, _08003BB4 @ =0x084EF2D8
	ldr r0, _08003BB8 @ =0x04000008
	ldrh r3, [r0]
	movs r4, #0x80
	lsls r4, r4, #2
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08003BBC @ =0x084EF95C
	ldr r0, _08003BC0 @ =0x0400000A
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08003BC4 @ =0x084F02B8
	ldr r0, _08003BC8 @ =0x0400000C
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08003BCC @ =0x084F122C
	ldr r0, _08003BD0 @ =0x0400000E
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldrb r0, [r6]
	cmp r0, #1
	bne _08003C00
	ldr r0, _08003BD4 @ =0x084F2680
	ldr r1, _08003BD8 @ =0x0202FA00
	movs r2, #0x60
	bl CpuFastSet
	ldr r0, _08003BDC @ =0x0850DEF8
	ldr r1, _08003BE0 @ =0x0202F800
	movs r2, #0x40
	bl CpuFastSet
	ldr r4, _08003BE4 @ =0x0850DD18
	ldr r1, _08003BE8 @ =0x0202F9A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r4, #0x20
	ldr r1, _08003BEC @ =0x0202F9C0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08003BF0 @ =0x084E2EB8
	ldr r1, _08003BF4 @ =0x0202F980
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08003BF8 @ =0x084E2ED8
	ldr r1, _08003BFC @ =0x0202F9E0
	movs r2, #8
	bl CpuFastSet
	adds r1, r5, #0
	adds r1, #0x84
	movs r0, #0
	strb r0, [r1]
	b _08003C4C
	.align 2, 0
_08003BB4: .4byte 0x084EF2D8
_08003BB8: .4byte 0x04000008
_08003BBC: .4byte 0x084EF95C
_08003BC0: .4byte 0x0400000A
_08003BC4: .4byte 0x084F02B8
_08003BC8: .4byte 0x0400000C
_08003BCC: .4byte 0x084F122C
_08003BD0: .4byte 0x0400000E
_08003BD4: .4byte 0x084F2680
_08003BD8: .4byte 0x0202FA00
_08003BDC: .4byte 0x0850DEF8
_08003BE0: .4byte 0x0202F800
_08003BE4: .4byte 0x0850DD18
_08003BE8: .4byte 0x0202F9A0
_08003BEC: .4byte 0x0202F9C0
_08003BF0: .4byte 0x084E2EB8
_08003BF4: .4byte 0x0202F980
_08003BF8: .4byte 0x084E2ED8
_08003BFC: .4byte 0x0202F9E0
_08003C00:
	ldr r0, _08003C80 @ =0x084F2680
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x60
	bl CpuFastSet
	ldr r0, _08003C84 @ =0x0850DEF8
	ldr r1, _08003C88 @ =0x05000200
	movs r2, #0x40
	bl CpuFastSet
	ldr r4, _08003C8C @ =0x0850DD18
	ldr r1, _08003C90 @ =0x050003A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r4, #0x20
	ldr r1, _08003C94 @ =0x050003C0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08003C98 @ =0x084E2EB8
	ldr r1, _08003C9C @ =0x05000380
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08003CA0 @ =0x084E2ED8
	ldr r1, _08003CA4 @ =0x050003E0
	movs r2, #8
	bl CpuFastSet
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
_08003C4C:
	movs r0, #0
	str r0, [sp, #4]
	ldr r1, _08003CA8 @ =0x03002C30
	ldr r2, _08003CAC @ =0x01000800
	add r0, sp, #4
	bl CpuFastSet
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0xfa
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r1, [r2]
	ldr r0, _08003CB0 @ =0x0000FFDF
	ands r0, r1
	strh r0, [r2]
	ldr r0, _08003CB4 @ =0x03000440
	ldr r2, _08003CB8 @ =0x00000139
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	b _08003D34
	.align 2, 0
_08003C80: .4byte 0x084F2680
_08003C84: .4byte 0x0850DEF8
_08003C88: .4byte 0x05000200
_08003C8C: .4byte 0x0850DD18
_08003C90: .4byte 0x050003A0
_08003C94: .4byte 0x050003C0
_08003C98: .4byte 0x084E2EB8
_08003C9C: .4byte 0x05000380
_08003CA0: .4byte 0x084E2ED8
_08003CA4: .4byte 0x050003E0
_08003CA8: .4byte 0x03002C30
_08003CAC: .4byte 0x01000800
_08003CB0: .4byte 0x0000FFDF
_08003CB4: .4byte 0x03000440
_08003CB8: .4byte 0x00000139
_08003CBC:
	adds r4, r5, #0
	adds r4, #0x56
	ldrb r0, [r4]
	cmp r0, #1
	bne _08003CCA
	bl setup_overworld_scene_from_position
_08003CCA:
	adds r1, r5, #0
	adds r1, #0x96
	movs r0, #1
	strb r0, [r1]
	bl sub_08004FD0
	bl sub_08005000
	bl sub_08004E98
	bl sub_0800508C
	bl sub_08005118
	bl sub_0800519C
	bl sub_0800522C
	bl sub_08005948
	bl sub_0800750C
	ldrb r0, [r4]
	cmp r0, #0
	bne _08003D12
	bl sub_0800529C
	adds r0, r5, #0
	adds r0, #0x50
	ldrb r0, [r0]
	cmp r0, #3
	bne _08003D24
	movs r0, #7
	bl play_song
	b _08003D24
_08003D12:
	adds r0, r5, #0
	adds r0, #0x52
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08003D24
	bl sub_08005628
_08003D24:
	ldr r1, _08003D40 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, _08003D44 @ =0x03000440
	ldr r3, _08003D48 @ =0x00000139
	adds r1, r0, r3
	movs r0, #0
_08003D34:
	strb r0, [r1]
_08003D36:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08003D40: .4byte 0x0300137C
_08003D44: .4byte 0x03000440
_08003D48: .4byte 0x00000139
	.syntax divided
