	.syntax unified

	thumb_func_start sub_08005118
	.global sub_08005118
sub_08005118: @ 0x08005118
	push {r4, lr}
	sub sp, #0x10
	movs r0, #0x32
	movs r1, #0xa
	bl clear_sprite_table_mask
	ldr r0, _08005160 @ =0x030017A0
	ldr r4, _08005164 @ =0x03000440
	adds r1, r4, #0
	adds r1, #0x51
	ldrb r1, [r1]
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #1
	bls _0800516C
	ldrb r0, [r1, #2]
	bl find_medal_slot_by_id
	lsls r0, r0, #6
	ldr r1, _08005168 @ =0x03000BAA
	adds r0, r0, r1
	movs r1, #0xa
	str r1, [sp]
	movs r1, #0xd
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #2
	str r1, [sp, #0xc]
	movs r1, #0x32
	movs r2, #1
	movs r3, #0xd
	bl render_text_sprites_08040DB8
	b _08005192
	.align 2, 0
_08005160: .4byte 0x030017A0
_08005164: .4byte 0x03000440
_08005168: .4byte 0x03000BAA
_0800516C:
	adds r4, #0x9e
	adds r0, r4, #0
	movs r1, #0xa
	bl sub_08042678
	movs r0, #0xa
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0x32
	movs r2, #1
	movs r3, #0xd
	bl render_text_sprites_08040DB8
_08005192:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
