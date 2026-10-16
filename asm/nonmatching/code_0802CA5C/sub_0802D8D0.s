	.syntax unified

	thumb_func_start sub_0802D8D0
sub_0802D8D0: @ 0x0802D8D0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	movs r3, #0
	movs r2, #0
	movs r5, #0
	ldr r6, _0802D914 @ =0x03001800
	movs r0, #0xf8
	adds r0, r0, r6
	mov r8, r0
	ldr r0, _0802D918 @ =0x03002C30
	movs r1, #0x84
	lsls r1, r1, #4
	adds r4, r0, r1
	ldr r0, _0802D91C @ =0x000003FF
	adds r7, r0, #0
_0802D8F4:
	adds r0, r6, #0
	adds r0, #0xd2
	adds r0, r5, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802D93E
	adds r2, #1
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0802D920
	ldrh r0, [r4, #0x18]
	subs r0, #0x40
	b _0802D924
	.align 2, 0
_0802D914: .4byte 0x03001800
_0802D918: .4byte 0x03002C30
_0802D91C: .4byte 0x000003FF
_0802D920:
	ldrh r0, [r4, #0x18]
	adds r0, #0x40
_0802D924:
	ands r0, r7
	strh r0, [r4, #0x18]
	adds r0, r5, #0
	adds r0, #0x21
	str r2, [sp]
	str r3, [sp, #4]
	bl move_sprite_toward_target
	ldr r2, [sp]
	ldr r3, [sp, #4]
	cmp r0, #0
	beq _0802D93E
	adds r3, #1
_0802D93E:
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _0802D8F4
	cmp r3, r2
	bne _0802D9F4
	movs r5, #0
	ldr r0, _0802D9B4 @ =0x03002C30
	mov sb, r5
	ldr r1, _0802D9B8 @ =0x00000904
	adds r4, r0, r1
	subs r1, #0xc2
	adds r1, r1, r0
	mov r8, r1
	movs r1, #0x90
	lsls r1, r1, #4
	adds r7, r0, r1
	adds r3, r7, #0
_0802D962:
	ldr r0, _0802D9BC @ =0x03001800
	adds r0, #0xd2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _0802D9D4
	adds r0, r5, #0
	adds r0, #0x21
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	str r3, [sp, #4]
	bl clear_sprite_table_mask
	movs r2, #0
	ldr r0, _0802D9C0 @ =0x0000C404
	strh r0, [r7]
	strb r2, [r4, #0x18]
	mov r1, r8
	ldrh r0, [r1]
	strh r0, [r7, #2]
	ldrh r0, [r1, #2]
	strh r0, [r4]
	movs r0, #7
	strb r0, [r4, #6]
	movs r0, #0xe0
	strb r0, [r4, #7]
	mov r0, sb
	strh r0, [r4, #0x14]
	strb r2, [r4, #0x1f]
	ldrb r0, [r6]
	movs r1, #0x7f
	ands r1, r0
	ldr r3, [sp, #4]
	cmp r1, #1
	beq _0802D9C8
	cmp r1, #2
	beq _0802D9D0
	ldr r0, _0802D9C4 @ =0x00004E01
	strh r0, [r4, #2]
	b _0802D9D4
	.align 2, 0
_0802D9B4: .4byte 0x03002C30
_0802D9B8: .4byte 0x00000904
_0802D9BC: .4byte 0x03001800
_0802D9C0: .4byte 0x0000C404
_0802D9C4: .4byte 0x00004E01
_0802D9C8:
	ldr r0, _0802D9CC @ =0x00004E02
	b _0802D9D2
	.align 2, 0
_0802D9CC: .4byte 0x00004E02
_0802D9D0:
	ldr r0, _0802DA04 @ =0x00004E03
_0802D9D2:
	strh r0, [r3, #6]
_0802D9D4:
	adds r4, #0x40
	movs r1, #0x40
	add r8, r1
	adds r7, #0x40
	adds r3, #0x40
	adds r5, #1
	cmp r5, #2
	bls _0802D962
	movs r0, #0x6a
	bl play_sound_effect
	ldr r1, _0802DA08 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802D9F4:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802DA04: .4byte 0x00004E03
_0802DA08: .4byte 0x03001800
	.syntax divided
