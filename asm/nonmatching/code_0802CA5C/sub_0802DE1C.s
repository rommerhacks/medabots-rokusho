	.syntax unified

	thumb_func_start sub_0802DE1C
sub_0802DE1C: @ 0x0802DE1C
	push {r4, r5, r6, lr}
	ldr r1, _0802DE4C @ =0x03000440
	adds r3, r1, #0
	adds r3, #0x86
	ldrh r2, [r3]
	movs r0, #0x1f
	ands r0, r2
	cmp r0, #0
	bne _0802DE5C
	ldr r0, _0802DE50 @ =0x03002C30
	ldr r4, _0802DE54 @ =0x00000863
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #7
	bhi _0802DE5C
	ldr r0, _0802DE58 @ =0x03001800
	adds r0, #0xaa
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	adds r0, r2, #1
	strh r0, [r3]
	b _0802DF0E
	.align 2, 0
_0802DE4C: .4byte 0x03000440
_0802DE50: .4byte 0x03002C30
_0802DE54: .4byte 0x00000863
_0802DE58: .4byte 0x03001800
_0802DE5C:
	adds r1, #0x86
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _0802DE94 @ =0x083B5F80
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	movs r0, #0x21
	bl update_sprite_animation_position
	ldr r3, _0802DE98 @ =0x03002C30
	ldr r4, _0802DE9C @ =0x00000864
	adds r1, r3, r4
	movs r0, #4
	strb r0, [r1]
	ldr r0, _0802DEA0 @ =0x00000868
	adds r5, r3, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0802DEA4
	subs r0, #1
	strb r0, [r5]
	b _0802DF0E
	.align 2, 0
_0802DE94: .4byte 0x083B5F80
_0802DE98: .4byte 0x03002C30
_0802DE9C: .4byte 0x00000864
_0802DEA0: .4byte 0x00000868
_0802DEA4:
	ldr r6, _0802DED4 @ =0x083AE988
	ldr r1, _0802DED8 @ =0x00000863
	adds r4, r3, r1
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r2, [r0]
	ldr r0, _0802DEDC @ =0x00000865
	adds r3, r3, r0
	strb r2, [r3]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _0802DEE4
	movs r0, #0x21
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r0, _0802DEE0 @ =0x03001800
	adds r0, #0xaa
	movs r1, #0xa
	strb r1, [r0]
	b _0802DF0E
	.align 2, 0
_0802DED4: .4byte 0x083AE988
_0802DED8: .4byte 0x00000863
_0802DEDC: .4byte 0x00000865
_0802DEE0: .4byte 0x03001800
_0802DEE4:
	ldr r0, _0802DF14 @ =0x03001800
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802DEFC
	movs r0, #0x20
	subs r0, r0, r2
	movs r1, #0x1f
	ands r0, r1
	strb r0, [r3]
_0802DEFC:
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	strb r0, [r5]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0802DF0E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802DF14: .4byte 0x03001800
	.syntax divided
