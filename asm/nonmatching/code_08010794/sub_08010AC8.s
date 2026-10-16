	.syntax unified

	thumb_func_start sub_08010AC8
sub_08010AC8: @ 0x08010AC8
	push {r4, r5, r6, lr}
	ldr r0, _08010B04 @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x84
	ldrb r0, [r6]
	cmp r0, #0x10
	bhi _08010B0C
	bl blend_effect_update
	ldrb r1, [r6]
	lsls r1, r1, #1
	movs r4, #0x20
	subs r1, r4, r1
	ldr r5, _08010B08 @ =0x0000FFFF
	movs r0, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r6]
	lsls r0, r0, #1
	subs r4, r4, r0
	movs r0, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	b _08010B16
	.align 2, 0
_08010B04: .4byte 0x03000440
_08010B08: .4byte 0x0000FFFF
_08010B0C:
	ldr r1, _08010B1C @ =0x030017F0
	ldr r0, _08010B20 @ =0x08000841
	str r0, [r1]
	bl sub_08044094
_08010B16:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010B1C: .4byte 0x030017F0
_08010B20: .4byte 0x08000841
	.syntax divided
