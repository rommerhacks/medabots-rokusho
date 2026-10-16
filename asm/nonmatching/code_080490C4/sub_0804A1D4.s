	.syntax unified

	thumb_func_start sub_0804A1D4
sub_0804A1D4: @ 0x0804A1D4
	push {r4, lr}
	ldr r1, _0804A1FC @ =0x03005310
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	ldr r1, _0804A200 @ =0x030057E0
	ldr r2, _0804A204 @ =0x00000C88
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804A23C
	adds r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804A208
	bl map_script_update_command
	b _0804A20C
	.align 2, 0
_0804A1FC: .4byte 0x03005310
_0804A200: .4byte 0x030057E0
_0804A204: .4byte 0x00000C88
_0804A208:
	bl map_script_run_command
_0804A20C:
	ldr r0, _0804A22C @ =0x030057E0
	ldr r1, _0804A230 @ =0x00000C5F
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804A24C
	ldr r1, _0804A234 @ =0x083D1FAC
	ldr r0, _0804A238 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	b _0804A24C
	.align 2, 0
_0804A22C: .4byte 0x030057E0
_0804A230: .4byte 0x00000C5F
_0804A234: .4byte 0x083D1FAC
_0804A238: .4byte 0x0300137C
_0804A23C:
	ldr r1, _0804A294 @ =0x083D1FAC
	ldr r0, _0804A298 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_0804A24C:
	bl update_entity_sprites_on_screen
	bl update_npc_sprite_animations
	bl update_sprite_animation_dma
	movs r4, #0
_0804A25A:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl calculate_oam_affine_matrix
	adds r4, #1
	cmp r4, #0x1f
	ble _0804A25A
	bl update_battle_entity_status_chars
	ldr r0, _0804A29C @ =0x03006D40
	adds r2, r0, #6
	ldr r1, _0804A2A0 @ =0x03001380
	movs r3, #0x1f
_0804A274:
	ldrh r0, [r2]
	strh r0, [r1, #6]
	ldrh r0, [r2, #2]
	strh r0, [r1, #0xe]
	ldrh r0, [r2, #4]
	strh r0, [r1, #0x16]
	ldrh r0, [r2, #6]
	strh r0, [r1, #0x1e]
	adds r2, #0x10
	adds r1, #0x20
	subs r3, #1
	cmp r3, #0
	bge _0804A274
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804A294: .4byte 0x083D1FAC
_0804A298: .4byte 0x0300137C
_0804A29C: .4byte 0x03006D40
_0804A2A0: .4byte 0x03001380
	.syntax divided
