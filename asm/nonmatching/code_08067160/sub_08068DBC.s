	.syntax unified

	thumb_func_start sub_08068DBC
sub_08068DBC: @ 0x08068DBC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	bl sub_0806918C
	bl load_battle_sprite_graphics
	bl init_battle_background_layers
	bl load_bg_tilemaps_and_palette
	movs r0, #0
	bl play_song
	movs r7, #0
	ldr r5, _08068FA8 @ =0x03001800
	ldr r0, _08068FAC @ =0x03006FA0
	mov sb, r0
	movs r1, #0x92
	adds r1, r1, r5
	mov r8, r1
	mov r6, sb
_08068DEE:
	ldr r3, _08068FB0 @ =0x03006FD0
	adds r1, r7, r3
	adds r0, r5, #0
	adds r0, #0x8c
	adds r0, r7, r0
	ldrb r0, [r0]
	strb r0, [r1]
	lsls r1, r7, #2
	adds r0, r5, #0
	adds r0, #0x8f
	adds r0, r1, r0
	ldrb r0, [r0]
	strb r0, [r6]
	movs r4, #3
	add r4, sb
	mov sl, r4
	adds r3, r7, r4
	adds r0, r5, #0
	adds r0, #0x90
	adds r0, r1, r0
	ldrb r0, [r0]
	strb r0, [r3]
	mov r2, sb
	adds r2, #6
	adds r2, r7, r2
	adds r0, r5, #0
	adds r0, #0x91
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r2]
	mov r1, r8
	ldrb r0, [r1]
	strb r0, [r6, #9]
	ldrb r0, [r6]
	ldrb r1, [r3]
	ldrb r2, [r2]
	ldrb r3, [r6, #9]
	movs r4, #2
	subs r4, r4, r7
	str r4, [sp]
	bl decompress_sprite_to_vram_08042D94
	movs r3, #4
	add r8, r3
	adds r6, #1
	adds r7, #1
	cmp r7, #2
	ble _08068DEE
	ldr r3, _08068FB4 @ =0x083C1A00
	ldr r2, _08068FB8 @ =0x08486160
	ldr r0, _08068FBC @ =0x03006FDC
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r4, #2
	ldrsh r0, [r0, r4]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r6, [r0]
	adds r6, #4
	movs r7, #0
	movs r5, #3
	rsbs r5, r5, #0
	add r5, sl
	mov sb, r5
	movs r0, #0x12
	add r0, sl
	mov r8, r0
_08068E7A:
	movs r1, #0xc
	add r1, sb
	mov sl, r1
	adds r5, r7, r1
	ldrb r0, [r6]
	strb r0, [r5]
	adds r6, #1
	mov r3, sb
	adds r3, #0xf
	adds r3, r7, r3
	ldrb r0, [r6]
	strb r0, [r3]
	adds r6, #1
	mov r2, sb
	adds r2, #0x12
	adds r2, r7, r2
	ldrb r0, [r6]
	strb r0, [r2]
	adds r6, #1
	ldrb r0, [r6]
	mov r4, r8
	strb r0, [r4]
	adds r6, #9
	ldr r0, _08068FC0 @ =0x03006FD3
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _08068FC4 @ =0x083B827C
	ldrb r0, [r4]
	lsls r0, r0, #6
	adds r0, #0x31
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #0x64
	mov r1, ip
	strb r0, [r1]
	ldrb r0, [r5]
	ldrb r1, [r3]
	ldrb r2, [r2]
	ldrb r3, [r4]
	movs r4, #5
	subs r4, r4, r7
	str r4, [sp]
	bl decompress_sprite_to_vram_08042D94
	movs r3, #1
	add r8, r3
	adds r7, #1
	cmp r7, #2
	ble _08068E7A
	ldr r3, _08068FB4 @ =0x083C1A00
	ldr r2, _08068FB8 @ =0x08486160
	ldr r0, _08068FBC @ =0x03006FDC
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r4, #6
	ldrsh r0, [r0, r4]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r6, [r0]
	adds r6, #4
	movs r7, #0
	movs r5, #0xc
	rsbs r5, r5, #0
	add r5, sl
	mov sb, r5
	movs r0, #0x15
	add r0, sl
	mov r8, r0
	ldr r1, _08068FC8 @ =0x03006FD6
	mov sl, r1
_08068F0C:
	mov r4, sb
	adds r4, #0x18
	adds r4, r7, r4
	ldrb r0, [r6]
	strb r0, [r4]
	adds r6, #1
	mov r3, sb
	adds r3, #0x1b
	adds r3, r7, r3
	ldrb r0, [r6]
	strb r0, [r3]
	adds r6, #1
	mov r2, sb
	adds r2, #0x1e
	adds r2, r7, r2
	ldrb r0, [r6]
	strb r0, [r2]
	adds r6, #1
	ldrb r0, [r6]
	mov r5, r8
	strb r0, [r5]
	adds r6, #9
	adds r0, r7, #0
	add r0, sl
	mov ip, r0
	ldr r1, _08068FC4 @ =0x083B827C
	ldrb r0, [r5]
	lsls r0, r0, #6
	adds r0, #0x31
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #0x64
	mov r1, ip
	strb r0, [r1]
	ldrb r0, [r4]
	ldrb r1, [r3]
	ldrb r2, [r2]
	ldrb r3, [r5]
	movs r4, #8
	subs r4, r4, r7
	str r4, [sp]
	bl decompress_sprite_to_vram_08042D94
	movs r3, #1
	add r8, r3
	adds r7, #1
	cmp r7, #2
	ble _08068F0C
	movs r0, #0x13
	bl play_song
	movs r0, #2
	movs r1, #2
	movs r2, #0
	bl setup_screen_transition_effect_080682CC
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r4, #0xf0
	lsls r4, r4, #5
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _08068FCC @ =0x03006F80
	movs r0, #6
	str r0, [r1]
	ldr r1, _08068FD0 @ =0x0300137C
	movs r0, #1
	str r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08068FA8: .4byte 0x03001800
_08068FAC: .4byte 0x03006FA0
_08068FB0: .4byte 0x03006FD0
_08068FB4: .4byte 0x083C1A00
_08068FB8: .4byte 0x08486160
_08068FBC: .4byte 0x03006FDC
_08068FC0: .4byte 0x03006FD3
_08068FC4: .4byte 0x083B827C
_08068FC8: .4byte 0x03006FD6
_08068FCC: .4byte 0x03006F80
_08068FD0: .4byte 0x0300137C
	.syntax divided
