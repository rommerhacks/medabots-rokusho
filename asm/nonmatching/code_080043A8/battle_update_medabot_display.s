	.syntax unified

	thumb_func_start battle_update_medabot_display
battle_update_medabot_display: @ 0x08006E44
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r5, _08006EC0 @ =0x03000440
	ldr r1, _08006EC4 @ =0x03000493
	ldrb r0, [r1]
	cmp r0, #0
	beq _08006EC8
	adds r0, r5, #0
	adds r0, #0x97
	ldrb r0, [r0]
	movs r2, #0x98
	adds r2, r2, r5
	mov sl, r2
	ldrb r1, [r2]
	movs r3, #0x99
	adds r3, r3, r5
	mov sb, r3
	ldrb r2, [r3]
	movs r4, #0x9a
	adds r4, r4, r5
	mov r8, r4
	ldrb r3, [r4]
	adds r7, r5, #0
	adds r7, #0x9b
	ldrb r4, [r7]
	str r4, [sp]
	bl validate_medapart_stats
	adds r6, r0, #0
	cmp r6, #0
	bne _08006EFE
	mov r1, sl
	ldrb r0, [r1]
	mov r2, sb
	ldrb r1, [r2]
	mov r3, r8
	ldrb r2, [r3]
	ldrb r3, [r7]
	str r6, [sp]
	movs r4, #6
	str r4, [sp, #4]
	movs r4, #0xa8
	str r4, [sp, #8]
	movs r4, #0x20
	str r4, [sp, #0xc]
	adds r4, r5, #0
	adds r4, #0x5e
	ldrb r4, [r4]
	str r4, [sp, #0x10]
	movs r4, #1
	str r4, [sp, #0x14]
	movs r4, #5
	str r4, [sp, #0x18]
	bl init_battle_medabot_sprites
	ldr r4, _08006EC4 @ =0x03000493
	strb r6, [r4]
	b _08006EFE
	.align 2, 0
_08006EC0: .4byte 0x03000440
_08006EC4: .4byte 0x03000493
_08006EC8:
	adds r0, r5, #0
	adds r0, #0x97
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x98
	ldrb r1, [r1]
	adds r2, r5, #0
	adds r2, #0x99
	ldrb r2, [r2]
	adds r3, r5, #0
	adds r3, #0x9a
	ldrb r3, [r3]
	adds r4, r5, #0
	adds r4, #0x9b
	ldrb r4, [r4]
	str r4, [sp]
	bl validate_medapart_stats
	cmp r0, #0
	beq _08006EFE
	movs r0, #6
	movs r1, #8
	bl battle_sprite_set_palette_index
	movs r0, #1
	ldr r1, _08006F10 @ =0x03000493
	strb r0, [r1]
_08006EFE:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08006F10: .4byte 0x03000493
	.syntax divided
