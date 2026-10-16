	.syntax unified

	thumb_func_start copy_player_medals_to_battle_bots
copy_player_medals_to_battle_bots: @ 0x08014EE8
	push {r4, r5, r6, r7, lr}
	movs r4, #0
	ldr r0, _08014F34 @ =0x03001800
	adds r1, r0, #0
	adds r1, #0x5a
	ldrb r2, [r1]
	cmp r4, r2
	bhs _08014F2E
	ldr r7, _08014F38 @ =0x030017A0
	adds r5, r0, #0
	adds r6, r1, #0
_08014EFE:
	adds r0, r5, #0
	adds r0, #0x41
	adds r0, r4, r0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #3
	adds r0, r0, r7
	ldrb r0, [r0, #2]
	bl find_medal_slot_by_id
	lsls r0, r0, #6
	ldr r1, _08014F3C @ =0x03000BA0
	adds r0, r0, r1
	lsls r1, r4, #8
	ldr r2, _08014F40 @ =0x03000590
	adds r1, r1, r2
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	adds r4, #1
	ldrb r0, [r6]
	cmp r4, r0
	blo _08014EFE
_08014F2E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08014F34: .4byte 0x03001800
_08014F38: .4byte 0x030017A0
_08014F3C: .4byte 0x03000BA0
_08014F40: .4byte 0x03000590
	.syntax divided
