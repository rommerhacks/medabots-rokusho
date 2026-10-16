	.syntax unified

	thumb_func_start format_number_to_text_buffer
	.global format_number_to_text_buffer
format_number_to_text_buffer: @ 0x08047C84
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r6, r1, #0
	add r3, sp, #0xc
	adds r2, r3, #0
	ldr r1, _08047CE0 @ =0x080ABBFC
	ldm r1!, {r4, r5, r7}
	stm r2!, {r4, r5, r7}
	ldr r1, [r1]
	str r1, [r2]
	lsls r0, r0, #2
	adds r3, r3, r0
	ldr r7, [r3]
	adds r0, r6, #0
	bl safe_divide_one
	adds r4, r0, #0
	movs r5, #0
	cmp r5, r4
	bge _08047CC8
_08047CAC:
	subs r1, r4, #1
	subs r1, r1, r5
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl truncate_to_digit_count
	mov r2, sp
	adds r1, r2, r5
	adds r0, #0x35
	strb r0, [r1]
	adds r5, #1
	cmp r5, r4
	blt _08047CAC
_08047CC8:
	mov r0, sp
	adds r1, r7, #0
	adds r2, r4, #0
	bl memcpy_u8
	adds r1, r7, r4
	movs r0, #0xfe
	strb r0, [r1]
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08047CE0: .4byte 0x080ABBFC
	.syntax divided
