	.syntax unified

	thumb_func_start battle_setup_bot_font_tile
	.global battle_setup_bot_font_tile
battle_setup_bot_font_tile: @ 0x08017EA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r6, #0
	ldr r4, _08017F48 @ =0x03000440
	movs r0, #0x3d
	adds r0, r0, r4
	mov sl, r0
	movs r1, #0xee
	adds r1, r1, r4
	mov sb, r1
	movs r5, #4
	movs r7, #0
	movs r2, #0x3c
	adds r2, r2, r4
	mov r8, r2
_08017ECE:
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	mov r1, sl
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #8
	adds r0, r7, r0
	ldr r2, _08017F4C @ =0x03000590
	adds r0, r0, r2
	adds r0, #0x5f
	ldrb r0, [r0]
	adds r1, r6, #0
	mov r2, sb
	bl load_part_data
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	mov r1, sl
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #8
	ldr r2, _08017F4C @ =0x03000590
	adds r0, r0, r2
	ldrb r0, [r0, #1]
	lsls r0, r0, #4
	ldr r1, _08017F50 @ =0x083B6158
	adds r0, r0, r1
	movs r2, #0x87
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0x10
	bl memcpy_bytes_08041D04
	ldr r0, _08017F54 @ =0x0000010F
	adds r1, r4, r0
	mov r2, sb
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08017F64
	ldr r0, _08017F58 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r1, _08017F5C @ =0x03000555
	ldrb r0, [r1]
	lsls r0, r0, #0x12
	ldr r2, _08017F60 @ =0xD3400000
	adds r0, r0, r2
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xb
	adds r3, r5, #0
	bl fill_tilemap_rect_08042698
	b _08017F7A
	.align 2, 0
_08017F48: .4byte 0x03000440
_08017F4C: .4byte 0x03000590
_08017F50: .4byte 0x083B6158
_08017F54: .4byte 0x0000010F
_08017F58: .4byte 0x0400000A
_08017F5C: .4byte 0x03000555
_08017F60: .4byte 0xD3400000
_08017F64:
	ldr r0, _08017F94 @ =0x0400000A
	ldrh r0, [r0]
	str r0, [sp]
	ldr r0, _08017F98 @ =0x0000D340
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #2
	movs r2, #0xb
	adds r3, r5, #0
	bl fill_tilemap_rect_08042698
_08017F7A:
	adds r5, #2
	adds r7, #0x18
	adds r6, #1
	cmp r6, #3
	bls _08017ECE
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08017F94: .4byte 0x0400000A
_08017F98: .4byte 0x0000D340
	.syntax divided
