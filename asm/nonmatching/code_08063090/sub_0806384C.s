	.syntax unified

	thumb_func_start sub_0806384C
sub_0806384C: @ 0x0806384C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	ldr r3, _08063A74 @ =0x02023000
	ldr r0, _08063A78 @ =0x03006F74
	ldr r0, [r0]
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #0
_08063866:
	ldrb r0, [r3]
	strb r0, [r1]
	adds r3, #1
	adds r1, #1
	adds r2, #1
	cmp r2, #0x3f
	bls _08063866
	bl sub_08074B68
	cmp r0, #0x18
	beq _08063882
	movs r0, #0x18
	bl play_song
_08063882:
	movs r0, #0
	str r0, [sp, #0x10]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	ldr r2, _08063A7C @ =0x01006000
	add r0, sp, #0x10
	bl CpuFastSet
	bl sub_080415BC
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0x60
	strh r0, [r1]
	adds r1, #0x50
	ldr r3, _08063A80 @ =0x000002FF
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #4
	movs r0, #0x10
	strh r0, [r1]
	subs r1, #0x4a
	ldr r5, _08063A84 @ =0x00001E05
	adds r0, r5, #0
	strh r0, [r1]
	ldr r7, _08063A88 @ =0x0400000C
	ldr r2, _08063A8C @ =0x00001B06
	adds r0, r2, #0
	strh r0, [r7]
	ldr r4, _08063A90 @ =0x0400000E
	ldr r3, _08063A94 @ =0x00003C07
	adds r0, r3, #0
	strh r0, [r4]
	ldr r0, _08063A98 @ =0x0879FDC0
	ldrh r1, [r1]
	bl decompress_and_write_tilemap
	ldr r0, _08063A9C @ =0x0879FB10
	ldrh r1, [r7]
	bl decompress_and_write_tilemap
	ldr r0, _08063AA0 @ =0x087A0050
	ldrh r1, [r4]
	bl decompress_and_write_tilemap
	subs r5, #0xff
	adds r0, r5, #0
	strh r0, [r7]
	ldr r0, _08063AA4 @ =0x0879FEFC
	ldrh r1, [r7]
	bl decompress_and_write_tilemap
	ldr r0, _08063AA8 @ =0x0879E618
	ldr r5, _08063AAC @ =0x02030000
	adds r1, r5, #0
	bl dma3_copy_or_decompress
	str r0, [sp, #0x14]
	ldr r4, _08063AB0 @ =0x06004000
	lsls r2, r0, #0xa
	lsrs r2, r2, #0xb
	adds r0, r5, #0
	adds r1, r4, #0
	bl CpuSet
	ldr r0, _08063AB4 @ =0x08784CB0
	ldr r1, [sp, #0x14]
	adds r4, r1, r4
	adds r1, r4, #0
	bl lz_decompress_dispatch
	ldr r5, _08063A78 @ =0x03006F74
	ldr r1, [r5]
	ldr r2, [sp, #0x14]
	lsrs r6, r2, #5
	adds r0, r6, #4
	strh r0, [r1, #0x36]
	ldr r0, _08063AB8 @ =0x084C3208
	ldr r3, _08063ABC @ =0x06004080
	adds r1, r2, r3
	bl lz_decompress_dispatch
	ldr r0, _08063AC0 @ =0x0879E4D8
	movs r1, #0xa0
	lsls r1, r1, #0x13
	movs r2, #0x50
	bl CpuFastSet
	ldr r4, _08063AC4 @ =0x0850DD78
	ldr r1, _08063AC8 @ =0x050003A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08063ACC @ =0x0202F9A0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08063AD0 @ =0x084E2E98
	ldr r1, _08063AD4 @ =0x05000200
	movs r2, #8
	bl CpuFastSet
	adds r0, r4, #0
	subs r0, #0x20
	ldr r1, _08063AD8 @ =0x05000220
	movs r2, #8
	bl CpuFastSet
	subs r4, #0x60
	ldr r1, _08063ADC @ =0x05000240
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08063AE0 @ =0x084C6A98
	ldr r1, _08063AE4 @ =0x06017400
	bl lz_decompress_dispatch
	ldr r0, [r5]
	mov r8, r0
	movs r0, #0xa0
	lsls r0, r0, #2
	mov r1, r8
	strh r0, [r1, #0x3a]
	mov r0, r8
	adds r0, #0x7a
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	beq _08063994
	b _08063C10
_08063994:
	ldr r0, _08063AE8 @ =0x00000231
	add r0, r8
	ldrb r0, [r0]
	str r0, [sp, #0x18]
	movs r0, #0x8e
	lsls r0, r0, #2
	add r0, r8
	ldrb r1, [r0]
	ldr r0, [sp, #0x18]
	bl sub_08062AB0
	ldr r0, [r5]
	ldr r2, _08063AEC @ =0x0000023A
	adds r0, r0, r2
	movs r1, #0xa
	str r1, [sp]
	movs r1, #2
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	str r1, [sp, #0xc]
	movs r1, #0x20
	movs r2, #4
	movs r3, #4
	bl render_text_sprites_08040DB8
	movs r2, #0
	str r6, [sp, #0x1c]
	ldr r4, _08063AF0 @ =0x030004DE
	ldr r1, _08063AF4 @ =0x083B6410
	ldr r3, [sp, #0x18]
	lsls r0, r3, #2
	adds r3, r0, r1
_080639D6:
	adds r0, r2, r4
	ldr r1, [r3]
	adds r1, r1, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #9
	ble _080639D6
	ldr r0, _08063AF0 @ =0x030004DE
	movs r1, #0xa
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #0x10
	movs r2, #5
	movs r3, #8
	bl render_text_sprites_08040DB8
	ldr r5, _08063A78 @ =0x03006F74
	mov sl, r5
	ldr r5, [r5]
	ldr r1, _08063AF8 @ =0x00000235
	adds r0, r5, r1
	ldrb r7, [r0]
	cmp r7, #0x64
	beq _08063A10
	b _08063B10
_08063A10:
	ldr r4, _08063AFC @ =0x0400000A
	ldrh r1, [r4]
	lsrs r1, r1, #8
	movs r2, #0x1f
	ands r1, r2
	lsls r1, r1, #0xb
	ldr r0, _08063B00 @ =0x0600021A
	adds r1, r1, r0
	ldrh r0, [r5, #0x36]
	adds r0, #0x14
	movs r5, #0xe0
	lsls r5, r5, #7
	adds r3, r5, #0
	orrs r0, r3
	strh r0, [r1]
	ldrh r1, [r4]
	lsrs r1, r1, #8
	ands r1, r2
	lsls r1, r1, #0xb
	ldr r0, _08063B04 @ =0x0600025A
	adds r1, r1, r0
	mov r5, sl
	ldr r0, [r5]
	ldrh r0, [r0, #0x36]
	adds r0, #0x15
	orrs r0, r3
	strh r0, [r1]
	ldrh r1, [r4]
	lsrs r1, r1, #8
	ands r1, r2
	lsls r1, r1, #0xb
	ldr r0, _08063B08 @ =0x0600021C
	adds r1, r1, r0
	ldr r0, [r5]
	ldrh r0, [r0, #0x36]
	adds r0, #0x16
	orrs r0, r3
	strh r0, [r1]
	ldrh r1, [r4]
	lsrs r1, r1, #8
	ands r1, r2
	lsls r1, r1, #0xb
	ldr r0, _08063B0C @ =0x0600025C
	adds r1, r1, r0
	ldr r0, [r5]
	ldrh r0, [r0, #0x36]
	adds r0, #0x17
	orrs r0, r3
	strh r0, [r1]
	b _08063B9C
	.align 2, 0
_08063A74: .4byte 0x02023000
_08063A78: .4byte 0x03006F74
_08063A7C: .4byte 0x01006000
_08063A80: .4byte 0x000002FF
_08063A84: .4byte 0x00001E05
_08063A88: .4byte 0x0400000C
_08063A8C: .4byte 0x00001B06
_08063A90: .4byte 0x0400000E
_08063A94: .4byte 0x00003C07
_08063A98: .4byte 0x0879FDC0
_08063A9C: .4byte 0x0879FB10
_08063AA0: .4byte 0x087A0050
_08063AA4: .4byte 0x0879FEFC
_08063AA8: .4byte 0x0879E618
_08063AAC: .4byte 0x02030000
_08063AB0: .4byte 0x06004000
_08063AB4: .4byte 0x08784CB0
_08063AB8: .4byte 0x084C3208
_08063ABC: .4byte 0x06004080
_08063AC0: .4byte 0x0879E4D8
_08063AC4: .4byte 0x0850DD78
_08063AC8: .4byte 0x050003A0
_08063ACC: .4byte 0x0202F9A0
_08063AD0: .4byte 0x084E2E98
_08063AD4: .4byte 0x05000200
_08063AD8: .4byte 0x05000220
_08063ADC: .4byte 0x05000240
_08063AE0: .4byte 0x084C6A98
_08063AE4: .4byte 0x06017400
_08063AE8: .4byte 0x00000231
_08063AEC: .4byte 0x0000023A
_08063AF0: .4byte 0x030004DE
_08063AF4: .4byte 0x083B6410
_08063AF8: .4byte 0x00000235
_08063AFC: .4byte 0x0400000A
_08063B00: .4byte 0x0600021A
_08063B04: .4byte 0x0600025A
_08063B08: .4byte 0x0600021C
_08063B0C: .4byte 0x0600025C
_08063B10:
	ldr r0, _08063BE8 @ =0x0400000A
	mov sb, r0
	ldrh r4, [r0]
	lsrs r4, r4, #8
	movs r1, #0x1f
	mov r8, r1
	mov r2, r8
	ands r4, r2
	lsls r4, r4, #0xb
	ldr r0, _08063BEC @ =0x0600021A
	adds r4, r4, r0
	adds r0, r7, #0
	movs r1, #0xa
	bl sub_0807CBBC
	lsls r0, r0, #1
	ldrh r1, [r5, #0x36]
	adds r1, r1, r0
	movs r3, #0xe0
	lsls r3, r3, #7
	adds r6, r3, #0
	orrs r1, r6
	strh r1, [r4]
	mov r5, sb
	ldrh r2, [r5]
	lsrs r2, r2, #8
	mov r1, r8
	ands r2, r1
	lsls r2, r2, #0xb
	ldr r1, _08063BF0 @ =0x0600025A
	adds r2, r2, r1
	mov r3, sl
	ldr r1, [r3]
	ldrh r1, [r1, #0x36]
	adds r1, r1, r0
	adds r1, #1
	orrs r1, r6
	strh r1, [r2]
	ldrh r4, [r5]
	lsrs r4, r4, #8
	mov r5, r8
	ands r4, r5
	lsls r4, r4, #0xb
	ldr r0, _08063BF4 @ =0x0600021C
	adds r4, r4, r0
	ldr r5, [r3]
	adds r0, r7, #0
	movs r1, #0xa
	bl sub_0807CC88
	lsls r0, r0, #1
	ldrh r1, [r5, #0x36]
	adds r1, r1, r0
	orrs r1, r6
	strh r1, [r4]
	mov r1, sb
	ldrh r2, [r1]
	lsrs r2, r2, #8
	mov r3, r8
	ands r2, r3
	lsls r2, r2, #0xb
	ldr r1, _08063BF8 @ =0x0600025C
	adds r2, r2, r1
	mov r5, sl
	ldr r1, [r5]
	ldrh r1, [r1, #0x36]
	adds r1, r1, r0
	adds r1, #1
	orrs r1, r6
	strh r1, [r2]
_08063B9C:
	ldr r1, [sp, #0x18]
	lsls r0, r1, #7
	ldr r1, _08063BFC @ =0x084C21BC
	adds r0, r0, r1
	ldr r2, [sp, #0x14]
	ldr r3, _08063C00 @ =0x06004000
	adds r1, r2, r3
	movs r2, #0x40
	bl CpuSet
	ldr r5, [sp, #0x1c]
	lsls r0, r5, #0x10
	movs r2, #0xc0
	lsls r2, r2, #0x17
	orrs r2, r0
	lsrs r2, r2, #0x10
	ldr r0, _08063BE8 @ =0x0400000A
	ldrh r0, [r0]
	lsrs r0, r0, #8
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #0xb
	ldr r1, _08063C04 @ =0x06000206
	adds r3, r0, r1
	strh r2, [r3]
	adds r1, #2
	adds r3, r0, r1
	adds r1, r2, #1
	strh r1, [r3]
	ldr r5, _08063C08 @ =0x06000246
	adds r3, r0, r5
	adds r1, r2, #2
	strh r1, [r3]
	ldr r1, _08063C0C @ =0x06000248
	adds r3, r0, r1
	adds r2, #3
	strh r2, [r3]
	b _08063CC6
	.align 2, 0
_08063BE8: .4byte 0x0400000A
_08063BEC: .4byte 0x0600021A
_08063BF0: .4byte 0x0600025A
_08063BF4: .4byte 0x0600021C
_08063BF8: .4byte 0x0600025C
_08063BFC: .4byte 0x084C21BC
_08063C00: .4byte 0x06004000
_08063C04: .4byte 0x06000206
_08063C08: .4byte 0x06000246
_08063C0C: .4byte 0x06000248
_08063C10:
	ldrh r0, [r7]
	lsrs r0, r0, #8
	movs r2, #0x1f
	ands r0, r2
	lsls r0, r0, #0xb
	ldr r3, _08063D2C @ =0x06000218
	adds r0, r0, r3
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x40
	strh r1, [r0]
	ldrh r0, [r7]
	lsrs r0, r0, #8
	ands r0, r2
	lsls r0, r0, #0xb
	ldr r4, _08063D30 @ =0x0600021A
	adds r0, r0, r4
	ldrh r0, [r0]
	mov r1, r8
	adds r1, #0x42
	strh r0, [r1]
	ldrh r0, [r7]
	lsrs r0, r0, #8
	ands r0, r2
	lsls r0, r0, #0xb
	ldr r5, _08063D34 @ =0x06000258
	adds r0, r0, r5
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	ldrh r0, [r7]
	lsrs r0, r0, #8
	ands r0, r2
	lsls r0, r0, #0xb
	ldr r6, _08063D38 @ =0x0600025A
	adds r0, r0, r6
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x46
	strh r1, [r0]
	ldrh r1, [r7]
	lsrs r1, r1, #8
	ands r1, r2
	lsls r1, r1, #0xb
	adds r1, r1, r3
	ldrh r0, [r7]
	lsrs r0, r0, #8
	ands r0, r2
	lsls r0, r0, #0xb
	subs r3, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	ldrh r1, [r7]
	lsrs r1, r1, #8
	ands r1, r2
	lsls r1, r1, #0xb
	adds r1, r1, r4
	ldrh r0, [r7]
	lsrs r0, r0, #8
	ands r0, r2
	lsls r0, r0, #0xb
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	ldrh r1, [r7]
	lsrs r1, r1, #8
	ands r1, r2
	lsls r1, r1, #0xb
	adds r1, r1, r5
	ldrh r0, [r7]
	lsrs r0, r0, #8
	ands r0, r2
	lsls r0, r0, #0xb
	adds r3, #0x40
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	ldrh r1, [r7]
	lsrs r1, r1, #8
	ands r1, r2
	lsls r1, r1, #0xb
	adds r1, r1, r6
	ldrh r0, [r7]
	lsrs r0, r0, #8
	ands r0, r2
	lsls r0, r0, #0xb
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
_08063CC6:
	bl animate_battle_scroll_tiles
	ldr r0, _08063D3C @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x50
	movs r3, #1
	rsbs r3, r3, #0
	movs r1, #0xc0
	str r1, [sp]
	movs r1, #0x10
	movs r2, #0
	bl init_blend_effect
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r5, #0x80
	lsls r5, r5, #3
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r5, #0x80
	lsls r5, r5, #5
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08063D40 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08063D2C: .4byte 0x06000218
_08063D30: .4byte 0x0600021A
_08063D34: .4byte 0x06000258
_08063D38: .4byte 0x0600025A
_08063D3C: .4byte 0x03006F74
_08063D40: .4byte 0x0300137C
	.syntax divided
