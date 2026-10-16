	.syntax unified

	thumb_func_start sub_0803DCDC
sub_0803DCDC: @ 0x0803DCDC
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	bl sub_08043CA8
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	movs r5, #0x80
	lsls r5, r5, #0x13
	ldrh r1, [r5]
	ldr r0, _0803DDFC @ =0x0000E0FF
	ands r0, r1
	strh r0, [r5]
	ldr r4, _0803DE00 @ =0x04000008
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r1, #0
	strh r0, [r4]
	ldr r6, _0803DE04 @ =0x0400000A
	ldr r2, _0803DE08 @ =0x00001801
	adds r0, r2, #0
	strh r0, [r6]
	ldr r0, _0803DE0C @ =0x0400000C
	mov r8, r0
	ldr r1, _0803DE10 @ =0x00001902
	adds r0, r1, #0
	mov r2, r8
	strh r0, [r2]
	ldr r0, _0803DE14 @ =0x0400000E
	mov sb, r0
	ldr r1, _0803DE18 @ =0x00001B03
	adds r0, r1, #0
	mov r2, sb
	strh r0, [r2]
	ldr r0, _0803DE1C @ =0x084EDEF0
	ldr r1, _0803DE20 @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _0803DE24 @ =0x084C66B8
	ldr r1, _0803DE28 @ =0x06007000
	bl lz_decompress_dispatch
	ldr r0, _0803DE2C @ =0x084C68E0
	ldr r1, _0803DE30 @ =0x06007A00
	bl lz_decompress_dispatch
	ldr r0, _0803DE34 @ =0x084C6A98
	ldr r1, _0803DE38 @ =0x06017400
	bl lz_decompress_dispatch
	ldr r0, _0803DE3C @ =0x084E20F8
	ldr r1, _0803DE40 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r2, _0803DE44 @ =0x084EF668
	ldrh r3, [r4]
	movs r4, #0x80
	lsls r4, r4, #2
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _0803DE48 @ =0x084F0194
	ldrh r3, [r6]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _0803DE4C @ =0x084F0D9C
	mov r0, r8
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _0803DE50 @ =0x084F21E8
	mov r1, sb
	ldrh r3, [r1]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r0, _0803DE54 @ =0x084F39A0
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x60
	bl CpuFastSet
	ldr r0, _0803DE58 @ =0x0850EF58
	ldr r1, _0803DE5C @ =0x05000200
	movs r2, #0x10
	bl CpuFastSet
	movs r4, #0
	str r4, [sp, #4]
	ldr r1, _0803DE60 @ =0x03002C30
	ldr r2, _0803DE64 @ =0x01000800
	add r0, sp, #4
	bl CpuFastSet
	ldrh r0, [r5]
	movs r2, #0xfb
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r5]
	bl sub_0803E8B8
	bl sub_0803E8EC
	bl sub_0803E934
	bl sub_0803E978
	bl sub_0803E9BC
	ldr r0, _0803DE68 @ =0x03001800
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r0, r1
	strb r4, [r0]
	movs r0, #0x14
	bl play_song
	ldr r1, _0803DE6C @ =0x0300137C
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
_0803DDFC: .4byte 0x0000E0FF
_0803DE00: .4byte 0x04000008
_0803DE04: .4byte 0x0400000A
_0803DE08: .4byte 0x00001801
_0803DE0C: .4byte 0x0400000C
_0803DE10: .4byte 0x00001902
_0803DE14: .4byte 0x0400000E
_0803DE18: .4byte 0x00001B03
_0803DE1C: .4byte 0x084EDEF0
_0803DE20: .4byte 0x06004000
_0803DE24: .4byte 0x084C66B8
_0803DE28: .4byte 0x06007000
_0803DE2C: .4byte 0x084C68E0
_0803DE30: .4byte 0x06007A00
_0803DE34: .4byte 0x084C6A98
_0803DE38: .4byte 0x06017400
_0803DE3C: .4byte 0x084E20F8
_0803DE40: .4byte 0x06010000
_0803DE44: .4byte 0x084EF668
_0803DE48: .4byte 0x084F0194
_0803DE4C: .4byte 0x084F0D9C
_0803DE50: .4byte 0x084F21E8
_0803DE54: .4byte 0x084F39A0
_0803DE58: .4byte 0x0850EF58
_0803DE5C: .4byte 0x05000200
_0803DE60: .4byte 0x03002C30
_0803DE64: .4byte 0x01000800
_0803DE68: .4byte 0x03001800
_0803DE6C: .4byte 0x0300137C
	.syntax divided
