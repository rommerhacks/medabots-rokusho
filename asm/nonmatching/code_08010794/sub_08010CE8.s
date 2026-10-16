	.syntax unified

	thumb_func_start sub_08010CE8
sub_08010CE8: @ 0x08010CE8
	push {r4, r5, r6, lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl setup_battle_result_sprite_animation
	ldr r1, _08010D40 @ =0x083C6DE8
	ldr r6, _08010D44 @ =0x03001800
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r5, r6, r0
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r4, _08010D48 @ =0x030004DE
	adds r1, r4, #0
	movs r2, #0xe
	bl memcpy_bytes_0803F63C
	ldr r1, _08010D4C @ =0x083BB9CC
	ldr r2, _08010D50 @ =0x00000169
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	ldrb r5, [r5]
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, #0x14
	adds r1, r4, #0
	movs r2, #0xf
	bl memcpy_bytes_0803F63C
	ldr r1, _08010D54 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08010D40: .4byte 0x083C6DE8
_08010D44: .4byte 0x03001800
_08010D48: .4byte 0x030004DE
_08010D4C: .4byte 0x083BB9CC
_08010D50: .4byte 0x00000169
_08010D54: .4byte 0x0300137C
	.syntax divided
