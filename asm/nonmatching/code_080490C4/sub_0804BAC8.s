	.syntax unified

	thumb_func_start sub_0804BAC8
sub_0804BAC8: @ 0x0804BAC8
	push {r4, r5, r6, lr}
	movs r0, #4
	bl read_map_script_bytes
	ldr r1, _0804BB3C @ =0x03002B64
	movs r0, #0
	strb r0, [r1]
	ldr r6, _0804BB40 @ =0x030063F0
	adds r1, r6, #0
	adds r1, #0x10
	adds r0, r6, #0
	movs r2, #8
	bl memcpy_u8
	adds r0, r6, #0
	movs r1, #8
	bl sub_080496C8
	ldr r4, _0804BB44 @ =0x03002C30
	ldr r1, _0804BB48 @ =0x00000BE8
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0804BB4C @ =0x00000BE6
	adds r2, r4, r3
	strb r1, [r2]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x4f
	movs r5, #1
	strb r5, [r0]
	adds r0, #0x35
	ldrb r2, [r2]
	adds r0, r0, r2
	ldrb r1, [r0]
	ldr r2, _0804BB50 @ =0x083D28B0
	adds r0, r6, #0
	adds r0, #0x4c
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r2, [r0]
	movs r0, #0x2f
	bl setup_battle_sprite_terrain
	movs r0, #0xbe
	lsls r0, r0, #4
	adds r4, r4, r0
	ldrb r0, [r4]
	bl field_set_player_facing
	adds r0, r6, #0
	adds r0, #0x79
	strb r5, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804BB3C: .4byte 0x03002B64
_0804BB40: .4byte 0x030063F0
_0804BB44: .4byte 0x03002C30
_0804BB48: .4byte 0x00000BE8
_0804BB4C: .4byte 0x00000BE6
_0804BB50: .4byte 0x083D28B0
	.syntax divided
