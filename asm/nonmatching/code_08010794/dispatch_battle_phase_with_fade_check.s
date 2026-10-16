	.syntax unified

	thumb_func_start dispatch_battle_phase_with_fade_check
dispatch_battle_phase_with_fade_check: @ 0x08012970
	push {lr}
	sub sp, #4
	bl sub_0803EED8
	cmp r0, #0
	bne _080129AA
	ldr r0, _080129B0 @ =0x03000430
	ldr r0, [r0]
	cmp r0, #2
	bne _0801299A
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp]
	ldr r0, _080129B4 @ =0x03002414
	ldr r1, [r0]
	ldr r0, _080129B8 @ =0x00000B84
	adds r1, r1, r0
	ldr r2, _080129BC @ =0x01000100
	mov r0, sp
	bl CpuFastSet
_0801299A:
	ldr r1, _080129C0 @ =0x083ACF00
	ldr r0, _080129C4 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_080129AA:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_080129B0: .4byte 0x03000430
_080129B4: .4byte 0x03002414
_080129B8: .4byte 0x00000B84
_080129BC: .4byte 0x01000100
_080129C0: .4byte 0x083ACF00
_080129C4: .4byte 0x0300137C
	.syntax divided
