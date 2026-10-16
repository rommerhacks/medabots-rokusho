	.syntax unified

	thumb_func_start update_npc_random_animation
	.global update_npc_random_animation
update_npc_random_animation: @ 0x0805215C
	push {r4, r5, lr}
	ldr r5, _080521B0 @ =0x03005DBC
	ldr r0, _080521B4 @ =0x03005310
	ldr r0, [r0, #4]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080521AA
	movs r0, #0x40
	bl get_entity_speed_fraction
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x15
	adds r5, r0, r5
	ldrb r4, [r5, #4]
	movs r0, #0x80
	ands r0, r4
	cmp r0, #0
	beq _080521AA
	ldrh r0, [r5, #2]
	lsrs r0, r0, #0xc
	cmp r0, #0
	bne _080521AA
	lsls r4, r4, #0x1b
	lsrs r4, r4, #3
	movs r0, #0xc4
	lsls r0, r0, #0x16
	adds r4, r4, r0
	lsrs r4, r4, #0x18
	movs r0, #4
	bl get_entity_speed_fraction
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	adds r2, r5, #0
	bl set_sprite_anim_and_store
_080521AA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080521B0: .4byte 0x03005DBC
_080521B4: .4byte 0x03005310
	.syntax divided
