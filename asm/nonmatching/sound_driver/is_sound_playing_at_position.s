	.syntax unified

	thumb_func_start is_sound_playing_at_position
is_sound_playing_at_position: @ 0x08074DFC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_08074E02:
	ldr r1, _08074E18 @ =0x083ABC7C
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl get_sound_channel_position
	cmp r5, r0
	bne _08074E1C
	movs r0, #1
	b _08074E24
	.align 2, 0
_08074E18: .4byte 0x083ABC7C
_08074E1C:
	adds r4, #1
	cmp r4, #5
	bls _08074E02
	movs r0, #0
_08074E24:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
