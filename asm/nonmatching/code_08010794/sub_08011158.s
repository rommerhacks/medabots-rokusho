	.syntax unified

	thumb_func_start sub_08011158
sub_08011158: @ 0x08011158
	push {r4, r5, r6, lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r5, _0801117C @ =0x03001800
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #3
	bne _08011184
	movs r0, #0
	strb r0, [r6]
	ldr r1, _08011180 @ =0x0300137C
	movs r0, #0x4b
	str r0, [r1]
	b _08011204
	.align 2, 0
_0801117C: .4byte 0x03001800
_08011180: .4byte 0x0300137C
_08011184:
	ldrb r2, [r6]
	lsls r0, r2, #3
	movs r3, #0xba
	lsls r3, r3, #1
	adds r1, r5, r3
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08011200
	bl sub_0803FB0C
	ldr r2, _080111EC @ =0x083B6410
	ldrb r0, [r6]
	lsls r0, r0, #3
	movs r3, #0xb7
	lsls r3, r3, #1
	adds r1, r5, r3
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r4, _080111F0 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #0xb
	bl memcpy_bytes_0803F63C
	ldr r2, _080111F4 @ =0x083B7338
	ldrb r0, [r6]
	lsls r0, r0, #3
	ldr r3, _080111F8 @ =0x00000175
	adds r1, r5, r3
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	adds r4, #0x14
	adds r1, r4, #0
	movs r2, #0x11
	bl memcpy_bytes_0803F63C
	movs r0, #0x10
	bl play_song
	ldr r1, _080111FC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _08011204
	.align 2, 0
_080111EC: .4byte 0x083B6410
_080111F0: .4byte 0x030004DE
_080111F4: .4byte 0x083B7338
_080111F8: .4byte 0x00000175
_080111FC: .4byte 0x0300137C
_08011200:
	adds r0, r2, #1
	strb r0, [r6]
_08011204:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
