	.syntax unified

	thumb_func_start sub_080200A8
sub_080200A8: @ 0x080200A8
	push {r4, r5, r6, r7, lr}
	ldr r0, _080200E4 @ =0x084CA1A4
	ldr r1, _080200E8 @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _080200EC @ =0x0850E158
	ldr r1, _080200F0 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _080200F4 @ =0x084D1074
	ldr r1, _080200F8 @ =0x06010800
	bl lz_decompress_dispatch
	ldr r0, _080200FC @ =0x0850E478
	ldr r1, _08020100 @ =0x050003A0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _08020104 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08020108
	movs r1, #0xac
	lsls r1, r1, #1
	b _0802010C
	.align 2, 0
_080200E4: .4byte 0x084CA1A4
_080200E8: .4byte 0x06010000
_080200EC: .4byte 0x0850E158
_080200F0: .4byte 0x050003C0
_080200F4: .4byte 0x084D1074
_080200F8: .4byte 0x06010800
_080200FC: .4byte 0x0850E478
_08020100: .4byte 0x050003A0
_08020104: .4byte 0x03001800
_08020108:
	movs r1, #0xaa
	lsls r1, r1, #1
_0802010C:
	adds r0, r2, r1
	ldrh r7, [r0]
	adds r1, #2
	adds r0, r2, r1
	ldrh r6, [r0]
	ldr r1, _080201B0 @ =0x03002C30
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r3, #0
	ldr r5, _080201B4 @ =0x0000C404
	strh r5, [r0]
	adds r2, #0x1c
	adds r0, r1, r2
	strb r3, [r0]
	subs r2, #0x1a
	adds r0, r1, r2
	strh r7, [r0]
	adds r2, #2
	adds r0, r1, r2
	strh r6, [r0]
	ldr r0, _080201B8 @ =0x0000028A
	adds r2, r1, r0
	movs r0, #0xe
	strb r0, [r2]
	ldr r2, _080201BC @ =0x0000028B
	adds r0, r1, r2
	movs r4, #0x80
	strb r4, [r0]
	ldr r0, _080201C0 @ =0x00000286
	adds r2, r1, r0
	movs r0, #0x98
	lsls r0, r0, #5
	strh r0, [r2]
	ldr r2, _080201C4 @ =0x000002AB
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, #0x14
	adds r0, r1, r2
	strh r5, [r0]
	adds r2, #0x1c
	adds r0, r1, r2
	strb r3, [r0]
	subs r2, #0x1a
	adds r0, r1, r2
	strh r7, [r0]
	adds r2, #2
	adds r0, r1, r2
	strh r6, [r0]
	ldr r0, _080201C8 @ =0x000002CA
	adds r2, r1, r0
	movs r0, #0xd
	strb r0, [r2]
	ldr r2, _080201CC @ =0x000002CB
	adds r0, r1, r2
	strb r4, [r0]
	ldr r0, _080201D0 @ =0x000002C6
	adds r1, r1, r0
	movs r0, #0xb0
	lsls r0, r0, #6
	strh r0, [r1]
	ldr r0, _080201D4 @ =0x083B5F80
	adds r0, #0xdc
	ldr r0, [r0]
	movs r1, #0xb
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x53
	bl play_sound_effect
	ldr r1, _080201D8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080201B0: .4byte 0x03002C30
_080201B4: .4byte 0x0000C404
_080201B8: .4byte 0x0000028A
_080201BC: .4byte 0x0000028B
_080201C0: .4byte 0x00000286
_080201C4: .4byte 0x000002AB
_080201C8: .4byte 0x000002CA
_080201CC: .4byte 0x000002CB
_080201D0: .4byte 0x000002C6
_080201D4: .4byte 0x083B5F80
_080201D8: .4byte 0x03001800
	.syntax divided
