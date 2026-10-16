	.syntax unified

	thumb_func_start setup_battle_sprite_terrain
	.global setup_battle_sprite_terrain
setup_battle_sprite_terrain: @ 0x08050070
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	ldr r1, _080500D4 @ =0x03002C30
	lsls r0, r5, #6
	adds r7, r0, r1
	movs r0, #0xf
	ands r0, r4
	adds r1, r7, #0
	adds r1, #0x27
	strb r0, [r1]
	lsrs r4, r4, #4
	adds r0, r5, #0
	adds r1, r4, #0
	bl set_sprite_animation_state
	adds r0, r7, #0
	adds r0, #0x2a
	strb r6, [r0]
	adds r0, r5, #0
	bl sub_080518F4
	adds r1, r0, #0
	movs r0, #0x10
	bl sub_0807CBBC
	adds r1, r7, #0
	adds r1, #0x28
	strb r0, [r1]
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_080502B4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl sub_080493D4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080500D4: .4byte 0x03002C30
	.syntax divided
