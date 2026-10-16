	.syntax unified

	thumb_func_start sub_0802ACF4
sub_0802ACF4: @ 0x0802ACF4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0802AE38 @ =0x084DF400
	ldr r1, _0802AE3C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802AE40 @ =0x0850ED98
	ldr r1, _0802AE44 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r4, _0802AE48 @ =0x03002C30
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r6, #0
	ldr r2, _0802AE4C @ =0xFFFFC624
	strh r2, [r0]
	adds r1, #0x1c
	adds r0, r4, r1
	strb r6, [r0]
	ldr r2, _0802AE50 @ =0x03001800
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
	ldr r2, _0802AE54 @ =0x00000842
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
	ldr r1, _0802AE58 @ =0x0000084A
	adds r0, r4, r1
	movs r2, #7
	mov sl, r2
	mov r1, sl
	strb r1, [r0]
	ldr r2, _0802AE5C @ =0x0000084B
	adds r0, r4, r2
	movs r1, #0xf0
	mov sb, r1
	mov r2, sb
	strb r2, [r0]
	ldr r1, _0802AE60 @ =0x00000848
	adds r0, r4, r1
	movs r5, #0x80
	strb r5, [r0]
	ldr r2, _0802AE64 @ =0x00000849
	adds r0, r4, r2
	strb r5, [r0]
	adds r1, #0x23
	adds r0, r4, r1
	movs r2, #0x1c
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r6, [r0]
	ldr r2, _0802AE68 @ =0x0000086D
	adds r0, r4, r2
	strb r6, [r0]
	ldr r0, _0802AE6C @ =0x083B5F80
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	movs r2, #0x88
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r1, _0802AE4C @ =0xFFFFC624
	strh r1, [r0]
	adds r2, #0x1c
	adds r0, r4, r2
	strb r6, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0, #2]
	adds r0, #0x20
	subs r2, #0x1a
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
	ldr r1, _0802AE70 @ =0x0000088A
	adds r0, r4, r1
	mov r2, sl
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	mov r2, sb
	strb r2, [r0]
	subs r1, #3
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _0802AE74 @ =0x00000889
	adds r0, r4, r2
	strb r5, [r0]
	ldr r0, _0802AE78 @ =0x00000886
	adds r1, r4, r0
	ldr r0, _0802AE7C @ =0x00007901
	strh r0, [r1]
	ldr r1, _0802AE80 @ =0x000008AB
	adds r0, r4, r1
	movs r2, #0x1c
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _0802AE84 @ =0x000008AD
	adds r4, r4, r2
	strb r6, [r4]
	movs r0, #0x33
	bl play_sound_effect
	movs r0, #0xaa
	add r8, r0
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
_0802AE38: .4byte 0x084DF400
_0802AE3C: .4byte 0x06014800
_0802AE40: .4byte 0x0850ED98
_0802AE44: .4byte 0x050002E0
_0802AE48: .4byte 0x03002C30
_0802AE4C: .4byte 0xFFFFC624
_0802AE50: .4byte 0x03001800
_0802AE54: .4byte 0x00000842
_0802AE58: .4byte 0x0000084A
_0802AE5C: .4byte 0x0000084B
_0802AE60: .4byte 0x00000848
_0802AE64: .4byte 0x00000849
_0802AE68: .4byte 0x0000086D
_0802AE6C: .4byte 0x083B5F80
_0802AE70: .4byte 0x0000088A
_0802AE74: .4byte 0x00000889
_0802AE78: .4byte 0x00000886
_0802AE7C: .4byte 0x00007901
_0802AE80: .4byte 0x000008AB
_0802AE84: .4byte 0x000008AD
	.syntax divided
