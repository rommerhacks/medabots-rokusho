	.syntax unified

	thumb_func_start reset_sound_channel_if_idle
reset_sound_channel_if_idle: @ 0x080746BC
	push {lr}
	ldr r0, _080746DC @ =0x03007014
	ldr r1, [r0]
	ldr r2, _080746E0 @ =0x0000049C
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _080746D6
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r0, r1, r2
	bl sub_08073CA4
_080746D6:
	pop {r0}
	bx r0
	.align 2, 0
_080746DC: .4byte 0x03007014
_080746E0: .4byte 0x0000049C
	.syntax divided
