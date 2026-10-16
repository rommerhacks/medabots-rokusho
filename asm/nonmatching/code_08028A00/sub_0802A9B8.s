	.syntax unified

	thumb_func_start sub_0802A9B8
sub_0802A9B8: @ 0x0802A9B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0
	mov sl, r0
	mov sb, r0
	movs r4, #0
	ldr r7, _0802AAA0 @ =0x03001800
	ldr r1, _0802AAA4 @ =0x03002C30
	mov r8, r1
	ldr r6, _0802AAA8 @ =0x00000882
	add r6, r8
_0802A9D4:
	adds r0, r7, #0
	adds r0, #0xd2
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802AA3A
	movs r0, #1
	add sb, r0
	adds r5, r7, #0
	adds r5, #0x60
	ldrb r0, [r5]
	adds r0, r0, r4
	bl sub_08019544
	ldrb r0, [r5]
	adds r0, r0, r4
	bl sub_08019440
	cmp r0, #0
	beq _0802AA00
	movs r1, #1
	add sl, r1
_0802AA00:
	ldr r1, _0802AAAC @ =0x083B610C
	ldr r0, [r1]
	adds r1, r4, #0
	adds r1, #0x22
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	ldrb r0, [r5]
	adds r0, r0, r4
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	add r0, r8
	ldrh r0, [r0, #2]
	strh r0, [r6]
	ldrb r0, [r5]
	adds r0, r0, r4
	lsls r0, r0, #8
	adds r0, r0, r1
	add r0, r8
	ldrh r0, [r0, #4]
	subs r0, #0x10
	strh r0, [r6, #2]
	ldrb r0, [r5]
	adds r0, r0, r4
	bl init_battle_sprite_entry_0801BC04
_0802AA3A:
	adds r6, #0x40
	adds r4, #1
	cmp r4, #2
	bls _0802A9D4
	ldr r0, _0802AAB0 @ =0x083B5F80
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	ldr r0, _0802AAB4 @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x86
	ldrh r1, [r4]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _0802AA68
	movs r0, #0x33
	bl play_sound_effect
_0802AA68:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	bl sub_080383E8
	cmp sl, sb
	bne _0802AA92
	ldrh r0, [r4]
	cmp r0, #0x3c
	bls _0802AA92
	movs r0, #0x21
	movs r1, #0x1b
	bl clear_battle_sprite_slot
	bl iterate_bots_setup_battle_sprites
	ldr r1, _0802AAA0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802AA92:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802AAA0: .4byte 0x03001800
_0802AAA4: .4byte 0x03002C30
_0802AAA8: .4byte 0x00000882
_0802AAAC: .4byte 0x083B610C
_0802AAB0: .4byte 0x083B5F80
_0802AAB4: .4byte 0x03000440
_0802AAB8:
	.byte 0x04, 0x49, 0x0A, 0x1C, 0xA6, 0x32, 0x65, 0x20
	.byte 0x10, 0x70, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30, 0x08, 0x70, 0x70, 0x47, 0x00, 0x18, 0x00, 0x03
	.syntax divided
