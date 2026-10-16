	.syntax unified

	thumb_func_start render_shop_menu_screen
render_shop_menu_screen: @ 0x08003104
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	ldr r5, _08003180 @ =0x03000440
	movs r0, #0x84
	adds r0, r0, r5
	mov r8, r0
	ldrb r3, [r0]
	adds r3, #1
	ldr r4, _08003184 @ =0x083B4AE0
	movs r1, #0x8e
	adds r1, r1, r5
	mov sb, r1
	ldrb r1, [r1]
	movs r0, #0xd
	muls r0, r1, r0
	adds r0, #0x1f
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	str r0, [sp]
	ldr r6, _08003188 @ =0x04000008
	ldrh r0, [r6]
	str r0, [sp, #4]
	movs r7, #0
	str r7, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	bl write_tilemap_rect
	mov r0, r8
	ldrb r3, [r0]
	ldrh r0, [r6]
	str r0, [sp]
	str r7, [sp, #4]
	movs r0, #0xc
	movs r1, #1
	movs r2, #0x12
	bl vram_fill_tilemap_rect
	mov r1, r8
	ldrb r0, [r1]
	adds r1, r0, #1
	adds r0, r5, #0
	adds r0, #0x88
	ldrb r0, [r0]
	cmp r1, r0
	beq _0800316C
	b _080032EC
_0800316C:
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #1
	beq _080031C4
	cmp r0, #1
	bgt _0800318C
	cmp r0, #0
	beq _08003192
	b _08003240
	.align 2, 0
_08003180: .4byte 0x03000440
_08003184: .4byte 0x083B4AE0
_08003188: .4byte 0x04000008
_0800318C:
	cmp r0, #2
	beq _080031F2
	b _08003240
_08003192:
	adds r0, r4, #0
	adds r0, #0xb0
	ldr r0, [r0]
	str r0, [sp]
	ldrh r0, [r6]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #3
	bl write_tilemap_rect
	adds r0, r4, #0
	adds r0, #0xe4
	ldr r0, [r0]
	str r0, [sp]
	ldrh r0, [r6]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #5
	b _0800321E
_080031C4:
	ldr r0, [r4, #0x7c]
	str r0, [sp]
	ldrh r0, [r6]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #1
	bl write_tilemap_rect
	adds r0, r4, #0
	adds r0, #0xe4
	ldr r0, [r0]
	str r0, [sp]
	ldrh r0, [r6]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #5
	b _0800321E
_080031F2:
	ldr r0, [r4, #0x7c]
	str r0, [sp]
	ldrh r0, [r6]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #1
	bl write_tilemap_rect
	adds r0, r4, #0
	adds r0, #0xb0
	ldr r0, [r0]
	str r0, [sp]
	ldrh r0, [r6]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #3
_0800321E:
	bl write_tilemap_rect
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	str r0, [sp]
	ldrh r0, [r6]
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #7
	bl write_tilemap_rect
	b _0800328E
_08003240:
	ldr r4, _080032D4 @ =0x083B4AE0
	ldr r0, [r4, #0x7c]
	str r0, [sp]
	ldr r6, _080032D8 @ =0x04000008
	ldrh r0, [r6]
	str r0, [sp, #4]
	movs r5, #0
	str r5, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #1
	bl write_tilemap_rect
	adds r0, r4, #0
	adds r0, #0xb0
	ldr r0, [r0]
	str r0, [sp]
	ldrh r0, [r6]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #3
	bl write_tilemap_rect
	adds r4, #0xe4
	ldr r0, [r4]
	str r0, [sp]
	ldrh r0, [r6]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #5
	bl write_tilemap_rect
_0800328E:
	ldr r2, _080032DC @ =0x08488644
	ldr r0, _080032D8 @ =0x04000008
	ldrh r3, [r0]
	movs r0, #0x90
	lsls r0, r0, #1
	str r0, [sp]
	movs r0, #0x15
	movs r1, #9
	bl set_tilemap_and_decompress_bg
	ldr r5, _080032E0 @ =0x030004DE
	ldr r0, _080032E4 @ =0x03002B70
	ldr r1, [r0]
	adds r0, r5, #0
	bl divide_by_10000
	movs r0, #5
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x17
	movs r3, #0xa
	bl render_text_sprites_08040DB8
	bl sub_08003300
	ldr r0, _080032E8 @ =0x0300137C
	str r4, [r0]
	b _080032F0
	.align 2, 0
_080032D4: .4byte 0x083B4AE0
_080032D8: .4byte 0x04000008
_080032DC: .4byte 0x08488644
_080032E0: .4byte 0x030004DE
_080032E4: .4byte 0x03002B70
_080032E8: .4byte 0x0300137C
_080032EC:
	mov r0, r8
	strb r1, [r0]
_080032F0:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
