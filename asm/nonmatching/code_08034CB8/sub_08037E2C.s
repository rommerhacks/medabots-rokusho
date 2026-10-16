	.syntax unified

	thumb_func_start sub_08037E2C
sub_08037E2C: @ 0x08037E2C
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r2, _08037E6C @ =0x083B5F80
	ldr r4, _08037E70 @ =0x03002C30
	ldr r0, _08037E74 @ =0x03000440
	ldr r1, _08037E78 @ =0x0000012F
	adds r5, r0, r1
	ldrb r1, [r5]
	lsls r0, r1, #6
	adds r0, r0, r4
	adds r0, #0x2e
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	bl process_sprite_anim_commands
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r1, r0, r4
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r2, [r0]
	adds r0, r2, #0
	cmp r0, #0xff
	bne _08037E7C
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08037FCA
	.align 2, 0
_08037E6C: .4byte 0x083B5F80
_08037E70: .4byte 0x03002C30
_08037E74: .4byte 0x03000440
_08037E78: .4byte 0x0000012F
_08037E7C:
	movs r0, #0x3f
	ands r0, r2
	cmp r0, #0
	bne _08037EB8
	ldr r0, _08037E98 @ =0x03001800
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #1
	beq _08037EAA
	cmp r0, #1
	bgt _08037E9C
	cmp r0, #0
	beq _08037EA2
	b _08037EB8
	.align 2, 0
_08037E98: .4byte 0x03001800
_08037E9C:
	cmp r0, #2
	beq _08037EB2
	b _08037EB8
_08037EA2:
	movs r0, #0x5d
	bl play_sound_effect
	b _08037EB8
_08037EAA:
	movs r0, #0x2e
	bl play_sound_effect
	b _08037EB8
_08037EB2:
	movs r0, #0x4b
	bl play_sound_effect
_08037EB8:
	ldr r5, _08037F3C @ =0x03002C30
	ldr r0, _08037F40 @ =0x03000440
	ldr r2, _08037F44 @ =0x0000012F
	adds r4, r0, r2
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r3, r0, #0
	adds r3, #0x2b
	ldr r2, _08037F48 @ =0x083AF630
	adds r0, #0x2d
	ldrb r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	ldrb r1, [r3]
	adds r0, r0, r1
	strb r0, [r3]
	ldr r2, _08037F4C @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08037F54
	adds r0, r2, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #0
	bne _08037F0C
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	ldrh r1, [r0, #0x18]
	subs r1, #0x10
	ldr r3, _08037F50 @ =0x000003FF
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r0, #0x18]
_08037F0C:
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x2c
	ldrb r1, [r0]
	subs r1, #1
	strb r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r1, r0, #0
	adds r1, #0x2c
	ldrb r1, [r1]
	adds r0, #0x2b
	ldrb r2, [r0]
	movs r0, #0x34
	str r0, [sp]
	add r0, sp, #4
	movs r3, #0xb8
	bl calc_polar_to_screen_coords
	ldr r1, [sp, #4]
	b _08037F9C
	.align 2, 0
_08037F3C: .4byte 0x03002C30
_08037F40: .4byte 0x03000440
_08037F44: .4byte 0x0000012F
_08037F48: .4byte 0x083AF630
_08037F4C: .4byte 0x03001800
_08037F50: .4byte 0x000003FF
_08037F54:
	adds r0, r2, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #0
	bne _08037F70
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	ldrh r1, [r0, #0x18]
	adds r1, #0x10
	ldr r3, _08037FD4 @ =0x000003FF
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r0, #0x18]
_08037F70:
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r0, #0x2c
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r1, r0, #0
	adds r1, #0x2c
	ldrb r1, [r1]
	adds r0, #0x2b
	ldrb r2, [r0]
	movs r0, #0x34
	str r0, [sp]
	add r0, sp, #8
	movs r3, #0x38
	bl calc_polar_to_screen_coords
	ldr r1, [sp, #8]
_08037F9C:
	ldr r4, _08037FD8 @ =0x03002C30
	ldr r0, _08037FDC @ =0x03000440
	ldr r2, _08037FE0 @ =0x0000012F
	adds r5, r0, r2
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	strh r1, [r0, #2]
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	asrs r1, r1, #0x10
	strh r1, [r0, #4]
	ldrb r0, [r5]
	bl spawn_battle_particle_effect
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x2d
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
_08037FCA:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08037FD4: .4byte 0x000003FF
_08037FD8: .4byte 0x03002C30
_08037FDC: .4byte 0x03000440
_08037FE0: .4byte 0x0000012F
_08037FE4:
	.byte 0x07, 0x4B, 0x08, 0x48, 0x08, 0x49, 0x42, 0x18, 0x10, 0x78, 0x80, 0x01
	.byte 0xC1, 0x18, 0x08, 0x7A, 0x04, 0x28, 0x0B, 0xD1, 0x29, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70
	.byte 0x0E, 0xE0, 0x00, 0x00, 0x30, 0x2C, 0x00, 0x03, 0x40, 0x04, 0x00, 0x03, 0x2F, 0x01, 0x00, 0x00
	.byte 0x04, 0x38, 0x08, 0x72, 0x11, 0x78, 0x89, 0x01, 0xC9, 0x18, 0x48, 0x7A, 0x04, 0x38, 0x48, 0x72
	.byte 0x70, 0x47, 0x00, 0x00, 0x08, 0x49, 0x09, 0x48, 0x09, 0x4A, 0x80, 0x18, 0x00, 0x78, 0x80, 0x01
	.byte 0x41, 0x18, 0x0A, 0x1C, 0x2D, 0x32, 0x10, 0x78, 0x5A, 0x28, 0x0B, 0xD1, 0x29, 0x31, 0x08, 0x78
	.byte 0x01, 0x30, 0x08, 0x70, 0x08, 0xE0, 0x00, 0x00, 0x30, 0x2C, 0x00, 0x03, 0x40, 0x04, 0x00, 0x03
	.byte 0x2F, 0x01, 0x00, 0x00, 0x01, 0x30, 0x10, 0x70, 0x70, 0x47, 0x00, 0x00, 0x07, 0x4B, 0x08, 0x48
	.byte 0x08, 0x49, 0x42, 0x18, 0x10, 0x78, 0x80, 0x01, 0xC1, 0x18, 0x08, 0x7A, 0x08, 0x28, 0x0B, 0xD1
	.byte 0x29, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x0E, 0xE0, 0x00, 0x00, 0x30, 0x2C, 0x00, 0x03
	.byte 0x40, 0x04, 0x00, 0x03, 0x2F, 0x01, 0x00, 0x00, 0x08, 0x38, 0x08, 0x72, 0x11, 0x78, 0x89, 0x01
	.byte 0xC9, 0x18, 0x48, 0x7A, 0x08, 0x38, 0x48, 0x72, 0x70, 0x47, 0x00, 0x00
	.syntax divided
