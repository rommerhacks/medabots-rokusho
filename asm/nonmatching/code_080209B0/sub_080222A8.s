	.syntax unified

	thumb_func_start sub_080222A8
sub_080222A8: @ 0x080222A8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	movs r6, #0
	ldr r0, _08022368 @ =0x03002C30
	mov r8, r0
	ldr r4, _0802236C @ =0x0000086B
	add r4, r8
	ldr r5, _08022370 @ =0x00000842
	add r5, r8
_080222C0:
	ldr r0, _08022374 @ =0x083B5F80
	adds r0, #0xf4
	ldr r0, [r0]
	adds r1, r6, #0
	adds r1, #0x21
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl process_sprite_anim_commands
	ldrb r1, [r4, #1]
	ldrb r2, [r4]
	ldr r3, _08022378 @ =0x03001800
	mov sb, r3
	mov r0, sb
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	movs r7, #0xba
	lsls r7, r7, #5
	adds r0, r0, r7
	add r0, r8
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
	adds r0, #4
	strb r0, [r4, #1]
	ldrb r0, [r4, #2]
	adds r0, #1
	strb r0, [r4, #2]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0802231E
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0802231E:
	ldrb r0, [r4, #2]
	cmp r0, #0xb4
	bls _08022330
	ldrb r0, [r5, #6]
	subs r0, #4
	strb r0, [r5, #6]
	ldrb r0, [r5, #7]
	subs r0, #4
	strb r0, [r5, #7]
_08022330:
	adds r4, #0x40
	adds r5, #0x40
	adds r6, #1
	cmp r6, #3
	bls _080222C0
	ldr r0, _08022368 @ =0x03002C30
	ldr r1, _0802237C @ =0x00000849
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _08022358
	movs r0, #0x21
	movs r1, #4
	bl clear_battle_sprite_slot
	mov r1, sb
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08022358:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08022368: .4byte 0x03002C30
_0802236C: .4byte 0x0000086B
_08022370: .4byte 0x00000842
_08022374: .4byte 0x083B5F80
_08022378: .4byte 0x03001800
_0802237C: .4byte 0x00000849
	.syntax divided
