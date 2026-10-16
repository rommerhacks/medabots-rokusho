	.syntax unified

	thumb_func_start sub_08010DAC
sub_08010DAC: @ 0x08010DAC
	push {lr}
	bl update_all_battle_sprite_orbits
	bl update_scroll_movement_a
	bl setup_battle_result_sprite
	ldr r0, _08010E2C @ =0x084D7C9C
	ldr r1, _08010E30 @ =0x06012400
	bl lz_decompress_dispatch
	ldr r1, _08010E34 @ =0x040000D4
	ldr r0, _08010E38 @ =0x0850E9D8
	str r0, [r1]
	ldr r0, _08010E3C @ =0x05000340
	str r0, [r1, #4]
	ldr r0, _08010E40 @ =0x84000008
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r0, _08010E44 @ =0x03002C30
	mov ip, r0
	mov r1, ip
	adds r1, #0x40
	movs r3, #0
	ldr r0, _08010E48 @ =0x0000C624
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x5c
	strb r3, [r0]
	subs r0, #0x1a
	movs r2, #0xc0
	strh r2, [r0]
	adds r1, #4
	movs r0, #0x60
	strh r0, [r1]
	adds r1, #6
	movs r0, #0xa
	strb r0, [r1]
	mov r0, ip
	adds r0, #0x4b
	strb r2, [r0]
	subs r1, #4
	movs r0, #0xb2
	lsls r0, r0, #7
	strh r0, [r1]
	mov r0, ip
	adds r0, #0x49
	movs r1, #0x40
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	adds r0, #0x1b
	strb r3, [r0]
	adds r0, #5
	strb r3, [r0]
	movs r0, #0x2a
	bl play_sound_effect
	ldr r1, _08010E4C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08010E2C: .4byte 0x084D7C9C
_08010E30: .4byte 0x06012400
_08010E34: .4byte 0x040000D4
_08010E38: .4byte 0x0850E9D8
_08010E3C: .4byte 0x05000340
_08010E40: .4byte 0x84000008
_08010E44: .4byte 0x03002C30
_08010E48: .4byte 0x0000C624
_08010E4C: .4byte 0x0300137C
	.syntax divided
