	.syntax unified

	thumb_func_start setup_battle_sprite_from_game_state
setup_battle_sprite_from_game_state: @ 0x08006444
	push {r4, lr}
	sub sp, #0x1c
	ldr r0, _08006490 @ =0x03000440
	mov ip, r0
	adds r0, #0x98
	ldrb r0, [r0]
	mov r1, ip
	adds r1, #0x99
	ldrb r1, [r1]
	mov r2, ip
	adds r2, #0x9a
	ldrb r2, [r2]
	mov r3, ip
	adds r3, #0x9b
	ldrb r3, [r3]
	movs r4, #0
	str r4, [sp]
	movs r4, #6
	str r4, [sp, #4]
	movs r4, #0xa8
	str r4, [sp, #8]
	movs r4, #0x20
	str r4, [sp, #0xc]
	mov r4, ip
	adds r4, #0x5e
	ldrb r4, [r4]
	str r4, [sp, #0x10]
	movs r4, #1
	str r4, [sp, #0x14]
	movs r4, #5
	str r4, [sp, #0x18]
	bl setup_battle_sprite_group
	add sp, #0x1c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08006490: .4byte 0x03000440
	.syntax divided
