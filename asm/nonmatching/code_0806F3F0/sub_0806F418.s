	.syntax unified

	thumb_func_start sub_0806F418
sub_0806F418: @ 0x0806F418
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r5, #0xc4
	ldr r4, _0806F450 @ =0x03001800
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
	blt _0806F43E
	b _0806F580
_0806F43E:
	cmp r0, #4
	bls _0806F444
	b _0806F570
_0806F444:
	lsls r0, r0, #2
	ldr r1, _0806F454 @ =_0806F458
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806F450: .4byte 0x03001800
_0806F454: .4byte _0806F458
_0806F458: @ jump table
	.4byte _0806F46C @ case 0
	.4byte _0806F648 @ case 1
	.4byte _0806F4D0 @ case 2
	.4byte _0806F51C @ case 3
	.4byte _0806F56C @ case 4
_0806F46C:
	movs r1, #0xca
	lsls r1, r1, #8
	ldr r2, _0806F4C4 @ =0x0000040B
	movs r0, #3
	str r0, [sp]
	movs r0, #1
	movs r3, #3
	bl init_battle_sprite_entry_08048818
	ldr r2, _0806F4C8 @ =0x03002C30
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
	ldr r1, _0806F4CC @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _0806F71E
	.align 2, 0
_0806F4C4: .4byte 0x0000040B
_0806F4C8: .4byte 0x03002C30
_0806F4CC: .4byte 0x03001800
_0806F4D0:
	movs r1, #0xc6
	lsls r1, r1, #8
	ldr r2, _0806F510 @ =0x00000406
	movs r0, #3
	str r0, [sp]
	movs r0, #2
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	ldr r2, _0806F514 @ =0x03002C30
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
	ldr r1, _0806F518 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _0806F71E
	.align 2, 0
_0806F510: .4byte 0x00000406
_0806F514: .4byte 0x03002C30
_0806F518: .4byte 0x03001800
_0806F51C:
	ldr r0, _0806F568 @ =0x03002C30
	adds r0, #0xa0
	ldrb r0, [r0]
	lsls r7, r5, #1
	cmp r0, #0
	beq _0806F52A
	b _0806F720
_0806F52A:
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
	b _0806F6F8
	.align 2, 0
_0806F568: .4byte 0x03002C30
_0806F56C:
	movs r0, #2
	b _0806F6EE
_0806F570:
	movs r0, #0x28
	bl check_battle_timer_expired
	cmp r0, #0
	bne _0806F57C
	b _0806F718
_0806F57C:
	movs r0, #2
	b _0806F714
_0806F580:
	cmp r0, #0xc4
	bne _0806F5E0
	bl sub_0806FF50
	bl sub_0806FF90
	bl sub_08070030
	ldr r2, _0806F5DC @ =0x03002C30
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
_0806F5A8:
	strh r1, [r0, #4]
	subs r0, #0x40
	subs r4, #1
	cmp r4, #0
	bge _0806F5A8
	movs r4, #0
	ldr r0, _0806F5DC @ =0x03002C30
	adds r6, r0, #0
	adds r6, #0xc0
	movs r5, #0xc0
	lsls r5, r5, #0x12
_0806F5BE:
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
	ble _0806F5BE
	b _0806F6F8
	.align 2, 0
_0806F5DC: .4byte 0x03002C30
_0806F5E0:
	subs r0, #0xc5
	cmp r0, #4
	bls _0806F5E8
	b _0806F708
_0806F5E8:
	lsls r0, r0, #2
	ldr r1, _0806F5F4 @ =_0806F5F8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0806F5F4: .4byte _0806F5F8
_0806F5F8: @ jump table
	.4byte _0806F60C @ case 0
	.4byte _0806F648 @ case 1
	.4byte _0806F660 @ case 2
	.4byte _0806F69C @ case 3
	.4byte _0806F6EC @ case 4
_0806F60C:
	ldr r2, _0806F63C @ =0x03002C30
	adds r1, r2, #0
	adds r1, #0x46
	ldr r0, _0806F640 @ =0x0000040C
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
	ldr r1, _0806F644 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _0806F71E
	.align 2, 0
_0806F63C: .4byte 0x03002C30
_0806F640: .4byte 0x0000040C
_0806F644: .4byte 0x03001800
_0806F648:
	ldr r0, _0806F65C @ =0x03002C30
	adds r0, #0x60
	ldrb r0, [r0]
	lsls r7, r5, #1
	cmp r0, #0
	bne _0806F720
	ldr r0, [r2, #8]
	adds r0, #1
	str r0, [r2, #8]
	b _0806F720
	.align 2, 0
_0806F65C: .4byte 0x03002C30
_0806F660:
	ldr r2, _0806F690 @ =0x03002C30
	adds r1, r2, #0
	adds r1, #0x86
	ldr r0, _0806F694 @ =0x00000407
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
	ldr r1, _0806F698 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _0806F71E
	.align 2, 0
_0806F690: .4byte 0x03002C30
_0806F694: .4byte 0x00000407
_0806F698: .4byte 0x03001800
_0806F69C:
	ldr r0, _0806F6E8 @ =0x03002C30
	adds r0, #0xa0
	ldrb r0, [r0]
	lsls r7, r5, #1
	cmp r0, #0
	bne _0806F720
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
	b _0806F6F8
	.align 2, 0
_0806F6E8: .4byte 0x03002C30
_0806F6EC:
	movs r0, #3
_0806F6EE:
	bl battle_draw_tilemap_row_dma
	lsls r7, r5, #1
	cmp r0, #0
	beq _0806F720
_0806F6F8:
	ldr r1, _0806F704 @ =0x03001800
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	b _0806F720
	.align 2, 0
_0806F704: .4byte 0x03001800
_0806F708:
	movs r0, #0
	bl check_battle_timer_expired
	cmp r0, #0
	beq _0806F718
	movs r0, #3
_0806F714:
	bl process_text_tile_and_dma_transfer
_0806F718:
	ldr r0, [r4, #8]
	adds r0, #1
	str r0, [r4, #8]
_0806F71E:
	lsls r7, r5, #1
_0806F720:
	bl battle_timer_digit_extract
	bl update_sprite_animations_080703D8
	ldr r1, _0806F748 @ =0x03001800
	ldr r0, [r1, #8]
	cmp r7, r0
	bgt _0806F73E
	movs r0, #0
	str r0, [r1, #8]
	movs r0, #9
	strh r0, [r1, #4]
	ldr r1, _0806F74C @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_0806F73E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806F748: .4byte 0x03001800
_0806F74C: .4byte 0x0300137C
_0806F750:
	.byte 0x0C, 0x4A, 0x11, 0x1C, 0xF4, 0x31, 0x08, 0x88, 0x10, 0x30, 0x08, 0x80, 0x02, 0x31, 0x08, 0x88
	.byte 0x10, 0x38, 0x08, 0x80, 0x90, 0x68, 0x01, 0x1C, 0x01, 0x30, 0x90, 0x60, 0x3A, 0x29, 0x08, 0xDD
	.byte 0x00, 0x20, 0x90, 0x60, 0x06, 0x20, 0x90, 0x80, 0x10, 0x20, 0x90, 0x81, 0x02, 0x49, 0x02, 0x20
	.byte 0x08, 0x60, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03, 0x7C, 0x13, 0x00, 0x03
	.syntax divided
