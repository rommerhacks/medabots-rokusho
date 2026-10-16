	.syntax unified

	thumb_func_start sub_080277DC
sub_080277DC: @ 0x080277DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08027894 @ =0x084CC9A8
	ldr r1, _08027898 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802789C @ =0x0850E338
	ldr r1, _080278A0 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	movs r6, #0
	ldr r7, _080278A4 @ =0x03001800
	ldr r0, _080278A8 @ =0x03002C30
	mov r8, r0
	movs r5, #0x84
	lsls r5, r5, #4
	add r5, r8
	movs r0, #0x7f
	mov sl, r0
_0802780A:
	movs r0, #0xd2
	adds r0, r0, r7
	mov sb, r0
	adds r4, r6, r0
	ldrb r1, [r4]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08027872
	adds r1, r6, #0
	adds r1, #0x21
	movs r2, #0
	ldr r0, _080278AC @ =0x0000C004
	strh r0, [r5]
	strb r2, [r5, #0x1c]
	ldr r0, _080278B0 @ =0x03001860
	ldrb r2, [r0]
	adds r2, r2, r6
	lsls r2, r2, #2
	ldrb r3, [r4]
	mov r0, sl
	ands r0, r3
	adds r0, #0x5a
	adds r2, r2, r0
	lsls r2, r2, #6
	add r2, r8
	ldrh r0, [r2, #2]
	strh r0, [r5, #2]
	ldr r0, _080278B0 @ =0x03001860
	ldrb r2, [r0]
	adds r2, r2, r6
	lsls r2, r2, #2
	ldrb r3, [r4]
	mov r0, sl
	ands r0, r3
	adds r0, #0x5a
	adds r2, r2, r0
	lsls r2, r2, #6
	add r2, r8
	ldrh r0, [r2, #4]
	strh r0, [r5, #4]
	movs r0, #7
	strb r0, [r5, #0xa]
	movs r0, #0xf0
	strb r0, [r5, #0xb]
	ldr r0, _080278B4 @ =0x083B5F80
	adds r0, #0x88
	ldr r0, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
_08027872:
	adds r5, #0x40
	adds r6, #1
	cmp r6, #2
	bls _0802780A
	mov r1, sb
	subs r1, #0x28
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
_08027894: .4byte 0x084CC9A8
_08027898: .4byte 0x06014800
_0802789C: .4byte 0x0850E338
_080278A0: .4byte 0x050002E0
_080278A4: .4byte 0x03001800
_080278A8: .4byte 0x03002C30
_080278AC: .4byte 0x0000C004
_080278B0: .4byte 0x03001860
_080278B4: .4byte 0x083B5F80
	.syntax divided
