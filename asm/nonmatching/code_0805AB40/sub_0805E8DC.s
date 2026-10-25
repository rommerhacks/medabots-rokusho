	.syntax unified

	thumb_func_start sub_0805E8DC
sub_0805E8DC: @ 0x0805E8DC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r4, _0805E91C @ =0x03002C30
	ldr r0, _0805E920 @ =0x03001780
	ldr r0, [r0]
	movs r1, #6
	bl sub_0807CD58
	movs r1, #3
	ands r0, r1
	adds r0, #0x26
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	ldr r0, _0805E924 @ =0x03006F74
	ldr r2, [r0]
	ldrb r3, [r2, #6]
	cmp r3, #0
	beq _0805E92E
	ldrh r0, [r2, #2]
	adds r1, r0, #1
	strh r1, [r2, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0805E928
	ldr r0, [r2, #8]
	adds r0, #1
	str r0, [r2, #8]
	b _0805E94A
	.align 2, 0
_0805E91C: .4byte 0x03002C30
_0805E920: .4byte 0x03001780
_0805E924: .4byte 0x03006F74
_0805E928:
	movs r0, #0
	strh r0, [r2, #2]
	b _0805E948
_0805E92E:
	ldrh r0, [r2, #2]
	adds r1, r0, #1
	strh r1, [r2, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0805E944
	ldr r0, [r2, #8]
	subs r0, #1
	str r0, [r2, #8]
	b _0805E94A
_0805E944:
	strh r3, [r2, #2]
	movs r0, #1
_0805E948:
	strb r0, [r2, #6]
_0805E94A:
	ldr r2, _0805E970 @ =0x03001798
	ldrb r1, [r2]
	movs r0, #0x10
	ands r0, r1
	adds r4, r2, #0
	cmp r0, #0
	beq _0805E994
	movs r0, #2
	bl play_sound_effect
	ldr r0, _0805E974 @ =0x03006F74
	ldr r0, [r0]
	ldrb r1, [r0, #0xd]
	ldrb r0, [r0, #0xe]
	cmp r0, #3
	bne _0805E978
	cmp r1, #2
	beq _0805E97C
	b _0805E988
	.align 2, 0
_0805E970: .4byte 0x03001798
_0805E974: .4byte 0x03006F74
_0805E978:
	cmp r1, #0x19
	bne _0805E988
_0805E97C:
	ldr r0, _0805E984 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0
	b _0805E990
	.align 2, 0
_0805E984: .4byte 0x03006F74
_0805E988:
	ldr r0, _0805E9BC @ =0x03006F74
	ldr r1, [r0]
	ldrb r0, [r1, #0xd]
	adds r0, #1
_0805E990:
	strb r0, [r1, #0xd]
	ldr r4, _0805E9C0 @ =0x03001798
_0805E994:
	ldrb r1, [r4]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0805E9C8
	movs r0, #2
	bl play_sound_effect
	ldr r0, _0805E9BC @ =0x03006F74
	ldr r1, [r0]
	ldrb r0, [r1, #0xd]
	cmp r0, #0
	bne _0805E9C4
	ldrb r0, [r1, #0xe]
	movs r2, #0x19
	cmp r0, #3
	bne _0805E9B8
	movs r2, #2
_0805E9B8:
	strb r2, [r1, #0xd]
	b _0805E9C8
	.align 2, 0
_0805E9BC: .4byte 0x03006F74
_0805E9C0: .4byte 0x03001798
_0805E9C4:
	subs r0, #1
	strb r0, [r1, #0xd]
_0805E9C8:
	ldrb r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0805EA1E
	movs r0, #2
	bl play_sound_effect
	ldr r2, _0805E9F4 @ =0x03006F74
	ldr r1, [r2]
	ldrb r0, [r1, #0xe]
	adds r3, r0, #0
	cmp r3, #0
	bne _0805EA08
	movs r0, #3
	strb r0, [r1, #0xe]
	ldr r1, [r2]
	ldrb r0, [r1, #0xd]
	cmp r0, #8
	bhi _0805E9F8
	strb r3, [r1, #0xd]
	b _0805EA1E
	.align 2, 0
_0805E9F4: .4byte 0x03006F74
_0805E9F8:
	cmp r0, #0x10
	bhi _0805EA02
	movs r0, #1
	strb r0, [r1, #0xd]
	b _0805EA1E
_0805EA02:
	movs r0, #2
	strb r0, [r1, #0xd]
	b _0805EA1E
_0805EA08:
	subs r0, #1
	strb r0, [r1, #0xe]
	ldr r2, [r2]
	ldrb r0, [r2, #0xe]
	cmp r0, #2
	bne _0805EA1E
	ldr r0, _0805EA4C @ =0x080AF850
	ldrb r1, [r2, #0xd]
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r2, #0xd]
_0805EA1E:
	ldrb r1, [r4]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0805EA78
	movs r0, #2
	bl play_sound_effect
	ldr r1, _0805EA50 @ =0x03006F74
	ldr r3, [r1]
	ldrb r0, [r3, #0xe]
	cmp r0, #3
	bne _0805EA54
	movs r0, #0
	strb r0, [r3, #0xe]
	ldr r2, [r1]
	ldr r1, _0805EA4C @ =0x080AF850
	ldrb r0, [r2, #0xd]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2, #0xd]
	b _0805EA78
	.align 2, 0
_0805EA4C: .4byte gUnk_080AF850
_0805EA50: .4byte 0x03006F74
_0805EA54:
	adds r0, #1
	strb r0, [r3, #0xe]
	ldr r3, [r1]
	ldrb r0, [r3, #0xe]
	adds r6, r1, #0
	cmp r0, #3
	bne _0805EAEC
	ldrb r0, [r3, #0xd]
	cmp r0, #8
	bhi _0805EA6C
	movs r0, #0
	b _0805EA76
_0805EA6C:
	cmp r0, #0x10
	bhi _0805EA74
	movs r0, #1
	b _0805EA76
_0805EA74:
	movs r0, #2
_0805EA76:
	strb r0, [r3, #0xd]
_0805EA78:
	ldr r0, _0805EAE0 @ =0x03006F74
	ldr r4, [r0]
	ldrb r1, [r4, #0xe]
	adds r6, r0, #0
	cmp r1, #3
	bne _0805EAEC
	ldr r3, _0805EAE4 @ =0x03002C30
	ldrb r2, [r4, #0xd]
	lsls r2, r2, #6
	ldr r0, [r4, #8]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	subs r0, #0x18
	subs r2, r2, r0
	strh r2, [r3, #2]
	movs r0, #0x8c
	strh r0, [r3, #4]
	ldrb r2, [r4, #0xd]
	lsls r2, r2, #6
	ldr r0, [r4, #8]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r0, #0x58
	adds r2, r2, r0
	adds r0, r3, #0
	adds r0, #0x42
	strh r2, [r0]
	movs r1, #0x8c
	adds r0, #2
	strh r1, [r0]
	movs r0, #5
	strh r0, [r3, #6]
	adds r1, r3, #0
	adds r1, #0x46
	strh r0, [r1]
	ldrh r1, [r3]
	ldr r0, _0805EAE8 @ =0x0000DFFF
	ands r0, r1
	strh r0, [r3]
	adds r2, r3, #0
	adds r2, #0x40
	ldrh r1, [r2]
	movs r4, #0x80
	lsls r4, r4, #5
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
	adds r5, r3, #0
	b _0805EB54
	.align 2, 0
_0805EAE0: .4byte 0x03006F74
_0805EAE4: .4byte 0x03002C30
_0805EAE8: .4byte 0x0000DFFF
_0805EAEC:
	ldr r4, _0805EB78 @ =0x03002C30
	ldr r2, [r6]
	ldrb r3, [r2, #0xd]
	lsls r3, r3, #3
	adds r3, #0x14
	strh r3, [r4, #2]
	ldrb r0, [r2, #0xe]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, [r2, #8]
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	adds r0, #0x40
	adds r1, r1, r0
	strh r1, [r4, #4]
	adds r0, r4, #0
	adds r0, #0x42
	strh r3, [r0]
	ldr r2, [r6]
	ldrb r0, [r2, #0xe]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, [r2, #8]
	lsrs r2, r0, #0x1f
	adds r0, r0, r2
	asrs r0, r0, #1
	subs r0, #0x50
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x44
	strh r1, [r0]
	movs r0, #8
	strh r0, [r4, #6]
	adds r1, r4, #0
	adds r1, #0x46
	strh r0, [r1]
	ldrh r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r2, #0
	orrs r0, r1
	strh r0, [r4]
	adds r2, r4, #0
	adds r2, #0x40
	ldrh r1, [r2]
	ldr r0, _0805EB7C @ =0x0000EFFF
	ands r0, r1
	strh r0, [r2]
	adds r5, r4, #0
_0805EB54:
	ldr r3, _0805EB80 @ =0x0300058C
	ldrb r2, [r3]
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0805EB88
_0805EB60:
	movs r0, #4
	bl play_sound_effect
	ldr r2, _0805EB84 @ =0x03006F74
	ldr r1, [r2]
	movs r0, #3
	strb r0, [r1, #0xe]
	ldr r1, [r2]
	movs r0, #2
	strb r0, [r1, #0xd]
	b _0805EDF0
	.align 2, 0
_0805EB78: .4byte 0x03002C30
_0805EB7C: .4byte 0x0000EFFF
_0805EB80: .4byte 0x0300058C
_0805EB84: .4byte 0x03006F74
_0805EB88:
	ldrb r1, [r3, #1]
	movs r4, #1
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0805EC04
_0805EB94:
	ldr r5, _0805EBF0 @ =0x03006F74
	ldr r0, [r5]
	ldrb r0, [r0, #0xf]
	cmp r0, #9
	bhi _0805EBFC
	movs r0, #4
	bl play_sound_effect
	ldr r1, [r5]
	adds r0, r1, #0
	adds r0, #0x58
	ldrb r1, [r1, #0xf]
	adds r0, r0, r1
	movs r6, #0
	strb r6, [r0]
	ldr r1, [r5]
	ldrb r0, [r1, #0xf]
	adds r0, #1
	strb r0, [r1, #0xf]
	ldr r0, [r5]
	ldrb r4, [r0, #0xf]
	cmp r4, #0xa
	beq _0805EBC4
	b _0805ED3E
_0805EBC4:
	ldr r1, _0805EBF4 @ =0x03002C30
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
	ldrh r2, [r1]
	ldr r0, _0805EBF8 @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	movs r0, #5
	movs r1, #0xa
	bl clear_sprite_table_mask
	ldr r0, [r5]
	adds r0, #0x58
	str r4, [sp]
	movs r1, #0xd
	str r1, [sp, #4]
	movs r1, #1
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	b _0805ED1E
	.align 2, 0
_0805EBF0: .4byte 0x03006F74
_0805EBF4: .4byte 0x03002C30
_0805EBF8: .4byte 0x0000BFFF
_0805EBFC:
	movs r0, #6
	bl play_sound_effect
	b _0805ED3E
_0805EC04:
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	bne _0805EC0E
	b _0805ED6C
_0805EC0E:
	ldr r1, [r6]
	ldrb r0, [r1, #0xe]
	cmp r0, #3
	bne _0805ECBC
	ldrb r0, [r1, #0xd]
	cmp r0, #1
	bne _0805EC1E
	b _0805ED76
_0805EC1E:
	cmp r0, #1
	bgt _0805EC28
	cmp r0, #0
	beq _0805EB94
	b _0805ECBC
_0805EC28:
	cmp r0, #2
	bne _0805ECBC
	movs r4, #0x80
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrh r1, [r2]
	ldr r0, _0805ECB0 @ =0x0000BFFF
	ands r0, r1
	strh r0, [r2]
	movs r1, #1
	movs r2, #0
	ldr r0, [r6]
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0xfe
	beq _0805EC64
	cmp r0, #0
	bne _0805EC76
_0805EC4C:
	adds r2, #1
	cmp r2, #0xf
	bhi _0805EC64
	ldr r0, [r6]
	adds r0, #0x58
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0xfe
	beq _0805EC64
	cmp r0, #0
	beq _0805EC4C
	movs r1, #0
_0805EC64:
	cmp r1, #0
	beq _0805EC76
	ldr r1, [r6]
	adds r0, r1, #0
	adds r0, #0x68
	adds r1, #0x58
	movs r2, #8
	bl CpuSet
_0805EC76:
	movs r0, #5
	movs r1, #0xa
	bl clear_sprite_table_mask
	ldr r0, _0805ECB4 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x58
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xd
	str r1, [sp, #4]
	movs r1, #1
	str r1, [sp, #8]
	movs r1, #0
	str r1, [sp, #0xc]
	movs r1, #5
	movs r2, #5
	movs r3, #3
	bl render_text_sprites_08040DB8
	movs r0, #7
	bl play_sound_effect
	ldr r1, _0805ECB8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0805EE56
	.align 2, 0
_0805ECB0: .4byte 0x0000BFFF
_0805ECB4: .4byte 0x03006F74
_0805ECB8: .4byte 0x0300137C
_0805ECBC:
	ldr r5, _0805ED2C @ =0x03006F74
	ldr r0, [r5]
	ldrb r0, [r0, #0xf]
	cmp r0, #9
	bhi _0805ED38
	movs r0, #4
	bl play_sound_effect
	ldr r1, [r5]
	adds r2, r1, #0
	adds r2, #0x58
	ldrb r0, [r1, #0xf]
	adds r2, r2, r0
	ldrb r3, [r1, #0xe]
	movs r0, #0x1a
	muls r0, r3, r0
	ldrb r1, [r1, #0xd]
	adds r0, r0, r1
	adds r0, #1
	strb r0, [r2]
	ldr r1, [r5]
	ldrb r0, [r1, #0xf]
	adds r0, #1
	strb r0, [r1, #0xf]
	ldr r0, [r5]
	ldrb r4, [r0, #0xf]
	cmp r4, #0xa
	bne _0805ED3E
	ldr r1, _0805ED30 @ =0x03002C30
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
	ldrh r2, [r1]
	ldr r0, _0805ED34 @ =0x0000BFFF
	ands r0, r2
	strh r0, [r1]
	movs r0, #5
	movs r1, #0xa
	bl clear_sprite_table_mask
	ldr r0, [r5]
	adds r0, #0x58
	str r4, [sp]
	movs r1, #0xd
	str r1, [sp, #4]
	movs r1, #1
	str r1, [sp, #8]
	movs r1, #0
	str r1, [sp, #0xc]
_0805ED1E:
	movs r1, #5
	movs r2, #5
	movs r3, #3
	bl render_text_sprites_08040DB8
	b _0805EB60
	.align 2, 0
_0805ED2C: .4byte 0x03006F74
_0805ED30: .4byte 0x03002C30
_0805ED34: .4byte 0x0000BFFF
_0805ED38:
	movs r0, #6
	bl play_sound_effect
_0805ED3E:
	movs r0, #5
	movs r1, #0xa
	bl clear_sprite_table_mask
	ldr r0, _0805ED68 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x58
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xd
	str r1, [sp, #4]
	movs r1, #1
	str r1, [sp, #8]
	movs r1, #0
	str r1, [sp, #0xc]
	movs r1, #5
	movs r2, #5
	movs r3, #3
	bl render_text_sprites_08040DB8
	b _0805EDF0
	.align 2, 0
_0805ED68: .4byte 0x03006F74
_0805ED6C:
	ldrh r1, [r3]
	ldr r0, _0805ED9C @ =0x00000202
	ands r0, r1
	cmp r0, #0
	beq _0805EE56
_0805ED76:
	movs r0, #5
	bl play_sound_effect
	ldr r1, _0805EDA0 @ =0x03006F74
	ldr r2, [r1]
	ldrb r0, [r2, #0xf]
	adds r3, r0, #0
	cmp r3, #0
	beq _0805EDA4
	subs r0, #1
	strb r0, [r2, #0xf]
	ldr r1, [r1]
	adds r0, r1, #0
	adds r0, #0x58
	ldrb r1, [r1, #0xf]
	adds r0, r0, r1
	movs r1, #0xfe
	strb r1, [r0]
	b _0805EDB4
	.align 2, 0
_0805ED9C: .4byte 0x00000202
_0805EDA0: .4byte 0x03006F74
_0805EDA4:
	strb r3, [r2, #0xf]
	ldr r0, [r1]
	adds r1, r0, #0
	adds r1, #0x58
	ldrb r0, [r0, #0xf]
	adds r1, r1, r0
	movs r0, #0xfe
	strb r0, [r1]
_0805EDB4:
	movs r0, #5
	movs r1, #0xa
	bl clear_sprite_table_mask
	ldr r0, _0805EE60 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x58
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xd
	str r1, [sp, #4]
	movs r1, #1
	str r1, [sp, #8]
	movs r1, #0
	str r1, [sp, #0xc]
	movs r1, #5
	movs r2, #5
	movs r3, #3
	bl render_text_sprites_08040DB8
	ldr r1, _0805EE64 @ =0x03002C30
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
	ldrh r2, [r1]
	movs r4, #0x80
	lsls r4, r4, #7
	adds r0, r4, #0
	orrs r0, r2
	strh r0, [r1]
_0805EDF0:
	ldr r4, _0805EE60 @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x58
	bl calc_text_pixel_width
	ldr r5, _0805EE64 @ =0x03002C30
	adds r0, #0x28
	movs r1, #0x81
	lsls r1, r1, #1
	adds r2, r5, r1
	strh r0, [r2]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0x1b
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r3, r0, #2
	ldr r0, [r4]
	ldrb r2, [r0, #0xf]
	cmp r2, #9
	bgt _0805EE56
	movs r6, #0
	ldr r4, _0805EE68 @ =0x083B4C88
	lsls r0, r2, #6
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, r0, r5
	movs r5, #0xc0
	lsls r5, r5, #8
_0805EE30:
	strh r5, [r1]
	strb r6, [r1, #0x1c]
	movs r0, #0xd
	strb r0, [r1, #0xa]
	movs r0, #0x42
	strh r0, [r1, #6]
	strh r3, [r1, #2]
	movs r0, #0x1c
	strh r0, [r1, #4]
	movs r0, #0xff
	strb r0, [r1, #0xb]
	adds r0, r4, #0
	adds r0, #0x86
	ldrb r0, [r0]
	adds r3, r3, r0
	adds r1, #0x40
	adds r2, #1
	cmp r2, #9
	ble _0805EE30
_0805EE56:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805EE60: .4byte 0x03006F74
_0805EE64: .4byte 0x03002C30
_0805EE68: .4byte gUnk_083B4C88
	.syntax divided
