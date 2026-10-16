	.syntax unified

	thumb_func_start sub_08037C50
sub_08037C50: @ 0x08037C50
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r2, _08037C90 @ =0x083B5F80
	ldr r4, _08037C94 @ =0x03002C30
	ldr r0, _08037C98 @ =0x03000440
	ldr r1, _08037C9C @ =0x0000012F
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
	bne _08037CA0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08037E12
	.align 2, 0
_08037C90: .4byte 0x083B5F80
_08037C94: .4byte 0x03002C30
_08037C98: .4byte 0x03000440
_08037C9C: .4byte 0x0000012F
_08037CA0:
	movs r0, #0x3f
	ands r0, r2
	cmp r0, #0
	bne _08037D02
	ldr r0, _08037CBC @ =0x03001800
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #5
	bhi _08037D02
	lsls r0, r0, #2
	ldr r1, _08037CC0 @ =_08037CC4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08037CBC: .4byte 0x03001800
_08037CC0: .4byte _08037CC4
_08037CC4: @ jump table
	.4byte _08037CDC @ case 0
	.4byte _08037CE4 @ case 1
	.4byte _08037CEC @ case 2
	.4byte _08037CF4 @ case 3
	.4byte _08037CFC @ case 4
	.4byte _08037D02 @ case 5
_08037CDC:
	movs r0, #0x36
	bl play_sound_effect
	b _08037D02
_08037CE4:
	movs r0, #0x28
	bl play_sound_effect
	b _08037D02
_08037CEC:
	movs r0, #0x31
	bl play_sound_effect
	b _08037D02
_08037CF4:
	movs r0, #0x71
	bl play_sound_effect
	b _08037D02
_08037CFC:
	movs r0, #0x4f
	bl play_sound_effect
_08037D02:
	ldr r5, _08037D84 @ =0x03002C30
	ldr r0, _08037D88 @ =0x03000440
	ldr r2, _08037D8C @ =0x0000012F
	adds r4, r0, r2
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	adds r3, r0, #0
	adds r3, #0x2b
	ldr r2, _08037D90 @ =0x083AF630
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
	ldr r2, _08037D94 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08037D9C
	adds r0, r2, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #3
	beq _08037D56
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	ldrh r1, [r0, #0x18]
	subs r1, #0x10
	ldr r3, _08037D98 @ =0x000003FF
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r0, #0x18]
_08037D56:
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
	b _08037DE4
	.align 2, 0
_08037D84: .4byte 0x03002C30
_08037D88: .4byte 0x03000440
_08037D8C: .4byte 0x0000012F
_08037D90: .4byte 0x083AF630
_08037D94: .4byte 0x03001800
_08037D98: .4byte 0x000003FF
_08037D9C:
	adds r0, r2, #0
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #3
	beq _08037DB8
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, r0, r5
	ldrh r1, [r0, #0x18]
	adds r1, #0x10
	ldr r3, _08037E1C @ =0x000003FF
	adds r2, r3, #0
	ands r1, r2
	strh r1, [r0, #0x18]
_08037DB8:
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
_08037DE4:
	ldr r4, _08037E20 @ =0x03002C30
	ldr r0, _08037E24 @ =0x03000440
	ldr r2, _08037E28 @ =0x0000012F
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
	bl sub_080378F0
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x2d
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
_08037E12:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08037E1C: .4byte 0x000003FF
_08037E20: .4byte 0x03002C30
_08037E24: .4byte 0x03000440
_08037E28: .4byte 0x0000012F
	.syntax divided
