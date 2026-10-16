	.syntax unified

	thumb_func_start sub_0802AECC
sub_0802AECC: @ 0x0802AECC
	push {r4, r5, lr}
	ldr r2, _0802AF48 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r3, #0
	ldr r0, _0802AF4C @ =0x0000CC04
	strh r0, [r1]
	ldr r1, _0802AF50 @ =0x0000085C
	adds r0, r2, r1
	strb r3, [r0]
	ldr r4, _0802AF54 @ =0x03001800
	movs r5, #0x87
	adds r5, r5, r4
	mov ip, r5
	ldrb r0, [r5]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	ldr r5, _0802AF58 @ =0x00000842
	adds r0, r2, r5
	strh r1, [r0]
	mov r1, ip
	ldrb r0, [r1]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r5, _0802AF5C @ =0x00000844
	adds r1, r2, r5
	strh r0, [r1]
	ldr r0, _0802AF60 @ =0x0000084A
	adds r1, r2, r0
	movs r0, #7
	strb r0, [r1]
	ldr r1, _0802AF64 @ =0x0000084B
	adds r2, r2, r1
	strb r3, [r2]
	ldr r0, _0802AF68 @ =0x083B5F80
	movs r5, #0xca
	lsls r5, r5, #1
	adds r0, r0, r5
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x71
	bl play_sound_effect
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802AF48: .4byte 0x03002C30
_0802AF4C: .4byte 0x0000CC04
_0802AF50: .4byte 0x0000085C
_0802AF54: .4byte 0x03001800
_0802AF58: .4byte 0x00000842
_0802AF5C: .4byte 0x00000844
_0802AF60: .4byte 0x0000084A
_0802AF64: .4byte 0x0000084B
_0802AF68: .4byte 0x083B5F80
	.syntax divided
