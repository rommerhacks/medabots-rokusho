	.syntax unified

	thumb_func_start sub_0804A8F8
sub_0804A8F8: @ 0x0804A8F8
	push {lr}
	sub sp, #4
	ldr r0, _0804A98C @ =0x03002C30
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_080496C8
	ldr r0, _0804A990 @ =0x030055A0
	movs r1, #0x80
	lsls r1, r1, #2
	bl sub_080496C8
	movs r2, #0
	str r2, [sp]
	ldr r0, _0804A994 @ =0x040000D4
	mov r1, sp
	str r1, [r0]
	movs r1, #0xe0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r3, _0804A998 @ =0x85000100
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	str r2, [sp]
	mov r1, sp
	str r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r0, [r0, #8]
	ldr r0, _0804A99C @ =0x04000050
	movs r1, #0
	strh r2, [r0]
	adds r0, #4
	strh r2, [r0]
	ldr r0, _0804A9A0 @ =0x03005310
	strb r1, [r0, #1]
	bl init_battle_medapart_sprites_all
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xf2
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0804A9A4 @ =0x030057E0
	ldr r1, _0804A9A8 @ =0x00000CBA
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	bl update_battle_field_frame
	bl load_battlefield_data_to_buffer
	movs r0, #0xe
	movs r1, #0
	bl dispatch_jump_table_29
	bl field_center_camera_on_player
	bl sub_080487E4
	ldr r1, _0804A9AC @ =0x42000000
	ldr r2, _0804A9B0 @ =0x00000000
	ldr r3, _0804A9B4 @ =0x41000000
	movs r0, #0
	bl setup_palette_fade_to_color
	bl sub_0804A1C4
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0804A98C: .4byte 0x03002C30
_0804A990: .4byte 0x030055A0
_0804A994: .4byte 0x040000D4
_0804A998: .4byte 0x85000100
_0804A99C: .4byte 0x04000050
_0804A9A0: .4byte 0x03005310
_0804A9A4: .4byte 0x030057E0
_0804A9A8: .4byte 0x00000CBA
_0804A9AC: .4byte 0x42000000
_0804A9B0: .4byte 0x00000000
_0804A9B4: .4byte 0x41000000
	.syntax divided
