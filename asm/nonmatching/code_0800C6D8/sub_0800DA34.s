	.syntax unified

	thumb_func_start sub_0800DA34
sub_0800DA34: @ 0x0800DA34
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x10
	ldr r1, _0800DA50 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x42
	ldrb r0, [r0]
	cmp r0, #1
	bne _0800DA54
	bl load_medapart_sprite_by_slot
	b _0800DA64
	.align 2, 0
_0800DA50: .4byte 0x03000440
_0800DA54:
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #4
	bne _0800DA64
	movs r0, #7
	bl play_song
_0800DA64:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _0800DB54 @ =0x0000F0FF
	ands r0, r1
	strh r0, [r2]
	ldr r4, _0800DB58 @ =0x04000008
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r0, r1, #0
	strh r0, [r4]
	ldr r5, _0800DB5C @ =0x0400000A
	ldr r3, _0800DB60 @ =0x00001801
	adds r0, r3, #0
	strh r0, [r5]
	ldr r6, _0800DB64 @ =0x0400000C
	ldr r1, _0800DB68 @ =0x00001902
	adds r0, r1, #0
	strh r0, [r6]
	ldr r3, _0800DB6C @ =0x0400000E
	mov r8, r3
	ldr r1, _0800DB70 @ =0x00001A03
	adds r0, r1, #0
	strh r0, [r3]
	ldr r0, _0800DB74 @ =0x084EBF50
	ldr r1, _0800DB78 @ =0x06004000
	bl lz_decompress_dispatch
	ldr r0, _0800DB7C @ =0x084C4014
	ldr r1, _0800DB80 @ =0x06006000
	bl lz_decompress_dispatch
	ldr r0, _0800DB84 @ =0x084C4330
	ldr r1, _0800DB88 @ =0x06006A00
	bl lz_decompress_dispatch
	ldr r0, _0800DB8C @ =0x084C36F0
	ldr r1, _0800DB90 @ =0x06006C00
	bl lz_decompress_dispatch
	ldr r0, _0800DB94 @ =0x084C7318
	ldr r1, _0800DB98 @ =0x06017E00
	bl lz_decompress_dispatch
	ldr r0, _0800DB9C @ =0x0848833C
	ldr r1, _0800DBA0 @ =0x06007000
	bl lz_decompress_dispatch
	ldr r0, _0800DBA4 @ =0x084C6A98
	ldr r1, _0800DBA8 @ =0x06017400
	bl lz_decompress_dispatch
	ldr r2, _0800DBAC @ =0x084EF550
	ldrh r3, [r4]
	movs r4, #0x80
	lsls r4, r4, #2
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _0800DBB0 @ =0x084EFF74
	ldrh r3, [r5]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _0800DBB4 @ =0x084F0BF0
	ldrh r3, [r6]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r2, _0800DBB8 @ =0x084F1D34
	mov r0, r8
	ldrh r3, [r0]
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	bl set_tilemap_and_decompress_bg
	ldr r4, _0800DBBC @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x42
	ldrb r0, [r0]
	cmp r0, #1
	bne _0800DBE8
	ldr r0, _0800DBC0 @ =0x084F3460
	ldr r1, _0800DBC4 @ =0x0202FA00
	movs r2, #0x70
	bl CpuFastSet
	ldr r0, _0800DBC8 @ =0x05000200
	ldr r1, _0800DBCC @ =0x0202F800
	movs r2, #0x80
	bl CpuFastSet
	ldr r0, _0800DBD0 @ =0x0850DD78
	ldr r1, _0800DBD4 @ =0x0202F9A0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0800DBD8 @ =0x084E2E58
	ldr r1, _0800DBDC @ =0x0202F9C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0800DBE0 @ =0x08488B44
	ldr r1, _0800DBE4 @ =0x0202FB60
	movs r2, #8
	bl CpuFastSet
	adds r1, r4, #0
	adds r1, #0x84
	movs r0, #0
	strb r0, [r1]
	b _0800DC1C
	.align 2, 0
