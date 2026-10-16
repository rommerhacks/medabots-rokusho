	.syntax unified

	thumb_func_start sub_0802F6CC
sub_0802F6CC: @ 0x0802F6CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0802F790 @ =0x084E1884
	ldr r1, _0802F794 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802F798 @ =0x0850EEF8
	ldr r1, _0802F79C @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0802F7A0 @ =0x084E30B8
	ldr r1, _0802F7A4 @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	movs r6, #0
	ldr r7, _0802F7A8 @ =0x03001800
	mov sl, r6
	movs r0, #0xf8
	adds r0, r0, r7
	mov sb, r0
	ldr r2, _0802F7AC @ =0x0000C404
	mov r8, r2
_0802F702:
	adds r0, r7, #0
	adds r0, #0xd2
	adds r0, r6, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802F76A
	ldr r2, _0802F7B0 @ =0x03002C30
	adds r1, r6, #0
	adds r1, #0x21
	lsls r0, r1, #6
	adds r4, r0, r2
	movs r5, #0
	mov r0, r8
	strh r0, [r4]
	strb r5, [r4, #0x1c]
	movs r0, #0x78
	strh r0, [r4, #2]
	movs r2, #0xf0
	strh r2, [r4, #4]
	movs r0, #7
	strb r0, [r4, #0xa]
	strb r2, [r4, #0xb]
	adds r2, r4, #0
	adds r2, #0x24
	movs r0, #4
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x25
	strb r5, [r0]
	mov r2, sl
	strh r2, [r4, #0x30]
	ldr r0, _0802F7B4 @ =0x083B5F80
	movs r2, #0xda
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl init_battle_sprite_entry_08040B90
	mov r0, sb
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802F76A
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
_0802F76A:
	adds r6, #1
	cmp r6, #2
	bls _0802F702
	movs r0, #0x61
	bl play_sound_effect
	ldr r1, _0802F7A8 @ =0x03001800
	adds r1, #0xaa
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
_0802F790: .4byte 0x084E1884
_0802F794: .4byte 0x06014800
_0802F798: .4byte 0x0850EEF8
_0802F79C: .4byte 0x050002E0
_0802F7A0: .4byte 0x084E30B8
_0802F7A4: .4byte 0x050002C0
_0802F7A8: .4byte 0x03001800
_0802F7AC: .4byte 0x0000C404
_0802F7B0: .4byte 0x03002C30
_0802F7B4: .4byte 0x083B5F80
	.syntax divided
