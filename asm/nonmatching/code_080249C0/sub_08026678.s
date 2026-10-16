	.syntax unified

	thumb_func_start sub_08026678
sub_08026678: @ 0x08026678
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _080267FC @ =0x083B5F80
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	movs r1, #0x22
	bl process_sprite_anim_commands
	ldr r6, _08026800 @ =0x03001800
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r5, _08026804 @ =0x03000590
	adds r7, r6, #0
	adds r7, #0xa7
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0x87
	adds r1, r1, r6
	mov r8, r1
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r5
	adds r0, #0x49
	ldrb r0, [r0]
	subs r0, #0x37
	ldr r2, _08026808 @ =0x00000119
	adds r1, r6, r2
	strb r0, [r1]
	ldrb r0, [r1]
	ldrb r1, [r7]
	bl sub_08037578
	movs r1, #0x8d
	lsls r1, r1, #1
	adds r1, r1, r6
	mov sb, r1
	strb r0, [r1]
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, r0, #8
	adds r1, r5, #0
	adds r1, #0x48
	adds r0, r0, r1
	ldrb r2, [r7]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #0x18
	bl memcpy_bytes_0803F63C
	mov r1, sb
	ldrb r0, [r1]
	ldrb r1, [r7]
	ldr r4, _0802680C @ =0x0300052E
	adds r2, r4, #0
	bl load_part_data
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	mov r2, r8
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r5
	ldrb r1, [r4]
	adds r0, #0x48
	strb r1, [r0]
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r5
	ldrb r1, [r4, #1]
	adds r0, #0x49
	strb r1, [r0]
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r5
	ldrb r1, [r4, #5]
	adds r0, #0x4d
	strb r1, [r0]
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r5
	ldrb r1, [r4, #6]
	adds r0, #0x4e
	strb r1, [r0]
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r5
	ldrb r1, [r4, #7]
	adds r0, #0x4f
	strb r1, [r0]
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r5
	ldrb r1, [r4, #0xc]
	adds r0, #0x54
	strb r1, [r0]
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r5
	adds r0, #0x4a
	movs r1, #7
	strb r1, [r0]
	ldrb r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r5
	mov r2, sb
	ldrb r1, [r2]
	adds r0, #0x5f
	strb r1, [r0]
	mov r1, r8
	ldrb r0, [r1]
	bl battle_process_all_bot_actions
	mov r2, r8
	ldrb r0, [r2]
	ldrb r1, [r7]
	adds r1, #1
	bl battle_bot_select_part
	bl load_all_bot_part_sprites
	bl iterate_bots_setup_battle_sprites
	adds r1, r6, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080267FC: .4byte 0x083B5F80
_08026800: .4byte 0x03001800
_08026804: .4byte 0x03000590
_08026808: .4byte 0x00000119
_0802680C: .4byte 0x0300052E
	.syntax divided
