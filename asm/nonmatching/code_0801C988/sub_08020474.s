	.syntax unified

	thumb_func_start sub_08020474
sub_08020474: @ 0x08020474
	push {r4, r5, lr}
	ldr r0, _080204A0 @ =0x084D073C
	ldr r1, _080204A4 @ =0x06010800
	bl lz_decompress_dispatch
	ldr r0, _080204A8 @ =0x0850E458
	ldr r1, _080204AC @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _080204B0 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080204B4
	movs r1, #0xac
	lsls r1, r1, #1
	b _080204B8
	.align 2, 0
_080204A0: .4byte 0x084D073C
_080204A4: .4byte 0x06010800
_080204A8: .4byte 0x0850E458
_080204AC: .4byte 0x050003C0
_080204B0: .4byte 0x03001800
_080204B4:
	movs r1, #0xaa
	lsls r1, r1, #1
_080204B8:
	adds r0, r2, r1
	ldrh r5, [r0]
	adds r1, #2
	adds r0, r2, r1
	ldrh r4, [r0]
	ldr r1, _08020518 @ =0x03002C30
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r2, r1, r0
	movs r3, #0
	ldr r0, _0802051C @ =0x0000C404
	strh r0, [r2]
	movs r2, #0xa7
	lsls r2, r2, #2
	adds r0, r1, r2
	strb r3, [r0]
	subs r2, #0x1a
	adds r0, r1, r2
	strh r5, [r0]
	adds r2, #2
	adds r0, r1, r2
	strh r4, [r0]
	ldr r0, _08020520 @ =0x0000028A
	adds r2, r1, r0
	movs r0, #0xe
	strb r0, [r2]
	ldr r2, _08020524 @ =0x0000028B
	adds r1, r1, r2
	movs r0, #0x80
	strb r0, [r1]
	ldr r0, _08020528 @ =0x083B5F80
	adds r0, #0x98
	ldr r0, [r0]
	movs r1, #0xa
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x2b
	bl play_sound_effect
	ldr r1, _0802052C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08020518: .4byte 0x03002C30
_0802051C: .4byte 0x0000C404
_08020520: .4byte 0x0000028A
_08020524: .4byte 0x0000028B
_08020528: .4byte 0x083B5F80
_0802052C: .4byte 0x03001800
	.syntax divided
