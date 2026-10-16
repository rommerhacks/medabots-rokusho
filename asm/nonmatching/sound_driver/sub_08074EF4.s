	.syntax unified

	thumb_func_start sub_08074EF4
sub_08074EF4: @ 0x08074EF4
	push {lr}
	mov ip, r3
	mov r3, sb
	push {r3}
	mov r3, ip
	sub sp, #4
	mov r1, sb
	str r1, [sp]
	adds r2, r1, #0
	ldr r1, _08074F30 @ =0x03007014
	ldr r3, [r1]
	movs r1, #0x74
	muls r1, r0, r1
	adds r0, r3, #0
	adds r0, #0x14
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08074F24
	adds r0, r3, r1
	ldr r2, [r2]
	movs r1, #0
	bl sound_play_with_lock
_08074F24:
	add sp, #4
	pop {r3}
	mov sb, r3
	pop {r0}
	bx r0
	.align 2, 0
_08074F30: .4byte 0x03007014
	.syntax divided
