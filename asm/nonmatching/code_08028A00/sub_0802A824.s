	.syntax unified

	thumb_func_start sub_0802A824
sub_0802A824: @ 0x0802A824
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	bl sub_0803836C
	ldr r4, _0802A98C @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r3, _0802A990 @ =0x03000590
	mov r8, r4
	adds r6, r1, #0
	movs r0, #1
	mov sl, r0
	ldr r1, _0802A994 @ =0x03002C30
	mov sb, r1
	movs r4, #0x88
	lsls r4, r4, #4
	add r4, sb
_0802A85C:
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r1, r0, r3
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A928
	adds r0, r1, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A928
	adds r2, r1, #0
	adds r2, #0xbd
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	mov r0, r8
	adds r0, #0xd2
	adds r0, r5, r0
	mov r2, sl
	strb r2, [r0]
	ldrb r0, [r6]
	adds r0, r0, r5
	str r3, [sp]
	bl sub_080385D0
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	ldr r3, [sp]
	adds r0, r0, r3
	adds r0, #0xd7
	movs r1, #0
	strb r1, [r0]
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r3
	adds r0, #0xbb
	movs r1, #0x14
	strb r1, [r0]
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r3
	adds r0, #0xda
	movs r2, #0
	strb r2, [r0]
	adds r1, r5, #0
	adds r1, #0x22
	movs r7, #0
	ldr r0, _0802A998 @ =0x0000C404
	strh r0, [r4]
	strb r7, [r4, #0x1c]
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r0, r0, r2
	add r0, sb
	ldrh r0, [r0, #2]
	strh r0, [r4, #2]
	ldrb r0, [r6]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r2
	add r0, sb
	ldrh r0, [r0, #4]
	subs r0, #0x10
	strh r0, [r4, #4]
	movs r0, #7
	strb r0, [r4, #0xa]
	movs r0, #0xe0
	strb r0, [r4, #0xb]
	ldr r0, _0802A99C @ =0x083B5F80
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r3, [sp]
	bl init_battle_sprite_entry_08040B90
	ldr r0, _0802A9A0 @ =0x030018F8
	ldrb r1, [r0]
	mov r0, sl
	ands r0, r1
	ldr r3, [sp]
	cmp r0, #0
	beq _0802A928
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r4]
_0802A928:
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _0802A85C
	bl iterate_bots_setup_battle_sprites
	ldr r0, _0802A9A4 @ =0x03000440
	adds r0, #0x86
	movs r1, #0
	strh r1, [r0]
	ldr r1, _0802A994 @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r3, r1, r0
	ldrh r2, [r3]
	ldr r0, _0802A9A8 @ =0x0000FDFF
	ands r0, r2
	strh r0, [r3]
	ldr r3, _0802A9AC @ =0x00000AE9
	adds r2, r1, r3
	movs r0, #1
	strb r0, [r2]
	ldr r2, _0802A9B0 @ =0x00000842
	adds r0, r1, r2
	ldrh r2, [r0]
	subs r3, #0x27
	adds r0, r1, r3
	strh r2, [r0]
	ldr r2, _0802A9B4 @ =0x00000844
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r3, #2
	adds r1, r1, r3
	strh r0, [r1]
	bl sort_active_medal_slots
	ldr r1, _0802A98C @ =0x03001800
	adds r1, #0xaa
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
_0802A98C: .4byte 0x03001800
_0802A990: .4byte 0x03000590
_0802A994: .4byte 0x03002C30
_0802A998: .4byte 0x0000C404
_0802A99C: .4byte 0x083B5F80
_0802A9A0: .4byte 0x030018F8
_0802A9A4: .4byte 0x03000440
_0802A9A8: .4byte 0x0000FDFF
_0802A9AC: .4byte 0x00000AE9
_0802A9B0: .4byte 0x00000842
_0802A9B4: .4byte 0x00000844
	.syntax divided
