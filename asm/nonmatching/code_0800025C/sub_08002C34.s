	.syntax unified

	thumb_func_start sub_08002C34
sub_08002C34: @ 0x08002C34
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r6, _08002C50 @ =0x03000440
	adds r0, r6, #0
	adds r0, #0x8e
	ldrb r1, [r0]
	cmp r1, #1
	beq _08002C7C
	cmp r1, #1
	bgt _08002C54
	cmp r1, #0
	beq _08002C5A
	b _08002CEC
	.align 2, 0
_08002C50: .4byte 0x03000440
_08002C54:
	cmp r1, #2
	beq _08002CB4
	b _08002CEC
_08002C5A:
	ldr r0, _08002C78 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #0xd
	movs r1, #0xa
	movs r2, #0x11
	movs r3, #3
	bl vram_fill_tilemap_rect
	adds r1, r6, #0
	adds r1, #0x88
	movs r0, #1
	strb r0, [r1]
	b _08002D1C
	.align 2, 0
_08002C78: .4byte 0x04000008
_08002C7C:
	ldr r5, _08002CB0 @ =0x04000008
	ldrh r0, [r5]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #0xd
	movs r1, #2
	movs r2, #0x11
	movs r3, #1
	bl vram_fill_tilemap_rect
	ldrh r0, [r5]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0xd
	movs r1, #8
	movs r2, #0x11
	movs r3, #5
	bl vram_fill_tilemap_rect
	adds r1, r6, #0
	adds r1, #0x88
	movs r0, #3
	strb r0, [r1]
	b _08002D1C
	.align 2, 0
_08002CB0: .4byte 0x04000008
_08002CB4:
	ldr r5, _08002CE8 @ =0x04000008
	ldrh r0, [r5]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #0xd
	movs r1, #4
	movs r2, #0x11
	movs r3, #1
	bl vram_fill_tilemap_rect
	ldrh r0, [r5]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0xd
	movs r1, #6
	movs r2, #0x11
	movs r3, #7
	bl vram_fill_tilemap_rect
	adds r1, r6, #0
	adds r1, #0x88
	movs r0, #5
	strb r0, [r1]
	b _08002D1C
	.align 2, 0
_08002CE8: .4byte 0x04000008
_08002CEC:
	ldr r5, _08002D3C @ =0x04000008
	ldrh r0, [r5]
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r0, #0xd
	movs r1, #6
	movs r2, #0x11
	movs r3, #1
	bl vram_fill_tilemap_rect
	ldrh r0, [r5]
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0xd
	movs r1, #4
	movs r2, #0x11
	movs r3, #9
	bl vram_fill_tilemap_rect
	ldr r0, _08002D40 @ =0x03000440
	adds r0, #0x88
	movs r1, #7
	strb r1, [r0]
_08002D1C:
	movs r0, #0
	movs r1, #1
	bl clear_battle_sprite_slot
	movs r0, #0xa
	movs r1, #7
	bl clear_battle_sprite_slot
	ldr r1, _08002D44 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08002D3C: .4byte 0x04000008
_08002D40: .4byte 0x03000440
_08002D44: .4byte 0x0300137C
	.syntax divided
