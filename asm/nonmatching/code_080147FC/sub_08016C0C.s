	.syntax unified

	thumb_func_start sub_08016C0C
	.global sub_08016C0C
sub_08016C0C: @ 0x08016C0C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	movs r6, #0
	ldr r0, _08016C4C @ =0x03001800
	adds r1, r0, #0
	adds r1, #0x82
	ldrb r2, [r1]
	adds r3, r0, #0
	cmp r2, #0
	beq _08016CC0
	cmp r2, #0
	blt _08016CC0
	cmp r2, #3
	bgt _08016CC0
	ldr r4, _08016C50 @ =0x03000590
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
	bne _08016C58
	ldr r0, _08016C54 @ =0x083C4A10
	ldr r0, [r0]
	b _08016C88
	.align 2, 0
_08016C4C: .4byte 0x03001800
_08016C50: .4byte 0x03000590
_08016C54: .4byte 0x083C4A10
_08016C58:
	adds r1, r1, r4
	adds r0, r1, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0x2b
	bne _08016C6E
	adds r0, r1, #0
	adds r0, #0xca
	ldrb r0, [r0]
	cmp r2, r0
	beq _08016C84
_08016C6E:
	adds r5, r3, #0
	adds r5, #0x80
	ldrb r0, [r5]
	adds r4, r3, #0
	adds r4, #0x82
	ldrb r1, [r4]
	subs r1, #1
	bl sub_08016E5C
	cmp r0, #0
	beq _08016C9C
_08016C84:
	ldr r0, _08016C94 @ =0x083C4A10
	ldr r0, [r0, #4]
_08016C88:
	ldr r1, _08016C98 @ =0x030004DE
	movs r2, #0xe
	bl memcpy_bytes_08041D04
	b _08016CC4
	.align 2, 0
_08016C94: .4byte 0x083C4A10
_08016C98: .4byte 0x030004DE
_08016C9C:
	ldrb r0, [r4]
	cmp r0, #1
	bne _08016CC0
	ldr r0, _08016CE4 @ =0x03000590
	ldrb r1, [r5]
	lsls r1, r1, #8
	adds r1, r1, r0
	adds r1, #0x58
	ldrb r0, [r1]
	cmp r0, #0
	bne _08016CC0
	ldr r0, _08016CE8 @ =0x083C4A10
	ldr r0, [r0, #8]
	ldr r1, _08016CEC @ =0x030004DE
	movs r2, #0xe
	bl memcpy_bytes_08041D04
	movs r6, #1
_08016CC0:
	cmp r6, #0
	beq _08016D0E
_08016CC4:
	ldr r3, _08016CF0 @ =0x03000440
	adds r0, r3, #0
	adds r0, #0x84
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08016CF4
	movs r0, #0x2d
	movs r1, #0xd
	bl clear_sprite_table_mask
	b _08016D0E
	.align 2, 0
_08016CE4: .4byte 0x03000590
_08016CE8: .4byte 0x083C4A10
_08016CEC: .4byte 0x030004DE
_08016CF0: .4byte 0x03000440
_08016CF4:
	adds r0, r3, #0
	adds r0, #0x9e
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xe
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	movs r1, #0x2d
	movs r2, #0x13
	movs r3, #0xe
	bl render_text_sprites_08040DB8
_08016D0E:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
