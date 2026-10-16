	.syntax unified

	thumb_func_start sub_08063284
sub_08063284: @ 0x08063284
	push {r4, lr}
	ldr r0, _080632A8 @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x84
	ldrb r0, [r4]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #0x40
	bhi _080632B0
	ldr r0, _080632AC @ =0x00007FFF
	lsrs r1, r1, #0x19
	movs r2, #0xff
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _080632C4
	.align 2, 0
_080632A8: .4byte 0x03000440
_080632AC: .4byte 0x00007FFF
_080632B0:
	ldr r0, _080632F4 @ =0x03006F74
	ldr r1, [r0]
	movs r2, #0
	movs r0, #0
	strh r0, [r1, #0x3c]
	strb r2, [r4]
	ldr r1, _080632F8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080632C4:
	ldr r4, _080632F4 @ =0x03006F74
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
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080632F4: .4byte 0x03006F74
_080632F8: .4byte 0x0300137C
	.syntax divided
