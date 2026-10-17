	.syntax unified

	thumb_func_start status_side_change_scroll_out
	.global status_side_change_scroll_out
status_side_change_scroll_out: @ 0x080185E8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	movs r0, #4
	movs r1, #1
	bl clear_sprite_table_mask
	movs r0, #5
	movs r1, #1
	bl clear_sprite_table_mask
	movs r0, #6
	movs r1, #1
	bl clear_sprite_table_mask
	movs r0, #7
	movs r1, #1
	bl clear_sprite_table_mask
	ldr r1, _080186B4 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0
	bne _080186D0
	movs r5, #0
	ldr r0, _080186B8 @ =0x03000590
	mov sb, r0
	adds r6, r1, #0
	ldr r7, _080186BC @ =0x083AD3A4
	movs r2, #0x40
	adds r2, r2, r6
	mov r8, r2
_0801862E:
	adds r0, r6, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r4, r0, r5
	lsls r0, r4, #8
	add r0, sb
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08018662
	lsls r1, r4, #1
	adds r0, r1, r7
	ldrb r2, [r0]
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, r0, #3
	subs r3, r2, r0
	adds r1, #1
	adds r1, r1, r7
	ldrb r2, [r1]
	adds r0, r4, #0
	adds r1, r3, #0
	bl setup_battle_bot_sprites_08017994
_08018662:
	adds r5, #1
	cmp r5, #2
	bls _0801862E
	movs r5, #0
	ldr r0, _080186C0 @ =0x03002C30
	ldr r2, _080186C4 @ =0x00000242
	adds r1, r0, r2
_08018670:
	ldrh r0, [r1]
	subs r0, #8
	strh r0, [r1]
	adds r1, #0x40
	adds r5, #1
	cmp r5, #0xc
	bls _08018670
	ldr r4, _080186B4 @ =0x03000440
	adds r4, #0x40
	ldrb r0, [r4]
	movs r2, #0x10
	subs r2, r2, r0
	ldr r6, _080186C8 @ =0x04000008
	ldrh r0, [r6]
	str r0, [sp]
	ldr r5, _080186CC @ =0x02020000
	str r5, [sp, #4]
	movs r0, #0xd
	movs r1, #6
	movs r3, #0xd
	bl read_vram_tilemap_rect
	ldrb r0, [r4]
	movs r2, #0xf
	subs r2, r2, r0
	ldrh r0, [r6]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0xd
	movs r1, #6
	movs r3, #0xd
	bl write_vram_tilemap_rect
	b _08018760
	.align 2, 0
_080186B4: .4byte 0x03000440
_080186B8: .4byte 0x03000590
_080186BC: .4byte 0x083AD3A4
_080186C0: .4byte 0x03002C30
_080186C4: .4byte 0x00000242
_080186C8: .4byte 0x04000008
_080186CC: .4byte 0x02020000
_080186D0:
	movs r5, #0
	ldr r3, _08018778 @ =0x03000590
	mov sb, r3
	adds r6, r1, #0
	ldr r7, _0801877C @ =0x083AD3A4
	movs r0, #0x40
	adds r0, r0, r6
	mov r8, r0
_080186E0:
	adds r0, r6, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r4, r0, r5
	lsls r0, r4, #8
	add r0, sb
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08018714
	lsls r0, r4, #1
	adds r2, r0, r7
	mov r3, r8
	ldrb r1, [r3]
	lsls r1, r1, #3
	ldrb r2, [r2]
	adds r3, r1, r2
	adds r0, #1
	adds r0, r0, r7
	ldrb r2, [r0]
	adds r0, r4, #0
	adds r1, r3, #0
	bl setup_battle_bot_sprites_08017994
_08018714:
	adds r5, #1
	cmp r5, #2
	bls _080186E0
	movs r5, #0
	ldr r0, _08018780 @ =0x03002C30
	ldr r2, _08018784 @ =0x00000242
	adds r1, r0, r2
_08018722:
	ldrh r0, [r1]
	adds r0, #8
	strh r0, [r1]
	adds r1, #0x40
	adds r5, #1
	cmp r5, #0xc
	bls _08018722
	ldr r4, _08018788 @ =0x03000440
	adds r4, #0x40
	ldrb r2, [r4]
	adds r2, #1
	ldr r6, _0801878C @ =0x04000008
	ldrh r0, [r6]
	str r0, [sp]
	ldr r5, _08018790 @ =0x02020000
	str r5, [sp, #4]
	movs r0, #0xd
	movs r1, #6
	movs r3, #0xd
	bl read_vram_tilemap_rect
	ldrb r2, [r4]
	adds r2, #2
	ldrh r0, [r6]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0xd
	movs r1, #6
	movs r3, #0xd
	bl write_vram_tilemap_rect
_08018760:
	ldr r1, _08018788 @ =0x03000440
	adds r1, #0x40
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	beq _08018794
	movs r0, #0
	b _0801879A
	.align 2, 0
_08018778: .4byte 0x03000590
_0801877C: .4byte 0x083AD3A4
_08018780: .4byte 0x03002C30
_08018784: .4byte 0x00000242
_08018788: .4byte 0x03000440
_0801878C: .4byte 0x04000008
_08018790: .4byte 0x02020000
_08018794:
	bl status_switch_side
	movs r0, #1
_0801879A:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
