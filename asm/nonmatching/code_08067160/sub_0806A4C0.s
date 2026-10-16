	.syntax unified

	thumb_func_start sub_0806A4C0
sub_0806A4C0: @ 0x0806A4C0
	push {r4, lr}
	ldr r4, _0806A4D0 @ =0x03006F88
	ldr r0, [r4]
	cmp r0, #0
	beq _0806A4D4
	cmp r0, #1
	beq _0806A4EC
	b _0806A57C
	.align 2, 0
_0806A4D0: .4byte 0x03006F88
_0806A4D4:
	bl init_battle_sprite_c400
	movs r0, #0
	movs r1, #5
	movs r2, #0
	movs r3, #0
	bl sprite_animation_dispatch
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	b _0806A57C
_0806A4EC:
	ldr r0, _0806A564 @ =0x03002C30
	ldrh r0, [r0, #0x1a]
	cmp r0, #0xb4
	bne _0806A57C
	movs r0, #0x42
	bl play_sound_effect
	movs r0, #0x26
	movs r1, #0xc
	bl battle_sprite_set_palette_index
	movs r0, #0x32
	movs r1, #0xc
	bl battle_sprite_set_palette_index
	movs r0, #0x3e
	movs r1, #0xc
	bl battle_sprite_set_palette_index
	movs r0, #1
	movs r1, #0xa
	movs r2, #0
	movs r3, #0
	bl sprite_animation_dispatch
	movs r0, #2
	movs r1, #0xa
	movs r2, #1
	movs r3, #0
	bl sprite_animation_dispatch
	movs r0, #3
	movs r1, #0xa
	movs r2, #2
	movs r3, #0
	bl sprite_animation_dispatch
	ldr r0, _0806A568 @ =0x03006FF8
	movs r2, #0
	str r2, [r0, #4]
	str r2, [r0]
	ldr r0, _0806A56C @ =0x03007000
	str r2, [r0, #4]
	str r2, [r0]
	ldr r0, _0806A570 @ =0x03006FE0
	str r2, [r0, #8]
	str r2, [r0, #4]
	str r2, [r0]
	ldr r1, _0806A574 @ =0x03006FEC
	movs r0, #0x20
	strb r0, [r1, #2]
	strb r0, [r1, #1]
	strb r0, [r1]
	ldr r0, _0806A578 @ =0x03006FF0
	strb r2, [r0, #2]
	strb r2, [r0, #1]
	strb r2, [r0]
	movs r0, #1
	b _0806A57E
	.align 2, 0
_0806A564: .4byte 0x03002C30
_0806A568: .4byte 0x03006FF8
_0806A56C: .4byte 0x03007000
_0806A570: .4byte 0x03006FE0
_0806A574: .4byte 0x03006FEC
_0806A578: .4byte 0x03006FF0
_0806A57C:
	movs r0, #0
_0806A57E:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