_0800DB54: .4byte 0x0000F0FF
_0800DB58: .4byte 0x04000008
_0800DB5C: .4byte 0x0400000A
_0800DB60: .4byte 0x00001801
_0800DB64: .4byte 0x0400000C
_0800DB68: .4byte 0x00001902
_0800DB6C: .4byte 0x0400000E
_0800DB70: .4byte 0x00001A03
_0800DB74: .4byte 0x084EBF50
_0800DB78: .4byte 0x06004000
_0800DB7C: .4byte 0x084C4014
_0800DB80: .4byte 0x06006000
_0800DB84: .4byte 0x084C4330
_0800DB88: .4byte 0x06006A00
_0800DB8C: .4byte 0x084C36F0
_0800DB90: .4byte 0x06006C00
_0800DB94: .4byte 0x084C7318
_0800DB98: .4byte 0x06017E00
_0800DB9C: .4byte 0x0848833C
_0800DBA0: .4byte 0x06007000
_0800DBA4: .4byte 0x084C6A98
_0800DBA8: .4byte 0x06017400
_0800DBAC: .4byte 0x084EF550
_0800DBB0: .4byte 0x084EFF74
_0800DBB4: .4byte 0x084F0BF0
_0800DBB8: .4byte 0x084F1D34
_0800DBBC: .4byte 0x03000440
_0800DBC0: .4byte 0x084F3460
_0800DBC4: .4byte 0x0202FA00
_0800DBC8: .4byte 0x05000200
_0800DBCC: .4byte 0x0202F800
_0800DBD0: .4byte 0x0850DD78
_0800DBD4: .4byte 0x0202F9A0
_0800DBD8: .4byte 0x084E2E58
_0800DBDC: .4byte 0x0202F9C0
_0800DBE0: .4byte 0x08488B44
_0800DBE4: .4byte 0x0202FB60
_0800DBE8:
	ldr r0, _0800DCC4 @ =0x084F3460
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x70
	bl CpuFastSet
	ldr r0, _0800DCC8 @ =0x0850DD78
	ldr r1, _0800DCCC @ =0x050003A0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0800DCD0 @ =0x084E2E58
	ldr r1, _0800DCD4 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0800DCD8 @ =0x08488B44
	ldr r1, _0800DCDC @ =0x05000160
	movs r2, #8
	bl CpuFastSet
	movs r0, #5
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
_0800DC1C:
	movs r4, #0
	str r4, [sp, #0xc]
	ldr r1, _0800DCE0 @ =0x03002C30
	ldr r2, _0800DCE4 @ =0x01000800
	add r0, sp, #0xc
	bl CpuFastSet
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0xfb
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0800DCE8 @ =0x083B4AE0
	ldr r5, _0800DCEC @ =0x03000440
	adds r0, r5, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	adds r0, #0x59
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _0800DCF0 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	movs r0, #0xa
	movs r1, #2
	movs r2, #0x10
	movs r3, #0
	bl write_tilemap_rect
	bl sub_0800EC20
	adds r0, r5, #0
	adds r0, #0x3f
	ldrb r0, [r0]
	adds r0, #1
	ldr r1, _0800DCF4 @ =0x0400000A
	ldrh r1, [r1]
	str r1, [sp]
	ldr r1, _0800DCF8 @ =0x00007360
	str r1, [sp, #4]
	movs r1, #0xb
	movs r2, #2
	movs r3, #2
	bl sub_08042950
	bl sub_0800EC44
	bl sub_0800ED10
	bl sub_0800EDA0
	bl sub_0800EE34
	bl sub_0800EEE4
	bl sub_0800EFB0
	adds r0, r5, #0
	adds r0, #0x44
	strb r4, [r0]
	subs r0, #2
	ldrb r0, [r0]
	cmp r0, #1
	beq _0800DCB0
	bl sub_0800F218
_0800DCB0:
	ldr r1, _0800DCFC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800DCC4: .4byte 0x084F3460
_0800DCC8: .4byte 0x0850DD78
_0800DCCC: .4byte 0x050003A0
_0800DCD0: .4byte 0x084E2E58
_0800DCD4: .4byte 0x050003C0
_0800DCD8: .4byte 0x08488B44
_0800DCDC: .4byte 0x05000160
_0800DCE0: .4byte 0x03002C30
_0800DCE4: .4byte 0x01000800
_0800DCE8: .4byte 0x083B4AE0
_0800DCEC: .4byte 0x03000440
_0800DCF0: .4byte 0x04000008
_0800DCF4: .4byte 0x0400000A
_0800DCF8: .4byte 0x00007360
_0800DCFC: .4byte 0x0300137C
	.syntax divided
