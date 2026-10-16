	.syntax unified

	thumb_func_start copy_string_to_text_buffer
	.global copy_string_to_text_buffer
copy_string_to_text_buffer: @ 0x08047CE4
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r3, r1, #0
	mov r2, sp
	ldr r1, _08047D00 @ =0x080ABBFC
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldr r1, [r1]
	str r1, [r2]
	lsls r0, r0, #2
	add r0, sp
	ldr r1, [r0]
	movs r2, #0
	b _08047D10
	.align 2, 0
_08047D00: .4byte 0x080ABBFC
_08047D04:
	strb r0, [r1]
	adds r3, #1
	adds r1, #1
	adds r2, #1
	cmp r2, #0xf
	bgt _08047D16
_08047D10:
	ldrb r0, [r3]
	cmp r0, #0xfe
	bne _08047D04
_08047D16:
	movs r0, #0xfe
	strb r0, [r1]
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
