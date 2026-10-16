	.syntax unified

	thumb_func_start update_battle_sprite_orbit_clockwise
	.global update_battle_sprite_orbit_clockwise
update_battle_sprite_orbit_clockwise: @ 0x08004EF8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r2, _08004F88 @ =0x083AC420
	ldr r0, _08004F8C @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x51
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r1, r0, r2
	ldrb r3, [r1]
	adds r0, #1
	adds r0, r0, r2
	ldrb r4, [r0]
	ldr r1, _08004F90 @ =0x03002C30
	lsls r0, r7, #6
	adds r5, r0, r1
	adds r0, r5, #0
	adds r0, #0x23
	ldrb r1, [r0]
	adds r1, #0x10
	movs r0, #0x3f
	ands r1, r0
	lsls r1, r1, #2
	str r4, [sp]
	movs r0, #8
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #0xc
	movs r2, #0x10
	bl compute_polar_to_screen_position
	ldr r0, [sp, #0xc]
	movs r1, #0
	strh r0, [r5, #2]
	asrs r0, r0, #0x10
	strh r0, [r5, #4]
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r5, #6]
	movs r0, #0xc
	strb r0, [r5, #0xa]
	strb r1, [r5, #0x1c]
	movs r1, #4
	ldrsh r0, [r5, r1]
	subs r0, #8
	subs r0, r4, r0
	lsls r1, r0, #1
	adds r1, r1, r0
	movs r0, #0x40
	subs r0, r0, r1
	strb r0, [r5, #9]
	movs r1, #4
	ldrsh r0, [r5, r1]
	subs r0, #8
	subs r0, r4, r0
	lsls r1, r0, #1
	adds r1, r1, r0
	movs r0, #0x60
	subs r0, r0, r1
	strb r0, [r5, #8]
	movs r1, #4
	ldrsh r0, [r5, r1]
	cmp r4, r0
	bls _08004F98
	ldr r0, _08004F94 @ =0x083AC432
	ldrb r1, [r6]
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	b _08004FA2
	.align 2, 0
_08004F88: .4byte 0x083AC420
_08004F8C: .4byte 0x03000440
_08004F90: .4byte 0x03002C30
_08004F94: .4byte 0x083AC432
_08004F98:
	ldr r0, _08004FC8 @ =0x083AC432
	ldrb r1, [r6]
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #4
_08004FA2:
	strb r0, [r5, #0xb]
	ldr r0, _08004FCC @ =0x03002C30
	lsls r1, r7, #6
	adds r1, r1, r0
	adds r2, r1, #0
	adds r2, #0x23
	ldrb r0, [r2]
	lsls r0, r0, #4
	strh r0, [r1, #0x18]
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #0x3f
	ands r0, r1
	strb r0, [r2]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08004FC8: .4byte 0x083AC432
_08004FCC: .4byte 0x03002C30
	.syntax divided
