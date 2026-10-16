	.syntax unified

	thumb_func_start sub_0806A230
sub_0806A230: @ 0x0806A230
	push {r4, r5, r6, lr}
	ldr r4, _0806A2CC @ =0x03006F88
	ldr r0, [r4]
	cmp r0, #0x96
	bne _0806A23C
	b _0806A410
_0806A23C:
	cmp r0, #0x96
	bgt _0806A2D8
	cmp r0, #0
	beq _0806A2EC
	cmp r0, #0
	bge _0806A24A
	b _0806A3F6
_0806A24A:
	cmp r0, #0xd
	ble _0806A250
	b _0806A3F6
_0806A250:
	cmp r0, #6
	bge _0806A256
	b _0806A3F6
_0806A256:
	cmp r0, #6
	beq _0806A25C
	b _0806A3E8
_0806A25C:
	bl init_battle_sprite_large
	movs r0, #4
	movs r1, #7
	movs r2, #2
	movs r3, #0
	bl sprite_animation_dispatch
	ldr r6, _0806A2D0 @ =0x03002C30
	ldr r5, _0806A2D4 @ =0x03006F94
	ldrb r0, [r5, #2]
	subs r0, #1
	lsls r0, r0, #6
	adds r0, #0x38
	movs r2, #0x81
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r4, #0x18
	strh r4, [r0]
	movs r0, #3
	movs r1, #7
	movs r2, #1
	movs r3, #0
	bl sprite_animation_dispatch
	ldrb r0, [r5, #1]
	subs r0, #1
	lsls r0, r0, #6
	adds r0, #0x38
	adds r1, r6, #0
	adds r1, #0xc2
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc4
	strh r4, [r0]
	movs r0, #2
	movs r1, #7
	movs r2, #0
	movs r3, #0
	bl sprite_animation_dispatch
	ldrb r0, [r5]
	subs r0, #1
	lsls r0, r0, #6
	adds r0, #0x38
	adds r1, r6, #0
	adds r1, #0x82
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x84
	strh r4, [r0]
	b _0806A3E8
	.align 2, 0
_0806A2CC: .4byte 0x03006F88
_0806A2D0: .4byte 0x03002C30
_0806A2D4: .4byte 0x03006F94
_0806A2D8:
	cmp r0, #0x98
	bne _0806A2DE
	b _0806A490
_0806A2DE:
	cmp r0, #0x98
	bge _0806A2E4
	b _0806A450
_0806A2E4:
	cmp r0, #0x99
	bne _0806A2EA
	b _0806A49C
_0806A2EA:
	b _0806A3F6
_0806A2EC:
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl text_window_init
	bl init_battle_sprite_small
	movs r0, #0x15
	bl play_sound_effect
	ldr r0, _0806A320 @ =0x03006F94
	ldrb r0, [r0]
	cmp r0, #1
	bne _0806A32C
	movs r0, #0
	movs r1, #1
	movs r2, #0x18
	movs r3, #0x58
	bl sprite_animation_dispatch
	ldr r0, _0806A324 @ =0x030004DE
	ldr r1, _0806A328 @ =0x03002B74
	bl sub_08069EE4
	b _0806A3B6
	.align 2, 0
_0806A320: .4byte 0x03006F94
_0806A324: .4byte 0x030004DE
_0806A328: .4byte 0x03002B74
_0806A32C:
	cmp r0, #2
	bne _0806A37C
	movs r0, #0
	movs r1, #1
	movs r2, #0x58
	movs r3, #0x58
	bl sprite_animation_dispatch
	ldr r3, _0806A368 @ =0x083C1A00
	ldr r2, _0806A36C @ =0x08486160
	ldr r0, _0806A370 @ =0x03006FDC
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #2
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r1, [r0]
	ldr r0, _0806A374 @ =0x030004DE
	ldr r2, _0806A378 @ =0x083C3F38
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl sub_08069EE4
	b _0806A3B6
	.align 2, 0
_0806A368: .4byte 0x083C1A00
_0806A36C: .4byte 0x08486160
_0806A370: .4byte 0x03006FDC
_0806A374: .4byte 0x030004DE
_0806A378: .4byte 0x083C3F38
_0806A37C:
	cmp r0, #3
	bne _0806A3B6
	movs r0, #0
	movs r1, #1
	movs r2, #0x98
	movs r3, #0x58
	bl sprite_animation_dispatch
	ldr r3, _0806A3D0 @ =0x083C1A00
	ldr r2, _0806A3D4 @ =0x08486160
	ldr r0, _0806A3D8 @ =0x03006FDC
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r2, #6
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r1, [r0]
	ldr r0, _0806A3DC @ =0x030004DE
	ldr r2, _0806A3E0 @ =0x083C3F38
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl sub_08069EE4
_0806A3B6:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0806A3E4 @ =0x03006F88
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0806A4B8
	.align 2, 0
_0806A3D0: .4byte 0x083C1A00
_0806A3D4: .4byte 0x08486160
_0806A3D8: .4byte 0x03006FDC
_0806A3DC: .4byte 0x030004DE
_0806A3E0: .4byte 0x083C3F38
_0806A3E4: .4byte 0x03006F88
_0806A3E8:
	ldr r0, _0806A408 @ =0x03006F88
	ldr r0, [r0]
	subs r0, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl dma_copy_tilemap_strip
_0806A3F6:
	ldr r0, _0806A40C @ =0x084864E8
	ldr r0, [r0, #0x78]
	bl run_message
	ldr r1, _0806A408 @ =0x03006F88
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	b _0806A4B0
	.align 2, 0
_0806A408: .4byte 0x03006F88
_0806A40C: .4byte 0x084864E8
_0806A410:
	movs r0, #0x16
	bl play_sound_effect
	ldr r1, _0806A444 @ =0x04000050
	movs r0, #0x7f
	strh r0, [r1]
	bl init_battle_sprite_entry_1
	movs r0, #1
	movs r1, #6
	movs r2, #0
	movs r3, #0
	bl sprite_animation_dispatch
	ldr r1, _0806A448 @ =0x03002C30
	ldr r0, _0806A44C @ =0x03006F94
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #6
	adds r0, #0x18
	adds r1, #0x42
	strh r0, [r1]
	bl sub_0803FB0C
	b _0806A472
	.align 2, 0
_0806A444: .4byte 0x04000050
_0806A448: .4byte 0x03002C30
_0806A44C: .4byte 0x03006F94
_0806A450:
	ldr r0, _0806A47C @ =0x084864E8
	ldr r0, [r0, #0x1c]
	bl run_message
	cmp r0, #0
	beq _0806A4B0
	ldr r0, _0806A480 @ =0x03002C30
	adds r0, #0x60
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806A4B0
	bl sub_0803FB0C
	ldr r0, _0806A484 @ =0x03006F94
	ldrb r0, [r0]
	cmp r0, #1
	bne _0806A488
_0806A472:
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	b _0806A4B0
	.align 2, 0
_0806A47C: .4byte 0x084864E8
_0806A480: .4byte 0x03002C30
_0806A484: .4byte 0x03006F94
_0806A488:
	ldr r0, [r4]
	adds r0, #2
	str r0, [r4]
	b _0806A4B0
_0806A490:
	ldr r0, _0806A498 @ =0x084864E8
	ldr r0, [r0, #0x20]
	b _0806A4A0
	.align 2, 0
_0806A498: .4byte 0x084864E8
_0806A49C:
	ldr r0, _0806A4AC @ =0x084864E8
	ldr r0, [r0, #0x24]
_0806A4A0:
	bl run_message
	cmp r0, #0
	beq _0806A4B0
	movs r0, #1
	b _0806A4BA
	.align 2, 0
_0806A4AC: .4byte 0x084864E8
_0806A4B0:
	bl update_sprite_animations_tick_0806AF40
	bl update_sprite_animations_0806B334
_0806A4B8:
	movs r0, #0
_0806A4BA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.syntax divided
