	.syntax unified

	thumb_func_start sub_0802EC4C
sub_0802EC4C: @ 0x0802EC4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0802ED10 @ =0x084D6F88
	ldr r1, _0802ED14 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _0802ED18 @ =0x0850E938
	ldr r1, _0802ED1C @ =0x050002E0
	movs r2, #0x10
	bl CpuFastSet
	movs r5, #0
	ldr r6, _0802ED20 @ =0x03001800
	ldr r7, _0802ED24 @ =0x03002C30
	mov sl, r5
	adds r3, r6, #0
	adds r3, #0x60
	movs r0, #0x84
	lsls r0, r0, #4
	adds r4, r7, r0
	ldr r1, _0802ED28 @ =0x030004C4
	mov sb, r1
_0802EC80:
	movs r2, #0xd2
	adds r2, r2, r6
	mov r8, r2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802ECE8
	adds r1, r5, #0
	adds r1, #0x21
	movs r2, #0
	ldr r0, _0802ED2C @ =0x0000C624
	strh r0, [r4]
	strb r2, [r4, #0x1c]
	ldrb r0, [r3]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	adds r0, r0, r7
	ldrh r0, [r0, #2]
	strh r0, [r4, #2]
	ldrb r0, [r3]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, r0, r7
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r4, #4]
	movs r0, #0x80
	strb r0, [r4, #8]
	strb r0, [r4, #9]
	mov r0, sl
	strh r0, [r4, #0x18]
	movs r0, #7
	strb r0, [r4, #0xa]
	movs r0, #0xe0
	strb r0, [r4, #0xb]
	movs r2, #0x48
	mov r0, sb
	strb r2, [r0]
	ldr r0, _0802ED30 @ =0x083B5F80
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r3, [sp]
	bl init_battle_sprite_entry_08040B90
	ldr r3, [sp]
_0802ECE8:
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _0802EC80
	movs r0, #0x6a
	bl play_sound_effect
	mov r1, r8
	subs r1, #0x28
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802ED10: .4byte 0x084D6F88
_0802ED14: .4byte 0x06014800
_0802ED18: .4byte 0x0850E938
_0802ED1C: .4byte 0x050002E0
_0802ED20: .4byte 0x03001800
_0802ED24: .4byte 0x03002C30
_0802ED28: .4byte 0x030004C4
_0802ED2C: .4byte 0x0000C624
_0802ED30: .4byte 0x083B5F80
	.syntax divided
