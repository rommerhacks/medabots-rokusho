	.syntax unified

	thumb_func_start sub_0801F5BC
sub_0801F5BC: @ 0x0801F5BC
	push {r4, r5, lr}
	ldr r0, _0801F5E8 @ =0x084CA89C
	ldr r1, _0801F5EC @ =0x06010000
	bl lz_decompress_dispatch
	ldr r0, _0801F5F0 @ =0x0850E1B8
	ldr r1, _0801F5F4 @ =0x050003C0
	movs r2, #8
	bl CpuFastSet
	ldr r2, _0801F5F8 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0801F5FC
	movs r1, #0xac
	lsls r1, r1, #1
	b _0801F600
	.align 2, 0
_0801F5E8: .4byte 0x084CA89C
_0801F5EC: .4byte 0x06010000
_0801F5F0: .4byte 0x0850E1B8
_0801F5F4: .4byte 0x050003C0
_0801F5F8: .4byte 0x03001800
_0801F5FC:
	movs r1, #0xaa
	lsls r1, r1, #1
_0801F600:
	adds r0, r2, r1
	ldrh r5, [r0]
	adds r1, #2
	adds r0, r2, r1
	ldrh r4, [r0]
	ldr r1, _0801F674 @ =0x03002C30
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r2, r1, r0
	movs r3, #0
	ldr r0, _0801F678 @ =0x0000C624
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
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r2, r1, r0
	movs r0, #0x40
	strb r0, [r2]
	ldr r0, _0801F67C @ =0x00000289
	adds r2, r1, r0
	movs r0, #4
	strb r0, [r2]
	ldr r0, _0801F680 @ =0x0000028A
	adds r2, r1, r0
	movs r0, #0xe
	strb r0, [r2]
	ldr r0, _0801F684 @ =0x0000028B
	adds r2, r1, r0
	movs r0, #0xf0
	strb r0, [r2]
	ldr r0, _0801F688 @ =0x00000286
	adds r2, r1, r0
	movs r0, #0xb0
	lsls r0, r0, #5
	strh r0, [r2]
	movs r2, #0xa8
	lsls r2, r2, #2
	adds r1, r1, r2
	strb r3, [r1]
	ldr r0, _0801F68C @ =0x03001800
	adds r0, #0x51
	ldrb r0, [r0]
	cmp r0, #1
	beq _0801F6B4
	cmp r0, #1
	bgt _0801F690
	cmp r0, #0
	beq _0801F69A
	b _0801F702
	.align 2, 0
_0801F674: .4byte 0x03002C30
_0801F678: .4byte 0x0000C624
_0801F67C: .4byte 0x00000289
_0801F680: .4byte 0x0000028A
_0801F684: .4byte 0x0000028B
_0801F688: .4byte 0x00000286
_0801F68C: .4byte 0x03001800
_0801F690:
	cmp r0, #2
	beq _0801F6CC
	cmp r0, #3
	beq _0801F6F0
	b _0801F702
_0801F69A:
	ldr r0, _0801F6A8 @ =0x084CE154
	ldr r1, _0801F6AC @ =0x06010800
	bl lz_decompress_dispatch
	ldr r0, _0801F6B0 @ =0x0850E3B8
	b _0801F6D6
	.align 2, 0
_0801F6A8: .4byte 0x084CE154
_0801F6AC: .4byte 0x06010800
_0801F6B0: .4byte 0x0850E3B8
_0801F6B4:
	ldr r0, _0801F6C0 @ =0x084CE644
	ldr r1, _0801F6C4 @ =0x06010800
	bl lz_decompress_dispatch
	ldr r0, _0801F6C8 @ =0x0850E3D8
	b _0801F6D6
	.align 2, 0
_0801F6C0: .4byte 0x084CE644
_0801F6C4: .4byte 0x06010800
_0801F6C8: .4byte 0x0850E3D8
_0801F6CC:
	ldr r0, _0801F6E0 @ =0x084CEF14
	ldr r1, _0801F6E4 @ =0x06010800
	bl lz_decompress_dispatch
	ldr r0, _0801F6E8 @ =0x0850E3F8
_0801F6D6:
	ldr r1, _0801F6EC @ =0x050003A0
	movs r2, #8
	bl CpuFastSet
	b _0801F702
	.align 2, 0
_0801F6E0: .4byte 0x084CEF14
_0801F6E4: .4byte 0x06010800
_0801F6E8: .4byte 0x0850E3F8
_0801F6EC: .4byte 0x050003A0
_0801F6F0:
	ldr r0, _0801F758 @ =0x084CF340
	ldr r1, _0801F75C @ =0x06010800
	bl lz_decompress_dispatch
	ldr r0, _0801F760 @ =0x0850E418
	ldr r1, _0801F764 @ =0x050003A0
	movs r2, #8
	bl CpuFastSet
_0801F702:
	ldr r1, _0801F768 @ =0x03002C30
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r2, r1, r0
	movs r3, #0
	ldr r0, _0801F76C @ =0x0000C404
	strh r0, [r2]
	movs r2, #0xb7
	lsls r2, r2, #2
	adds r0, r1, r2
	strb r3, [r0]
	subs r2, #0x1a
	adds r0, r1, r2
	strh r5, [r0]
	adds r2, #2
	adds r0, r1, r2
	strh r4, [r0]
	ldr r0, _0801F770 @ =0x000002CA
	adds r2, r1, r0
	movs r0, #0xd
	strb r0, [r2]
	ldr r2, _0801F774 @ =0x000002CB
	adds r1, r1, r2
	movs r0, #0x80
	strb r0, [r1]
	ldr r0, _0801F778 @ =0x083B5F80
	adds r0, #0x84
	ldr r0, [r0]
	movs r1, #0xb
	bl init_battle_sprite_entry_08040B90
	movs r0, #0x2f
	bl play_sound_effect
	ldr r1, _0801F77C @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F758: .4byte 0x084CF340
_0801F75C: .4byte 0x06010800
_0801F760: .4byte 0x0850E418
_0801F764: .4byte 0x050003A0
_0801F768: .4byte 0x03002C30
_0801F76C: .4byte 0x0000C404
_0801F770: .4byte 0x000002CA
_0801F774: .4byte 0x000002CB
_0801F778: .4byte 0x083B5F80
_0801F77C: .4byte 0x03001800
	.syntax divided
