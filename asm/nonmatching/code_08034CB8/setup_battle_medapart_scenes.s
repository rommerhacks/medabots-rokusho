	.syntax unified

	thumb_func_start setup_battle_medapart_scenes
	.global setup_battle_medapart_scenes
setup_battle_medapart_scenes: @ 0x08035F20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r0, _08035F44 @ =0x03001800
	adds r0, #0xff
	ldrb r0, [r0]
	movs r2, #1
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	beq _08035F4C
	ldr r0, _08035F48 @ =0x03000440
	adds r0, #0x96
	strb r2, [r0]
	b _08035F52
	.align 2, 0
_08035F44: .4byte 0x03001800
_08035F48: .4byte 0x03000440
_08035F4C:
	ldr r0, _08036020 @ =0x03000440
	adds r0, #0x96
	strb r1, [r0]
_08035F52:
	ldr r7, _08036024 @ =0x03001800
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl sub_08035DD4
	cmp r0, #0
	beq _08036004
	movs r0, #0
	bl get_active_bot_part_index_and_load_values
	movs r2, #0x64
	adds r2, r2, r7
	mov sb, r2
	ldrb r1, [r2]
	ldr r3, _08036028 @ =0x03001865
	ldrb r2, [r3]
	ldr r4, _0803602C @ =0x03001866
	ldrb r3, [r4]
	ldr r5, _08036030 @ =0x03001867
	ldrb r0, [r5]
	str r0, [sp]
	mov r6, sl
	movs r4, #0
	ldrsh r0, [r6, r4]
	str r0, [sp, #4]
	movs r5, #0xab
	lsls r5, r5, #1
	adds r5, r5, r7
	mov r8, r5
	movs r6, #0
	ldrsh r0, [r5, r6]
	str r0, [sp, #8]
	ldr r4, _08036034 @ =0x0300183C
	ldrb r0, [r4]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r5, #4
	str r5, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	movs r0, #2
	str r0, [sp, #0x18]
	str r4, [sp, #0x1c]
	movs r6, #0x8a
	lsls r6, r6, #1
	adds r5, r7, r6
	ldrb r0, [r5]
	str r0, [sp, #0x20]
	movs r0, #0
	bl init_scene_with_bg_and_palette
	mov r0, sb
	ldrb r1, [r0]
	ldr r3, _08036028 @ =0x03001865
	ldrb r2, [r3]
	ldr r6, _0803602C @ =0x03001866
	ldrb r6, [r6]
	mov sb, r6
	ldr r3, _08036030 @ =0x03001867
	ldrb r0, [r3]
	str r0, [sp]
	mov r6, sl
	movs r3, #0
	ldrsh r0, [r6, r3]
	str r0, [sp, #4]
	mov r6, r8
	movs r3, #0
	ldrsh r0, [r6, r3]
	str r0, [sp, #8]
	ldr r6, _08036034 @ =0x0300183C
	ldrb r0, [r6]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	movs r0, #1
	str r0, [sp, #0x18]
	str r4, [sp, #0x1c]
	ldrb r0, [r5]
	str r0, [sp, #0x20]
	movs r0, #0
	mov r3, sb
	bl init_scene_with_bg_and_palette
_08036004:
	adds r0, r7, #0
	adds r0, #0xff
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08036038
	ldr r0, _08036020 @ =0x03000440
	adds r0, #0x96
	movs r1, #1
	b _0803603C
	.align 2, 0
_08036020: .4byte 0x03000440
_08036024: .4byte 0x03001800
_08036028: .4byte 0x03001865
_0803602C: .4byte 0x03001866
_08036030: .4byte 0x03001867
_08036034: .4byte 0x0300183C
_08036038:
	ldr r0, _08036104 @ =0x03000440
	adds r0, #0x96
_0803603C:
	strb r1, [r0]
	ldr r1, _08036108 @ =0x03001800
	mov sb, r1
	movs r7, #0xac
	lsls r7, r7, #1
	add r7, sb
	movs r2, #0
	ldrsh r0, [r7, r2]
	bl sub_08035DD4
	cmp r0, #0
	beq _080360EA
	movs r0, #1
	bl get_active_bot_part_index_and_load_values
	ldr r3, _0803610C @ =0x03001864
	ldrb r1, [r3]
	ldr r4, _08036110 @ =0x03001865
	ldrb r2, [r4]
	ldr r5, _08036114 @ =0x03001866
	ldrb r5, [r5]
	mov ip, r5
	ldr r6, _08036118 @ =0x03001867
	ldrb r0, [r6]
	str r0, [sp]
	movs r3, #0
	ldrsh r0, [r7, r3]
	str r0, [sp, #4]
	movs r4, #0xad
	lsls r4, r4, #1
	add r4, sb
	mov sl, r4
	movs r5, #0
	ldrsh r0, [r4, r5]
	str r0, [sp, #8]
	mov r6, sb
	adds r6, #0x3c
	ldrb r0, [r6]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r5, #8
	str r5, [sp, #0x10]
	movs r4, #1
	str r4, [sp, #0x14]
	movs r0, #2
	str r0, [sp, #0x18]
	str r4, [sp, #0x1c]
	ldr r0, _0803611C @ =0x00000115
	add sb, r0
	mov r3, sb
	ldrb r0, [r3]
	str r0, [sp, #0x20]
	movs r0, #1
	mov r3, ip
	bl init_scene_with_bg_and_palette
	ldr r0, _0803610C @ =0x03001864
	ldrb r1, [r0]
	ldr r3, _08036110 @ =0x03001865
	ldrb r2, [r3]
	ldr r0, _08036114 @ =0x03001866
	ldrb r0, [r0]
	mov r8, r0
	ldr r3, _08036118 @ =0x03001867
	ldrb r0, [r3]
	str r0, [sp]
	movs r3, #0
	ldrsh r0, [r7, r3]
	str r0, [sp, #4]
	mov r7, sl
	movs r3, #0
	ldrsh r0, [r7, r3]
	str r0, [sp, #8]
	ldrb r0, [r6]
	adds r0, #2
	str r0, [sp, #0xc]
	str r5, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	mov r4, sb
	ldrb r0, [r4]
	str r0, [sp, #0x20]
	movs r0, #1
	mov r3, r8
	bl init_scene_with_bg_and_palette
_080360EA:
	ldr r0, _08036104 @ =0x03000440
	adds r0, #0x96
	movs r1, #0
	strb r1, [r0]
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08036104: .4byte 0x03000440
_08036108: .4byte 0x03001800
_0803610C: .4byte 0x03001864
_08036110: .4byte 0x03001865
_08036114: .4byte 0x03001866
_08036118: .4byte 0x03001867
_0803611C: .4byte 0x00000115
	.syntax divided
