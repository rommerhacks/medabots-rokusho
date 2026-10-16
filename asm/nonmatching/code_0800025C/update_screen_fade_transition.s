	.syntax unified

	thumb_func_start update_screen_fade_transition
update_screen_fade_transition: @ 0x08003018
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r1, _080030E4 @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x8e
	ldrb r0, [r0]
	cmp r0, #2
	beq _08003060
	adds r5, r1, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #0x10
	bhi _08003060
	bl blend_effect_update
	ldrb r1, [r5]
	lsls r1, r1, #1
	movs r4, #0x20
	subs r1, r4, r1
	ldr r2, _080030E8 @ =0x00001FFF
	movs r0, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r0, [r5]
	lsls r0, r0, #1
	subs r4, r4, r0
	ldr r2, _080030EC @ =0x0000FFFF
	movs r0, #0
	adds r1, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_08003060:
	ldr r6, _080030E4 @ =0x03000440
	adds r7, r6, #0
	adds r7, #0x88
	ldrb r0, [r7]
	subs r0, #1
	movs r5, #0
	strb r0, [r7]
	ldrb r0, [r7]
	movs r2, #0x12
	subs r2, r2, r0
	ldr r3, _080030F0 @ =0x083B4AE0
	movs r0, #0x8e
	adds r0, r0, r6
	mov r8, r0
	ldrb r1, [r0]
	movs r0, #0xd
	muls r0, r1, r0
	adds r0, #0x1f
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [sp]
	ldr r4, _080030F4 @ =0x04000008
	ldrh r0, [r4]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r3, #0
	bl write_tilemap_rect
	ldrb r0, [r7]
	movs r2, #0x11
	subs r2, r2, r0
	ldrh r0, [r4]
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #1
	movs r1, #2
	movs r3, #0
	bl vram_fill_tilemap_rect
	ldrb r2, [r7]
	cmp r2, #0
	bne _080030D8
	ldr r1, _080030F8 @ =0x030017F0
	ldr r0, _080030FC @ =0x08000841
	str r0, [r1]
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #1
	adds r0, #1
	strb r0, [r7]
	adds r0, r6, #0
	adds r0, #0x84
	strb r2, [r0]
	ldr r1, _08003100 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080030D8:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080030E4: .4byte 0x03000440
_080030E8: .4byte 0x00001FFF
_080030EC: .4byte 0x0000FFFF
_080030F0: .4byte 0x083B4AE0
_080030F4: .4byte 0x04000008
_080030F8: .4byte 0x030017F0
_080030FC: .4byte 0x08000841
_08003100: .4byte 0x0300137C
	.syntax divided
