	.syntax unified

	thumb_func_start sub_080264E4
sub_080264E4: @ 0x080264E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _080265E8 @ =0x084D7528
	ldr r1, _080265EC @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080265F0 @ =0x0850E998
	ldr r1, _080265F4 @ =0x050002C0
	movs r2, #0x10
	bl CpuFastSet
	ldr r4, _080265F8 @ =0x03002C30
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r2, #0
	mov r8, r2
	movs r1, #0
	mov sb, r1
	ldr r6, _080265FC @ =0x0000C404
	strh r6, [r0]
	ldr r2, _08026600 @ =0x0000085C
	adds r0, r4, r2
	mov r1, r8
	strb r1, [r0]
	ldr r5, _08026604 @ =0x03001800
	adds r7, r5, #0
	adds r7, #0x87
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r4
	ldrh r1, [r0, #2]
	ldr r2, _08026608 @ =0x00000842
	adds r0, r4, r2
	strh r1, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0, #4]
	subs r0, #4
	adds r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	ldr r0, _0802660C @ =0x0000084A
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	adds r2, #7
	adds r1, r4, r2
	movs r0, #0xe0
	strb r0, [r1]
	ldr r0, _08026610 @ =0x083B5F80
	mov sl, r0
	movs r0, #0x96
	lsls r0, r0, #1
	add r0, sl
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	movs r1, #0x88
	lsls r1, r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	ldr r2, _08026614 @ =0x0000089C
	adds r0, r4, r2
	mov r1, r8
	strb r1, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r4
	ldrh r1, [r0, #2]
	ldr r2, _08026618 @ =0x00000882
	adds r0, r4, r2
	strh r1, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0, #4]
	subs r0, #6
	adds r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	ldr r0, _0802661C @ =0x0000088A
	adds r1, r4, r0
	movs r0, #7
	strb r0, [r1]
	ldr r1, _08026620 @ =0x0000088B
	adds r4, r4, r1
	movs r0, #0xf0
	strb r0, [r4]
	adds r0, #0x40
	add r0, sl
	ldr r0, [r0]
	movs r1, #0x22
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x5e
	bl play_sound_effect
	ldr r0, _08026624 @ =0x03000440
	adds r0, #0x86
	mov r2, sb
	strh r2, [r0]
	adds r5, #0xaa
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080265E8: .4byte 0x084D7528
_080265EC: .4byte 0x06014800
_080265F0: .4byte 0x0850E998
_080265F4: .4byte 0x050002C0
_080265F8: .4byte 0x03002C30
_080265FC: .4byte 0x0000C404
_08026600: .4byte 0x0000085C
_08026604: .4byte 0x03001800
_08026608: .4byte 0x00000842
_0802660C: .4byte 0x0000084A
_08026610: .4byte 0x083B5F80
_08026614: .4byte 0x0000089C
_08026618: .4byte 0x00000882
_0802661C: .4byte 0x0000088A
_08026620: .4byte 0x0000088B
_08026624: .4byte 0x03000440
	.syntax divided
