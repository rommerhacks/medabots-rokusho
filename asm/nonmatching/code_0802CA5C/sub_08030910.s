	.syntax unified

	thumb_func_start sub_08030910
sub_08030910: @ 0x08030910
	push {lr}
	ldr r3, _0803097C @ =0x03002C30
	adds r1, r3, #0
	adds r1, #0xc0
	movs r2, #0
	ldr r0, _08030980 @ =0x0000C004
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0xdc
	strb r2, [r0]
	ldr r1, _08030984 @ =0x03001800
	adds r1, #0x87
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	adds r2, r3, #0
	adds r2, #0xc2
	strh r0, [r2]
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	subs r0, #4
	adds r1, r3, #0
	adds r1, #0xc4
	strh r0, [r1]
	adds r1, #6
	movs r0, #6
	strb r0, [r1]
	adds r1, #1
	movs r0, #0x81
	strb r0, [r1]
	ldr r0, _08030988 @ =0x083B5F80
	ldr r0, [r0, #0x54]
	movs r1, #3
	bl init_battle_sprite_entry_08040B90
	movs r0, #7
	bl play_sound_effect
	ldr r1, _0803098C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803097C: .4byte 0x03002C30
_08030980: .4byte 0x0000C004
_08030984: .4byte 0x03001800
_08030988: .4byte 0x083B5F80
_0803098C: .4byte 0x0300137C
	.syntax divided
