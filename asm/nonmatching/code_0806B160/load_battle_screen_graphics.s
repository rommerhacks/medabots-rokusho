	.syntax unified

	thumb_func_start load_battle_screen_graphics
load_battle_screen_graphics: @ 0x0806B68C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	ldr r0, _0806B8E8 @ =0x087B3B30
	ldr r1, _0806B8EC @ =0x06004000
	bl LZ77UnCompVram
	ldr r0, _0806B8F0 @ =0x087B50AC
	ldr r1, _0806B8F4 @ =0x06000800
	bl LZ77UnCompVram
	ldr r0, _0806B8F8 @ =0x087B5214
	ldr r1, _0806B8FC @ =0x06001000
	bl LZ77UnCompVram
	ldr r0, _0806B900 @ =0x087B52E4
	ldr r1, _0806B904 @ =0x06001800
	bl LZ77UnCompVram
	ldr r4, _0806B908 @ =0x040000D4
	ldr r0, _0806B90C @ =0x087B551C
	str r0, [r4]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r4, #4]
	ldr r0, _0806B910 @ =0x80000050
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _0806B914 @ =0x0400000A
	ldr r2, _0806B918 @ =0x00000105
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	ldr r3, _0806B91C @ =0x00000206
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	ldr r6, _0806B920 @ =0x00000307
	adds r0, r6, #0
	strh r0, [r1]
	ldr r0, _0806B924 @ =0x087AA19C
	ldr r1, _0806B928 @ =0x06010000
	bl LZ77UnCompVram
	ldr r0, _0806B92C @ =0x0807C0A0
	str r0, [r4]
	ldr r0, _0806B930 @ =0x05000200
	str r0, [r4, #4]
	ldr r0, _0806B934 @ =0x800000F0
	str r0, [r4, #8]
	ldr r0, [r4, #8]
	ldr r1, _0806B938 @ =0x0000CF20
	movs r5, #3
	str r5, [sp]
	movs r0, #0x1e
	movs r2, #0
	movs r3, #0
	bl init_battle_sprite_entry_08048818
	ldr r4, _0806B93C @ =0x03002C30
	ldr r1, _0806B940 @ =0x00000782
	adds r0, r4, r1
	movs r3, #0
	movs r2, #0
	movs r6, #0x78
	mov r8, r6
	mov r1, r8
	strh r1, [r0]
	ldr r6, _0806B944 @ =0x00000784
	adds r1, r4, r6
	movs r0, #0x80
	strh r0, [r1]
	movs r1, #0xf1
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0x40
	strb r1, [r0]
	adds r6, #5
	adds r0, r4, r6
	strb r1, [r0]
	movs r1, #0xf3
	lsls r1, r1, #3
	adds r0, r4, r1
	strh r2, [r0]
	ldr r0, _0806B948 @ =0x03001800
	adds r0, #0x41
	strb r3, [r0]
	movs r2, #0xf4
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r5, [r0]
	adds r6, #0x18
	adds r0, r4, r6
	strb r3, [r0]
	movs r6, #0xcc
	lsls r6, r6, #8
	str r5, [sp]
	movs r0, #0x20
	adds r1, r6, #0
	movs r2, #7
	movs r3, #1
	bl init_battle_sprite_entry_08048818
	ldr r1, _0806B94C @ =0x00000802
	adds r0, r4, r1
	mov r2, r8
	strh r2, [r0]
	ldr r3, _0806B950 @ =0x00000804
	adds r0, r4, r3
	movs r1, #0x10
	mov r8, r1
	mov r2, r8
	strh r2, [r0]
	str r5, [sp]
	movs r0, #0x1f
	adds r1, r6, #0
	movs r2, #0x10
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	ldr r3, _0806B954 @ =0x000007C4
	adds r1, r4, r3
	movs r0, #0xc8
	strh r0, [r1]
	movs r1, #0xc4
	lsls r1, r1, #8
	str r5, [sp]
	movs r0, #0xa
	movs r2, #0x10
	movs r3, #2
	bl init_battle_sprite_entry_08048818
	ldr r6, _0806B958 @ =0x00000282
	adds r0, r4, r6
	mov r1, r8
	strh r1, [r0]
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0x30
	strh r0, [r1]
	movs r5, #0
	ldr r3, _0806B95C @ =0x000002C2
	adds r4, r4, r3
	movs r7, #0x18
	movs r6, #0xb0
	lsls r6, r6, #0x14
_0806B7B6:
	lsrs r0, r6, #0x18
	movs r1, #3
	mov r8, r1
	str r1, [sp]
	movs r1, #0xc4
	lsls r1, r1, #8
	movs r2, #0x21
	movs r3, #8
	bl init_battle_sprite_entry_08048818
	strh r7, [r4]
	movs r0, #0x28
	strh r0, [r4, #2]
	adds r4, #0x40
	adds r7, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x11
	adds r6, r6, r2
	adds r5, #1
	cmp r5, #1
	ble _0806B7B6
	movs r1, #0xc8
	lsls r1, r1, #8
	mov r3, r8
	str r3, [sp]
	movs r0, #0x39
	movs r2, #0x2b
	movs r3, #9
	bl init_battle_sprite_entry_08048818
	ldr r1, _0806B93C @ =0x03002C30
	ldr r6, _0806B960 @ =0x00000E42
	adds r2, r1, r6
	movs r0, #0x78
	strh r0, [r2]
	ldr r0, _0806B964 @ =0x00000E44
	adds r2, r1, r0
	movs r0, #0x98
	strh r0, [r2]
	movs r5, #0
	ldr r2, _0806B968 @ =0x00000342
	adds r4, r1, r2
	movs r7, #8
	movs r6, #0xd0
	lsls r6, r6, #0x14
_0806B810:
	lsrs r0, r6, #0x18
	movs r3, #3
	mov sb, r3
	str r3, [sp]
	movs r1, #0xc4
	lsls r1, r1, #8
	movs r2, #0x18
	movs r3, #5
	bl init_battle_sprite_entry_08048818
	strh r7, [r4]
	movs r0, #0x78
	strh r0, [r4, #2]
	adds r4, #0x40
	adds r7, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r6, r6, r0
	adds r5, #1
	cmp r5, #2
	ble _0806B810
	movs r5, #0xc4
	lsls r5, r5, #8
	mov r1, sb
	str r1, [sp]
	movs r0, #0x10
	adds r1, r5, #0
	movs r2, #0x1e
	movs r3, #7
	bl init_battle_sprite_entry_08048818
	ldr r4, _0806B93C @ =0x03002C30
	ldr r2, _0806B96C @ =0x00000402
	adds r0, r4, r2
	movs r3, #0xb8
	mov r8, r3
	mov r6, r8
	strh r6, [r0]
	ldr r0, _0806B970 @ =0x00000404
	adds r1, r4, r0
	movs r0, #0x68
	strh r0, [r1]
	mov r1, sb
	str r1, [sp]
	movs r0, #0x11
	adds r1, r5, #0
	movs r2, #0x1a
	movs r3, #6
	bl init_battle_sprite_entry_08048818
	ldr r2, _0806B974 @ =0x00000442
	adds r0, r4, r2
	strh r6, [r0]
	ldr r3, _0806B978 @ =0x00000444
	adds r0, r4, r3
	movs r6, #0x58
	strh r6, [r0]
	mov r0, sb
	str r0, [sp]
	movs r0, #0x12
	adds r1, r5, #0
	movs r2, #0x1c
	movs r3, #6
	bl init_battle_sprite_entry_08048818
	ldr r2, _0806B97C @ =0x00000482
	adds r1, r4, r2
	movs r0, #0xd8
	strh r0, [r1]
	ldr r3, _0806B980 @ =0x00000484
	adds r0, r4, r3
	strh r6, [r0]
	mov r6, sb
	str r6, [sp]
	movs r0, #0x13
	adds r1, r5, #0
	movs r2, #0x19
	movs r3, #6
	bl init_battle_sprite_entry_08048818
	ldr r1, _0806B984 @ =0x000004C2
	adds r0, r4, r1
	mov r2, r8
	strh r2, [r0]
	ldr r3, _0806B988 @ =0x000004C4
	adds r4, r4, r3
	movs r0, #0xc8
	strh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r6, #0xf0
	lsls r6, r6, #5
	adds r1, r6, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _0806B98C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806B8E8: .4byte 0x087B3B30
_0806B8EC: .4byte 0x06004000
_0806B8F0: .4byte 0x087B50AC
_0806B8F4: .4byte 0x06000800
_0806B8F8: .4byte 0x087B5214
_0806B8FC: .4byte 0x06001000
_0806B900: .4byte 0x087B52E4
_0806B904: .4byte 0x06001800
_0806B908: .4byte 0x040000D4
_0806B90C: .4byte 0x087B551C
_0806B910: .4byte 0x80000050
_0806B914: .4byte 0x0400000A
_0806B918: .4byte 0x00000105
_0806B91C: .4byte 0x00000206
_0806B920: .4byte 0x00000307
_0806B924: .4byte 0x087AA19C
_0806B928: .4byte 0x06010000
_0806B92C: .4byte 0x0807C0A0
_0806B930: .4byte 0x05000200
_0806B934: .4byte 0x800000F0
_0806B938: .4byte 0x0000CF20
_0806B93C: .4byte 0x03002C30
_0806B940: .4byte 0x00000782
_0806B944: .4byte 0x00000784
_0806B948: .4byte 0x03001800
_0806B94C: .4byte 0x00000802
_0806B950: .4byte 0x00000804
_0806B954: .4byte 0x000007C4
_0806B958: .4byte 0x00000282
_0806B95C: .4byte 0x000002C2
_0806B960: .4byte 0x00000E42
_0806B964: .4byte 0x00000E44
_0806B968: .4byte 0x00000342
_0806B96C: .4byte 0x00000402
_0806B970: .4byte 0x00000404
_0806B974: .4byte 0x00000442
_0806B978: .4byte 0x00000444
_0806B97C: .4byte 0x00000482
_0806B980: .4byte 0x00000484
_0806B984: .4byte 0x000004C2
_0806B988: .4byte 0x000004C4
_0806B98C: .4byte 0x0300137C
	.syntax divided
