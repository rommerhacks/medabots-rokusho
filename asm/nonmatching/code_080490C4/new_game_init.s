	.syntax unified

	thumb_func_start new_game_init
new_game_init: @ 0x0804A2A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _0804A4EC @ =0x03002B70
	movs r1, #0x1c
	bl sub_080496C8
	ldr r0, _0804A4F0 @ =0x03000BE0
	movs r1, #0xf0
	lsls r1, r1, #3
	bl sub_080496C8
	ldr r0, _0804A4F4 @ =0x03004C40
	movs r1, #0xf0
	lsls r1, r1, #2
	bl sub_080496C8
	ldr r0, _0804A4F8 @ =0x030017A0
	movs r1, #0x48
	bl sub_080496C8
	ldr r0, _0804A4FC @ =0x03002BA0
	movs r1, #0x80
	bl sub_080496C8
	ldr r7, _0804A500 @ =0x030057E0
	movs r1, #0xcc
	lsls r1, r1, #4
	adds r0, r7, #0
	bl sub_080496C8
	ldr r0, _0804A504 @ =0x03000440
	movs r1, #0x9e
	lsls r1, r1, #1
	bl sub_080496C8
	ldr r0, _0804A508 @ =0x03000590
	movs r1, #0xc0
	lsls r1, r1, #3
	bl sub_080496C8
	bl clear_oam
	ldr r0, _0804A50C @ =0x03002C30
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_080496C8
	ldr r0, _0804A510 @ =0x030055A0
	mov r8, r0
	movs r1, #0x80
	lsls r1, r1, #2
	mov sb, r1
	bl sub_080496C8
	movs r6, #0
	str r6, [sp, #4]
	ldr r4, _0804A514 @ =0x040000D4
	add r2, sp, #4
	str r2, [r4]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	mov sl, r0
	str r0, [r4, #4]
	ldr r5, _0804A518 @ =0x85000100
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_08041D28
	bl sub_080421A0
	ldr r1, _0804A51C @ =0x00000CBC
	adds r0, r7, r1
	movs r1, #0x10
	strb r1, [r0]
	ldr r2, _0804A520 @ =0x00000CBD
	adds r0, r7, r2
	strb r1, [r0]
	ldr r1, _0804A524 @ =0x0400000A
	ldr r2, _0804A528 @ =0x0000C609
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0804A52C @ =0x0000EA0A
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r2, _0804A530 @ =0x0000EE0B
	adds r0, r2, #0
	strh r0, [r1]
	subs r1, #0xe
	movs r2, #0xf2
	lsls r2, r2, #5
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _0804A534 @ =0x03005590
	ldr r0, _0804A538 @ =0x08764CB0
	str r0, [r1]
	ldr r0, _0804A53C @ =0x030057D8
	str r7, [r0]
	ldr r1, _0804A540 @ =0x03006D30
	ldr r0, _0804A544 @ =0x02039000
	str r0, [r1]
	ldr r1, _0804A548 @ =0x03006D14
	ldr r0, _0804A54C @ =0x02030000
	str r0, [r1]
	ldr r1, _0804A550 @ =0x030057DC
	ldr r0, _0804A554 @ =0x02038000
	str r0, [r1]
	ldr r0, _0804A50C @ =0x03002C30
	movs r1, #0x80
	lsls r1, r1, #6
	bl sub_080496C8
	mov r0, r8
	mov r1, sb
	bl sub_080496C8
	str r6, [sp, #4]
	add r0, sp, #4
	str r0, [r4]
	mov r1, sl
	str r1, [r4, #4]
	str r5, [r4, #8]
	ldr r0, [r4, #8]
	bl sub_080492CC
	bl sub_08048B6C
	ldr r5, _0804A558 @ =0x03005310
	movs r2, #0
	mov sb, r2
	strh r6, [r5, #0x1c]
	strh r6, [r5, #0x24]
	strh r6, [r5, #0x1e]
	strh r6, [r5, #0x26]
	strh r6, [r5, #0x20]
	strh r6, [r5, #0x28]
	strh r6, [r5, #0x22]
	strh r6, [r5, #0x2a]
	ldr r0, _0804A55C @ =0x03005000
	strh r6, [r0]
	strh r6, [r0, #2]
	ldr r0, _0804A560 @ =0x03004C30
	strh r6, [r0]
	strh r6, [r0, #2]
	ldr r0, _0804A564 @ =0x0300057C
	strh r6, [r0]
	strh r6, [r0, #2]
	ldr r0, _0804A568 @ =0x03001C04
	strh r6, [r0]
	strh r6, [r0, #2]
	ldr r0, _0804A56C @ =0x000007FC
	adds r4, r7, r0
	ldr r1, _0804A570 @ =0x00000454
	adds r0, r4, #0
	bl sub_080496C8
	ldr r1, _0804A574 @ =0x00000CBA
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	ldr r0, _0804A578 @ =0x000007FE
	adds r1, r7, r0
	movs r0, #0x17
	strb r0, [r1]
	movs r0, #0xe
	strb r0, [r4]
	ldr r2, _0804A57C @ =0x000007FD
	adds r1, r7, r2
	movs r0, #7
	strb r0, [r1]
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r1, #0
	ldr r2, _0804A580 @ =0x03006428
	ldrh r2, [r2]
	adds r0, r0, r2
	ldr r2, _0804A584 @ =0x00000C52
	adds r1, r7, r2
	strh r0, [r1]
	ldr r0, _0804A588 @ =0x00000C4A
	adds r0, r0, r7
	mov sl, r0
	ldrh r0, [r0]
	adds r0, #0xd0
	adds r2, #2
	adds r4, r7, r2
	strh r0, [r4]
	adds r2, #0x13
	adds r0, r7, r2
	mov r2, sb
	strb r2, [r0]
	ldr r2, _0804A58C @ =0x00000C34
	adds r0, r7, r2
	movs r2, #1
	mov r8, r2
	mov r2, r8
	strb r2, [r0]
	ldrh r0, [r1]
	bl sub_080526F0
	ldr r2, _0804A590 @ =0x00000C56
	adds r1, r7, r2
	strb r0, [r1]
	ldrh r0, [r4]
	bl sub_08052714
	ldr r2, _0804A594 @ =0x00000C57
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _0804A598 @ =0x00000C5C
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	subs r1, #1
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
	ldr r4, _0804A59C @ =0x0000C804
	mov r0, r8
	str r0, [sp]
	movs r0, #0x2f
	adds r1, r4, #0
	movs r2, #3
	movs r3, #0
	bl init_battle_sprite_entry_08048818
	bl update_bg_scroll_offsets_a
	ldr r1, _0804A5A0 @ =0x00000C76
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0804A4BC
	ldr r2, _0804A5A4 @ =0x00000C84
	adds r0, r7, r2
	ldrb r3, [r0]
	lsls r2, r3, #1
	adds r2, r2, r3
	adds r1, #0xd
	adds r0, r7, r1
	lsls r2, r2, #2
	ldrb r0, [r0]
	adds r2, r2, r0
	mov r0, r8
	str r0, [sp]
	movs r0, #0x30
	adds r1, r4, #0
	bl init_battle_sprite_entry_08048818
	ldr r2, _0804A580 @ =0x03006428
	ldrh r1, [r2]
	movs r0, #0x50
	subs r0, r0, r1
	ldr r2, _0804A5A8 @ =0x00000C6E
	adds r1, r7, r2
	strh r0, [r1]
	mov r0, sl
	ldrh r1, [r0]
	movs r0, #0x60
	subs r0, r0, r1
	adds r2, #2
	adds r1, r7, r2
	strh r0, [r1]
_0804A4BC:
	mov r0, sb
	strb r0, [r5, #1]
	ldr r0, _0804A5AC @ =0x04000050
	strh r6, [r0]
	adds r0, #4
	strh r6, [r0]
	bl sub_080487E4
	ldr r0, _0804A5B0 @ =0x00007FFF
	ldr r1, _0804A5B4 @ =0x42000000
	ldr r2, _0804A5B8 @ =0x00000000
	ldr r3, _0804A5BC @ =0x41000000
	bl setup_palette_fade_to_color
	bl sub_0804A1C4
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804A4EC: .4byte 0x03002B70
_0804A4F0: .4byte 0x03000BE0
_0804A4F4: .4byte 0x03004C40
_0804A4F8: .4byte 0x030017A0
_0804A4FC: .4byte 0x03002BA0
_0804A500: .4byte 0x030057E0
_0804A504: .4byte 0x03000440
_0804A508: .4byte 0x03000590
_0804A50C: .4byte 0x03002C30
_0804A510: .4byte 0x030055A0
_0804A514: .4byte 0x040000D4
_0804A518: .4byte 0x85000100
_0804A51C: .4byte 0x00000CBC
_0804A520: .4byte 0x00000CBD
_0804A524: .4byte 0x0400000A
_0804A528: .4byte 0x0000C609
_0804A52C: .4byte 0x0000EA0A
_0804A530: .4byte 0x0000EE0B
_0804A534: .4byte 0x03005590
_0804A538: .4byte 0x08764CB0
_0804A53C: .4byte 0x030057D8
_0804A540: .4byte 0x03006D30
_0804A544: .4byte 0x02039000
_0804A548: .4byte 0x03006D14
_0804A54C: .4byte 0x02030000
_0804A550: .4byte 0x030057DC
_0804A554: .4byte 0x02038000
_0804A558: .4byte 0x03005310
_0804A55C: .4byte 0x03005000
_0804A560: .4byte 0x03004C30
_0804A564: .4byte 0x0300057C
_0804A568: .4byte 0x03001C04
_0804A56C: .4byte 0x000007FC
_0804A570: .4byte 0x00000454
_0804A574: .4byte 0x00000CBA
_0804A578: .4byte 0x000007FE
_0804A57C: .4byte 0x000007FD
_0804A580: .4byte 0x03006428
_0804A584: .4byte 0x00000C52
_0804A588: .4byte 0x00000C4A
_0804A58C: .4byte 0x00000C34
_0804A590: .4byte 0x00000C56
_0804A594: .4byte 0x00000C57
_0804A598: .4byte 0x00000C5C
_0804A59C: .4byte 0x0000C804
_0804A5A0: .4byte 0x00000C76
_0804A5A4: .4byte 0x00000C84
_0804A5A8: .4byte 0x00000C6E
_0804A5AC: .4byte 0x04000050
_0804A5B0: .4byte 0x00007FFF
_0804A5B4: .4byte 0x42000000
_0804A5B8: .4byte 0x00000000
_0804A5BC: .4byte 0x41000000
	.syntax divided
