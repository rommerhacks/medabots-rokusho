	.syntax unified

	thumb_func_start sub_08022648
sub_08022648: @ 0x08022648
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	movs r6, #0
	ldr r0, _080226F8 @ =0x03002C30
	mov sb, r0
	ldr r4, _080226FC @ =0x0000086B
	add r4, sb
	ldr r5, _08022700 @ =0x00000842
	add r5, sb
_08022660:
	ldrb r1, [r4, #1]
	ldrb r2, [r4]
	ldr r3, _08022704 @ =0x03001800
	mov r8, r3
	mov r0, r8
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	add r0, sb
	movs r7, #2
	ldrsh r3, [r0, r7]
	movs r7, #4
	ldrsh r0, [r0, r7]
	subs r0, #4
	str r0, [sp]
	add r0, sp, #4
	bl calc_polar_to_screen_coords
	ldr r0, [sp, #4]
	strh r0, [r5]
	asrs r0, r0, #0x10
	strh r0, [r5, #2]
	ldrb r0, [r4, #1]
	adds r0, #8
	strb r0, [r4, #1]
	ldrb r0, [r4, #2]
	adds r0, #1
	strb r0, [r4, #2]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080226AC
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
_080226AC:
	ldrb r0, [r5, #6]
	cmp r0, #0x40
	beq _080226BC
	subs r0, #1
	strb r0, [r5, #6]
	ldrb r0, [r5, #7]
	subs r0, #1
	strb r0, [r5, #7]
_080226BC:
	adds r4, #0x40
	adds r5, #0x40
	adds r6, #1
	cmp r6, #1
	bls _08022660
	ldr r0, _080226F8 @ =0x03002C30
	ldr r1, _080226FC @ =0x0000086B
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080226EA
	movs r0, #0x30
	bl play_sound_effect
	movs r0, #0x22
	movs r1, #1
	bl clear_battle_sprite_slot
	mov r1, r8
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080226EA:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080226F8: .4byte 0x03002C30
_080226FC: .4byte 0x0000086B
_08022700: .4byte 0x00000842
_08022704: .4byte 0x03001800
	.syntax divided
