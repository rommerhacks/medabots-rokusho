	.syntax unified

	thumb_func_start sub_0802AAF8
sub_0802AAF8: @ 0x0802AAF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0802AC38 @ =0x084DF024
	ldr r1, _0802AC3C @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802AC40 @ =0x0850ED78
	ldr r1, _0802AC44 @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	ldr r4, _0802AC48 @ =0x03002C30
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r6, #0
	ldr r2, _0802AC4C @ =0xFFFFC624
	strh r2, [r0]
	adds r1, #0x1c
	adds r0, r4, r1
	strb r6, [r0]
	ldr r2, _0802AC50 @ =0x03001800
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
	ldr r2, _0802AC54 @ =0x00000842
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
	ldr r1, _0802AC58 @ =0x0000084A
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
	ldr r2, _0802AC5C @ =0x00000849
	adds r0, r4, r2
	strb r5, [r0]
	adds r1, #0x23
	adds r0, r4, r1
	movs r2, #0x1c
	mov sl, r2
	mov r1, sl
	strb r1, [r0]
	ldr r2, _0802AC60 @ =0x0000086C
	adds r0, r4, r2
	strb r6, [r0]
	ldr r1, _0802AC64 @ =0x0000086D
	adds r0, r4, r1
	strb r6, [r0]
	ldr r2, _0802AC68 @ =0x083B5F80
	mov sb, r2
	ldr r0, [r2, #0x70]
	movs r1, #0x21
	bl init_battle_sprite_entry_08040B90
	movs r1, #0x88
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r2, _0802AC4C @ =0xFFFFC624
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
	ldr r2, _0802AC6C @ =0x00000882
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
	ldr r1, _0802AC70 @ =0x0000088A
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
	ldr r2, _0802AC74 @ =0x00000889
	adds r0, r4, r2
	strb r5, [r0]
	adds r1, #0x23
	adds r0, r4, r1
	mov r2, sl
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _0802AC78 @ =0x000008AD
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
_0802AC38: .4byte 0x084DF024
_0802AC3C: .4byte 0x06014800
_0802AC40: .4byte 0x0850ED78
_0802AC44: .4byte 0x050002E0
_0802AC48: .4byte 0x03002C30
_0802AC4C: .4byte 0xFFFFC624
_0802AC50: .4byte 0x03001800
_0802AC54: .4byte 0x00000842
_0802AC58: .4byte 0x0000084A
_0802AC5C: .4byte 0x00000849
_0802AC60: .4byte 0x0000086C
_0802AC64: .4byte 0x0000086D
_0802AC68: .4byte 0x083B5F80
_0802AC6C: .4byte 0x00000882
_0802AC70: .4byte 0x0000088A
_0802AC74: .4byte 0x00000889
_0802AC78: .4byte 0x000008AD
	.syntax divided
