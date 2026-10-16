	.syntax unified

	thumb_func_start sub_0802E820
sub_0802E820: @ 0x0802E820
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r0, #0
	mov r8, r0
	movs r3, #0
	movs r6, #0
	ldr r7, _0802E86C @ =0x03001800
	movs r0, #0xf8
	adds r0, r0, r7
	mov sl, r0
	ldr r0, _0802E870 @ =0x03002C30
	mov sb, r0
	movs r5, #0xa0
	lsls r5, r5, #2
	add r5, sb
	ldr r0, _0802E874 @ =0x000003FF
	adds r2, r0, #0
_0802E84A:
	adds r0, r7, #0
	adds r0, #0xd2
	adds r0, r6, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E8A2
	adds r3, #1
	mov r0, sl
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802E878
	ldrh r0, [r5, #0x18]
	subs r0, #0x40
	b _0802E87C
	.align 2, 0
_0802E86C: .4byte 0x03001800
_0802E870: .4byte 0x03002C30
_0802E874: .4byte 0x000003FF
_0802E878:
	ldrh r0, [r5, #0x18]
	adds r0, #0x40
_0802E87C:
	ands r0, r2
	strh r0, [r5, #0x18]
	adds r4, r6, #0
	adds r4, #0xa
	adds r0, r4, #0
	str r2, [sp]
	str r3, [sp, #4]
	bl move_sprite_toward_target
	ldr r2, [sp]
	ldr r3, [sp, #4]
	cmp r0, #0
	beq _0802E8A2
	lsls r0, r4, #6
	add r0, sb
	movs r1, #0
	strh r1, [r0, #0x18]
	movs r0, #1
	add r8, r0
_0802E8A2:
	adds r5, #0x40
	adds r6, #1
	cmp r6, #2
	bls _0802E84A
	cmp r8, r3
	bne _0802E8BE
	movs r0, #0x2b
	bl play_sound_effect
	ldr r1, _0802E8D0 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802E8BE:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802E8D0: .4byte 0x03001800
	.syntax divided
