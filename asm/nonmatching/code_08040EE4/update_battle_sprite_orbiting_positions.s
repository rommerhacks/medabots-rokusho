	.syntax unified

	thumb_func_start update_battle_sprite_orbiting_positions
	.global update_battle_sprite_orbiting_positions
update_battle_sprite_orbiting_positions: @ 0x080432A0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	adds r2, r1, #0
	ldr r4, _08043338 @ =0x03002C30
	lsls r1, r7, #6
	adds r1, r1, r4
	adds r0, r7, #3
	lsls r0, r0, #6
	adds r5, r0, r4
	ldrh r0, [r5, #2]
	strh r0, [r1, #2]
	adds r3, r5, #0
	adds r3, #0x26
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	ldrb r6, [r3]
	adds r1, r0, r6
	strb r1, [r3]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3f
	bls _080432FC
	adds r0, r1, #0
	subs r0, #0x40
	strb r0, [r3]
	subs r3, #5
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r3]
	lsls r2, r2, #3
	ldr r0, _0804333C @ =0x083B296C
	ldrb r1, [r3]
	adds r1, r1, r0
	ldr r3, _08043340 @ =0x00000505
	adds r0, r3, #0
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r2, r2, r0
	strh r2, [r5, #6]
_080432FC:
	adds r1, r7, #1
	lsls r0, r1, #6
	adds r4, r0, r4
	adds r2, r4, #0
	adds r2, #0x26
	adds r0, r4, #0
	adds r0, #0x24
	ldrb r0, [r0]
	ldrb r6, [r2]
	adds r0, r0, r6
	strb r0, [r2]
	ldrb r0, [r2]
	lsrs r6, r0, #1
	mov sb, r1
	cmp r0, #0x3f
	bls _08043322
	movs r6, #0x20
	subs r0, #0x40
	strb r0, [r2]
_08043322:
	adds r0, r4, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #1
	beq _0804336C
	cmp r0, #1
	bgt _08043344
	cmp r0, #0
	beq _0804334E
	b _080433E0
	.align 2, 0
_08043338: .4byte 0x03002C30
_0804333C: .4byte 0x083B296C
_08043340: .4byte 0x00000505
_08043344:
	cmp r0, #2
	beq _0804338E
	cmp r0, #3
	beq _080433B4
	b _080433E0
_0804334E:
	lsls r0, r6, #2
	strh r0, [r4, #0x18]
	adds r1, r6, #0
	adds r1, #0x60
	movs r0, #2
	ldrsh r3, [r5, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	str r0, [sp]
	add r0, sp, #4
	movs r2, #5
	bl calc_polar_to_screen_coords
	ldr r1, [sp, #4]
	b _080433D6
_0804336C:
	lsls r1, r6, #2
	movs r0, #0x80
	subs r0, r0, r1
	strh r0, [r4, #0x18]
	movs r1, #0x80
	subs r1, r1, r6
	movs r0, #2
	ldrsh r3, [r5, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	str r0, [sp]
	add r0, sp, #8
	movs r2, #5
	bl calc_polar_to_screen_coords
	ldr r1, [sp, #8]
	b _080433D6
_0804338E:
	lsls r1, r6, #2
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r3, #0
	subs r0, r0, r1
	strh r0, [r4, #0x18]
	movs r1, #0x60
	subs r1, r1, r6
	movs r0, #2
	ldrsh r3, [r5, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	str r0, [sp]
	add r0, sp, #0xc
	movs r2, #5
	bl calc_polar_to_screen_coords
	ldr r1, [sp, #0xc]
	b _080433D6
_080433B4:
	lsls r0, r6, #2
	movs r3, #0xe0
	lsls r3, r3, #2
	adds r0, r0, r3
	strh r0, [r4, #0x18]
	adds r1, r6, #0
	adds r1, #0x40
	movs r0, #2
	ldrsh r3, [r5, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	str r0, [sp]
	add r0, sp, #0x10
	movs r2, #5
	bl calc_polar_to_screen_coords
	ldr r1, [sp, #0x10]
_080433D6:
	subs r0, r1, #5
	strh r0, [r4, #2]
	asrs r0, r1, #0x10
	subs r0, #3
	strh r0, [r4, #4]
_080433E0:
	cmp r6, #0x20
	bne _080433F8
	ldr r0, _08043438 @ =0x03002C30
	mov r3, sb
	lsls r1, r3, #6
	adds r1, r1, r0
	adds r1, #0x21
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #3
	ands r0, r2
	strb r0, [r1]
_080433F8:
	ldr r3, _08043438 @ =0x03002C30
	adds r1, r7, #2
	lsls r0, r1, #6
	adds r5, r0, r3
	adds r2, r5, #0
	adds r2, #0x26
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	ldrb r4, [r2]
	adds r0, r0, r4
	strb r0, [r2]
	ldrb r0, [r2]
	lsrs r6, r0, #1
	mov r8, r1
	cmp r0, #0x3f
	bls _08043420
	movs r6, #0x20
	subs r0, #0x40
	strb r0, [r2]
_08043420:
	adds r0, r5, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #1
	beq _080434C0
	cmp r0, #1
	bgt _0804343C
	cmp r0, #0
	beq _08043494
	adds r4, r7, #3
	b _080434F0
	.align 2, 0
_08043438: .4byte 0x03002C30
_0804343C:
	cmp r0, #2
	beq _08043448
	cmp r0, #3
	beq _0804346C
	adds r4, r7, #3
	b _080434F0
_08043448:
	lsls r0, r6, #2
	strh r0, [r5, #0x18]
	adds r1, r6, #0
	adds r1, #0x20
	adds r4, r7, #3
	lsls r0, r4, #6
	adds r0, r0, r3
	movs r2, #2
	ldrsh r3, [r0, r2]
	movs r2, #4
	ldrsh r0, [r0, r2]
	str r0, [sp]
	add r0, sp, #0x14
	movs r2, #5
	bl calc_polar_to_screen_coords
	ldr r1, [sp, #0x14]
	b _080434E6
_0804346C:
	lsls r1, r6, #2
	movs r0, #0x80
	subs r0, r0, r1
	strh r0, [r5, #0x18]
	movs r1, #0x40
	subs r1, r1, r6
	adds r4, r7, #3
	lsls r0, r4, #6
	adds r0, r0, r3
	movs r2, #2
	ldrsh r3, [r0, r2]
	movs r2, #4
	ldrsh r0, [r0, r2]
	str r0, [sp]
	add r0, sp, #0x18
	movs r2, #5
	bl calc_polar_to_screen_coords
	ldr r1, [sp, #0x18]
	b _080434E6
_08043494:
	lsls r1, r6, #2
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r4, #0
	subs r0, r0, r1
	strh r0, [r5, #0x18]
	movs r1, #0x20
	subs r1, r1, r6
	adds r4, r7, #3
	lsls r0, r4, #6
	adds r0, r0, r3
	movs r2, #2
	ldrsh r3, [r0, r2]
	movs r2, #4
	ldrsh r0, [r0, r2]
	str r0, [sp]
	add r0, sp, #0x1c
	movs r2, #5
	bl calc_polar_to_screen_coords
	ldr r1, [sp, #0x1c]
	b _080434E6
_080434C0:
	lsls r0, r6, #2
	movs r4, #0xe0
	lsls r4, r4, #2
	adds r0, r0, r4
	strh r0, [r5, #0x18]
	adds r4, r7, #3
	lsls r0, r4, #6
	adds r0, r0, r3
	movs r1, #2
	ldrsh r3, [r0, r1]
	movs r2, #4
	ldrsh r0, [r0, r2]
	str r0, [sp]
	add r0, sp, #0x20
	adds r1, r6, #0
	movs r2, #5
	bl calc_polar_to_screen_coords
	ldr r1, [sp, #0x20]
_080434E6:
	adds r0, r1, #5
	strh r0, [r5, #2]
	asrs r0, r1, #0x10
	subs r0, #3
	strh r0, [r5, #4]
_080434F0:
	ldr r3, _08043540 @ =0x03002C30
	cmp r6, #0x20
	bne _08043508
	mov r6, r8
	lsls r0, r6, #6
	adds r0, r0, r3
	adds r0, #0x21
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #3
	ands r1, r2
	strb r1, [r0]
_08043508:
	ldr r1, _08043544 @ =0x083B296C
	lsls r0, r4, #6
	adds r4, r0, r3
	adds r0, r4, #0
	adds r0, #0x21
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043548
	lsls r1, r7, #6
	adds r1, r1, r3
	ldrh r0, [r4, #4]
	subs r0, #7
	strh r0, [r1, #4]
	mov r0, sb
	lsls r1, r0, #6
	adds r1, r1, r3
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
	mov r2, r8
	lsls r1, r2, #6
	adds r1, r1, r3
	ldrh r0, [r1, #4]
	adds r0, #1
	b _08043550
	.align 2, 0
_08043540: .4byte 0x03002C30
_08043544: .4byte 0x083B296C
_08043548:
	lsls r1, r7, #6
	adds r1, r1, r3
	ldrh r0, [r4, #4]
	subs r0, #8
_08043550:
	strh r0, [r1, #4]
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.syntax divided
