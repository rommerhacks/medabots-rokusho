	.syntax unified

	thumb_func_start set_all_sound_channels_flag_0x40
set_all_sound_channels_flag_0x40: @ 0x08074AB8
	push {r4, lr}
	mov r4, sb
	push {r4}
	sub sp, #4
	str r0, [sp]
	ldr r0, _08074B20 @ =0x03007014
	ldr r4, [r0]
	mov sb, sp
	adds r0, r4, #0
	bl sub_08074A94
	adds r0, r4, #0
	adds r0, #0x74
	mov sb, sp
	bl sub_08074A94
	adds r0, r4, #0
	adds r0, #0xe8
	mov sb, sp
	bl sub_08074A94
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r4, r1
	mov sb, sp
	bl sub_08074A94
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r4, r1
	mov sb, sp
	bl sub_08074A94
	ldr r1, _08074B24 @ =0x00000414
	adds r0, r4, r1
	mov sb, sp
	bl sub_08074A94
	movs r0, #0xae
	lsls r0, r0, #3
	adds r4, r4, r0
	mov sb, sp
	adds r0, r4, #0
	bl sub_08074A94
	add sp, #4
	pop {r3}
	mov sb, r3
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08074B20: .4byte 0x03007014
_08074B24: .4byte 0x00000414
	.syntax divided
