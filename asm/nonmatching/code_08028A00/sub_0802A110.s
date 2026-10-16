	.syntax unified

	thumb_func_start sub_0802A110
sub_0802A110: @ 0x0802A110
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0802A228 @ =0x084DE628
	ldr r1, _0802A22C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802A230 @ =0x0850ED38
	ldr r1, _0802A234 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0802A238 @ =0x084E30B8
	ldr r1, _0802A23C @ =0x050002C0
	movs r2, #8
	bl CpuFastSet
	ldr r4, _0802A240 @ =0x03002C30
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r2, #0
	mov sl, r2
	ldr r1, _0802A244 @ =0x0000C604
	mov sb, r1
	mov r2, sb
	strh r2, [r0]
	ldr r1, _0802A248 @ =0x0000085C
	adds r0, r4, r1
	movs r2, #0
	strb r2, [r0]
	subs r1, #0x1a
	adds r0, r4, r1
	movs r2, #0x78
	mov r8, r2
	mov r1, r8
	strh r1, [r0]
	ldr r6, _0802A24C @ =0x03001800
	adds r7, r6, #0
	adds r7, #0x87
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r4
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r2, _0802A250 @ =0x00000844
	adds r1, r4, r2
	strh r0, [r1]
	ldr r0, _0802A254 @ =0x0000084A
	adds r1, r4, r0
	movs r0, #7
	strb r0, [r1]
	adds r2, #7
	adds r1, r4, r2
	movs r0, #0xf0
	strb r0, [r1]
	ldr r1, _0802A258 @ =0x00000848
	adds r0, r4, r1
	movs r5, #4
	strb r5, [r0]
	subs r2, #2
	adds r0, r4, r2
	strb r5, [r0]
	adds r1, #0x10
	adds r0, r4, r1
	mov r2, sl
	strh r2, [r0]
	ldr r0, _0802A25C @ =0x083B5F80
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	movs r2, #0x88
	lsls r2, r2, #4
	adds r0, r4, r2
	mov r1, sb
	strh r1, [r0]
	adds r2, #0x1c
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	subs r2, #0x1a
	adds r0, r4, r2
	mov r1, r8
	strh r1, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r4
	ldrh r0, [r0, #4]
	subs r0, #4
	ldr r2, _0802A260 @ =0x00000884
	adds r1, r4, r2
	strh r0, [r1]
	ldr r0, _0802A264 @ =0x0000088A
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	adds r2, #7
	adds r1, r4, r2
	movs r0, #0xe0
	strb r0, [r1]
	ldr r1, _0802A268 @ =0x00000888
	adds r0, r4, r1
	strb r5, [r0]
	subs r2, #2
	adds r0, r4, r2
	strb r5, [r0]
	adds r1, #0x10
	adds r0, r4, r1
	mov r2, sl
	strh r2, [r0]
	ldr r0, _0802A26C @ =0x00000886
	adds r4, r4, r0
	ldr r0, _0802A270 @ =0x00007604
	strh r0, [r4]
	movs r0, #0x67
	bl play_sound_effect
	adds r6, #0xaa
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A228: .4byte 0x084DE628
_0802A22C: .4byte 0x06014800
_0802A230: .4byte 0x0850ED38
_0802A234: .4byte 0x050002E0
_0802A238: .4byte 0x084E30B8
_0802A23C: .4byte 0x050002C0
_0802A240: .4byte 0x03002C30
_0802A244: .4byte 0x0000C604
_0802A248: .4byte 0x0000085C
_0802A24C: .4byte 0x03001800
_0802A250: .4byte 0x00000844
_0802A254: .4byte 0x0000084A
_0802A258: .4byte 0x00000848
_0802A25C: .4byte 0x083B5F80
_0802A260: .4byte 0x00000884
_0802A264: .4byte 0x0000088A
_0802A268: .4byte 0x00000888
_0802A26C: .4byte 0x00000886
_0802A270: .4byte 0x00007604
_0802A274:
	.byte 0x07, 0x4A, 0x08, 0x48, 0x11, 0x18, 0x08, 0x78, 0x40, 0x28, 0x11, 0xD1
	.byte 0x06, 0x48, 0x86, 0x30, 0x3C, 0x21, 0x01, 0x80, 0x05, 0x49, 0xAA, 0x31, 0x08, 0x78, 0x01, 0x30
	.byte 0x18, 0xE0, 0x00, 0x00, 0x30, 0x2C, 0x00, 0x03, 0x48, 0x08, 0x00, 0x00, 0x40, 0x04, 0x00, 0x03
	.byte 0x00, 0x18, 0x00, 0x03, 0x04, 0x30, 0x08, 0x70, 0x07, 0x48, 0x11, 0x18, 0x08, 0x78, 0x04, 0x30
	.byte 0x08, 0x70, 0x06, 0x48, 0x11, 0x18, 0x08, 0x78, 0x04, 0x30, 0x08, 0x70, 0x04, 0x48, 0x11, 0x18
	.byte 0x08, 0x78, 0x04, 0x30, 0x08, 0x70, 0x70, 0x47, 0x49, 0x08, 0x00, 0x00, 0x88, 0x08, 0x00, 0x00
	.byte 0x89, 0x08, 0x00, 0x00
	.syntax divided
