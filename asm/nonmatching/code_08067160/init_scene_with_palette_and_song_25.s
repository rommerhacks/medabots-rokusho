	.syntax unified

	thumb_func_start init_scene_with_palette_and_song_25
init_scene_with_palette_and_song_25: @ 0x08067B6C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x24
	mov r4, sp
	mov r0, sp
	movs r1, #0
	movs r2, #0x20
	bl custom_memset
	movs r5, #0
	ldr r0, _08067D18 @ =0x00006FFF
	strh r0, [r4, #2]
	ldr r0, _08067D1C @ =0x00006B7A
	strh r0, [r4, #4]
	ldr r0, _08067D20 @ =0x000066D5
	strh r0, [r4, #6]
	ldr r0, _08067D24 @ =0x0000622F
	strh r0, [r4, #8]
	ldr r0, _08067D28 @ =0x030017EC
	ldrb r6, [r0]
	movs r0, #0x19
	bl play_song
	str r5, [sp, #0x20]
	add r0, sp, #0x20
	movs r1, #0xc0
	lsls r1, r1, #0x13
	mov r8, r1
	ldr r2, _08067D2C @ =0x01006000
	bl CpuFastSet
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	bl sub_080415BC
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x60
	strh r0, [r1]
	adds r1, #0xa
	ldr r2, _08067D30 @ =0x00001E05
	adds r0, r2, #0
	strh r0, [r1]
	ldr r4, _08067D34 @ =0x0400000C
	ldr r2, _08067D38 @ =0x00003D06
	adds r0, r2, #0
	strh r0, [r4]
	ldr r5, _08067D3C @ =0x0400000E
	ldr r2, _08067D40 @ =0x00001C07
	adds r0, r2, #0
	strh r0, [r5]
	ldr r0, _08067D44 @ =0x087A7F98
	ldrh r1, [r1]
	bl decompress_and_write_tilemap
	ldr r0, _08067D48 @ =0x087A80E8
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	ldr r0, _08067D4C @ =0x087A8324
	ldrh r1, [r5]
	bl decompress_and_write_tilemap
	ldr r0, _08067D50 @ =0x087A46F8
	ldr r4, _08067D54 @ =0x02030000
	adds r1, r4, #0
	bl dma3_copy_or_decompress
	adds r5, r0, #0
	ldr r1, _08067D58 @ =0x06004000
	lsls r2, r5, #9
	lsrs r2, r2, #0xb
	adds r0, r4, #0
	bl CpuFastSet
	movs r5, #0xc0
	lsls r5, r5, #5
	ldr r0, _08067D5C @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0xc4
	strh r0, [r1, #0x36]
	ldr r0, _08067D60 @ =0x03000BE0
	lsls r6, r6, #6
	adds r6, r6, r0
	ldrb r0, [r6, #1]
	lsls r0, r0, #7
	ldr r1, _08067D64 @ =0x084C21BC
	adds r0, r0, r1
	add r8, r5
	mov r1, r8
	movs r2, #0x20
	bl CpuFastSet
	ldr r0, _08067D68 @ =0x084C3208
	ldr r1, _08067D6C @ =0x06000080
	adds r1, r5, r1
	bl lz_decompress_dispatch
	ldr r2, _08067D70 @ =0x000060C0
	ldr r0, _08067D74 @ =0x04000008
	ldrh r0, [r0]
	lsrs r0, r0, #8
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #0xb
	ldr r1, _08067D78 @ =0x06000286
	adds r3, r0, r1
	strh r2, [r3]
	adds r1, #2
	adds r3, r0, r1
	adds r1, r2, #1
	strh r1, [r3]
	ldr r1, _08067D7C @ =0x060002C6
	adds r3, r0, r1
	adds r1, r2, #2
	strh r1, [r3]
	ldr r1, _08067D80 @ =0x060002C8
	adds r3, r0, r1
	adds r2, #3
	strh r2, [r3]
	ldr r0, _08067D84 @ =0x087A44F8
	ldr r1, _08067D88 @ =0x0202FA00
	movs r2, #0x80
	bl CpuFastSet
	ldr r0, _08067D8C @ =0x084E2E38
	ldr r1, _08067D90 @ =0x0202F9E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08067D94 @ =0x08785F34
	ldr r1, _08067D98 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _08067D9C @ =0x084E2E98
	ldr r1, _08067DA0 @ =0x0202F800
	movs r2, #8
	bl CpuFastSet
	ldr r4, _08067DA4 @ =0x0850DD58
	ldr r1, _08067DA8 @ =0x0202F820
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	subs r4, #0x40
	ldr r1, _08067DAC @ =0x0202F840
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08067DB0 @ =0x0202F860
	mov r0, sp
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08067DB4 @ =0x084C6A98
	ldr r1, _08067DB8 @ =0x06017400
	bl lz_decompress_dispatch
	movs r2, #0
	ldr r0, _08067DBC @ =0x03002C30
	movs r4, #3
	ldr r7, _08067DC0 @ =0x00000117
	adds r1, r0, #0
	adds r1, #0x40
	movs r6, #0xca
	lsls r6, r6, #8
	movs r5, #0x78
	movs r3, #0x40
_08067CC6:
	strh r6, [r1]
	strh r5, [r1, #2]
	movs r0, #0x28
	strh r0, [r1, #4]
	movs r0, #2
	strb r0, [r1, #0x1c]
	strb r4, [r1, #0xa]
	strh r7, [r1, #6]
	strb r3, [r1, #8]
	strb r3, [r1, #9]
	adds r0, r2, #0
	ands r0, r4
	lsls r0, r0, #4
	strh r0, [r1, #0x1a]
	adds r1, #0x40
	adds r2, #1
	cmp r2, #0xf
	ble _08067CC6
	ldr r1, _08067DC4 @ =0x04000050
	movs r2, #0xc4
	lsls r2, r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _08067DC8 @ =0x00001010
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	movs r0, #8
	strh r0, [r1]
	ldr r1, _08067DCC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08067D18: .4byte 0x00006FFF
_08067D1C: .4byte 0x00006B7A
_08067D20: .4byte 0x000066D5
_08067D24: .4byte 0x0000622F
_08067D28: .4byte 0x030017EC
_08067D2C: .4byte 0x01006000
_08067D30: .4byte 0x00001E05
_08067D34: .4byte 0x0400000C
_08067D38: .4byte 0x00003D06
_08067D3C: .4byte 0x0400000E
_08067D40: .4byte 0x00001C07
_08067D44: .4byte 0x087A7F98
_08067D48: .4byte 0x087A80E8
_08067D4C: .4byte 0x087A8324
_08067D50: .4byte 0x087A46F8
_08067D54: .4byte 0x02030000
_08067D58: .4byte 0x06004000
_08067D5C: .4byte 0x03006F74
_08067D60: .4byte 0x03000BE0
_08067D64: .4byte 0x084C21BC
_08067D68: .4byte 0x084C3208
_08067D6C: .4byte 0x06000080
_08067D70: .4byte 0x000060C0
_08067D74: .4byte 0x04000008
_08067D78: .4byte 0x06000286
_08067D7C: .4byte 0x060002C6
_08067D80: .4byte 0x060002C8
_08067D84: .4byte 0x087A44F8
_08067D88: .4byte 0x0202FA00
_08067D8C: .4byte 0x084E2E38
_08067D90: .4byte 0x0202F9E0
_08067D94: .4byte 0x08785F34
_08067D98: .4byte 0x06010000
_08067D9C: .4byte 0x084E2E98
_08067DA0: .4byte 0x0202F800
_08067DA4: .4byte 0x0850DD58
_08067DA8: .4byte 0x0202F820
_08067DAC: .4byte 0x0202F840
_08067DB0: .4byte 0x0202F860
_08067DB4: .4byte 0x084C6A98
_08067DB8: .4byte 0x06017400
_08067DBC: .4byte 0x03002C30
_08067DC0: .4byte 0x00000117
_08067DC4: .4byte 0x04000050
_08067DC8: .4byte 0x00001010
_08067DCC: .4byte 0x0300137C
	.syntax divided
