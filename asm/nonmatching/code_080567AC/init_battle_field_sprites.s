	.syntax unified

	thumb_func_start init_battle_field_sprites
init_battle_field_sprites: @ 0x08059814
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r1, _08059C08 @ =0x030057A0
	ldrh r0, [r1, #0x20]
	bl decompress_terrain_tiles_to_vram
	ldr r2, _08059C08 @ =0x030057A0
	ldrh r0, [r2, #0x20]
	bl dma_load_obj_palettes_08048730
	movs r7, #0
	ldr r6, _08059C0C @ =0x03002C30
	movs r4, #0xc4
	lsls r4, r4, #4
	adds r3, r6, r4
	ldr r1, _08059C08 @ =0x030057A0
	ldrh r0, [r1, #0x20]
	strh r0, [r3, #0x30]
	ldr r2, _08059C10 @ =0x03006432
	ldrh r0, [r2]
	subs r0, #0x30
	lsls r0, r0, #8
	ldrb r2, [r3, #0xc]
	orrs r2, r0
	str r2, [r3, #0xc]
	ldr r4, _08059C14 @ =0x03006434
	ldrh r0, [r4]
	adds r0, #0x10
	lsls r0, r0, #8
	ldrb r1, [r3, #0x10]
	orrs r1, r0
	str r1, [r3, #0x10]
	ldr r0, _08059C18 @ =0xFFFFC804
	strh r0, [r3]
	ldr r4, _08059C1C @ =0x00000C6E
	adds r0, r6, r4
	movs r4, #1
	mov sl, r4
	mov r4, sl
	strb r4, [r0]
	movs r0, #0xb6
	lsls r0, r0, #5
	adds r4, r6, r0
	ldr r0, _08059C20 @ =0xFFFFCC0C
	strh r0, [r4]
	asrs r2, r2, #8
	ldr r5, _08059C24 @ =0x03004C30
	ldrh r0, [r5]
	subs r2, r2, r0
	strh r2, [r3, #2]
	asrs r1, r1, #8
	ldrh r0, [r5, #2]
	subs r1, r1, r0
	strh r1, [r3, #4]
	strh r2, [r4, #2]
	ldr r2, _08059C28 @ =0x00000C6C
	adds r0, r6, r2
	ldr r2, _08059C2C @ =0x0000FFFB
	ldrb r0, [r0]
	adds r0, r2, r0
	adds r1, r1, r0
	strh r1, [r4, #4]
	strh r7, [r3, #6]
	movs r0, #0x31
	movs r1, #4
	bl sub_080493D4
	movs r4, #0xc8
	lsls r4, r4, #4
	adds r3, r6, r4
	ldr r1, _08059C08 @ =0x030057A0
	ldrh r0, [r1, #0x20]
	strh r0, [r3, #0x30]
	ldr r2, _08059C10 @ =0x03006432
	ldrh r0, [r2]
	subs r0, #0x10
	lsls r0, r0, #8
	ldrb r2, [r3, #0xc]
	orrs r2, r0
	str r2, [r3, #0xc]
	ldr r4, _08059C14 @ =0x03006434
	ldrh r0, [r4]
	adds r0, #0x10
	lsls r0, r0, #8
	ldrb r1, [r3, #0x10]
	orrs r1, r0
	str r1, [r3, #0x10]
	ldr r0, _08059C18 @ =0xFFFFC804
	strh r0, [r3]
	ldr r4, _08059C30 @ =0x00000CAE
	adds r0, r6, r4
	mov r4, sl
	strb r4, [r0]
	movs r0, #0xb8
	lsls r0, r0, #5
	adds r4, r6, r0
	ldr r0, _08059C20 @ =0xFFFFCC0C
	strh r0, [r4]
	asrs r2, r2, #8
	ldrh r0, [r5]
	subs r2, r2, r0
	strh r2, [r3, #2]
	asrs r1, r1, #8
	ldrh r0, [r5, #2]
	subs r1, r1, r0
	strh r1, [r3, #4]
	strh r2, [r4, #2]
	ldr r2, _08059C34 @ =0x00000CAC
	adds r0, r6, r2
	ldr r2, _08059C2C @ =0x0000FFFB
	ldrb r0, [r0]
	adds r0, r2, r0
	adds r1, r1, r0
	strh r1, [r4, #4]
	movs r0, #0xf
	strh r0, [r3, #6]
	movs r0, #0x32
	movs r1, #9
	bl sub_080493D4
	movs r4, #0xcc
	lsls r4, r4, #4
	adds r3, r6, r4
	ldr r1, _08059C08 @ =0x030057A0
	ldrh r0, [r1, #0x20]
	strh r0, [r3, #0x30]
	ldr r2, _08059C10 @ =0x03006432
	ldrh r0, [r2]
	adds r0, #0x10
	lsls r0, r0, #8
	ldrb r2, [r3, #0xc]
	orrs r2, r0
	str r2, [r3, #0xc]
	ldr r4, _08059C14 @ =0x03006434
	ldrh r0, [r4]
	adds r0, #0x10
	lsls r0, r0, #8
	ldrb r1, [r3, #0x10]
	orrs r1, r0
	str r1, [r3, #0x10]
	ldr r0, _08059C18 @ =0xFFFFC804
	strh r0, [r3]
	ldr r4, _08059C38 @ =0x00000CEE
	adds r0, r6, r4
	mov r4, sl
	strb r4, [r0]
	movs r0, #0x5d
	str r0, [sp, #8]
	movs r0, #0xba
	lsls r0, r0, #5
	adds r4, r6, r0
	ldr r0, _08059C20 @ =0xFFFFCC0C
	strh r0, [r4]
	asrs r2, r2, #8
	ldrh r0, [r5]
	subs r2, r2, r0
	strh r2, [r3, #2]
	asrs r1, r1, #8
	ldrh r0, [r5, #2]
	subs r1, r1, r0
	strh r1, [r3, #4]
	strh r2, [r4, #2]
	ldr r2, _08059C3C @ =0x00000CEC
	adds r0, r6, r2
	ldr r2, _08059C2C @ =0x0000FFFB
	ldrb r0, [r0]
	adds r0, r2, r0
	adds r1, r1, r0
	strh r1, [r4, #4]
	movs r0, #0x1e
	strh r0, [r3, #6]
	movs r0, #0x33
	movs r1, #0xe
	bl sub_080493D4
	movs r4, #0xd0
	lsls r4, r4, #4
	adds r3, r6, r4
	ldr r1, _08059C08 @ =0x030057A0
	ldrh r0, [r1, #0x20]
	strh r0, [r3, #0x30]
	ldr r2, _08059C10 @ =0x03006432
	ldrh r0, [r2]
	adds r0, #0x30
	lsls r0, r0, #8
	ldrb r2, [r3, #0xc]
	orrs r2, r0
	str r2, [r3, #0xc]
	ldr r4, _08059C14 @ =0x03006434
	ldrh r0, [r4]
	adds r0, #0x10
	lsls r0, r0, #8
	ldrb r1, [r3, #0x10]
	orrs r1, r0
	str r1, [r3, #0x10]
	ldr r0, _08059C18 @ =0xFFFFC804
	strh r0, [r3]
	ldr r4, _08059C40 @ =0x00000D2E
	adds r0, r6, r4
	mov r4, sl
	strb r4, [r0]
	movs r0, #0xbc
	lsls r0, r0, #5
	adds r4, r6, r0
	ldr r0, _08059C20 @ =0xFFFFCC0C
	strh r0, [r4]
	asrs r2, r2, #8
	ldrh r0, [r5]
	subs r2, r2, r0
	strh r2, [r3, #2]
	asrs r1, r1, #8
	ldrh r0, [r5, #2]
	subs r1, r1, r0
	strh r1, [r3, #4]
	strh r2, [r4, #2]
	ldr r2, _08059C44 @ =0x00000D2C
	adds r0, r6, r2
	ldr r2, _08059C2C @ =0x0000FFFB
	ldrb r0, [r0]
	adds r0, r2, r0
	adds r1, r1, r0
	strh r1, [r4, #4]
	movs r0, #0x2d
	strh r0, [r3, #6]
	movs r0, #0x34
	movs r1, #0x13
	bl sub_080493D4
	movs r4, #0xd4
	lsls r4, r4, #4
	adds r3, r6, r4
	ldr r1, _08059C08 @ =0x030057A0
	ldrh r0, [r1, #0x20]
	strh r0, [r3, #0x30]
	ldr r2, _08059C10 @ =0x03006432
	ldrh r0, [r2]
	subs r0, #0x30
	lsls r0, r0, #8
	ldrb r2, [r3, #0xc]
	orrs r2, r0
	str r2, [r3, #0xc]
	ldr r4, _08059C14 @ =0x03006434
	ldrh r0, [r4]
	subs r0, #0x10
	lsls r0, r0, #8
	ldrb r1, [r3, #0x10]
	orrs r1, r0
	str r1, [r3, #0x10]
	ldr r0, _08059C18 @ =0xFFFFC804
	strh r0, [r3]
	ldr r4, _08059C48 @ =0x00000D6E
	adds r0, r6, r4
	mov r4, sl
	strb r4, [r0]
	movs r0, #0xbe
	lsls r0, r0, #5
	adds r4, r6, r0
	ldr r0, _08059C20 @ =0xFFFFCC0C
	strh r0, [r4]
	adds r7, r6, #0
	asrs r2, r2, #8
	ldrh r0, [r5]
	subs r2, r2, r0
	strh r2, [r3, #2]
	asrs r1, r1, #8
	ldrh r0, [r5, #2]
	subs r1, r1, r0
	strh r1, [r3, #4]
	strh r2, [r4, #2]
	ldr r2, _08059C4C @ =0x00000D6C
	adds r0, r7, r2
	ldr r2, _08059C2C @ =0x0000FFFB
	ldrb r0, [r0]
	adds r0, r2, r0
	adds r1, r1, r0
	strh r1, [r4, #4]
	movs r0, #0x30
	strh r0, [r3, #6]
	movs r0, #0x35
	movs r1, #0x14
	bl sub_080493D4
	movs r4, #0xd8
	lsls r4, r4, #4
	adds r3, r7, r4
	ldr r0, _08059C08 @ =0x030057A0
	mov sb, r0
	ldrh r0, [r0, #0x20]
	strh r0, [r3, #0x30]
	ldr r1, _08059C10 @ =0x03006432
	ldrh r0, [r1]
	subs r0, #0x10
	lsls r0, r0, #8
	ldrb r2, [r3, #0xc]
	orrs r2, r0
	str r2, [r3, #0xc]
	ldr r4, _08059C14 @ =0x03006434
	ldrh r0, [r4]
	subs r0, #0x10
	lsls r0, r0, #8
	ldrb r1, [r3, #0x10]
	orrs r1, r0
	str r1, [r3, #0x10]
	ldr r0, _08059C18 @ =0xFFFFC804
	strh r0, [r3]
	ldr r4, _08059C50 @ =0x00000DAE
	adds r0, r7, r4
	mov r4, sl
	strb r4, [r0]
	movs r0, #0xc0
	lsls r0, r0, #5
	adds r4, r7, r0
	ldr r0, _08059C54 @ =0x0000CC0C
	mov r8, r0
	mov r0, r8
	strh r0, [r4]
	asrs r2, r2, #8
	ldrh r0, [r5]
	subs r2, r2, r0
	strh r2, [r3, #2]
	asrs r1, r1, #8
	ldrh r0, [r5, #2]
	subs r1, r1, r0
	strh r1, [r3, #4]
	strh r2, [r4, #2]
	ldr r2, _08059C58 @ =0x00000DAC
	adds r0, r7, r2
	ldr r2, _08059C2C @ =0x0000FFFB
	ldrb r0, [r0]
	adds r0, r2, r0
	adds r1, r1, r0
	strh r1, [r4, #4]
	movs r0, #0x3f
	strh r0, [r3, #6]
	movs r0, #0x36
	movs r1, #0x19
	bl sub_080493D4
	movs r4, #0xdc
	lsls r4, r4, #4
	adds r3, r7, r4
	mov r1, sb
	ldrh r0, [r1, #0x20]
	strh r0, [r3, #0x30]
	ldr r2, _08059C10 @ =0x03006432
	ldrh r0, [r2]
	adds r0, #0x10
	lsls r0, r0, #8
	ldrb r2, [r3, #0xc]
	orrs r2, r0
	str r2, [r3, #0xc]
	ldr r4, _08059C14 @ =0x03006434
	ldrh r0, [r4]
	subs r0, #0x10
	lsls r0, r0, #8
	ldrb r1, [r3, #0x10]
	orrs r1, r0
	str r1, [r3, #0x10]
	ldr r0, _08059C18 @ =0xFFFFC804
	strh r0, [r3]
	ldr r4, _08059C5C @ =0x00000DEE
	adds r0, r7, r4
	mov r4, sl
	strb r4, [r0]
	movs r0, #0xc2
	lsls r0, r0, #5
	adds r4, r7, r0
	mov r0, r8
	strh r0, [r4]
	asrs r2, r2, #8
	ldrh r0, [r5]
	subs r2, r2, r0
	strh r2, [r3, #2]
	asrs r1, r1, #8
	ldrh r0, [r5, #2]
	subs r1, r1, r0
	strh r1, [r3, #4]
	strh r2, [r4, #2]
	ldr r2, _08059C60 @ =0x00000DEC
	adds r0, r7, r2
	ldr r2, _08059C2C @ =0x0000FFFB
	ldrb r0, [r0]
	adds r0, r2, r0
	adds r1, r1, r0
	strh r1, [r4, #4]
	movs r0, #0x4e
	strh r0, [r3, #6]
	movs r0, #0x37
	movs r1, #0x1e
	bl sub_080493D4
	movs r4, #0xe0
	lsls r4, r4, #4
	adds r3, r7, r4
	mov r1, sb
	ldrh r0, [r1, #0x20]
	strh r0, [r3, #0x30]
	ldr r2, _08059C10 @ =0x03006432
	ldrh r0, [r2]
	adds r0, #0x30
	lsls r0, r0, #8
	ldrb r2, [r3, #0xc]
	orrs r2, r0
	str r2, [r3, #0xc]
	ldr r4, _08059C14 @ =0x03006434
	ldrh r0, [r4]
	subs r0, #0x10
	lsls r0, r0, #8
	movs r1, #0xff
	str r1, [sp, #4]
	ldrb r1, [r3, #0x10]
	orrs r1, r0
	str r1, [r3, #0x10]
	ldr r4, _08059C18 @ =0xFFFFC804
	strh r4, [r3]
	ldr r4, _08059C64 @ =0x00000E2E
	adds r0, r7, r4
	mov r4, sl
	strb r4, [r0]
	movs r0, #0xc4
	lsls r0, r0, #5
	adds r4, r7, r0
	mov r0, r8
	strh r0, [r4]
	asrs r2, r2, #8
	ldrh r0, [r5]
	subs r2, r2, r0
	strh r2, [r3, #2]
	asrs r1, r1, #8
	ldrh r0, [r5, #2]
	subs r1, r1, r0
	strh r1, [r3, #4]
	strh r2, [r4, #2]
	ldr r2, _08059C68 @ =0x00000E2C
	adds r0, r7, r2
	ldr r2, _08059C2C @ =0x0000FFFB
	ldrb r0, [r0]
	adds r0, r2, r0
	str r0, [sp, #0xc]
	adds r1, r1, r0
	strh r1, [r4, #4]
	mov r4, sp
	ldrh r4, [r4, #8]
	strh r4, [r3, #6]
	movs r0, #0x38
	movs r1, #0x23
	bl sub_080493D4
	movs r0, #0x39
	bl clear_battle_sprite_entry
	movs r0, #0x63
	bl clear_battle_sprite_entry
	movs r0, #0xe4
	lsls r0, r0, #4
	adds r5, r7, r0
	mov r1, sb
	ldrh r0, [r1, #0x20]
	strh r0, [r5, #0x30]
	ldr r1, _08059C6C @ =0x083D2C3D
	mov r2, sb
	ldrh r0, [r2, #0x20]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _08059CA2
	movs r0, #0
	bl calc_medapart_table_index
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0
	bl sub_08050264
	adds r3, r0, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r0, sl
	str r0, [sp]
	movs r0, #0x39
	ldr r1, _08059C70 @ =0x0000C804
	adds r2, r4, #0
	bl init_battle_sprite_entry_08048818
	movs r0, #0
	bl sub_08050264
	ldr r2, _08059C74 @ =0x00000E6B
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _08059C10 @ =0x03006432
	ldrh r1, [r3]
	subs r1, #0x30
	lsls r1, r1, #8
	ldr r0, [r5, #0xc]
	ldr r4, [sp, #4]
	ands r0, r4
	orrs r0, r1
	b _08059C78
	.align 2, 0
_08059C08: .4byte 0x030057A0
_08059C0C: .4byte 0x03002C30
_08059C10: .4byte 0x03006432
_08059C14: .4byte 0x03006434
_08059C18: .4byte 0xFFFFC804
_08059C1C: .4byte 0x00000C6E
_08059C20: .4byte 0xFFFFCC0C
_08059C24: .4byte 0x03004C30
_08059C28: .4byte 0x00000C6C
_08059C2C: .4byte 0x0000FFFB
_08059C30: .4byte 0x00000CAE
_08059C34: .4byte 0x00000CAC
_08059C38: .4byte 0x00000CEE
_08059C3C: .4byte 0x00000CEC
_08059C40: .4byte 0x00000D2E
_08059C44: .4byte 0x00000D2C
_08059C48: .4byte 0x00000D6E
_08059C4C: .4byte 0x00000D6C
_08059C50: .4byte 0x00000DAE
_08059C54: .4byte 0x0000CC0C
_08059C58: .4byte 0x00000DAC
_08059C5C: .4byte 0x00000DEE
_08059C60: .4byte 0x00000DEC
_08059C64: .4byte 0x00000E2E
_08059C68: .4byte 0x00000E2C
_08059C6C: .4byte 0x083D2C3D
_08059C70: .4byte 0x0000C804
_08059C74: .4byte 0x00000E6B
_08059C78:
	str r0, [r5, #0xc]
	ldr r0, _08059CE4 @ =0x03006434
	ldrh r1, [r0]
	adds r1, #0x30
	lsls r1, r1, #8
	ldr r0, [r5, #0x10]
	ands r0, r4
	orrs r0, r1
	str r0, [r5, #0x10]
	ldr r0, _08059CE8 @ =0x030055A0
	adds r0, #0xe4
	ldr r1, _08059CEC @ =0x0000FFFF
	strh r1, [r0]
	adds r2, #1
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x39
	movs r1, #0x60
	bl sub_080493D4
_08059CA2:
	movs r0, #0x63
	lsls r0, r0, #6
	adds r2, r6, r0
	movs r0, #0
	strh r0, [r2]
	ldr r1, _08059CF0 @ =0x083D2B8D
	ldr r3, _08059CF4 @ =0x030057A0
	ldrh r0, [r3, #0x20]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08059CD2
	ldr r4, _08059CF8 @ =0xFFFFCC0C
	strh r4, [r2]
	ldrh r0, [r5, #2]
	strh r0, [r2, #2]
	ldr r1, _08059CFC @ =0x00000E6C
	adds r0, r6, r1
	ldr r3, _08059D00 @ =0x0000FFFB
	ldrb r0, [r0]
	adds r1, r3, r0
	ldrh r0, [r5, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
_08059CD2:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08059CE4: .4byte 0x03006434
_08059CE8: .4byte 0x030055A0
_08059CEC: .4byte 0x0000FFFF
_08059CF0: .4byte 0x083D2B8D
_08059CF4: .4byte 0x030057A0
_08059CF8: .4byte 0xFFFFCC0C
_08059CFC: .4byte 0x00000E6C
_08059D00: .4byte 0x0000FFFB
	.syntax divided
