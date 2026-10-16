	.syntax unified

	thumb_func_start init_bg0_for_cursor
	.global init_bg0_for_cursor
init_bg0_for_cursor: @ 0x08047FB4
	push {lr}
	ldr r2, _08047FE4 @ =0x04000008
	movs r3, #0xa0
	lsls r3, r3, #3
	adds r1, r3, #0
	strh r1, [r2]
	subs r2, #8
	movs r3, #0xfb
	lsls r3, r3, #5
	adds r1, r3, #0
	strh r1, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x16
	movs r2, #7
	bl open_choice_menu
	ldr r0, _08047FE8 @ =0x030064A0
	adds r0, #0x64
	movs r1, #0
	strb r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_08047FE4: .4byte 0x04000008
_08047FE8: .4byte 0x030064A0
	.syntax divided
