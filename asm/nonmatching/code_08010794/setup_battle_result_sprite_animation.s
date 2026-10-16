	.syntax unified

	thumb_func_start setup_battle_result_sprite_animation
setup_battle_result_sprite_animation: @ 0x080124B8
	push {lr}
	sub sp, #0x14
	bl init_scene_buffers_080445F4
	ldr r1, _080124D8 @ =0x03001800
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r2, [r0]
	cmp r2, #1
	beq _0801250C
	cmp r2, #1
	bgt _080124DC
	cmp r2, #0
	beq _080124E6
	b _08012578
	.align 2, 0
_080124D8: .4byte 0x03001800
_080124DC:
	cmp r2, #2
	beq _08012530
	cmp r2, #3
	beq _08012558
	b _08012578
_080124E6:
	ldr r3, _08012508 @ =0x00000169
	adds r0, r1, r3
	ldrb r1, [r0]
	movs r0, #0x3c
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #8
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	str r2, [sp, #0x10]
	movs r0, #0
	movs r2, #0
	movs r3, #0xc2
	bl setup_sprite_animation_entry
	b _08012578
	.align 2, 0
_08012508: .4byte 0x00000169
_0801250C:
	ldr r3, _0801252C @ =0x00000169
	adds r0, r1, r3
	ldrb r1, [r0]
	movs r0, #0x28
	str r0, [sp]
	str r2, [sp, #4]
	movs r0, #7
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	movs r2, #1
	movs r3, #0xcc
	bl setup_sprite_animation_entry
	b _08012578
	.align 2, 0
_0801252C: .4byte 0x00000169
_08012530:
	ldr r2, _08012554 @ =0x00000169
	adds r0, r1, r2
	ldrb r1, [r0]
	movs r0, #0x28
	str r0, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r0, #6
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	movs r2, #2
	movs r3, #0xb8
	bl setup_sprite_animation_entry
	b _08012578
	.align 2, 0
_08012554: .4byte 0x00000169
_08012558:
	ldr r3, _08012580 @ =0x00000169
	adds r0, r1, r3
	ldrb r1, [r0]
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	movs r2, #3
	movs r3, #0xc2
	bl setup_sprite_animation_entry
_08012578:
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_08012580: .4byte 0x00000169
	.syntax divided
