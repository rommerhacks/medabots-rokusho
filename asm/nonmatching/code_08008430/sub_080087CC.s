	.syntax unified

	thumb_func_start sub_080087CC
sub_080087CC: @ 0x080087CC
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	movs r5, #0x80
	lsls r5, r5, #0x13
	ldrh r1, [r5]
	ldr r0, _08008908 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r5]
	ldr r4, _0800890C @ =0x04000008
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r1, #0
	strh r0, [r4]
	ldr r6, _08008910 @ =0x0400000A
	ldr r2, _08008914 @ =0x00001801
	adds r0, r2, #0
	strh r0, [r6]
	ldr r0, _08008918 @ =0x0400000C
	mov r8, r0
	ldr r1, _0800891C @ =0x00001902
	adds r0, r1, #0
	mov r2, r8
	strh r0, [r2]
	ldr r0, _08008920 @ =0x0400000E
	mov sb, r0
	ldr r1, _08008924 @ =0x00001A03
	adds r0, r1, #0
	mov r2, sb
	strh r0, [r2]
	ldr r0, _08008928 @ =0x084EAC58
	ldr r1, _0800892C @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _08008930 @ =0x084C3208
	ldr r1, _08008934 @ =0x06007480
	bl lz_decompress_dispatch
	ldr r0, _08008938 @ =0x084C3648
	ldr r1, _0800893C @ =0x06007880
	bl lz_decompress_dispatch
	ldr r0, _08008940 @ =0x084C7318
	ldr r1, _08008944 @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r2, _08008948 @ =0x084EF4E0
	ldrh r3, [r4]
	movs r4, #0x80
	lsls r4, r4, #2
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _0800894C @ =0x084EFE28
	ldrh r3, [r6]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08008950 @ =0x084F0A00
	mov r0, r8
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _08008954 @ =0x084F1BA0
	mov r1, sb
	ldrh r3, [r1]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r0, _08008958 @ =0x084F32A0
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x70
	bl CpuFastSet
	ldr r4, _0800895C @ =0x0850DD18
	ldr r1, _08008960 @ =0x05000380
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	adds r4, #0x20
	ldr r1, _08008964 @ =0x050003A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08008968 @ =0x084E2E58
	ldr r1, _0800896C @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	movs r4, #0
	str r4, [sp, #4]
	ldr r1, _08008970 @ =0x03002C30
	ldr r2, _08008974 @ =0x01000800
	add r0, sp, #4
	bl CpuFastSet
	ldrh r0, [r5]
	movs r2, #0xfb
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	ldr r6, _08008978 @ =0x03000440
	adds r0, r6, #0
	adds r0, #0x48
	movs r5, #0
	strh r4, [r0]
	subs r0, #9
	strb r5, [r0]
	bl sub_08009EA0
	bl sub_08009EF4
	bl sub_08009F50
	bl sub_08009FC8
	bl sub_0800A0FC
	bl render_medal_skill_stats
	bl sub_0800B0F8
	bl draw_medal_skill_bars
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	adds r0, r6, #0
	adds r0, #0x84
	strb r5, [r0]
	ldr r1, _0800897C @ =0x0300137C
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
_08008908: .4byte 0x0000F0FF
_0800890C: .4byte 0x04000008
_08008910: .4byte 0x0400000A
_08008914: .4byte 0x00001801
_08008918: .4byte 0x0400000C
_0800891C: .4byte 0x00001902
_08008920: .4byte 0x0400000E
_08008924: .4byte 0x00001A03
_08008928: .4byte 0x084EAC58
_0800892C: .4byte 0x06004000
_08008930: .4byte 0x084C3208
_08008934: .4byte 0x06007480
_08008938: .4byte 0x084C3648
_0800893C: .4byte 0x06007880
_08008940: .4byte 0x084C7318
_08008944: .4byte 0x06017E00
_08008948: .4byte 0x084EF4E0
_0800894C: .4byte 0x084EFE28
_08008950: .4byte 0x084F0A00
_08008954: .4byte 0x084F1BA0
_08008958: .4byte 0x084F32A0
_0800895C: .4byte 0x0850DD18
_08008960: .4byte 0x05000380
_08008964: .4byte 0x050003A0
_08008968: .4byte 0x084E2E58
_0800896C: .4byte 0x050003C0
_08008970: .4byte 0x03002C30
_08008974: .4byte 0x01000800
_08008978: .4byte 0x03000440
_0800897C: .4byte 0x0300137C
	.syntax divided
