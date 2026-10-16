	.syntax unified

	thumb_func_start setup_battle_cursor_sprite_08036FF8
	.global setup_battle_cursor_sprite_08036FF8
setup_battle_cursor_sprite_08036FF8: @ 0x08036FF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	adds r6, r3, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	bl clear_battle_sprite_slot
	movs r4, #0
	cmp r4, r6
	bhs _08037086
	ldr r5, _08037098 @ =0x083AF4C0
	ldr r0, _0803709C @ =0x00004004
	mov sl, r0
_0803702C:
	ldr r0, _080370A0 @ =0x03002C30
	ldr r2, [sp]
	adds r1, r2, r4
	lsls r3, r1, #6
	adds r3, r3, r0
	mov r7, sl
	strh r7, [r3]
	movs r0, #0
	strb r0, [r3, #0x1c]
	movs r0, #7
	strb r0, [r3, #0xa]
	movs r0, #0xf0
	strb r0, [r3, #0xb]
	lsls r2, r4, #3
	adds r0, r3, #0
	adds r0, #0x2c
	strb r2, [r0]
	mov r2, sb
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	ldrh r7, [r5]
	adds r0, r0, r7
	ldr r7, _080370A4 @ =0x000001FF
	adds r2, r7, #0
	ands r0, r2
	strh r0, [r3, #2]
	mov r2, r8
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	ldrh r7, [r5, #2]
	adds r0, r0, r7
	movs r2, #0xff
	ands r0, r2
	strh r0, [r3, #4]
	ldr r0, _080370A8 @ =0x083B5F80
	adds r0, #0x90
	ldr r0, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
	adds r5, #4
	adds r4, #1
	cmp r4, r6
	blo _0803702C
_08037086:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08037098: .4byte 0x083AF4C0
_0803709C: .4byte 0x00004004
_080370A0: .4byte 0x03002C30
_080370A4: .4byte 0x000001FF
_080370A8: .4byte 0x083B5F80
	.syntax divided
