	.syntax unified

	thumb_func_start sub_0802CE4C
sub_0802CE4C: @ 0x0802CE4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r6, #0
	ldr r0, _0802CF8C @ =0x03001800
	mov sl, r0
	ldr r7, _0802CF90 @ =0x03002C30
	mov sb, r6
	movs r1, #0x60
	add r1, sl
	mov r8, r1
	ldr r2, _0802CF94 @ =0x00000863
	adds r2, r7, r2
	str r2, [sp]
_0802CE6E:
	ldr r1, _0802CF98 @ =0x030018D2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802CF60
	mov r0, sb
	ldr r2, [sp]
	strb r0, [r2]
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r0, r6
	lsls r0, r0, #8
	movs r2, #0xb4
	lsls r2, r2, #5
	adds r1, r7, r2
	adds r0, r0, r1
	lsls r4, r6, #2
	lsls r5, r6, #8
	movs r2, #0x90
	lsls r2, r2, #4
	adds r1, r7, r2
	adds r1, r5, r1
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r0, r6
	lsls r0, r0, #8
	movs r2, #0xb6
	lsls r2, r2, #5
	adds r1, r7, r2
	adds r0, r0, r1
	movs r2, #0x94
	lsls r2, r2, #4
	adds r1, r7, r2
	adds r1, r5, r1
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r0, r6
	lsls r0, r0, #8
	movs r2, #0xb8
	lsls r2, r2, #5
	adds r1, r7, r2
	adds r0, r0, r1
	movs r2, #0x98
	lsls r2, r2, #4
	adds r1, r7, r2
	adds r1, r5, r1
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r0, r6
	lsls r0, r0, #8
	movs r2, #0xba
	lsls r2, r2, #5
	adds r1, r7, r2
	adds r0, r0, r1
	movs r2, #0x9c
	lsls r2, r2, #4
	adds r1, r7, r2
	adds r5, r5, r1
	adds r1, r5, #0
	movs r2, #0x40
	bl memcpy_bytes_0803F63C
	adds r4, #0x24
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #4
	bl clear_sprite_table_mask
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r0, r6
	lsls r0, r0, #8
	adds r0, r0, r7
	ldr r2, _0802CF9C @ =0x000016A3
	adds r0, r0, r2
	mov r1, sb
	strb r1, [r0]
	mov r2, r8
	ldrb r0, [r2]
	adds r0, r0, r6
	lsls r0, r0, #8
	adds r0, r0, r7
	ldr r1, _0802CFA0 @ =0x000016E3
	adds r0, r0, r1
	mov r2, sb
	strb r2, [r0]
	mov r1, r8
	ldrb r0, [r1]
	adds r0, r0, r6
	lsls r0, r0, #8
	adds r0, r0, r7
	ldr r2, _0802CFA4 @ =0x00001723
	adds r0, r0, r2
	mov r1, sb
	strb r1, [r0]
	mov r2, r8
	ldrb r0, [r2]
	adds r0, r0, r6
	lsls r0, r0, #8
	adds r0, r0, r7
	ldr r1, _0802CFA8 @ =0x00001763
	adds r0, r0, r1
	mov r2, sb
	strb r2, [r0]
	adds r0, r6, #0
	adds r0, #0x72
	mov r1, r8
	ldrb r1, [r1]
	adds r0, r0, r1
	bl sub_08035694
_0802CF60:
	ldr r2, [sp]
	adds r2, #0x40
	str r2, [sp]
	adds r6, #1
	cmp r6, #2
	bls _0802CE6E
	movs r0, #0x34
	bl play_sound_effect
	ldr r1, _0802CF98 @ =0x030018D2
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
_0802CF8C: .4byte 0x03001800
_0802CF90: .4byte 0x03002C30
_0802CF94: .4byte 0x00000863
_0802CF98: .4byte 0x030018D2
_0802CF9C: .4byte 0x000016A3
_0802CFA0: .4byte 0x000016E3
_0802CFA4: .4byte 0x00001723
_0802CFA8: .4byte 0x00001763
	.syntax divided
