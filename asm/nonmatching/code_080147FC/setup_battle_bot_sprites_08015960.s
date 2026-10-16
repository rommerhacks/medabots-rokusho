	.syntax unified

	thumb_func_start setup_battle_bot_sprites_08015960
setup_battle_bot_sprites_08015960: @ 0x08015960
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	ldr r4, _080159B8 @ =0x03001864
	adds r1, r4, #0
	bl get_bot_part_effective_values
	adds r0, r5, #0
	bl sub_08015924
	ldrb r6, [r4]
	ldrb r1, [r4, #1]
	ldrb r2, [r4, #2]
	ldrb r3, [r4, #3]
	str r5, [sp]
	lsls r5, r5, #2
	adds r5, #0x5a
	str r5, [sp, #4]
	mov r7, r8
	str r7, [sp, #8]
	mov r7, sb
	str r7, [sp, #0xc]
	str r0, [sp, #0x10]
	subs r4, #0x28
	ldrb r0, [r4]
	adds r0, #2
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	adds r0, r6, #0
	bl init_battle_medabot_sprites
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080159B8: .4byte 0x03001864
	.syntax divided
