	.syntax unified

	thumb_func_start init_battle_display_and_palette
init_battle_display_and_palette: @ 0x08002F70
	push {r4, r5, lr}
	sub sp, #0x14
	ldr r0, _08002FF8 @ =0x03000588
	movs r1, #1
	strb r1, [r0]
	ldr r5, _08002FFC @ =0x03000440
	adds r0, r5, #0
	adds r0, #0x8e
	ldrb r0, [r0]
	cmp r0, #2
	beq _08002FD6
	movs r4, #0x80
	lsls r4, r4, #0x13
	ldrh r1, [r4]
	ldr r0, _08003000 @ =0x0000F1FF
	ands r0, r1
	strh r0, [r4]
	ldr r1, _08003004 @ =0x040000D4
	ldr r0, _08003008 @ =0x084E2E38
	str r0, [r1]
	ldr r0, _0800300C @ =0x0202F9E0
	str r0, [r1, #4]
	ldr r0, _08003010 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bl update_battle_field_frame
	bl sub_080487E4
	movs r1, #0xbc
	lsls r1, r1, #6
	movs r0, #0x10
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	movs r0, #0xa
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	movs r0, #0x40
	movs r2, #5
	movs r3, #0x10
	bl setup_blend_effect
	ldrh r0, [r4]
	movs r2, #0xf6
	lsls r2, r2, #4
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
_08002FD6:
	adds r1, r5, #0
	adds r1, #0x88
	movs r2, #0
	movs r0, #0x12
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x84
	strb r2, [r0]
	ldr r1, _08003014 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08002FF8: .4byte 0x03000588
_08002FFC: .4byte 0x03000440
_08003000: .4byte 0x0000F1FF
_08003004: .4byte 0x040000D4
_08003008: .4byte 0x084E2E38
_0800300C: .4byte 0x0202F9E0
_08003010: .4byte 0x84000008
_08003014: .4byte 0x0300137C
	.syntax divided
