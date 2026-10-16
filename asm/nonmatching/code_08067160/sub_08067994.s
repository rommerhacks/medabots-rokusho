	.syntax unified

	thumb_func_start sub_08067994
sub_08067994: @ 0x08067994
	push {r4, r5, lr}
	bl update_scene_animation_frame
	ldr r5, _080679E0 @ =0x03006F74
	ldr r1, [r5]
	movs r2, #0x3e
	ldrsh r0, [r1, r2]
	cmp r0, #0xc0
	bgt _080679E8
	movs r1, #6
	bl sub_0807CBBC
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r4, _080679E4 @ =0x0000FFFF
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldr r0, [r5]
	movs r1, #0x3e
	ldrsh r0, [r0, r1]
	movs r1, #6
	bl sub_0807CBBC
	adds r1, r0, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldr r1, [r5]
	ldrh r0, [r1, #0x3e]
	adds r0, #1
	strh r0, [r1, #0x3e]
	b _080679FC
	.align 2, 0
_080679E0: .4byte 0x03006F74
_080679E4: .4byte 0x0000FFFF
_080679E8:
	bl sub_08074FB8
	adds r1, r0, #0
	cmp r1, #0
	bne _080679FC
	ldr r0, _08067A04 @ =0x0300137C
	str r1, [r0]
	movs r0, #0xc
	bl dispatch_by_index_0476e8
_080679FC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08067A04: .4byte 0x0300137C
	.syntax divided
