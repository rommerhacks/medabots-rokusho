	.syntax unified

	thumb_func_start sub_08016D18
	.global sub_08016D18
sub_08016D18: @ 0x08016D18
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0x14
	movs r1, #0xb
	bl clear_sprite_table_mask
	ldr r4, _08016D3C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x82
	ldrb r1, [r0]
	cmp r1, #0
	bne _08016D44
	ldr r0, _08016D40 @ =0x030004DE
	movs r1, #0xa
	bl sub_08042678
	b _08016D76
	.align 2, 0
_08016D3C: .4byte 0x03001800
_08016D40: .4byte 0x030004DE
_08016D44:
	cmp r1, #0
	blt _08016D76
	cmp r1, #3
	bgt _08016D76
	ldr r3, _08016D98 @ =0x083BE6E8
	ldr r2, _08016D9C @ =0x03000590
	subs r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r4, #0
	adds r1, #0x80
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x49
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r1, _08016DA0 @ =0x030004DE
	movs r2, #0xc
	bl memcpy_bytes_08041D04
_08016D76:
	ldr r0, _08016DA0 @ =0x030004DE
	movs r1, #8
	str r1, [sp]
	movs r1, #0xe
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #0x14
	movs r2, #0x15
	movs r3, #0x11
	bl render_text_sprites_08040DB8
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08016D98: .4byte 0x083BE6E8
_08016D9C: .4byte 0x03000590
_08016DA0: .4byte 0x030004DE
	.syntax divided
