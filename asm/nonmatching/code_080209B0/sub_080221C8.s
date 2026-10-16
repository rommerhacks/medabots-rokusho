	.syntax unified

	thumb_func_start sub_080221C8
sub_080221C8: @ 0x080221C8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	ldr r0, _08022280 @ =0x084D5788
	ldr r1, _08022284 @ =0x06014800
	bl lz_decompress_dispatch
	ldr r0, _08022288 @ =0x0850E6D8
	ldr r1, _0802228C @ =0x050002E0
	movs r2, #8
	bl CpuFastSet
	movs r6, #0
	ldr r2, _08022290 @ =0x03002C30
	movs r0, #0
	mov sb, r0
	ldr r3, _08022294 @ =0x03001887
	ldr r7, _08022298 @ =0x0000086B
	adds r5, r2, r7
	movs r0, #0x84
	lsls r0, r0, #4
	adds r4, r2, r0
	ldr r7, _0802229C @ =0x0000C604
	mov r8, r7
_080221FC:
	adds r1, r6, #0
	adds r1, #0x21
	mov r0, r8
	strh r0, [r4]
	mov r7, sb
	strb r7, [r4, #0x1c]
	ldrb r0, [r3]
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	adds r0, r0, r2
	ldrh r0, [r0, #2]
	strh r0, [r4, #2]
	ldrb r0, [r3]
	lsls r0, r0, #8
	adds r0, r0, r7
	adds r0, r0, r2
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r4, #4]
	movs r0, #7
	strb r0, [r4, #0xa]
	movs r0, #0xf0
	strb r0, [r4, #0xb]
	movs r0, #0x40
	strb r0, [r4, #8]
	strb r0, [r4, #9]
	mov r0, sb
	strb r0, [r5]
	lsls r0, r6, #6
	strb r0, [r5, #1]
	mov r7, sb
	strb r7, [r5, #2]
	ldr r0, _080222A0 @ =0x083B5F80
	adds r0, #0xf4
	ldr r0, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r2, [sp]
	str r3, [sp, #4]
	bl init_battle_sprite_entry_08040B90
	adds r5, #0x40
	adds r4, #0x40
	adds r6, #1
	ldr r2, [sp]
	ldr r3, [sp, #4]
	cmp r6, #3
	bls _080221FC
	movs r0, #0x5c
	bl play_sound_effect
	ldr r1, _080222A4 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022280: .4byte 0x084D5788
_08022284: .4byte 0x06014800
_08022288: .4byte 0x0850E6D8
_0802228C: .4byte 0x050002E0
_08022290: .4byte 0x03002C30
_08022294: .4byte 0x03001887
_08022298: .4byte 0x0000086B
_0802229C: .4byte 0x0000C604
_080222A0: .4byte 0x083B5F80
_080222A4: .4byte 0x03001800
	.syntax divided
