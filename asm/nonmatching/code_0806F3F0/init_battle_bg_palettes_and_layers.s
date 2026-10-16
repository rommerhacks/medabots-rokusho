	.syntax unified

	thumb_func_start init_battle_bg_palettes_and_layers
init_battle_bg_palettes_and_layers: @ 0x08070BFC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _08070E2C @ =0x040000D4
	ldr r1, _08070E30 @ =0x087C4DFC
	str r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _08070E34 @ =0x84000030
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r3, _08070E38 @ =0x0807C700
	str r3, [r0]
	ldr r1, _08070E3C @ =0x05000200
	str r1, [r0, #4]
	ldr r2, _08070E40 @ =0x80000010
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	adds r1, r3, #0
	subs r1, #0x40
	str r1, [r0]
	ldr r1, _08070E44 @ =0x05000220
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	adds r1, r3, #0
	subs r1, #0xc0
	str r1, [r0]
	ldr r1, _08070E48 @ =0x05000300
	str r1, [r0, #4]
	adds r2, #0x30
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	ldr r4, _08070E4C @ =0xFFFFFE40
	adds r1, r3, r4
	str r1, [r0]
	ldr r1, _08070E50 @ =0x05000380
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	ldr r1, _08070E54 @ =0x0400000A
	ldr r2, _08070E58 @ =0x00001509
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _08070E5C @ =0x0000160A
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r4, _08070E60 @ =0x0000170B
	adds r0, r4, #0
	strh r0, [r1]
	adds r1, #0x42
	ldr r2, _08070E64 @ =0x00001C42
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _08070E68 @ =0x0000080A
	adds r0, r3, #0
	strh r0, [r1]
	movs r5, #0xc8
	lsls r5, r5, #8
	movs r2, #0xa1
	lsls r2, r2, #3
	movs r4, #3
	str r4, [sp]
	movs r0, #6
	adds r1, r5, #0
	movs r3, #8
	bl init_battle_sprite_entry_08048818
	ldr r7, _08070E6C @ =0x03002C30
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0x40
	mov sb, r2
	mov r3, sb
	strh r3, [r0]
	adds r1, #2
	adds r0, r7, r1
	movs r2, #0x42
	mov r8, r2
	mov r3, r8
	strh r3, [r0]
	ldr r0, _08070E70 @ =0x0000018B
	adds r1, r7, r0
	movs r0, #0x24
	strb r0, [r1]
	ldr r2, _08070E74 @ =0x00000509
	str r4, [sp]
	movs r0, #7
	adds r1, r5, #0
	movs r3, #8
	bl init_battle_sprite_entry_08048818
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0x38
	strh r0, [r1]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r6, #0x3a
	strh r6, [r0]
	ldr r1, _08070E78 @ =0x000001CB
	adds r0, r7, r1
	movs r2, #0x28
	mov sl, r2
	mov r3, sl
	strb r3, [r0]
	ldr r2, _08070E7C @ =0x0000050A
	str r4, [sp]
	movs r0, #8
	adds r1, r5, #0
	movs r3, #8
	bl init_battle_sprite_entry_08048818
	ldr r0, _08070E80 @ =0x00000202
	adds r1, r7, r0
	movs r0, #0x44
	strh r0, [r1]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r6, [r0]
	ldr r2, _08070E84 @ =0x0000020B
	adds r1, r7, r2
	movs r0, #0x1c
	strb r0, [r1]
	ldr r2, _08070E88 @ =0x0000050B
	str r4, [sp]
	movs r0, #9
	adds r1, r5, #0
	movs r3, #8
	bl init_battle_sprite_entry_08048818
	ldr r3, _08070E8C @ =0x00000242
	adds r0, r7, r3
	mov r1, sb
	strh r1, [r0]
	movs r2, #0x91
	lsls r2, r2, #2
	adds r0, r7, r2
	mov r3, r8
	strh r3, [r0]
	ldr r0, _08070E90 @ =0x0000024B
	adds r1, r7, r0
	movs r0, #0x20
	strb r0, [r1]
	movs r2, #0xa0
	lsls r2, r2, #3
	str r4, [sp]
	movs r0, #2
	adds r1, r5, #0
	movs r3, #8
	bl init_battle_sprite_entry_08048818
	adds r0, r7, #0
	adds r0, #0x82
	movs r1, #0x50
	mov r8, r1
	mov r2, r8
	strh r2, [r0]
	adds r0, #2
	ldr r6, _08070E94 @ =0x0000FFD0
	strh r6, [r0]
	adds r1, r7, #0
	adds r1, #0x8b
	movs r0, #0x25
	strb r0, [r1]
	ldr r2, _08070E98 @ =0x0000050C
	str r4, [sp]
	movs r0, #1
	adds r1, r5, #0
	movs r3, #1
	bl init_battle_sprite_entry_08048818
	adds r0, r7, #0
	adds r0, #0x42
	mov r3, r8
	strh r3, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r1, r7, #0
	adds r1, #0x4b
	movs r0, #0x30
	strb r0, [r1]
	ldr r2, _08070E9C @ =0x00000501
	str r4, [sp]
	movs r0, #3
	adds r1, r5, #0
	movs r3, #8
	bl init_battle_sprite_entry_08048818
	adds r0, r7, #0
	adds r0, #0xc2
	mov r1, sl
	strh r1, [r0]
	adds r0, #2
	strh r6, [r0]
	adds r0, #7
	movs r2, #0x29
	mov sb, r2
	mov r3, sb
	strb r3, [r0]
	ldr r2, _08070EA0 @ =0x00000502
	str r4, [sp]
	movs r0, #4
	adds r1, r5, #0
	movs r3, #8
	bl init_battle_sprite_entry_08048818
	movs r0, #0x81
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x54
	strh r0, [r1]
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r6, [r0]
	ldr r2, _08070EA4 @ =0x0000010B
	adds r1, r7, r2
	movs r0, #0x1d
	strb r0, [r1]
	ldr r2, _08070EA8 @ =0x00000503
	str r4, [sp]
	movs r0, #5
	adds r1, r5, #0
	movs r3, #8
	bl init_battle_sprite_entry_08048818
	movs r3, #0xa1
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r4, r8
	strh r4, [r0]
	movs r1, #0xa2
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r6, [r0]
	ldr r2, _08070EAC @ =0x0000014B
	adds r0, r7, r2
	mov r3, sb
	strb r3, [r0]
	ldr r0, _08070EB0 @ =0x03001800
	movs r4, #1
	strb r4, [r0, #0xc]
	movs r1, #0
	strb r1, [r0, #0xd]
	movs r0, #4
	movs r1, #2
	movs r2, #0
	bl setup_screen_transition_effect_080682CC
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0xf0
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08070EB4 @ =0x0300137C
	str r4, [r0]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08070E2C: .4byte 0x040000D4
_08070E30: .4byte 0x087C4DFC
_08070E34: .4byte 0x84000030
_08070E38: .4byte 0x0807C700
_08070E3C: .4byte 0x05000200
_08070E40: .4byte 0x80000010
_08070E44: .4byte 0x05000220
_08070E48: .4byte 0x05000300
_08070E4C: .4byte 0xFFFFFE40
_08070E50: .4byte 0x05000380
_08070E54: .4byte 0x0400000A
_08070E58: .4byte 0x00001509
_08070E5C: .4byte 0x0000160A
_08070E60: .4byte 0x0000170B
_08070E64: .4byte 0x00001C42
_08070E68: .4byte 0x0000080A
_08070E6C: .4byte 0x03002C30
_08070E70: .4byte 0x0000018B
_08070E74: .4byte 0x00000509
_08070E78: .4byte 0x000001CB
_08070E7C: .4byte 0x0000050A
_08070E80: .4byte 0x00000202
_08070E84: .4byte 0x0000020B
_08070E88: .4byte 0x0000050B
_08070E8C: .4byte 0x00000242
_08070E90: .4byte 0x0000024B
_08070E94: .4byte 0x0000FFD0
_08070E98: .4byte 0x0000050C
_08070E9C: .4byte 0x00000501
_08070EA0: .4byte 0x00000502
_08070EA4: .4byte 0x0000010B
_08070EA8: .4byte 0x00000503
_08070EAC: .4byte 0x0000014B
_08070EB0: .4byte 0x03001800
_08070EB4: .4byte 0x0300137C
	.syntax divided
