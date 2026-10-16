	.syntax unified

	thumb_func_start sub_08016DCC
	.global sub_08016DCC
sub_08016DCC: @ 0x08016DCC
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r5, _08016E20 @ =0x03001800
	adds r0, r5, #0
	adds r0, #0x82
	ldrb r0, [r0]
	cmp r0, #1
	bne _08016E38
	ldr r4, _08016E24 @ =0x04000008
	ldrh r0, [r4]
	str r0, [sp]
	ldr r0, _08016E28 @ =0x0000D218
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #1
	movs r2, #0xe
	movs r3, #0xc
	bl fill_tilemap_rect_08042698
	ldr r2, _08016E2C @ =0x03000590
	adds r0, r5, #0
	adds r0, #0x80
	ldrb r1, [r0]
	lsls r1, r1, #8
	adds r1, r1, r2
	adds r0, r1, #0
	adds r0, #0x58
	ldrb r0, [r0]
	adds r1, #0x50
	ldrb r1, [r1]
	ldr r2, _08016E30 @ =0x0000D21A
	str r2, [sp]
	ldrh r2, [r4]
	str r2, [sp, #4]
	ldr r2, _08016E34 @ =0x0000D220
	str r2, [sp, #8]
	movs r2, #0x10
	movs r3, #0xc
	bl sub_08042A90
	b _08016E4E
	.align 2, 0
_08016E20: .4byte 0x03001800
_08016E24: .4byte 0x04000008
_08016E28: .4byte 0x0000D218
_08016E2C: .4byte 0x03000590
_08016E30: .4byte 0x0000D21A
_08016E34: .4byte 0x0000D220
_08016E38:
	ldr r0, _08016E58 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #7
	movs r1, #1
	movs r2, #0xe
	movs r3, #0xc
	bl vram_fill_tilemap_rect
_08016E4E:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08016E58: .4byte 0x04000008
	.syntax divided
