	.syntax unified

	thumb_func_start sub_080028AC
sub_080028AC: @ 0x080028AC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r6, _08002A04 @ =0x03000440
	adds r4, r6, #0
	adds r4, #0x84
	ldrb r0, [r4]
	cmp r0, #0xc
	bhi _080028DE
	ldr r1, _08002A08 @ =0x083B4AE0
	adds r0, #0x13
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _08002A0C @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #1
	bl write_tilemap_rect
_080028DE:
	ldrb r0, [r4]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bhi _0800290E
	ldr r1, _08002A08 @ =0x083B4AE0
	ldrb r0, [r4]
	adds r0, #0x1e
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _08002A0C @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #3
	bl write_tilemap_rect
_0800290E:
	ldrb r0, [r4]
	subs r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bhi _0800293E
	ldr r1, _08002A08 @ =0x083B4AE0
	ldrb r0, [r4]
	adds r0, #0x29
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _08002A0C @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #5
	bl write_tilemap_rect
_0800293E:
	ldrb r0, [r4]
	subs r0, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bhi _0800296E
	ldr r1, _08002A08 @ =0x083B4AE0
	ldrb r0, [r4]
	adds r0, #0x34
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _08002A0C @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #7
	bl write_tilemap_rect
_0800296E:
	ldrb r0, [r4]
	cmp r0, #0xa
	bne _08002990
	ldr r0, _08002A10 @ =0x08487814
	ldr r1, _08002A14 @ =0x06002400
	bl lz_decompress_dispatch
	ldr r2, _08002A18 @ =0x08488690
	ldr r0, _08002A0C @ =0x04000008
	ldrh r3, [r0]
	movs r0, #0x90
	lsls r0, r0, #1
	str r0, [sp]
	movs r0, #0x15
	movs r1, #9
	bl set_tilemap_and_decompress_bg
_08002990:
	ldrb r0, [r4]
	cmp r0, #0xc
	bne _080029B2
	ldr r0, _08002A1C @ =0x08487708
	ldr r1, _08002A14 @ =0x06002400
	bl lz_decompress_dispatch
	ldr r2, _08002A20 @ =0x08488644
	ldr r0, _08002A0C @ =0x04000008
	ldrh r3, [r0]
	movs r0, #0x90
	lsls r0, r0, #1
	str r0, [sp]
	movs r0, #0x15
	movs r1, #9
	bl set_tilemap_and_decompress_bg
_080029B2:
	ldrb r0, [r4]
	adds r0, #1
	movs r5, #0
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x12
	bls _080029FC
	adds r4, r6, #0
	adds r4, #0x9e
	ldr r0, _08002A24 @ =0x03002B70
	ldr r1, [r0]
	adds r0, r4, #0
	bl divide_by_10000
	movs r0, #5
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0x17
	movs r3, #0xa
	bl render_text_sprites_08040DB8
	adds r0, r6, #0
	adds r0, #0x8e
	strb r5, [r0]
	bl sub_08003300
	ldr r1, _08002A28 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080029FC:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08002A04: .4byte 0x03000440
_08002A08: .4byte 0x083B4AE0
_08002A0C: .4byte 0x04000008
_08002A10: .4byte 0x08487814
_08002A14: .4byte 0x06002400
_08002A18: .4byte 0x08488690
_08002A1C: .4byte 0x08487708
_08002A20: .4byte 0x08488644
_08002A24: .4byte 0x03002B70
_08002A28: .4byte 0x0300137C
	.syntax divided
