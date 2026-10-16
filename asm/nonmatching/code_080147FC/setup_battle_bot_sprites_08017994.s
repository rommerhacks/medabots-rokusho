	.syntax unified

	thumb_func_start setup_battle_bot_sprites_08017994
setup_battle_bot_sprites_08017994: @ 0x08017994
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r7, r1, #0
	mov r8, r2
	cmp r5, #2
	bhi _080179B0
	adds r1, r5, #0
	movs r0, #0
	mov sb, r0
	b _080179B6
_080179B0:
	subs r1, r5, #3
	movs r4, #1
	mov sb, r4
_080179B6:
	ldr r0, _080179C8 @ =0x03000440
	adds r2, r0, #0
	adds r2, #0x3d
	ldrb r2, [r2]
	cmp r1, r2
	bne _080179CC
	movs r6, #0
	b _080179D6
	.align 2, 0
_080179C8: .4byte 0x03000440
_080179CC:
	adds r0, #0x46
	ldrb r0, [r0]
	cmp r1, r0
	bne _08017A02
	movs r6, #1
_080179D6:
	ldr r4, _08017A10 @ =0x03001864
	adds r0, r5, #0
	adds r1, r4, #0
	bl get_bot_part_effective_values
	ldrb r0, [r4]
	ldrb r1, [r4, #1]
	ldrb r2, [r4, #2]
	ldrb r3, [r4, #3]
	str r5, [sp]
	lsls r5, r6, #2
	str r5, [sp, #4]
	str r7, [sp, #8]
	mov r4, r8
	str r4, [sp, #0xc]
	mov r4, sb
	str r4, [sp, #0x10]
	movs r4, #2
	str r4, [sp, #0x14]
	str r5, [sp, #0x18]
	bl init_battle_medabot_sprites
_08017A02:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08017A10: .4byte 0x03001864
	.syntax divided
