	.syntax unified

	thumb_func_start render_battle_bot_label
	.global render_battle_bot_label
render_battle_bot_label: @ 0x08017BD0
	push {lr}
	sub sp, #0x10
	movs r0, #9
	movs r1, #0xd
	bl clear_sprite_table_mask
	ldr r2, _08017C14 @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x3c
	ldrb r3, [r0]
	cmp r3, #0
	bne _08017C1C
	adds r2, #0x3d
	adds r1, r3, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #8
	ldr r1, _08017C18 @ =0x0300059A
	adds r0, r0, r1
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xf
	str r1, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	movs r1, #9
	movs r2, #0x11
	movs r3, #0xe
	bl render_text_sprites_08040DB8
	b _08017C46
	.align 2, 0
_08017C14: .4byte 0x03000440
_08017C18: .4byte 0x0300059A
_08017C1C:
	adds r2, #0x3d
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #8
	ldr r1, _08017C4C @ =0x0300059A
	adds r0, r0, r1
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xf
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #9
	movs r2, #3
	movs r3, #0xe
	bl render_text_sprites_08040DB8
_08017C46:
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
_08017C4C: .4byte 0x0300059A
	.syntax divided
