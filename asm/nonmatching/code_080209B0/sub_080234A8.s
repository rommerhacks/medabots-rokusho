	.syntax unified

	thumb_func_start sub_080234A8
sub_080234A8: @ 0x080234A8
	push {r4, r5, lr}
	ldr r0, _08023534 @ =0x084D5EBC
	ldr r1, _08023538 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802353C @ =0x0850E7B8
	ldr r1, _08023540 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _08023544 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r1, r2, r0
	movs r3, #0
	ldr r0, _08023548 @ =0x0000C404
	strh r0, [r1]
	ldr r1, _0802354C @ =0x0000085C
	adds r0, r2, r1
	strb r3, [r0]
	ldr r4, _08023550 @ =0x03001800
	adds r3, r4, #0
	adds r3, #0x87
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r5, #0xba
	lsls r5, r5, #5
	adds r0, r0, r5
	adds r0, r0, r2
	ldrh r1, [r0, #2]
	ldr r5, _08023554 @ =0x00000842
	adds r0, r2, r5
	strh r1, [r0]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r3, _08023558 @ =0x00000844
	adds r1, r2, r3
	strh r0, [r1]
	adds r5, #8
	adds r1, r2, r5
	movs r0, #7
	strb r0, [r1]
	ldr r0, _0802355C @ =0x0000084B
	adds r2, r2, r0
	movs r0, #0xf0
	strb r0, [r2]
	ldr r0, _08023560 @ =0x083B5F80
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x4d
	bl play_sound_effect
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08023534: .4byte 0x084D5EBC
_08023538: .4byte 0x06014800
_0802353C: .4byte 0x0850E7B8
_08023540: .4byte 0x050002E0
_08023544: .4byte 0x03002C30
_08023548: .4byte 0x0000C404
_0802354C: .4byte 0x0000085C
_08023550: .4byte 0x03001800
_08023554: .4byte 0x00000842
_08023558: .4byte 0x00000844
_0802355C: .4byte 0x0000084B
_08023560: .4byte 0x083B5F80
	.syntax divided
