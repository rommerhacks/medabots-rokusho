	.syntax unified

	thumb_func_start scene_transition_step_080686F4
	.global scene_transition_step_080686F4
scene_transition_step_080686F4: @ 0x080686F4
	push {r4, lr}
	ldr r1, _08068728 @ =0x08485C68
	ldr r4, _0806872C @ =0x03000004
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	cmp r0, #0
	beq _08068738
	ldr r0, _08068730 @ =0x03000000
	movs r1, #0
	str r1, [r0]
	ldrb r0, [r4]
	cmp r0, #3
	bne _08068722
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _08068734 @ =0x0000FEFF
	ands r0, r1
	strh r0, [r2]
_08068722:
	movs r0, #1
	b _08068742
	.align 2, 0
_08068728: .4byte 0x08485C68
_0806872C: .4byte 0x03000004
_08068730: .4byte 0x03000000
_08068734: .4byte 0x0000FEFF
_08068738:
	ldr r1, _08068748 @ =0x03000000
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
_08068742:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08068748: .4byte 0x03000000
	.syntax divided
