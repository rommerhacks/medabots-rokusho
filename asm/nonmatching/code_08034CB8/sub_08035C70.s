	.syntax unified

	thumb_func_start sub_08035C70
	.global sub_08035C70
sub_08035C70: @ 0x08035C70
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	bl init_scene_buffers_080445F4
	ldr r3, _08035CA0 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08035CA4
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r2, #0
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r3, r1
	strb r2, [r0]
	b _08035CC6
	.align 2, 0
_08035CA0: .4byte 0x03001800
_08035CA4:
	movs r4, #0xaa
	lsls r4, r4, #1
	adds r1, r3, r4
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r6, #0x8a
	lsls r6, r6, #1
	adds r1, r3, r6
	movs r0, #0x28
	strb r0, [r1]
	adds r2, r3, #0
	adds r2, #0xff
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
_08035CC6:
	movs r0, #0
	bl get_active_bot_part_index_and_load_values
	ldr r6, _08035D50 @ =0x03001800
	movs r7, #0xab
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r4, #0
	movs r5, #0x50
	strh r5, [r0]
	adds r0, r6, #0
	adds r0, #0x64
	ldrb r1, [r0]
	adds r0, #1
	ldrb r2, [r0]
	adds r0, #1
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	subs r7, #2
	adds r0, r6, r7
	movs r7, #0
	ldrsh r0, [r0, r7]
	str r0, [sp, #4]
	str r5, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	movs r4, #0x8a
	lsls r4, r4, #1
	adds r0, r6, r4
	ldrb r0, [r0]
	str r0, [sp, #0x20]
	movs r0, #0
	bl init_scene_with_bg_and_palette
	adds r0, r6, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08035D54
	movs r7, #0xac
	lsls r7, r7, #1
	adds r1, r6, r7
	movs r0, #0xe2
	lsls r0, r0, #1
	strh r0, [r1]
	subs r0, #0xaf
	adds r1, r6, r0
	movs r0, #0x28
	strb r0, [r1]
	adds r2, r6, #0
	adds r2, #0xff
	ldrb r1, [r2]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	b _08035D66
	.align 2, 0
_08035D50: .4byte 0x03001800
_08035D54:
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0xb4
	strh r1, [r0]
	ldr r4, _08035DCC @ =0x00000115
	adds r1, r6, r4
	movs r0, #0
	strb r0, [r1]
_08035D66:
	movs r0, #1
	bl get_active_bot_part_index_and_load_values
	ldr r6, _08035DD0 @ =0x03001800
	mov ip, r6
	movs r0, #0xad
	lsls r0, r0, #1
	add r0, ip
	movs r5, #0
	movs r4, #0x50
	strh r4, [r0]
	mov r0, ip
	adds r0, #0x64
	ldrb r1, [r0]
	adds r0, #1
	ldrb r2, [r0]
	adds r0, #1
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, ip
	movs r7, #0
	ldrsh r0, [r0, r7]
	str r0, [sp, #4]
	str r4, [sp, #8]
	mov r0, ip
	adds r0, #0x3c
	ldrb r0, [r0]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r0, #8
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	str r0, [sp, #0x1c]
	ldr r0, _08035DCC @ =0x00000115
	add r0, ip
	ldrb r0, [r0]
	str r0, [sp, #0x20]
	movs r0, #1
	bl init_scene_with_bg_and_palette
	add sp, #0x24
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08035DCC: .4byte 0x00000115
_08035DD0: .4byte 0x03001800
	.syntax divided
