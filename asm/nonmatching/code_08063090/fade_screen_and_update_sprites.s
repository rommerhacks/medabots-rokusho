	.syntax unified

	thumb_func_start fade_screen_and_update_sprites
fade_screen_and_update_sprites: @ 0x08063584
	push {r4, r5, lr}
	ldr r0, _080635AC @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	lsls r2, r0, #0x18
	lsrs r0, r2, #0x18
	cmp r0, #0x40
	bhi _080635B4
	ldr r0, _080635B0 @ =0x00007FFF
	lsrs r2, r2, #0x19
	movs r1, #0x20
	subs r1, r1, r2
	movs r2, #0xff
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _080635E0
	.align 2, 0
_080635AC: .4byte 0x03000440
_080635B0: .4byte 0x00007FFF
_080635B4:
	ldr r4, _08063610 @ =0x080AFA4C
	ldr r1, _08063614 @ =0x05000300
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08063618 @ =0x0202F900
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	movs r0, #0
	strb r0, [r5]
	ldr r1, _0806361C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, _08063620 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0xa0
	lsls r0, r0, #2
	strh r0, [r1, #0x3a]
_080635E0:
	ldr r4, _08063620 @ =0x03006F74
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	adds r1, #0x33
	ldrb r1, [r1]
	movs r2, #0
	bl load_medapart_sprite_animation
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	adds r1, #0x34
	ldrb r1, [r1]
	movs r2, #1
	bl load_medapart_sprite_animation
	bl update_animated_tilemap
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08063610: .4byte 0x080AFA4C
_08063614: .4byte 0x05000300
_08063618: .4byte 0x0202F900
_0806361C: .4byte 0x0300137C
_08063620: .4byte 0x03006F74
	.syntax divided
