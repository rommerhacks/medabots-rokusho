	.syntax unified

	thumb_func_start sub_08034074
sub_08034074: @ 0x08034074
	push {r4, lr}
	bl init_battle_scene_backgrounds
	bl battle_advance_dialogue_text
	bl battle_advance_action_text
	movs r0, #0
	movs r1, #0x28
	bl clear_battle_sprite_slot
	ldr r0, _080340E4 @ =0x084E30B8
	ldr r1, _080340E8 @ =0x05000380
	movs r2, #8
	bl CpuFastSet
	ldr r3, _080340EC @ =0x03001800
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r3, r0
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	adds r0, r3, #0
	adds r0, #0xfb
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r4, _080340F0 @ =0x03000590
	subs r0, #0x77
	ldrb r0, [r0]
	lsls r2, r0, #8
	adds r1, r2, r4
	adds r0, r1, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080340F4
	adds r0, r3, #0
	adds r0, #0xa7
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	adds r0, r0, r4
	adds r0, #0x49
	ldrb r1, [r0]
	adds r0, r3, #0
	adds r0, #0xf9
	strb r1, [r0]
	b _08034102
	.align 2, 0
_080340E4: .4byte 0x084E30B8
_080340E8: .4byte 0x05000380
_080340EC: .4byte 0x03001800
_080340F0: .4byte 0x03000590
_080340F4:
	adds r0, r1, #0
	adds r0, #0xa8
	ldrb r0, [r0]
	adds r0, #0x50
	adds r1, r3, #0
	adds r1, #0xf9
	strb r0, [r1]
_08034102:
	ldr r0, _0803411C @ =0x03002C30
	adds r2, r0, #0
	adds r2, #0x69
	movs r1, #1
	strb r1, [r2]
	adds r0, #0xa9
	strb r1, [r0]
	bl sub_08034F08
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803411C: .4byte 0x03002C30
	.syntax divided
