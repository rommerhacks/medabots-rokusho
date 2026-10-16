	.syntax unified

	thumb_func_start sub_08022480
sub_08022480: @ 0x08022480
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _080224A4 @ =0x03001800
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #0
	beq _080224B4
	cmp r0, #1
	beq _080224CC
	ldr r0, _080224A8 @ =0x084C9E9C
	ldr r1, _080224AC @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080224B0 @ =0x0850E138
	b _080224D6
	.align 2, 0
_080224A4: .4byte 0x03001800
_080224A8: .4byte 0x084C9E9C
_080224AC: .4byte 0x06014800
_080224B0: .4byte 0x0850E138
_080224B4:
	ldr r0, _080224C0 @ =0x084C9880
	ldr r1, _080224C4 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _080224C8 @ =0x0850E0F8
	b _080224D6
	.align 2, 0
_080224C0: .4byte 0x084C9880
_080224C4: .4byte 0x06014800
_080224C8: .4byte 0x0850E0F8
_080224CC:
	ldr r0, _08022604 @ =0x084C9B88
	ldr r1, _08022608 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802260C @ =0x0850E118
_080224D6:
	ldr r1, _08022610 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r4, _08022614 @ =0x03002C30
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r6, #0
	ldr r2, _08022618 @ =0xFFFFC624
	strh r2, [r0]
	adds r1, #0x1c
	adds r0, r4, r1
	strb r6, [r0]
	ldr r2, _0802261C @ =0x03001800
	mov r8, r2
	mov r7, r8
	adds r7, #0x87
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0, #2]
	subs r0, #0x20
	ldr r2, _08022620 @ =0x00000842
	adds r1, r4, r2
	strh r0, [r1]
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
	ldr r1, _08022624 @ =0x0000084A
	adds r0, r4, r1
	movs r2, #7
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	movs r2, #0x10
	rsbs r2, r2, #0
	strb r2, [r0]
	subs r1, #3
	adds r0, r4, r1
	movs r5, #0x80
	strb r5, [r0]
	ldr r2, _08022628 @ =0x00000849
	adds r0, r4, r2
	strb r5, [r0]
	adds r1, #0x23
	adds r0, r4, r1
	movs r2, #0x1c
	mov sl, r2
	mov r1, sl
	strb r1, [r0]
	ldr r2, _0802262C @ =0x0000086C
	adds r0, r4, r2
	strb r6, [r0]
	ldr r1, _08022630 @ =0x0000086D
	adds r0, r4, r1
	strb r6, [r0]
	ldr r2, _08022634 @ =0x083B5F80
	mov sb, r2
	ldr r0, [r2, #0x70]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	movs r1, #0x88
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r2, _08022618 @ =0xFFFFC624
	strh r2, [r0]
	adds r1, #0x1c
	adds r0, r4, r1
	strb r6, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r4
	ldrh r0, [r0, #2]
	adds r0, #0x20
	ldr r2, _08022638 @ =0x00000882
	adds r1, r4, r2
	strh r0, [r1]
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
	ldr r1, _0802263C @ =0x0000088A
	adds r0, r4, r1
	movs r2, #7
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	movs r2, #0x10
	rsbs r2, r2, #0
	strb r2, [r0]
	subs r1, #3
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _08022640 @ =0x00000889
	adds r0, r4, r2
	strb r5, [r0]
	adds r1, #0x23
	adds r0, r4, r1
	mov r2, sl
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _08022644 @ =0x000008AD
	adds r4, r4, r2
	strb r6, [r4]
	mov r1, sb
	ldr r0, [r1, #0x70]
	movs r1, #0x22
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x33
	bl play_sound_effect
	movs r2, #0xaa
	add r8, r2
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022604: .4byte 0x084C9B88
_08022608: .4byte 0x06014800
_0802260C: .4byte 0x0850E118
_08022610: .4byte 0x050002E0
_08022614: .4byte 0x03002C30
_08022618: .4byte 0xFFFFC624
_0802261C: .4byte 0x03001800
_08022620: .4byte 0x00000842
_08022624: .4byte 0x0000084A
_08022628: .4byte 0x00000849
_0802262C: .4byte 0x0000086C
_08022630: .4byte 0x0000086D
_08022634: .4byte 0x083B5F80
_08022638: .4byte 0x00000882
_0802263C: .4byte 0x0000088A
_08022640: .4byte 0x00000889
_08022644: .4byte 0x000008AD
	.syntax divided
