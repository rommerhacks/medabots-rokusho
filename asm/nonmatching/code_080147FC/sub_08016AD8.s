	.syntax unified

	thumb_func_start sub_08016AD8
	.global sub_08016AD8
sub_08016AD8: @ 0x08016AD8
	push {r4, r5, lr}
	sub sp, #0x10
	movs r0, #0x2d
	movs r1, #0xd
	bl clear_sprite_table_mask
	ldr r3, _08016AFC @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x82
	ldrb r2, [r0]
	cmp r2, #0
	bne _08016B04
	ldr r0, _08016B00 @ =0x030004DE
	movs r1, #0xd
	bl sub_08042678
	b _08016BDE
	.align 2, 0
_08016AFC: .4byte 0x03001800
_08016B00: .4byte 0x030004DE
_08016B04:
	cmp r2, #0
	blt _08016BDE
	cmp r2, #3
	bgt _08016BDE
	ldr r4, _08016B30 @ =0x03000590
	subs r1, r2, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r3, #0
	adds r1, #0x80
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r4
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	bne _08016B38
	ldr r0, _08016B34 @ =0x083C4A10
	ldr r0, [r0]
	b _08016B9A
	.align 2, 0
_08016B30: .4byte 0x03000590
_08016B34: .4byte 0x083C4A10
_08016B38:
	adds r1, r1, r4
	adds r0, r1, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0x2b
	bne _08016B58
	adds r0, r1, #0
	adds r0, #0xca
	ldrb r0, [r0]
	cmp r2, r0
	bne _08016B58
	ldr r0, _08016B54 @ =0x083C4A10
	ldr r0, [r0, #4]
	b _08016B9A
	.align 2, 0
_08016B54: .4byte 0x083C4A10
_08016B58:
	ldr r1, _08016B78 @ =0x03001800
	adds r5, r1, #0
	adds r5, #0x80
	ldrb r0, [r5]
	adds r4, r1, #0
	adds r4, #0x82
	ldrb r1, [r4]
	subs r1, #1
	bl sub_08016E5C
	cmp r0, #0
	beq _08016B80
	ldr r0, _08016B7C @ =0x083C4A10
	ldr r0, [r0, #4]
	b _08016B9A
	.align 2, 0
_08016B78: .4byte 0x03001800
_08016B7C: .4byte 0x083C4A10
_08016B80:
	ldrb r0, [r4]
	ldr r4, _08016BA4 @ =0x03000590
	cmp r0, #1
	bne _08016BB0
	ldrb r0, [r5]
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r0, #0x58
	ldrb r0, [r0]
	cmp r0, #0
	bne _08016BB0
	ldr r0, _08016BA8 @ =0x083C4A10
	ldr r0, [r0, #8]
_08016B9A:
	ldr r1, _08016BAC @ =0x030004DE
	movs r2, #0xe
	bl memcpy_bytes_08041D04
	b _08016BDE
	.align 2, 0
_08016BA4: .4byte 0x03000590
_08016BA8: .4byte 0x083C4A10
_08016BAC: .4byte 0x030004DE
_08016BB0:
	ldr r3, _08016C00 @ =0x083B6EC8
	ldr r2, _08016C04 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x82
	ldrb r1, [r0]
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, #0x80
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r4
	adds r0, #0x4a
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r1, _08016C08 @ =0x030004DE
	movs r2, #0xe
	bl memcpy_bytes_08041D04
_08016BDE:
	ldr r0, _08016C08 @ =0x030004DE
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xe
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #0x2d
	movs r2, #0x13
	movs r3, #0xe
	bl render_text_sprites_08040DB8
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08016C00: .4byte 0x083B6EC8
_08016C04: .4byte 0x03001800
_08016C08: .4byte 0x030004DE
	.syntax divided
