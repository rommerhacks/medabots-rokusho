	.syntax unified

	thumb_func_start sub_0800AF0C
	.global sub_0800AF0C
sub_0800AF0C: @ 0x0800AF0C
	push {r4, r5, lr}
	sub sp, #0x1c
	ldr r0, _0800AF4C @ =0x03000440
	adds r0, #0x3d
	ldrb r0, [r0]
	bl get_medal_active_slot
	adds r3, r0, #0
	cmp r3, #0xff
	beq _0800AF54
	ldr r0, _0800AF50 @ =0x030017A0
	lsls r3, r3, #3
	adds r3, r3, r0
	ldrb r0, [r3, #3]
	ldrb r1, [r3, #4]
	ldrb r2, [r3, #5]
	ldrb r3, [r3, #6]
	movs r5, #2
	str r5, [sp]
	movs r4, #0x64
	str r4, [sp, #4]
	movs r4, #0x18
	str r4, [sp, #8]
	movs r4, #0x40
	str r4, [sp, #0xc]
	movs r4, #0
	str r4, [sp, #0x10]
	str r5, [sp, #0x14]
	str r4, [sp, #0x18]
	bl init_battle_medabot_sprites
	b _0800AF5C
	.align 2, 0
_0800AF4C: .4byte 0x03000440
_0800AF50: .4byte 0x030017A0
_0800AF54:
	movs r0, #0x64
	movs r1, #4
	bl clear_sprite_table_mask
_0800AF5C:
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
