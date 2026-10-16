	.syntax unified

	thumb_func_start sub_08061D30
sub_08061D30: @ 0x08061D30
	push {r4, r5, lr}
	ldr r0, _08061D68 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _08061D74
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r4, #0x20
	subs r1, r4, r1
	ldr r2, _08061D6C @ =0x0000FFFE
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r5]
	lsls r0, r0, #2
	subs r4, r4, r0
	ldr r2, _08061D70 @ =0x00007FFD
	movs r0, #0
	adds r1, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _08061D88
	.align 2, 0
_08061D68: .4byte 0x03000440
_08061D6C: .4byte 0x0000FFFE
_08061D70: .4byte 0x00007FFD
_08061D74:
	bl update_battle_sprite_priority_flags
	ldr r0, _08061D90 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #2]
	ldr r1, _08061D94 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08061D88:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08061D90: .4byte 0x03006F74
_08061D94: .4byte 0x0300137C
	.syntax divided
