	.syntax unified

	thumb_func_start sub_08016A3C
	.global sub_08016A3C
sub_08016A3C: @ 0x08016A3C
	push {r4, r5, lr}
	sub sp, #0x10
	movs r0, #0x1f
	movs r1, #0xe
	bl clear_sprite_table_mask
	ldr r5, _08016A64 @ =0x03001800
	adds r0, r5, #0
	adds r0, #0x82
	ldrb r4, [r0]
	cmp r4, #0
	bne _08016A70
	ldr r0, _08016A68 @ =0x083C4A10
	ldr r0, [r0, #0xc]
	ldr r1, _08016A6C @ =0x030004DE
	movs r2, #0xe
	bl memcpy_bytes_08041D04
	b _08016AA8
	.align 2, 0
_08016A64: .4byte 0x03001800
_08016A68: .4byte 0x083C4A10
_08016A6C: .4byte 0x030004DE
_08016A70:
	cmp r4, #0
	blt _08016AA8
	cmp r4, #3
	bgt _08016AA8
	ldr r3, _08016ACC @ =0x083BB9CC
	ldr r2, _08016AD0 @ =0x03000590
	subs r1, r4, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r5, #0
	adds r1, #0x80
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x5f
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r4
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r1, _08016AD4 @ =0x030004DE
	movs r2, #0xf
	bl memcpy_bytes_08041D04
_08016AA8:
	ldr r0, _08016AD4 @ =0x030004DE
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xd
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #0x1f
	movs r2, #0xa
	movs r3, #0x11
	bl render_text_sprites_08040DB8
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08016ACC: .4byte 0x083BB9CC
_08016AD0: .4byte 0x03000590
_08016AD4: .4byte 0x030004DE
	.syntax divided
