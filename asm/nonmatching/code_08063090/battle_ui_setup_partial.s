	.syntax unified

	thumb_func_start battle_ui_setup_partial
	.global battle_ui_setup_partial
battle_ui_setup_partial: @ 0x08066740
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xdc
	adds r4, r0, #0
	mov r6, sp
	movs r5, #0
	add r0, sp, #8
	mov r8, r0
	mov r1, sp
	adds r1, #0x38
	str r1, [sp, #0xd8]
	add r2, sp, #0xc8
	mov sb, r2
	add r0, sp, #0xd0
	mov sl, r0
	ldr r7, _08066810 @ =0x080AE77C
_08066766:
	lsls r0, r5, #8
	movs r1, #6
	bl sub_0807CBBC
	lsls r1, r0, #1
	adds r1, r1, r7
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r4, r1
	stm r6!, {r1}
	adds r0, #0x40
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	stm r6!, {r0}
	adds r5, #1
	cmp r5, #5
	ble _08066766
	ldr r0, [sp]
	stm r6!, {r0}
	ldr r0, [sp, #4]
	str r0, [r6]
	mov r7, sp
	mov r6, r8
	ldr r4, [sp, #0xd8]
	mov r8, sl
	movs r5, #5
_080667A0:
	adds r0, r7, #0
	adds r1, r6, #0
	mov r2, sb
	mov r3, r8
	bl compute_difference_div3
	ldm r7!, {r0}
	stm r4!, {r0}
	ldm r7!, {r0}
	stm r4!, {r0}
	add r0, sp, #0xc8
	ldr r0, [r0]
	stm r4!, {r0}
	mov r2, sb
	ldr r0, [r2, #4]
	stm r4!, {r0}
	add r0, sp, #0xd0
	ldr r0, [r0]
	stm r4!, {r0}
	mov r1, r8
	ldr r0, [r1, #4]
	stm r4!, {r0}
	adds r6, #8
	subs r5, #1
	cmp r5, #0
	bge _080667A0
	ldr r4, [sp, #0xd8]
	movs r5, #0
	ldr r6, _08066814 @ =0x03006F74
	movs r3, #0x1e
_080667DC:
	ldr r1, [r6]
	lsls r0, r5, #4
	adds r2, r1, r0
	ldm r4!, {r0}
	asrs r0, r0, #8
	adds r1, r2, #0
	adds r1, #0xd2
	strh r0, [r1]
	ldm r4!, {r0}
	asrs r0, r0, #8
	adds r1, #2
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xd6
	strh r3, [r0]
	adds r5, #1
	cmp r5, #0x11
	ble _080667DC
	add sp, #0xdc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08066810: .4byte 0x080AE77C
_08066814: .4byte 0x03006F74
	.syntax divided
