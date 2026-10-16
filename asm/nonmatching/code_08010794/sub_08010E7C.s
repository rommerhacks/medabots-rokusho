	.syntax unified

	thumb_func_start sub_08010E7C
sub_08010E7C: @ 0x08010E7C
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl setup_battle_result_sprite
	bl sub_08012468
	ldr r0, _08010EE4 @ =0x084D7DB0
	ldr r1, _08010EE8 @ =0x06016C00
	bl lz_decompress_dispatch
	ldr r1, _08010EEC @ =0x040000D4
	ldr r0, _08010EF0 @ =0x084E2F98
	str r0, [r1]
	ldr r0, _08010EF4 @ =0x05000360
	str r0, [r1, #4]
	ldr r0, _08010EF8 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r3, _08010EFC @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0x80
	movs r2, #0
	ldr r0, _08010F00 @ =0x0000C404
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x9c
	strb r2, [r0]
	adds r1, #2
	movs r0, #8
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x50
	strh r0, [r1]
	adds r1, #6
	movs r0, #0xb
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xc0
	strb r0, [r1]
	subs r1, #5
	movs r0, #0xb4
	lsls r0, r0, #7
	strh r0, [r1]
	ldr r1, _08010F04 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08010EE4: .4byte 0x084D7DB0
_08010EE8: .4byte 0x06016C00
_08010EEC: .4byte 0x040000D4
_08010EF0: .4byte 0x084E2F98
_08010EF4: .4byte 0x05000360
_08010EF8: .4byte 0x84000008
_08010EFC: .4byte 0x03002C30
_08010F00: .4byte 0x0000C404
_08010F04: .4byte 0x0300137C
	.syntax divided
