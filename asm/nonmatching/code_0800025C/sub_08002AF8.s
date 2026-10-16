	.syntax unified

	thumb_func_start sub_08002AF8
sub_08002AF8: @ 0x08002AF8
	push {r4, lr}
	sub sp, #0xc
	ldr r0, _08002C1C @ =0x03000440
	adds r4, r0, #0
	adds r4, #0x84
	ldrb r0, [r4]
	cmp r0, #0xc
	bhi _08002B2E
	ldr r2, _08002C20 @ =0x083B4AE0
	adds r1, r0, #0
	movs r0, #0x1f
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _08002C24 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #1
	bl write_tilemap_rect
_08002B2E:
	ldrb r0, [r4]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bhi _08002B60
	ldr r2, _08002C20 @ =0x083B4AE0
	ldrb r1, [r4]
	movs r0, #0x2e
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _08002C24 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #3
	bl write_tilemap_rect
_08002B60:
	ldrb r0, [r4]
	subs r0, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bhi _08002B92
	ldr r2, _08002C20 @ =0x083B4AE0
	ldrb r1, [r4]
	movs r0, #0x3d
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _08002C24 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #5
	bl write_tilemap_rect
_08002B92:
	ldrb r0, [r4]
	subs r0, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc
	bhi _08002BC4
	ldr r2, _08002C20 @ =0x083B4AE0
	ldrb r1, [r4]
	movs r0, #0x4c
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _08002C24 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #0xc
	movs r1, #2
	movs r2, #0x12
	movs r3, #7
	bl write_tilemap_rect
_08002BC4:
	ldrb r0, [r4]
	cmp r0, #0xa
	bne _08002BE6
	ldr r0, _08002C28 @ =0x08487814
	ldr r1, _08002C2C @ =0x06002400
	bl lz_decompress_dispatch
	ldr r2, _08002C30 @ =0x08488690
	ldr r0, _08002C24 @ =0x04000008
	ldrh r3, [r0]
	movs r0, #0x90
	lsls r0, r0, #1
	str r0, [sp]
	movs r0, #0x15
	movs r1, #9
	bl set_tilemap_and_decompress_bg
_08002BE6:
	ldrb r0, [r4]
	cmp r0, #0xc
	bne _08002C02
	ldr r0, _08002C24 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #9
	movs r1, #4
	movs r2, #0x15
	movs r3, #9
	bl vram_fill_tilemap_rect
_08002C02:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x12
	bls _08002C14
	bl sub_08044094
_08002C14:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08002C1C: .4byte 0x03000440
_08002C20: .4byte 0x083B4AE0
_08002C24: .4byte 0x04000008
_08002C28: .4byte 0x08487814
_08002C2C: .4byte 0x06002400
_08002C30: .4byte 0x08488690
	.syntax divided
