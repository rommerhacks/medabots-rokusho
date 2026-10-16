	.syntax unified

	thumb_func_start sub_0804A718
sub_0804A718: @ 0x0804A718
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	bl clear_oam
	ldr r0, _0804A84C @ =0x03002C30
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_080496C8
	ldr r0, _0804A850 @ =0x030055A0
	movs r1, #0x80
	lsls r1, r1, #2
	bl sub_080496C8
	movs r6, #0
	str r6, [sp]
	ldr r0, _0804A854 @ =0x040000D4
	mov r8, r0
	mov r1, sp
	str r1, [r0]
	movs r7, #0xe0
	lsls r7, r7, #0x13
	str r7, [r0, #4]
	ldr r2, _0804A858 @ =0x85000100
	mov sl, r2
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	ldr r0, _0804A85C @ =0x03000440
	movs r1, #0x9e
	lsls r1, r1, #1
	bl sub_080496C8
	ldr r0, _0804A860 @ =0x03000590
	movs r1, #0xc0
	lsls r1, r1, #3
	bl sub_080496C8
	ldr r5, _0804A864 @ =0x030057E0
	ldr r1, _0804A868 @ =0x00000C88
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _0804A86C @ =0x00000C89
	adds r0, r5, r2
	strb r6, [r0]
	adds r1, #0xb
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #1
	adds r0, r5, r2
	movs r4, #0
	strh r6, [r0]
	subs r1, #5
	adds r0, r5, r1
	strh r6, [r0]
	subs r2, #0x2b
	adds r0, r5, r2
	strb r4, [r0]
	subs r1, #0x2e
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _0804A870 @ =0x03005310
	mov sb, r2
	mov r0, sb
	adds r0, #0x38
	strb r4, [r0]
	ldr r0, _0804A874 @ =0x03006D20
	movs r1, #0x10
	bl sub_080496C8
	bl sub_0804B1FC
	mov r0, sb
	strb r4, [r0, #1]
	bl init_battle_medapart_sprites_all
	ldr r1, _0804A878 @ =0x03005590
	ldr r0, _0804A87C @ =0x08764CB0
	str r0, [r1]
	ldr r0, _0804A880 @ =0x030057D8
	str r5, [r0]
	ldr r1, _0804A884 @ =0x03006D30
	ldr r0, _0804A888 @ =0x02039000
	str r0, [r1]
	ldr r1, _0804A88C @ =0x03006D14
	ldr r0, _0804A890 @ =0x02030000
	str r0, [r1]
	ldr r1, _0804A894 @ =0x030057DC
	ldr r0, _0804A898 @ =0x02038000
	str r0, [r1]
	ldr r0, _0804A84C @ =0x03002C30
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_080496C8
	ldr r0, _0804A850 @ =0x030055A0
	movs r1, #0x80
	lsls r1, r1, #2
	bl sub_080496C8
	str r6, [sp]
	mov r1, sp
	mov r2, r8
	str r1, [r2]
	str r7, [r2, #4]
	mov r0, sl
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	ldr r0, _0804A89C @ =0x04000050
	strh r6, [r0]
	adds r0, #4
	strh r6, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xf2
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0804A8A0 @ =0x00000CBA
	adds r5, r5, r0
	movs r0, #2
	strb r0, [r5]
	bl update_battle_field_frame
	bl load_battlefield_data_to_buffer
	movs r0, #0x1c
	movs r1, #0
	bl dispatch_jump_table_29
	bl calculate_camera_scroll_from_npc
	bl sub_080487E4
	ldr r0, _0804A8A4 @ =0x00007FFF
	ldr r1, _0804A8A8 @ =0x42000000
	ldr r2, _0804A8AC @ =0x00000000
	ldr r3, _0804A8B0 @ =0x41000000
	bl setup_palette_fade_to_color
	bl sub_0804A1C4
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804A84C: .4byte 0x03002C30
_0804A850: .4byte 0x030055A0
_0804A854: .4byte 0x040000D4
_0804A858: .4byte 0x85000100
_0804A85C: .4byte 0x03000440
_0804A860: .4byte 0x03000590
_0804A864: .4byte 0x030057E0
_0804A868: .4byte 0x00000C88
_0804A86C: .4byte 0x00000C89
_0804A870: .4byte 0x03005310
_0804A874: .4byte 0x03006D20
_0804A878: .4byte 0x03005590
_0804A87C: .4byte 0x08764CB0
_0804A880: .4byte 0x030057D8
_0804A884: .4byte 0x03006D30
_0804A888: .4byte 0x02039000
_0804A88C: .4byte 0x03006D14
_0804A890: .4byte 0x02030000
_0804A894: .4byte 0x030057DC
_0804A898: .4byte 0x02038000
_0804A89C: .4byte 0x04000050
_0804A8A0: .4byte 0x00000CBA
_0804A8A4: .4byte 0x00007FFF
_0804A8A8: .4byte 0x42000000
_0804A8AC: .4byte 0x00000000
_0804A8B0: .4byte 0x41000000
	.syntax divided
