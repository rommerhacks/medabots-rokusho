	.syntax unified

	thumb_func_start sub_08007868
sub_08007868: @ 0x08007868
	push {r4, r5, lr}
	bl sub_080093F8
	bl sub_0800994C
	ldr r0, _080078C0 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #0x18
	bl sub_08041C14
	bl update_battle_sprite_visibility
	bl sub_080099A4
	bl sub_08009A38
	bl sub_08009BC8
	ldr r0, _080078C4 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _080078E0
	ldr r0, _080078C8 @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x3e
	ldrb r1, [r4]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080078CC
	movs r0, #2
	bl play_sound_effect
	movs r0, #0
	strb r0, [r4]
	bl update_battle_sprite_visibility
	b _0800795E
	.align 2, 0
_080078C0: .4byte 0x03001780
_080078C4: .4byte 0x0300058C
_080078C8: .4byte 0x03000440
_080078CC:
	movs r0, #5
	bl play_sound_effect
	ldr r1, _080078DC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0800795E
	.align 2, 0
_080078DC: .4byte 0x0300137C
_080078E0:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800795E
	ldr r4, _08007930 @ =0x03000440
	adds r0, r4, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x40
	lsls r0, r0, #1
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r2, r4, #0
	adds r2, #0x3d
	strb r0, [r2]
	ldr r1, _08007934 @ =0x03000BE0
	ldrb r0, [r2]
	lsls r0, r0, #6
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08007958
	movs r0, #4
	bl play_sound_effect
	adds r0, r4, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #4
	bne _0800793C
	ldr r1, _08007938 @ =0x0300137C
	movs r0, #0x60
	str r0, [r1]
	b _0800795E
	.align 2, 0
_08007930: .4byte 0x03000440
_08007934: .4byte 0x03000BE0
_08007938: .4byte 0x0300137C
_0800793C:
	adds r0, r4, #0
	adds r0, #0x42
	strb r5, [r0]
	movs r0, #6
	movs r1, #0x3f
	movs r2, #0x20
	bl set_blend_effect_mode
	ldr r1, _08007954 @ =0x0300137C
	movs r0, #7
	str r0, [r1]
	b _0800795E
	.align 2, 0
_08007954: .4byte 0x0300137C
_08007958:
	movs r0, #6
	bl play_sound_effect
_0800795E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
