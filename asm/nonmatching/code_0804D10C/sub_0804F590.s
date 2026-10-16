	.syntax unified

	thumb_func_start sub_0804F590
sub_0804F590: @ 0x0804F590
	push {r4, r5, lr}
	bl populate_battle_entity_tile_positions
	ldr r4, _0804F614 @ =0x03003870
	movs r5, #0x90
	lsls r5, r5, #4
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080496C8
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r4, r4, r0
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080496C8
	ldr r4, _0804F618 @ =0x03005664
	adds r0, r4, #0
	movs r1, #0x90
	bl sub_080496C8
	adds r4, #0xa8
	adds r0, r4, #0
	movs r1, #0x90
	bl sub_080496C8
	bl init_battle_medapart_sprites_all
	ldr r4, _0804F61C @ =0x03005FF0
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r4, #0
	bl sub_080496C8
	ldr r1, _0804F620 @ =0x084045A8
	adds r0, r4, #0
	subs r0, #0x12
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r4, #0
	subs r1, #0xe
	ldrh r2, [r1]
	lsrs r2, r2, #1
	subs r1, #2
	ldrh r1, [r1]
	lsrs r1, r1, #1
	muls r2, r1, r2
	adds r1, r4, #0
	bl memcpy_u8
	ldr r0, _0804F624 @ =0x000004AA
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	bl load_map_npc_sprites
	bl update_entity_sprites_on_screen
	bl map_script_command_done
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804F614: .4byte 0x03003870
_0804F618: .4byte 0x03005664
_0804F61C: .4byte 0x03005FF0
_0804F620: .4byte 0x084045A8
_0804F624: .4byte 0x000004AA

	.syntax divided
