	.syntax unified

	thumb_func_start fade_out_transition_step
fade_out_transition_step: @ 0x08062808
	push {r4, r5, r6, lr}
	ldr r0, _08062840 @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x84
	ldrb r0, [r6]
	cmp r0, #8
	bhi _08062848
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r5, _08062844 @ =0x0000FFFF
	movs r0, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r6]
	lsls r0, r0, #2
	subs r4, r4, r0
	movs r0, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _08062860
	.align 2, 0
_08062840: .4byte 0x03000440
_08062844: .4byte 0x0000FFFF
_08062848:
	bl update_battle_sprite_priority_flags
	ldr r0, _08062868 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #2]
	ldr r1, _0806286C @ =0x03002B8C
	movs r0, #0xc
	str r0, [r1]
	ldr r1, _08062870 @ =0x0300137C
	movs r0, #4
	str r0, [r1]
_08062860:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08062868: .4byte 0x03006F74
_0806286C: .4byte 0x03002B8C
_08062870: .4byte 0x0300137C
	.syntax divided
