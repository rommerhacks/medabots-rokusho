	.syntax unified

	thumb_func_start sub_08058B04
sub_08058B04: @ 0x08058B04
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, _08058B3C @ =0x030057A0
	movs r0, #0
	strb r0, [r4, #0x13]
	bl update_bg_scroll_offsets_a
	ldr r0, _08058B40 @ =0x080AC494
	movs r1, #2
	movs r2, #0x28
	movs r3, #0x18
	bl load_battle_sprite_tile
	ldrb r0, [r4, #0x14]
	movs r1, #8
	movs r2, #0x50
	movs r3, #0x18
	bl load_battle_sprite_from_index
	cmp r5, #7
	bls _08058B32
	b _080592AE
_08058B32:
	lsls r0, r5, #2
	ldr r1, _08058B44 @ =_08058B48
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08058B3C: .4byte 0x030057A0
_08058B40: .4byte 0x080AC494
_08058B44: .4byte _08058B48
_08058B48: @ jump table
	.4byte _08058B68 @ case 0
	.4byte _08058DB4 @ case 1
	.4byte _08058E50 @ case 2
	.4byte _08058EB0 @ case 3
	.4byte _08058EE0 @ case 4
	.4byte _080590A0 @ case 5
	.4byte _08059114 @ case 6
	.4byte _080591EC @ case 7
_08058B68:
	ldr r0, _08058BC8 @ =0x080AC498
	movs r1, #2
	movs r2, #0x68
	movs r3, #0x18
	bl load_battle_sprite_tile
	ldr r0, _08058BCC @ =0x080AC49C
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x20
	bl load_battle_sprite_tile
	ldr r0, _08058BD0 @ =0x030057A0
	ldrh r1, [r0, #0x26]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _08058BD4 @ =0x080AC4A0
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x28
	bl load_battle_sprite_tile
	ldr r4, _08058BD8 @ =0x030057E0
	ldr r0, _08058BDC @ =0x00000C5C
	adds r4, r4, r0
	ldrb r1, [r4]
	movs r0, #0x28
	str r0, [sp]
	movs r0, #1
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldrb r0, [r4]
	cmp r0, #0xf
	bls _08058BBC
	b _08058CB4
_08058BBC:
	lsls r0, r0, #2
	ldr r1, _08058BE0 @ =_08058BE4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08058BC8: .4byte 0x080AC498
_08058BCC: .4byte 0x080AC49C
_08058BD0: .4byte 0x030057A0
_08058BD4: .4byte 0x080AC4A0
_08058BD8: .4byte 0x030057E0
_08058BDC: .4byte 0x00000C5C
_08058BE0: .4byte _08058BE4
_08058BE4: @ jump table
	.4byte _08058C24 @ case 0
	.4byte _08058C2C @ case 1
	.4byte _08058C34 @ case 2
	.4byte _08058C3C @ case 3
	.4byte _08058C44 @ case 4
	.4byte _08058C4C @ case 5
	.4byte _08058C54 @ case 6
	.4byte _08058C5C @ case 7
	.4byte _08058C64 @ case 8
	.4byte _08058C6C @ case 9
	.4byte _08058C74 @ case 10
	.4byte _08058C7C @ case 11
	.4byte _08058C84 @ case 12
	.4byte _08058C8C @ case 13
	.4byte _08058C94 @ case 14
	.4byte _08058CA8 @ case 15
_08058C24:
	ldr r0, _08058C28 @ =0x080AC4A4
	b _08058C96
	.align 2, 0
_08058C28: .4byte 0x080AC4A4
_08058C2C:
	ldr r0, _08058C30 @ =0x080AC4A8
	b _08058C96
	.align 2, 0
_08058C30: .4byte 0x080AC4A8
_08058C34:
	ldr r0, _08058C38 @ =0x080AC4AC
	b _08058C96
	.align 2, 0
_08058C38: .4byte 0x080AC4AC
_08058C3C:
	ldr r0, _08058C40 @ =0x080AC4B0
	b _08058C96
	.align 2, 0
_08058C40: .4byte 0x080AC4B0
_08058C44:
	ldr r0, _08058C48 @ =0x080AC4B4
	b _08058C96
	.align 2, 0
_08058C48: .4byte 0x080AC4B4
_08058C4C:
	ldr r0, _08058C50 @ =0x080AC4B8
	b _08058C96
	.align 2, 0
_08058C50: .4byte 0x080AC4B8
_08058C54:
	ldr r0, _08058C58 @ =0x080AC4BC
	b _08058C96
	.align 2, 0
_08058C58: .4byte 0x080AC4BC
_08058C5C:
	ldr r0, _08058C60 @ =0x080AC4C0
	b _08058C96
	.align 2, 0
_08058C60: .4byte 0x080AC4C0
_08058C64:
	ldr r0, _08058C68 @ =0x080AC4C4
	b _08058C96
	.align 2, 0
_08058C68: .4byte 0x080AC4C4
_08058C6C:
	ldr r0, _08058C70 @ =0x080AC4C8
	b _08058C96
	.align 2, 0
_08058C70: .4byte 0x080AC4C8
_08058C74:
	ldr r0, _08058C78 @ =0x080AC4CC
	b _08058C96
	.align 2, 0
_08058C78: .4byte 0x080AC4CC
_08058C7C:
	ldr r0, _08058C80 @ =0x080AC4D0
	b _08058C96
	.align 2, 0
_08058C80: .4byte 0x080AC4D0
_08058C84:
	ldr r0, _08058C88 @ =0x080AC4D4
	b _08058C96
	.align 2, 0
_08058C88: .4byte 0x080AC4D4
_08058C8C:
	ldr r0, _08058C90 @ =0x080AC4D8
	b _08058C96
	.align 2, 0
_08058C90: .4byte 0x080AC4D8
_08058C94:
	ldr r0, _08058CA4 @ =0x080AC4DC
_08058C96:
	movs r1, #3
	movs r2, #0x70
	movs r3, #0x28
	bl load_battle_sprite_tile
	b _08058CB4
	.align 2, 0
_08058CA4: .4byte 0x080AC4DC
_08058CA8:
	ldr r0, _08058D08 @ =0x080AC4E0
	movs r1, #3
	movs r2, #0x70
	movs r3, #0x28
	bl load_battle_sprite_tile
_08058CB4:
	ldr r0, _08058D0C @ =0x080AC4E4
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x30
	bl load_battle_sprite_tile
	ldr r4, _08058D10 @ =0x030057E0
	ldr r1, _08058D14 @ =0x00000C4D
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x30
	str r0, [sp]
	movs r0, #2
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _08058D18 @ =0x080AC4E8
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x38
	bl load_battle_sprite_tile
	ldr r0, _08058D1C @ =0x00000CB7
	adds r4, r4, r0
	ldrb r1, [r4]
	movs r0, #0x38
	str r0, [sp]
	movs r0, #3
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldrb r0, [r4]
	cmp r0, #1
	beq _08058D34
	cmp r0, #1
	bgt _08058D20
	cmp r0, #0
	beq _08058D2A
	b _08058D5C
	.align 2, 0
_08058D08: .4byte 0x080AC4E0
_08058D0C: .4byte 0x080AC4E4
_08058D10: .4byte 0x030057E0
_08058D14: .4byte 0x00000C4D
_08058D18: .4byte 0x080AC4E8
_08058D1C: .4byte 0x00000CB7
_08058D20:
	cmp r0, #2
	beq _08058D3C
	cmp r0, #3
	beq _08058D50
	b _08058D5C
_08058D2A:
	ldr r0, _08058D30 @ =0x080AC4EC
	b _08058D3E
	.align 2, 0
_08058D30: .4byte 0x080AC4EC
_08058D34:
	ldr r0, _08058D38 @ =0x080AC498
	b _08058D3E
	.align 2, 0
_08058D38: .4byte 0x080AC498
_08058D3C:
	ldr r0, _08058D4C @ =0x080AC4F0
_08058D3E:
	movs r1, #2
	movs r2, #0x70
	movs r3, #0x38
	bl load_battle_sprite_tile
	b _08058D5C
	.align 2, 0
_08058D4C: .4byte 0x080AC4F0
_08058D50:
	ldr r0, _08058D9C @ =0x080AC4F4
	movs r1, #2
	movs r2, #0x70
	movs r3, #0x38
	bl load_battle_sprite_tile
_08058D5C:
	ldr r0, _08058DA0 @ =0x080AC4F8
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x40
	bl load_battle_sprite_tile
	ldr r4, _08058DA4 @ =0x030057E0
	ldr r1, _08058DA8 @ =0x000007FF
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	movs r0, #4
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _08058DAC @ =0x080AC4FC
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x48
	bl load_battle_sprite_tile
	ldr r0, _08058DB0 @ =0x00000C33
	adds r4, r4, r0
	ldrb r1, [r4]
	movs r0, #0x48
	str r0, [sp]
	movs r0, #5
	movs r2, #8
	b _080591A2
	.align 2, 0
_08058D9C: .4byte 0x080AC4F4
_08058DA0: .4byte 0x080AC4F8
_08058DA4: .4byte 0x030057E0
_08058DA8: .4byte 0x000007FF
_08058DAC: .4byte 0x080AC4FC
_08058DB0: .4byte 0x00000C33
_08058DB4:
	ldr r0, _08058E38 @ =0x080AC500
	movs r1, #5
	movs r2, #0x68
	movs r3, #0x18
	bl load_battle_sprite_tile
	ldr r0, _08058E3C @ =0x080AC508
	movs r1, #3
	movs r2, #0x30
	movs r3, #0x20
	bl load_battle_sprite_tile
	ldr r4, _08058E40 @ =0x083D6070
	ldr r0, [r4]
	ldrh r1, [r0]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0
	movs r2, #0x10
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _08058E44 @ =0x080AC50C
	movs r1, #3
	movs r2, #0x30
	movs r3, #0x28
	bl load_battle_sprite_tile
	ldr r0, [r4, #4]
	ldrh r1, [r0]
	movs r0, #0x28
	str r0, [sp]
	movs r0, #1
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r5, _08058E48 @ =0x080AC510
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0x70
	movs r3, #0x28
	bl load_battle_sprite_tile
	ldr r0, _08058E4C @ =0x080AC514
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x30
	bl load_battle_sprite_tile
	ldr r0, [r4, #8]
	ldrh r1, [r0]
	movs r0, #0x30
	str r0, [sp]
	movs r0, #2
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0x70
	movs r3, #0x30
	bl load_battle_sprite_tile
	b _080592AE
	.align 2, 0
_08058E38: .4byte 0x080AC500
_08058E3C: .4byte 0x080AC508
_08058E40: .4byte 0x083D6070
_08058E44: .4byte 0x080AC50C
_08058E48: .4byte 0x080AC510
_08058E4C: .4byte 0x080AC514
_08058E50:
	ldr r0, _08058E98 @ =0x080AC518
	movs r1, #6
	movs r2, #0x68
	movs r3, #0x18
	bl load_battle_sprite_tile
	ldr r0, _08058E9C @ =0x080AC520
	movs r1, #3
	movs r2, #0x30
	movs r3, #0x20
	bl load_battle_sprite_tile
	ldr r4, _08058EA0 @ =0x030057E0
	ldr r1, _08058EA4 @ =0x00000C52
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0
	movs r2, #0x10
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _08058EA8 @ =0x080AC524
	movs r1, #3
	movs r2, #0x30
	movs r3, #0x28
	bl load_battle_sprite_tile
	ldr r0, _08058EAC @ =0x00000C54
	adds r4, r4, r0
	ldrh r1, [r4]
	movs r0, #0x28
	str r0, [sp]
	movs r0, #0
	b _080591A0
	.align 2, 0
_08058E98: .4byte 0x080AC518
_08058E9C: .4byte 0x080AC520
_08058EA0: .4byte 0x030057E0
_08058EA4: .4byte 0x00000C52
_08058EA8: .4byte 0x080AC524
_08058EAC: .4byte 0x00000C54
_08058EB0:
	ldr r0, _08058ED4 @ =0x080AC528
	movs r1, #0xa
	movs r2, #0x68
	movs r3, #0x18
	bl load_battle_sprite_tile
	ldr r0, _08058ED8 @ =0x080AC534
	movs r1, #3
	movs r2, #0x30
	movs r3, #0x20
	bl load_battle_sprite_tile
	ldr r0, _08058EDC @ =0x030057A0
	ldrb r1, [r0, #0x12]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0
	b _080591A0
	.align 2, 0
_08058ED4: .4byte 0x080AC528
_08058ED8: .4byte 0x080AC534
_08058EDC: .4byte 0x030057A0
_08058EE0:
	ldr r0, _08058F64 @ =0x080AC538
	movs r1, #3
	movs r2, #0x68
	movs r3, #0x18
	bl load_battle_sprite_tile
	ldr r0, _08058F68 @ =0x080AC53C
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x20
	bl load_battle_sprite_tile
	ldr r0, _08058F6C @ =0x030057A0
	ldrb r1, [r0, #0x11]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _08058F70 @ =0x080AC540
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x28
	bl load_battle_sprite_tile
	ldr r0, _08058F74 @ =0x03006D38
	ldrb r1, [r0, #2]
	movs r0, #0x28
	str r0, [sp]
	movs r0, #1
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _08058F78 @ =0x080AC544
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x30
	bl load_battle_sprite_tile
	ldr r4, _08058F7C @ =0x030057E0
	ldr r1, _08058F80 @ =0x00000C4E
	adds r4, r4, r1
	ldrb r1, [r4]
	movs r0, #0x30
	str r0, [sp]
	movs r0, #2
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldrb r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08058F88
	ldr r0, _08058F84 @ =0x080AC548
	movs r1, #1
	movs r2, #0x70
	movs r3, #0x30
	bl load_battle_sprite_tile
	b _08058F94
	.align 2, 0
_08058F64: .4byte 0x080AC538
_08058F68: .4byte 0x080AC53C
_08058F6C: .4byte 0x030057A0
_08058F70: .4byte 0x080AC540
_08058F74: .4byte 0x03006D38
_08058F78: .4byte 0x080AC544
_08058F7C: .4byte 0x030057E0
_08058F80: .4byte 0x00000C4E
_08058F84: .4byte 0x080AC548
_08058F88:
	ldr r0, _08058FB4 @ =0x080AC54C
	movs r1, #1
	movs r2, #0x70
	movs r3, #0x30
	bl load_battle_sprite_tile
_08058F94:
	ldr r0, _08058FB8 @ =0x030057E0
	ldr r1, _08058FBC @ =0x00000C4E
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08058FC4
	ldr r0, _08058FC0 @ =0x080AC550
	movs r1, #1
	movs r2, #0x90
	movs r3, #0x30
	bl load_battle_sprite_tile
	b _08058FD0
	.align 2, 0
_08058FB4: .4byte 0x080AC54C
_08058FB8: .4byte 0x030057E0
_08058FBC: .4byte 0x00000C4E
_08058FC0: .4byte 0x080AC550
_08058FC4:
	ldr r0, _08059050 @ =0x080AC54C
	movs r1, #1
	movs r2, #0x90
	movs r3, #0x30
	bl load_battle_sprite_tile
_08058FD0:
	ldr r0, _08059054 @ =0x080AC554
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x38
	bl load_battle_sprite_tile
	ldr r4, _08059058 @ =0x030057E0
	ldr r1, _0805905C @ =0x00000CB8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x38
	str r0, [sp]
	movs r0, #3
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _08059060 @ =0x080AC558
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x40
	bl load_battle_sprite_tile
	ldr r1, _08059064 @ =0x00000CB9
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	movs r0, #4
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _08059068 @ =0x080AC510
	movs r1, #1
	movs r2, #0x70
	movs r3, #0x40
	bl load_battle_sprite_tile
	ldr r0, _0805906C @ =0x080AC55C
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x48
	bl load_battle_sprite_tile
	ldr r0, _08059070 @ =0x00000C4F
	adds r4, r4, r0
	ldrb r1, [r4]
	movs r0, #0x48
	str r0, [sp]
	movs r0, #5
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldrb r0, [r4]
	cmp r0, #1
	beq _08059084
	cmp r0, #1
	bgt _08059074
	cmp r0, #0
	beq _0805907A
	b _080592AE
	.align 2, 0
_08059050: .4byte 0x080AC54C
_08059054: .4byte 0x080AC554
_08059058: .4byte 0x030057E0
_0805905C: .4byte 0x00000CB8
_08059060: .4byte 0x080AC558
_08059064: .4byte 0x00000CB9
_08059068: .4byte 0x080AC510
_0805906C: .4byte 0x080AC55C
_08059070: .4byte 0x00000C4F
_08059074:
	cmp r0, #2
	beq _0805908C
	b _080592AE
_0805907A:
	ldr r0, _08059080 @ =0x080AC560
	b _0805908E
	.align 2, 0
_08059080: .4byte 0x080AC560
_08059084:
	ldr r0, _08059088 @ =0x080AC564
	b _0805908E
	.align 2, 0
_08059088: .4byte 0x080AC564
_0805908C:
	ldr r0, _0805909C @ =0x080AC568
_0805908E:
	movs r1, #1
	movs r2, #0x70
	movs r3, #0x48
	bl load_battle_sprite_tile
	b _080592AE
	.align 2, 0
_0805909C: .4byte 0x080AC568
_080590A0:
	ldr r0, _08059104 @ =0x080AC56C
	movs r1, #4
	movs r2, #0x68
	movs r3, #0x18
	bl load_battle_sprite_tile
	ldr r0, _08059108 @ =0x080AC574
	movs r1, #3
	movs r2, #0x30
	movs r3, #0x20
	bl load_battle_sprite_tile
	ldr r4, _0805910C @ =0x030057A0
	ldrh r1, [r4, #0x20]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0
	movs r2, #0x10
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	adds r0, r4, #0
	adds r0, #0x32
	ldrb r0, [r0]
	cmp r0, #0
	bne _080590D6
	b _080592AE
_080590D6:
	movs r0, #0x31
	bl advance_sprite_animation_frame
	movs r0, #0x32
	bl advance_sprite_animation_frame
	movs r0, #0x33
	bl advance_sprite_animation_frame
	movs r0, #0x34
	bl advance_sprite_animation_frame
	ldr r0, _08059110 @ =0x083D2C3D
	ldrh r1, [r4, #0x20]
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #3
	beq _080590FC
	b _080592AE
_080590FC:
	movs r0, #0x39
	bl advance_sprite_animation_frame
	b _080592AE
	.align 2, 0
_08059104: .4byte 0x080AC56C
_08059108: .4byte 0x080AC574
_0805910C: .4byte 0x030057A0
_08059110: .4byte 0x083D2C3D
_08059114:
	ldr r4, _08059128 @ =0x030057A0
	adds r5, r4, #0
	adds r5, #0x32
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805912C
	cmp r0, #1
	beq _080591C0
	b _080592AE
	.align 2, 0
_08059128: .4byte 0x030057A0
_0805912C:
	ldr r0, _080591AC @ =0x080AC578
	movs r1, #4
	movs r2, #0x68
	movs r3, #0x18
	bl load_battle_sprite_tile
	ldr r0, _080591B0 @ =0x080AC580
	movs r1, #3
	movs r2, #0x30
	movs r3, #0x20
	bl load_battle_sprite_tile
	ldrh r1, [r4, #0x2e]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0
	movs r2, #0x10
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _080591B4 @ =0x080AC584
	movs r1, #3
	movs r2, #0x30
	movs r3, #0x28
	bl load_battle_sprite_tile
	ldrh r1, [r4, #0x30]
	movs r0, #0x28
	str r0, [sp]
	movs r0, #1
	movs r2, #0x10
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _080591B8 @ =0x080AC588
	movs r1, #3
	movs r2, #0x30
	movs r3, #0x30
	bl load_battle_sprite_tile
	ldrh r1, [r4, #0x24]
	movs r0, #0x30
	str r0, [sp]
	movs r0, #2
	movs r2, #0x10
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _080591BC @ =0x080AC58C
	movs r1, #3
	movs r2, #0x30
	movs r3, #0x38
	bl load_battle_sprite_tile
	ldrh r1, [r4, #0x1e]
	movs r0, #0x38
	str r0, [sp]
	movs r0, #3
_080591A0:
	movs r2, #0x10
_080591A2:
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	b _080592AE
	.align 2, 0
_080591AC: .4byte 0x080AC578
_080591B0: .4byte 0x080AC580
_080591B4: .4byte 0x080AC584
_080591B8: .4byte 0x080AC588
_080591BC: .4byte 0x080AC58C
_080591C0:
	ldr r1, _080591E8 @ =0x0847E45C
	ldrh r0, [r4, #0x2e]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldrh r0, [r4, #0x30]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl scene_transition_step_08047C24
	cmp r0, #0
	beq _080592AE
	movs r0, #0
	strb r0, [r5]
	b _080592AE
	.align 2, 0
_080591E8: .4byte 0x0847E45C
_080591EC:
	ldr r0, _080592B8 @ =0x080AC514
	movs r1, #2
	movs r2, #0x68
	movs r3, #0x18
	bl load_battle_sprite_tile
	ldr r0, _080592BC @ =0x080AC590
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x20
	bl load_battle_sprite_tile
	ldr r5, _080592C0 @ =0x030057E0
	ldr r1, _080592C4 @ =0x00000CBC
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _080592C8 @ =0x080AC594
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x28
	bl load_battle_sprite_tile
	ldr r1, _080592CC @ =0x00000CBD
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x28
	str r0, [sp]
	movs r0, #1
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _080592D0 @ =0x080AC598
	movs r1, #3
	movs r2, #0x30
	movs r3, #0x30
	bl load_battle_sprite_tile
	ldr r4, _080592D4 @ =0x030057A0
	adds r0, r4, #0
	adds r0, #0x33
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x30
	str r0, [sp]
	movs r0, #2
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _080592D8 @ =0x080AC59C
	movs r1, #2
	movs r2, #0x30
	movs r3, #0x38
	bl load_battle_sprite_tile
	adds r4, #0x34
	movs r1, #0
	ldrsb r1, [r4, r1]
	movs r0, #0x38
	str r0, [sp]
	movs r0, #3
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _080592DC @ =0x080AC5A0
	movs r1, #3
	movs r2, #0x30
	movs r3, #0x40
	bl load_battle_sprite_tile
	ldr r0, _080592E0 @ =0x00000C5D
	adds r5, r5, r0
	ldrb r1, [r5]
	movs r0, #0x40
	str r0, [sp]
	movs r0, #4
	movs r2, #8
	movs r3, #0x50
	bl load_or_clear_battle_sprites
	ldr r0, _080592E4 @ =0x080AC510
	movs r1, #1
	movs r2, #0x70
	movs r3, #0x40
	bl load_battle_sprite_tile
_080592AE:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080592B8: .4byte 0x080AC514
_080592BC: .4byte 0x080AC590
_080592C0: .4byte 0x030057E0
_080592C4: .4byte 0x00000CBC
_080592C8: .4byte 0x080AC594
_080592CC: .4byte 0x00000CBD
_080592D0: .4byte 0x080AC598
_080592D4: .4byte 0x030057A0
_080592D8: .4byte 0x080AC59C
_080592DC: .4byte 0x080AC5A0
_080592E0: .4byte 0x00000C5D
_080592E4: .4byte 0x080AC510
	.syntax divided
