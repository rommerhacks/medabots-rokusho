	.syntax unified

	thumb_func_start sub_08007E38
sub_08007E38: @ 0x08007E38
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	movs r5, #0x80
	lsls r5, r5, #0x13
	ldrh r1, [r5]
	ldr r0, _08007F94 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r5]
	ldr r4, _08007F98 @ =0x04000008
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r1, #0
	strh r0, [r4]
	ldr r6, _08007F9C @ =0x0400000A
	ldr r2, _08007FA0 @ =0x00001801
	adds r0, r2, #0
	strh r0, [r6]
	ldr r0, _08007FA4 @ =0x0400000C
	mov r8, r0
	ldr r1, _08007FA8 @ =0x00001902
	adds r0, r1, #0
	mov r2, r8
	strh r0, [r2]
	ldr r0, _08007FAC @ =0x0400000E
	mov sb, r0
	ldr r1, _08007FB0 @ =0x00001A03
	adds r0, r1, #0
	mov r2, sb
	strh r0, [r2]
	ldr r0, _08007FB4 @ =0x084E9020
	ldr r1, _08007FB8 @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _08007FBC @ =0x084C3208
	ldr r1, _08007FC0 @ =0x06006280
	bl lz_decompress_dispatch
	ldr r0, _08007FC4 @ =0x084C3524
	ldr r1, _08007FC8 @ =0x06006000
	bl lz_decompress_dispatch
	ldr r0, _08007FCC @ =0x084C3648
	ldr r1, _08007FD0 @ =0x06006680
	bl lz_decompress_dispatch
	ldr r0, _08007FD4 @ =0x084C7318
	ldr r1, _08007FD8 @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r2, _08007FDC @ =0x084EF3F4
	ldrh r3, [r4]
	movs r4, #0x80
	lsls r4, r4, #2
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08007FE0 @ =0x084EFCDC
	ldrh r3, [r6]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08007FE4 @ =0x084F07B8
	mov r0, r8
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08007FE8 @ =0x084F187C
	mov r1, sb
	ldrh r3, [r1]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r0, _08007FEC @ =0x084F2F20
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x70
	bl CpuFastSet
	ldr r4, _08007FF0 @ =0x0850DDB8
	ldr r1, _08007FF4 @ =0x05000340
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r0, r4, #0
	adds r0, #0x20
	ldr r1, _08007FF8 @ =0x05000360
	movs r2, #8
	bl CpuFastSet
	adds r0, r4, #0
	subs r0, #0xa0
	ldr r1, _08007FFC @ =0x05000380
	movs r2, #8
	bl CpuFastSet
	subs r4, #0x80
	ldr r1, _08008000 @ =0x050003A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08008004 @ =0x084E2E58
	ldr r1, _08008008 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	movs r4, #0
	str r4, [sp, #4]
	ldr r1, _0800800C @ =0x03002C30
	ldr r2, _08008010 @ =0x01000800
	add r0, sp, #4
	bl CpuFastSet
	ldrh r0, [r5]
	movs r2, #0xfb
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	ldr r5, _08008014 @ =0x03000440
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
	bl sub_0800A2E8
	bl sub_0800A594
	bl sub_0800A854
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	adds r0, r5, #0
	adds r0, #0x84
	strb r4, [r0]
	ldr r1, _08008018 @ =0x0300137C
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
_08007F94: .4byte 0x0000F0FF
_08007F98: .4byte 0x04000008
_08007F9C: .4byte 0x0400000A
_08007FA0: .4byte 0x00001801
_08007FA4: .4byte 0x0400000C
_08007FA8: .4byte 0x00001902
_08007FAC: .4byte 0x0400000E
_08007FB0: .4byte 0x00001A03
_08007FB4: .4byte 0x084E9020
_08007FB8: .4byte 0x06004000
_08007FBC: .4byte 0x084C3208
_08007FC0: .4byte 0x06006280
_08007FC4: .4byte 0x084C3524
_08007FC8: .4byte 0x06006000
_08007FCC: .4byte 0x084C3648
_08007FD0: .4byte 0x06006680
_08007FD4: .4byte 0x084C7318
_08007FD8: .4byte 0x06017E00
_08007FDC: .4byte 0x084EF3F4
_08007FE0: .4byte 0x084EFCDC
_08007FE4: .4byte 0x084F07B8
_08007FE8: .4byte 0x084F187C
_08007FEC: .4byte 0x084F2F20
_08007FF0: .4byte 0x0850DDB8
_08007FF4: .4byte 0x05000340
_08007FF8: .4byte 0x05000360
_08007FFC: .4byte 0x05000380
_08008000: .4byte 0x050003A0
_08008004: .4byte 0x084E2E58
_08008008: .4byte 0x050003C0
_0800800C: .4byte 0x03002C30
_08008010: .4byte 0x01000800
_08008014: .4byte 0x03000440
_08008018: .4byte 0x0300137C
	.syntax divided
