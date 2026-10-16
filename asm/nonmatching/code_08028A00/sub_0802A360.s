	.syntax unified

	thumb_func_start sub_0802A360
sub_0802A360: @ 0x0802A360
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	bl sub_0803836C
	ldr r4, _0802A430 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	adds r3, r1, #0
	ldr r6, _0802A434 @ =0x030034B0
	ldr r0, _0802A438 @ =0xFFFFF780
	adds r0, r0, r6
	mov r8, r0
	adds r4, #0xd2
	mov sl, r4
	adds r7, r6, #0
	adds r7, #0x63
	adds r4, r6, #0
	adds r4, #0x64
	movs r1, #0
	mov sb, r1
_0802A39E:
	ldrb r0, [r3]
	adds r0, r0, r5
	lsls r0, r0, #8
	ldr r2, _0802A43C @ =0x03000590
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A402
	adds r0, r1, #0
	adds r0, #0x59
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802A402
	lsls r1, r5, #6
	adds r0, r6, #0
	adds r0, #0x40
	adds r1, r1, r0
	adds r0, r6, #0
	movs r2, #0x40
	str r3, [sp]
	bl memcpy_bytes_0803F63C
	ldr r3, [sp]
	ldrb r0, [r3]
	adds r0, r0, r5
	lsls r0, r0, #8
	movs r1, #0xba
	lsls r1, r1, #5
	adds r0, r0, r1
	add r0, r8
	ldrh r0, [r0, #2]
	strh r0, [r4, #0xc]
	ldrb r0, [r3]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r0, r0, r1
	add r0, r8
	ldrh r0, [r0, #4]
	subs r0, #4
	strh r0, [r4, #0xe]
	movs r0, #3
	strb r0, [r4]
	mov r2, sb
	strb r2, [r7]
	mov r0, sl
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0802A402:
	adds r7, #0x40
	adds r4, #0x40
	adds r5, #1
	cmp r5, #2
	bls _0802A39E
	movs r0, #0x22
	movs r1, #1
	bl clear_battle_sprite_slot
	ldr r1, _0802A430 @ =0x03001800
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
_0802A430: .4byte 0x03001800
_0802A434: .4byte 0x030034B0
_0802A438: .4byte 0xFFFFF780
_0802A43C: .4byte 0x03000590
	.syntax divided
