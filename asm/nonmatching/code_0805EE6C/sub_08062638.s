	.syntax unified

	thumb_func_start sub_08062638
sub_08062638: @ 0x08062638
	push {r4, r5, lr}
	ldr r0, _08062668 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _08062670
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r4, _0806266C @ =0x0000FFFF
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
	b _08062692
	.align 2, 0
_08062668: .4byte 0x03000440
_0806266C: .4byte 0x0000FFFF
_08062670:
	ldr r0, _08062698 @ =0x03006F74
	ldr r1, [r0]
	ldrb r0, [r1, #0x19]
	movs r3, #0x81
	lsls r3, r3, #0x12
	ldrb r1, [r1, #0x1a]
	ldr r2, _0806269C @ =0x02023078
	ldrb r2, [r2]
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, r1, r3
	ldrh r1, [r1]
	bl init_battle_scene
	ldr r1, _080626A0 @ =0x0300178C
	movs r0, #0
	str r0, [r1]
_08062692:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08062698: .4byte 0x03006F74
_0806269C: .4byte 0x02023078
_080626A0: .4byte 0x0300178C
	.syntax divided
