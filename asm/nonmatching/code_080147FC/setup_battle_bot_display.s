	.syntax unified

	thumb_func_start setup_battle_bot_display
	.global setup_battle_bot_display
setup_battle_bot_display: @ 0x0801830C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r0, #4
	movs r1, #1
	bl clear_sprite_table_mask
	movs r0, #5
	movs r1, #1
	bl clear_sprite_table_mask
	movs r0, #6
	movs r1, #1
	bl clear_sprite_table_mask
	movs r0, #7
	movs r1, #1
	bl clear_sprite_table_mask
	movs r4, #0
	ldr r0, _08018398 @ =0x03000590
	mov r8, r0
	ldr r5, _0801839C @ =0x03000440
	adds r7, r5, #0
	adds r7, #0x3d
	ldr r6, _080183A0 @ =0x083AD3A4
_08018340:
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r3, r0, r4
	lsls r0, r3, #8
	add r0, r8
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _08018370
	ldrb r0, [r7]
	cmp r4, r0
	beq _08018370
	lsls r0, r3, #1
	adds r1, r0, r6
	ldrb r1, [r1]
	adds r0, #1
	adds r0, r0, r6
	ldrb r2, [r0]
	adds r0, r3, #0
	bl setup_battle_bot_sprites_08017994
_08018370:
	adds r4, #1
	cmp r4, #2
	bls _08018340
	ldr r0, _0801839C @ =0x03000440
	adds r3, r0, #0
	adds r3, #0x3d
	adds r0, #0x3c
	ldrb r2, [r0]
	lsls r1, r2, #1
	adds r1, r1, r2
	ldrb r3, [r3]
	adds r1, r1, r3
	movs r0, #0
	bl update_battle_sprite_orbiting_positions
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08018398: .4byte 0x03000590
_0801839C: .4byte 0x03000440
_080183A0: .4byte 0x083AD3A4
	.syntax divided
