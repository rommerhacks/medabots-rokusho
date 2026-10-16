	.syntax unified

	thumb_func_start init_battle_scene_backgrounds
	.global init_battle_scene_backgrounds
init_battle_scene_backgrounds: @ 0x08035DE8
	push {r4, r5, r6, lr}
	sub sp, #0x24
	ldr r0, _08035E04 @ =0x03001800
	adds r0, #0xff
	ldrb r0, [r0]
	movs r2, #1
	adds r1, r2, #0
	ands r1, r0
	cmp r1, #0
	beq _08035E0C
	ldr r0, _08035E08 @ =0x03000440
	adds r0, #0x96
	strb r2, [r0]
	b _08035E12
	.align 2, 0
_08035E04: .4byte 0x03001800
_08035E08: .4byte 0x03000440
_08035E0C:
	ldr r0, _08035E94 @ =0x03000440
	adds r0, #0x96
	strb r1, [r0]
_08035E12:
	ldr r5, _08035E98 @ =0x03001800
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	bl sub_08035DD4
	cmp r0, #0
	beq _08035E7A
	movs r0, #0
	bl get_active_bot_part_index_and_load_values
	adds r0, r5, #0
	adds r0, #0x64
	ldrb r1, [r0]
	adds r0, #1
	ldrb r2, [r0]
	adds r0, #1
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	movs r6, #0
	ldrsh r0, [r4, r6]
	str r0, [sp, #4]
	movs r4, #0xab
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r0, #4
	str r0, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	movs r0, #1
	str r0, [sp, #0x18]
	str r4, [sp, #0x1c]
	movs r4, #0x8a
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrb r0, [r0]
	str r0, [sp, #0x20]
	movs r0, #0
	bl init_scene_with_bg_and_palette
_08035E7A:
	adds r0, r5, #0
	adds r0, #0xff
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08035E9C
	ldr r0, _08035E94 @ =0x03000440
	adds r0, #0x96
	movs r1, #1
	b _08035EA0
	.align 2, 0
_08035E94: .4byte 0x03000440
_08035E98: .4byte 0x03001800
_08035E9C:
	ldr r0, _08035F18 @ =0x03000440
	adds r0, #0x96
_08035EA0:
	strb r1, [r0]
	ldr r4, _08035F1C @ =0x03001800
	movs r6, #0xac
	lsls r6, r6, #1
	adds r5, r4, r6
	movs r1, #0
	ldrsh r0, [r5, r1]
	bl sub_08035DD4
	cmp r0, #0
	beq _08035F06
	movs r0, #1
	bl get_active_bot_part_index_and_load_values
	adds r0, r4, #0
	adds r0, #0x64
	ldrb r1, [r0]
	adds r0, #1
	ldrb r2, [r0]
	adds r0, #1
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	movs r6, #0
	ldrsh r0, [r5, r6]
	str r0, [sp, #4]
	movs r5, #0xad
	lsls r5, r5, #1
	adds r0, r4, r5
	movs r6, #0
	ldrsh r0, [r0, r6]
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	adds r0, #2
	str r0, [sp, #0xc]
	movs r0, #8
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	subs r5, #0x45
	adds r0, r4, r5
	ldrb r0, [r0]
	str r0, [sp, #0x20]
	movs r0, #1
	bl init_scene_with_bg_and_palette
_08035F06:
	ldr r0, _08035F18 @ =0x03000440
	adds r0, #0x96
	movs r1, #0
	strb r1, [r0]
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08035F18: .4byte 0x03000440
_08035F1C: .4byte 0x03001800
	.syntax divided
