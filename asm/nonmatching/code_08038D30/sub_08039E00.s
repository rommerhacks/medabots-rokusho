	.syntax unified

	thumb_func_start sub_08039E00
sub_08039E00: @ 0x08039E00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r7, _08039EE0 @ =0x03001800
	adds r0, r7, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _08039EF8
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r4, r7, r0
	subs r0, #0x28
	strh r0, [r4]
	movs r1, #0xab
	lsls r1, r1, #1
	adds r1, r1, r7
	mov sl, r1
	movs r0, #0x50
	strh r0, [r1]
	movs r0, #0
	bl get_active_bot_part_index_and_load_values
	ldr r3, _08039EE4 @ =0x03001864
	ldrb r1, [r3]
	ldr r5, _08039EE8 @ =0x03001865
	ldrb r2, [r5]
	ldr r0, _08039EEC @ =0x03001866
	ldrb r0, [r0]
	mov ip, r0
	ldr r3, _08039EF0 @ =0x03001867
	ldrb r0, [r3]
	str r0, [sp]
	movs r5, #0
	ldrsh r0, [r4, r5]
	str r0, [sp, #4]
	mov r3, sl
	movs r5, #0
	ldrsh r0, [r3, r5]
	str r0, [sp, #8]
	ldr r3, _08039EF4 @ =0x0300183C
	ldrb r0, [r3]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r5, #4
	mov r8, r5
	str r5, [sp, #0x10]
	str r6, [sp, #0x14]
	movs r0, #2
	str r0, [sp, #0x18]
	str r6, [sp, #0x1c]
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r5, r7, r3
	ldrb r0, [r5]
	str r0, [sp, #0x20]
	movs r0, #0
	mov r3, ip
	bl init_scene_with_bg_and_palette
	ldr r0, _08039EE4 @ =0x03001864
	ldrb r1, [r0]
	ldr r3, _08039EE8 @ =0x03001865
	ldrb r2, [r3]
	ldr r0, _08039EEC @ =0x03001866
	ldrb r0, [r0]
	mov sb, r0
	ldr r3, _08039EF0 @ =0x03001867
	ldrb r0, [r3]
	str r0, [sp]
	movs r3, #0
	ldrsh r0, [r4, r3]
	str r0, [sp, #4]
	mov r4, sl
	movs r3, #0
	ldrsh r0, [r4, r3]
	str r0, [sp, #8]
	ldr r4, _08039EF4 @ =0x0300183C
	ldrb r0, [r4]
	adds r0, #2
	str r0, [sp, #0xc]
	mov r0, r8
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	movs r0, #1
	str r0, [sp, #0x18]
	str r6, [sp, #0x1c]
	ldrb r0, [r5]
	str r0, [sp, #0x20]
	movs r0, #0
	mov r3, sb
	bl init_scene_with_bg_and_palette
	movs r3, #0x89
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0x29
	strb r0, [r1]
	ldr r4, _08039EF0 @ =0x03001867
	ldrb r2, [r4]
	movs r0, #0
	movs r1, #0x29
	bl advance_text_display
	b _08039FAE
	.align 2, 0
_08039EE0: .4byte 0x03001800
_08039EE4: .4byte 0x03001864
_08039EE8: .4byte 0x03001865
_08039EEC: .4byte 0x03001866
_08039EF0: .4byte 0x03001867
_08039EF4: .4byte 0x0300183C
_08039EF8:
	movs r0, #0xe2
	lsls r0, r0, #1
	ldr r5, _08039FC4 @ =0x03001958
	strh r0, [r5]
	movs r6, #0xad
	lsls r6, r6, #1
	adds r6, r6, r7
	mov sl, r6
	movs r0, #0x50
	strh r0, [r6]
	movs r0, #1
	bl get_active_bot_part_index_and_load_values
	ldr r0, _08039FC8 @ =0x03001864
	ldrb r1, [r0]
	ldr r3, _08039FCC @ =0x03001865
	ldrb r2, [r3]
	ldr r4, _08039FD0 @ =0x03001866
	ldrb r3, [r4]
	ldr r5, _08039FD4 @ =0x03001867
	ldrb r0, [r5]
	str r0, [sp]
	ldr r6, _08039FC4 @ =0x03001958
	movs r4, #0
	ldrsh r0, [r6, r4]
	str r0, [sp, #4]
	mov r5, sl
	movs r6, #0
	ldrsh r0, [r5, r6]
	str r0, [sp, #8]
	ldr r4, _08039FD8 @ =0x0300183C
	ldrb r0, [r4]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r5, #8
	str r5, [sp, #0x10]
	movs r4, #1
	str r4, [sp, #0x14]
	movs r6, #2
	str r6, [sp, #0x18]
	str r4, [sp, #0x1c]
	ldr r0, _08039FDC @ =0x00000115
	adds r0, r0, r7
	mov sb, r0
	ldrb r0, [r0]
	str r0, [sp, #0x20]
	movs r0, #1
	bl init_scene_with_bg_and_palette
	ldr r3, _08039FC8 @ =0x03001864
	ldrb r1, [r3]
	ldr r5, _08039FCC @ =0x03001865
	ldrb r2, [r5]
	ldr r6, _08039FD0 @ =0x03001866
	ldrb r3, [r6]
	ldr r5, _08039FD4 @ =0x03001867
	ldrb r0, [r5]
	str r0, [sp]
	ldr r6, _08039FC4 @ =0x03001958
	movs r5, #0
	ldrsh r0, [r6, r5]
	str r0, [sp, #4]
	mov r6, sl
	movs r5, #0
	ldrsh r0, [r6, r5]
	str r0, [sp, #8]
	ldr r6, _08039FD8 @ =0x0300183C
	ldrb r0, [r6]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r0, #8
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	mov r4, sb
	ldrb r0, [r4]
	str r0, [sp, #0x20]
	movs r0, #1
	bl init_scene_with_bg_and_palette
	ldr r5, _08039FE0 @ =0x00000113
	adds r1, r7, r5
	movs r0, #0x29
	strb r0, [r1]
	ldr r6, _08039FD4 @ =0x03001867
	ldrb r2, [r6]
	movs r0, #1
	movs r1, #0x29
	bl advance_text_display
_08039FAE:
	bl battle_advance_sequence_counter
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08039FC4: .4byte 0x03001958
_08039FC8: .4byte 0x03001864
_08039FCC: .4byte 0x03001865
_08039FD0: .4byte 0x03001866
_08039FD4: .4byte 0x03001867
_08039FD8: .4byte 0x0300183C
_08039FDC: .4byte 0x00000115
_08039FE0: .4byte 0x00000113
	.syntax divided
