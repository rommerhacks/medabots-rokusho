	.syntax unified

	thumb_func_start update_battle_sprite_orbit_counterclockwise
update_battle_sprite_orbit_counterclockwise: @ 0x080056A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	ldr r2, _08005748 @ =0x083AC420
	ldr r0, _0800574C @ =0x03000440
	adds r6, r0, #0
	adds r6, #0x52
	ldrb r1, [r6]
	movs r7, #0x7f
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	adds r1, r0, r2
	ldrb r3, [r1]
	adds r0, #1
	adds r0, r0, r2
	ldrb r4, [r0]
	subs r4, #4
	ldr r1, _08005750 @ =0x03002C30
	mov r2, r8
	lsls r0, r2, #6
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
	movs r2, #4
	ldrsh r0, [r5, r2]
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
	bls _08005758
	ldr r2, _08005754 @ =0x083AC432
	ldrb r1, [r6]
	adds r0, r7, #0
	ands r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	subs r0, #1
	b _08005766
	.align 2, 0
_08005748: .4byte 0x083AC420
_0800574C: .4byte 0x03000440
_08005750: .4byte 0x03002C30
_08005754: .4byte 0x083AC432
_08005758:
	ldr r2, _08005790 @ =0x083AC432
	ldrb r1, [r6]
	adds r0, r7, #0
	ands r0, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	adds r0, #4
_08005766:
	strb r0, [r5, #0xb]
	ldr r0, _08005794 @ =0x03002C30
	mov r2, r8
	lsls r1, r2, #6
	adds r1, r1, r0
	adds r2, r1, #0
	adds r2, #0x23
	ldrb r0, [r2]
	lsls r0, r0, #4
	strh r0, [r1, #0x18]
	ldrb r0, [r2]
	subs r0, #1
	movs r1, #0x3f
	ands r0, r1
	strb r0, [r2]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005790: .4byte 0x083AC432
_08005794: .4byte 0x03002C30
	.syntax divided
