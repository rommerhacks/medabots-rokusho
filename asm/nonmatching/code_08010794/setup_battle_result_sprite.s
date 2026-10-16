	.syntax unified

	thumb_func_start setup_battle_result_sprite
setup_battle_result_sprite: @ 0x080123A0
	push {lr}
	sub sp, #0x14
	ldr r1, _080123BC @ =0x03001800
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r3, [r0]
	cmp r3, #1
	beq _080123F0
	cmp r3, #1
	bgt _080123C0
	cmp r3, #0
	beq _080123CA
	b _0801245C
	.align 2, 0
_080123BC: .4byte 0x03001800
_080123C0:
	cmp r3, #2
	beq _08012414
	cmp r3, #3
	beq _0801243C
	b _0801245C
_080123CA:
	ldr r2, _080123EC @ =0x00000169
	adds r0, r1, r2
	ldrb r1, [r0]
	movs r0, #0x50
	str r0, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r0, #8
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	str r2, [sp, #0x10]
	movs r0, #0
	movs r2, #0
	movs r3, #0xc2
	bl setup_sprite_animation_entry
	b _0801245C
	.align 2, 0
_080123EC: .4byte 0x00000169
_080123F0:
	ldr r2, _08012410 @ =0x00000169
	adds r0, r1, r2
	ldrb r1, [r0]
	movs r0, #0x38
	str r0, [sp]
	str r3, [sp, #4]
	movs r0, #7
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	str r3, [sp, #0x10]
	movs r2, #1
	movs r3, #0xcc
	bl setup_sprite_animation_entry
	b _0801245C
	.align 2, 0
_08012410: .4byte 0x00000169
_08012414:
	ldr r2, _08012438 @ =0x00000169
	adds r0, r1, r2
	ldrb r1, [r0]
	movs r0, #0x38
	str r0, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r0, #6
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	str r2, [sp, #0x10]
	movs r0, #0
	movs r2, #2
	movs r3, #0xb8
	bl setup_sprite_animation_entry
	b _0801245C
	.align 2, 0
_08012438: .4byte 0x00000169
_0801243C:
	ldr r2, _08012464 @ =0x00000169
	adds r0, r1, r2
	ldrb r1, [r0]
	movs r0, #0x2e
	str r0, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	str r2, [sp, #0x10]
	movs r2, #3
	movs r3, #0xc2
	bl setup_sprite_animation_entry
_0801245C:
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_08012464: .4byte 0x00000169
	.syntax divided
