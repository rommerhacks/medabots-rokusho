	.syntax unified

	thumb_func_start sub_08007A04
sub_08007A04: @ 0x08007A04
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	movs r6, #0x80
	lsls r6, r6, #0x13
	ldrh r1, [r6]
	ldr r0, _08007B50 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r6]
	ldr r4, _08007B54 @ =0x04000008
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r1, #0
	strh r0, [r4]
	ldr r5, _08007B58 @ =0x0400000A
	ldr r2, _08007B5C @ =0x00001801
	adds r0, r2, #0
	strh r0, [r5]
	ldr r0, _08007B60 @ =0x0400000C
	mov r8, r0
	ldr r1, _08007B64 @ =0x00001902
	adds r0, r1, #0
	mov r2, r8
	strh r0, [r2]
	ldr r0, _08007B68 @ =0x0400000E
	mov sb, r0
	ldr r1, _08007B6C @ =0x00001A03
	adds r0, r1, #0
	mov r2, sb
	strh r0, [r2]
	ldr r0, _08007B70 @ =0x084E80B0
	ldr r1, _08007B74 @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _08007B78 @ =0x084C3208
	ldr r1, _08007B7C @ =0x06006280
	bl lz_decompress_dispatch
	ldr r0, _08007B80 @ =0x084C33DC
	ldr r1, _08007B84 @ =0x06006800
	bl lz_decompress_dispatch
	ldr r0, _08007B88 @ =0x084C7318
	ldr r1, _08007B8C @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r2, _08007B90 @ =0x084EF380
	ldrh r3, [r4]
	movs r4, #0x80
	lsls r4, r4, #2
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08007B94 @ =0x084EFBE0
	ldrh r3, [r5]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08007B98 @ =0x084F0688
	mov r0, r8
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08007B9C @ =0x084F16E8
	mov r1, sb
	ldrh r3, [r1]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r0, _08007BA0 @ =0x084F2D60
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x70
	bl CpuFastSet
	ldr r4, _08007BA4 @ =0x0850DE38
	ldr r1, _08007BA8 @ =0x05000340
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r0, r4, #0
	subs r0, #0x60
	ldr r1, _08007BAC @ =0x05000360
	movs r2, #8
	bl CpuFastSet
	ldr r2, _08007BB0 @ =0xFFFFFEE0
	adds r0, r4, r2
	ldr r1, _08007BB4 @ =0x05000380
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08007BB8 @ =0xFFFFFF00
	adds r0, r4, r1
	ldr r1, _08007BBC @ =0x050003A0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08007BC0 @ =0x084E2E58
	ldr r1, _08007BC4 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	movs r5, #0
	str r5, [sp, #4]
	ldr r1, _08007BC8 @ =0x03002C30
	ldr r2, _08007BCC @ =0x01000800
	add r0, sp, #4
	bl CpuFastSet
	ldrh r0, [r6]
	movs r2, #0xfb
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r6]
	ldr r4, _08007BD0 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x44
	strb r5, [r0]
	bl sub_08009E4C
	bl sub_08009EF4
	bl sub_08009F50
	bl sub_08009F90
	bl sub_0800A000
	bl sub_0800A05C
	bl sub_0800A0B8
	bl sub_0800A0FC
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	adds r4, #0x84
	strb r5, [r4]
	ldr r1, _08007BD4 @ =0x0300137C
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
_08007B50: .4byte 0x0000F0FF
_08007B54: .4byte 0x04000008
_08007B58: .4byte 0x0400000A
_08007B5C: .4byte 0x00001801
_08007B60: .4byte 0x0400000C
_08007B64: .4byte 0x00001902
_08007B68: .4byte 0x0400000E
_08007B6C: .4byte 0x00001A03
_08007B70: .4byte 0x084E80B0
_08007B74: .4byte 0x06004000
_08007B78: .4byte 0x084C3208
_08007B7C: .4byte 0x06006280
_08007B80: .4byte 0x084C33DC
_08007B84: .4byte 0x06006800
_08007B88: .4byte 0x084C7318
_08007B8C: .4byte 0x06017E00
_08007B90: .4byte 0x084EF380
_08007B94: .4byte 0x084EFBE0
_08007B98: .4byte 0x084F0688
_08007B9C: .4byte 0x084F16E8
_08007BA0: .4byte 0x084F2D60
_08007BA4: .4byte 0x0850DE38
_08007BA8: .4byte 0x05000340
_08007BAC: .4byte 0x05000360
_08007BB0: .4byte 0xFFFFFEE0
_08007BB4: .4byte 0x05000380
_08007BB8: .4byte 0xFFFFFF00
_08007BBC: .4byte 0x050003A0
_08007BC0: .4byte 0x084E2E58
_08007BC4: .4byte 0x050003C0
_08007BC8: .4byte 0x03002C30
_08007BCC: .4byte 0x01000800
_08007BD0: .4byte 0x03000440
_08007BD4: .4byte 0x0300137C
	.syntax divided
