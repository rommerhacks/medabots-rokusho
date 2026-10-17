	.syntax unified

	thumb_func_start sub_0803185C
sub_0803185C: @ 0x0803185C
	push {r4, lr}
	movs r0, #0
	bl dispatch_battle_action_substate
	ldr r0, _080318B8 @ =0x03001800
	adds r0, #0x87
	ldrb r0, [r0]
	bl medaforce_gauge_drain_step
	ldr r4, _080318BC @ =0x083B5F80
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl process_sprite_anim_commands
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x22
	bl process_sprite_anim_commands
	ldr r0, _080318C0 @ =0x03002C30
	ldr r1, _080318C4 @ =0x00000862
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080318B0
	bl clear_battle_ui_tilemaps
	bl sub_0801AEB4
	movs r0, #0x21
	movs r1, #2
	bl clear_battle_sprite_slot
	ldr r1, _080318C8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080318B0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080318B8: .4byte 0x03001800
_080318BC: .4byte 0x083B5F80
_080318C0: .4byte 0x03002C30
_080318C4: .4byte 0x00000862
_080318C8: .4byte 0x0300137C
	.syntax divided
