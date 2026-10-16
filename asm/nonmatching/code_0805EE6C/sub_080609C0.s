	.syntax unified

	thumb_func_start sub_080609C0
sub_080609C0: @ 0x080609C0
	push {r4, r5, lr}
	bl update_battle_sprite_animation
	bl update_animation_timer
	ldr r0, _080609F8 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _08060A00
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r4, _080609FC @ =0x0000FFFF
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r5]
	lsls r1, r1, #2
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08060A76
	.align 2, 0
_080609F8: .4byte 0x03000440
_080609FC: .4byte 0x0000FFFF
_08060A00:
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldrh r2, [r1]
	ldr r0, _08060A34 @ =0x0000FDFF
	ands r0, r2
	strh r0, [r1]
	ldrh r2, [r1]
	ldr r0, _08060A38 @ =0x0000FEFF
	ands r0, r2
	strh r0, [r1]
	ldr r0, _08060A3C @ =0x02020800
	ldr r1, _08060A40 @ =0x06002800
	movs r2, #0x28
	bl CpuFastSet
	ldr r1, _08060A44 @ =0x03002B8C
	ldr r0, [r1]
	cmp r0, #0xa
	bne _08060A4C
	movs r0, #4
	str r0, [r1]
	ldr r1, _08060A48 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	b _08060A76
	.align 2, 0
_08060A34: .4byte 0x0000FDFF
_08060A38: .4byte 0x0000FEFF
_08060A3C: .4byte 0x02020800
_08060A40: .4byte 0x06002800
_08060A44: .4byte 0x03002B8C
_08060A48: .4byte 0x0300137C
_08060A4C:
	ldr r0, _08060A68 @ =0x03006F74
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x48
	ldrb r0, [r0]
	cmp r0, #0
	beq _08060A70
	ldr r1, _08060A6C @ =0x03006D38
	ldrb r0, [r2, #0x17]
	strb r0, [r1, #5]
	movs r0, #5
	bl dispatch_by_index_0476e8
	b _08060A76
	.align 2, 0
_08060A68: .4byte 0x03006F74
_08060A6C: .4byte 0x03006D38
_08060A70:
	movs r0, #6
	bl dispatch_by_index_0476e8
_08060A76:
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
