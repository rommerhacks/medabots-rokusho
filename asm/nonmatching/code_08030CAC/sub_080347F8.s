	.syntax unified

	thumb_func_start sub_080347F8
sub_080347F8: @ 0x080347F8
	push {r4, lr}
	bl init_battle_scene_backgrounds
	bl battle_advance_dialogue_text
	ldr r4, _08034864 @ =0x03001800
	ldr r2, _08034868 @ =0x0000015F
	adds r1, r4, r2
	strb r0, [r1]
	bl battle_advance_action_text
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0xf6
	movs r0, #3
	strb r0, [r1]
	ldr r2, _0803486C @ =0x03000590
	adds r3, r4, #0
	adds r3, #0x87
	ldrb r1, [r3]
	lsls r0, r1, #8
	adds r0, r0, r2
	adds r1, #1
	adds r0, #0xe0
	strb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x88
	ldrb r0, [r0]
	ldr r2, _08034870 @ =0x00000161
	adds r1, r4, r2
	strb r0, [r1]
	ldrb r0, [r3]
	bl sub_080355C4
	adds r2, r4, #0
	adds r2, #0xf8
	ldrb r0, [r2]
	movs r1, #2
	eors r0, r1
	strb r0, [r2]
	movs r1, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _08034874
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r3, [r0]
	b _0803488A
	.align 2, 0
_08034864: .4byte 0x03001800
_08034868: .4byte 0x0000015F
_0803486C: .4byte 0x03000590
_08034870: .4byte 0x00000161
_08034874:
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0x28
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0xff
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
_0803488A:
	ldr r2, _080348B0 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080348B8
	ldr r0, _080348B4 @ =0x00000115
	adds r1, r2, r0
	movs r0, #0x28
	strb r0, [r1]
	adds r2, #0xff
	ldrb r1, [r2]
	movs r0, #2
	orrs r0, r1
	strb r0, [r2]
	b _080348C0
	.align 2, 0
_080348B0: .4byte 0x03001800
_080348B4: .4byte 0x00000115
_080348B8:
	ldr r0, _080348CC @ =0x00000115
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
_080348C0:
	bl sub_08034F08
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080348CC: .4byte 0x00000115
	.syntax divided
