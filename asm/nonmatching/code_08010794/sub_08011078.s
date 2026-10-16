	.syntax unified

	thumb_func_start sub_08011078
sub_08011078: @ 0x08011078
	push {r4, r5, lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	ldr r2, _0801109C @ =0x03001800
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r4, r2, r0
	ldrb r0, [r4]
	cmp r0, #3
	bne _080110A4
	movs r0, #0
	strb r0, [r4]
	ldr r1, _080110A0 @ =0x0300137C
	movs r0, #0x47
	str r0, [r1]
	b _080110F4
	.align 2, 0
_0801109C: .4byte 0x03001800
_080110A0: .4byte 0x0300137C
_080110A4:
	ldrb r1, [r4]
	lsls r0, r1, #3
	movs r3, #0xb7
	lsls r3, r3, #1
	adds r5, r2, r3
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080110F0
	bl sub_0803FB0C
	ldr r1, _080110E4 @ =0x083B6410
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r5
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _080110E8 @ =0x030004DE
	movs r2, #0xb
	bl memcpy_bytes_0803F63C
	movs r0, #0x10
	bl play_song
	ldr r1, _080110EC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _080110F4
	.align 2, 0
_080110E4: .4byte 0x083B6410
_080110E8: .4byte 0x030004DE
_080110EC: .4byte 0x0300137C
_080110F0:
	adds r0, r1, #1
	strb r0, [r4]
_080110F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
