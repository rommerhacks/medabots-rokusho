	.syntax unified

	thumb_func_start sub_0806F0B4
sub_0806F0B4: @ 0x0806F0B4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r5, #0xc4
	ldr r4, _0806F0EC @ =0x03001800
	adds r0, r4, #0
	adds r0, #0xf0
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0xf2
	ldrh r0, [r1]
	adds r0, #0x6f
	strh r0, [r1]
	ldr r0, [r4, #8]
	adds r2, r4, #0
	cmp r0, #0xc4
	blt _0806F0DA
	b _0806F21C
_0806F0DA:
	cmp r0, #4
	bls _0806F0E0
	b _0806F20C
_0806F0E0:
	lsls r0, r0, #2
	ldr r1, _0806F0F0 @ =_0806F0F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806F0EC: .4byte 0x03001800
_0806F0F0: .4byte _0806F0F4
_0806F0F4: @ jump table
	.4byte _0806F108 @ case 0
	.4byte _0806F2E4 @ case 1
	.4byte _0806F16C @ case 2
	.4byte _0806F1B8 @ case 3
	.4byte _0806F208 @ case 4
_0806F108:
	movs r1, #0xca
	lsls r1, r1, #8
	ldr r2, _0806F160 @ =0x00000409
	movs r0, #3
	str r0, [sp]
	movs r0, #1
	movs r3, #3
	bl init_battle_sprite_entry_08048818
	ldr r2, _0806F164 @ =0x03002C30
	adds r1, r2, #0
	adds r1, #0x42
	movs r0, #0x50
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x48
	movs r1, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #1
	movs r1, #1
	movs r2, #0
	bl battle_sprite_set_action
	movs r0, #4
	movs r1, #9
	movs r2, #0
	bl battle_sprite_set_action
	movs r0, #5
	movs r1, #0xa
	movs r2, #0
	bl battle_sprite_set_action
	ldr r1, _0806F168 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _0806F3BA
	.align 2, 0
_0806F160: .4byte 0x00000409
_0806F164: .4byte 0x03002C30
_0806F168: .4byte 0x03001800
_0806F16C:
	movs r1, #0xc6
	lsls r1, r1, #8
	ldr r2, _0806F1AC @ =0x00000406
	movs r0, #3
	str r0, [sp]
	movs r0, #2
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	ldr r2, _0806F1B0 @ =0x03002C30
	adds r1, r2, #0
	adds r1, #0x82
	movs r0, #0xb8
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x70
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x88
	movs r1, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #2
	movs r2, #0
	bl battle_sprite_set_action
	ldr r1, _0806F1B4 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _0806F3BA
	.align 2, 0
_0806F1AC: .4byte 0x00000406
_0806F1B0: .4byte 0x03002C30
_0806F1B4: .4byte 0x03001800
_0806F1B8:
	ldr r0, _0806F204 @ =0x03002C30
	adds r0, #0xa0
	ldrb r0, [r0]
	lsls r7, r5, #1
	cmp r0, #0
	beq _0806F1C6
	b _0806F3BC
_0806F1C6:
	movs r0, #3
	movs r1, #3
	movs r2, #0x70
	bl battle_sprite_set_action
	movs r0, #3
	movs r1, #4
	movs r2, #0x68
	bl battle_sprite_set_action
	movs r0, #3
	movs r1, #5
	movs r2, #0x68
	bl battle_sprite_set_action
	movs r0, #3
	movs r1, #6
	movs r2, #0x70
	bl battle_sprite_set_action
	movs r0, #3
	movs r1, #7
	movs r2, #0x78
	bl battle_sprite_set_action
	movs r0, #3
	movs r1, #8
	movs r2, #0x78
	bl battle_sprite_set_action
	b _0806F394
	.align 2, 0
_0806F204: .4byte 0x03002C30
_0806F208:
	movs r0, #0
	b _0806F38A
_0806F20C:
	movs r0, #0
	bl check_battle_timer_expired
	cmp r0, #0
	bne _0806F218
	b _0806F3B4
_0806F218:
	movs r0, #0
	b _0806F3B0
_0806F21C:
	cmp r0, #0xc4
	bne _0806F27C
	bl sub_0806FF50
	bl sub_0806FF90
	bl sub_08070030
	ldr r2, _0806F278 @ =0x03002C30
	adds r0, r2, #0
	adds r0, #0x44
	movs r1, #0xc8
	strh r1, [r0]
	adds r0, #0x40
	strh r1, [r0]
	lsls r7, r5, #1
	movs r4, #2
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r0, r2, r3
_0806F244:
	strh r1, [r0, #4]
	subs r0, #0x40
	subs r4, #1
	cmp r4, #0
	bge _0806F244
	movs r4, #0
	ldr r0, _0806F278 @ =0x03002C30
	adds r6, r0, #0
	adds r6, #0xc0
	movs r5, #0xc0
	lsls r5, r5, #0x12
_0806F25A:
	lsrs r1, r5, #0x18
	movs r0, #0
	movs r2, #0
	bl battle_sprite_set_action
	movs r0, #0xc8
	strh r0, [r6, #4]
	adds r6, #0x40
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r5, r5, r0
	adds r4, #1
	cmp r4, #5
	ble _0806F25A
	b _0806F394
	.align 2, 0
_0806F278: .4byte 0x03002C30
_0806F27C:
	subs r0, #0xc5
	cmp r0, #4
	bls _0806F284
	b _0806F3A4
_0806F284:
	lsls r0, r0, #2
	ldr r1, _0806F290 @ =_0806F294
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806F290: .4byte _0806F294
_0806F294: @ jump table
	.4byte _0806F2A8 @ case 0
	.4byte _0806F2E4 @ case 1
	.4byte _0806F2FC @ case 2
	.4byte _0806F338 @ case 3
	.4byte _0806F388 @ case 4
_0806F2A8:
	ldr r2, _0806F2D8 @ =0x03002C30
	adds r1, r2, #0
	adds r1, #0x46
	ldr r0, _0806F2DC @ =0x0000040A
	strh r0, [r1]
	subs r1, #2
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x48
	movs r1, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #1
	movs r1, #1
	movs r2, #0
	bl battle_sprite_set_action
	ldr r1, _0806F2E0 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _0806F3BA
	.align 2, 0
_0806F2D8: .4byte 0x03002C30
_0806F2DC: .4byte 0x0000040A
_0806F2E0: .4byte 0x03001800
_0806F2E4:
	ldr r0, _0806F2F8 @ =0x03002C30
	adds r0, #0x60
	ldrb r0, [r0]
	lsls r7, r5, #1
	cmp r0, #0
	bne _0806F3BC
	ldr r0, [r2, #8]
	adds r0, #1
	str r0, [r2, #8]
	b _0806F3BC
	.align 2, 0
_0806F2F8: .4byte 0x03002C30
_0806F2FC:
	ldr r2, _0806F32C @ =0x03002C30
	adds r1, r2, #0
	adds r1, #0x86
	ldr r0, _0806F330 @ =0x00000407
	strh r0, [r1]
	subs r1, #2
	movs r0, #0x70
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x88
	movs r1, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #2
	movs r2, #0
	bl battle_sprite_set_action
	ldr r1, _0806F334 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _0806F3BA
	.align 2, 0
_0806F32C: .4byte 0x03002C30
_0806F330: .4byte 0x00000407
_0806F334: .4byte 0x03001800
_0806F338:
	ldr r0, _0806F384 @ =0x03002C30
	adds r0, #0xa0
	ldrb r0, [r0]
	lsls r7, r5, #1
	cmp r0, #0
	bne _0806F3BC
	movs r0, #3
	movs r1, #3
	movs r2, #0x78
	bl battle_sprite_set_action
	movs r0, #3
	movs r1, #4
	movs r2, #0x70
	bl battle_sprite_set_action
	movs r0, #3
	movs r1, #5
	movs r2, #0x78
	bl battle_sprite_set_action
	movs r0, #3
	movs r1, #6
	movs r2, #0x70
	bl battle_sprite_set_action
	movs r0, #3
	movs r1, #7
	movs r2, #0x68
	bl battle_sprite_set_action
	movs r0, #3
	movs r1, #8
	movs r2, #0x70
	bl battle_sprite_set_action
	b _0806F394
	.align 2, 0
_0806F384: .4byte 0x03002C30
_0806F388:
	movs r0, #1
_0806F38A:
	bl battle_draw_tilemap_row_dma
	lsls r7, r5, #1
	cmp r0, #0
	beq _0806F3BC
_0806F394:
	ldr r1, _0806F3A0 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _0806F3BC
	.align 2, 0
_0806F3A0: .4byte 0x03001800
_0806F3A4:
	movs r0, #0x28
	bl check_battle_timer_expired
	cmp r0, #0
	beq _0806F3B4
	movs r0, #1
_0806F3B0:
	bl process_text_tile_and_dma_transfer
_0806F3B4:
	ldr r0, [r4, #8]
	adds r0, #1
	str r0, [r4, #8]
_0806F3BA:
	lsls r7, r5, #1
_0806F3BC:
	bl battle_timer_digit_extract
	bl update_sprite_animations_080703D8
	ldr r1, _0806F3E8 @ =0x03001800
	ldr r0, [r1, #8]
	cmp r7, r0
	bgt _0806F3DE
	movs r0, #0
	str r0, [r1, #8]
	movs r0, #6
	strh r0, [r1, #4]
	movs r0, #0xd
	strh r0, [r1, #0xc]
	ldr r1, _0806F3EC @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_0806F3DE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806F3E8: .4byte 0x03001800
_0806F3EC: .4byte 0x0300137C
	.syntax divided
