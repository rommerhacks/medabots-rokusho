	.syntax unified

	thumb_func_start sub_08074A94
sub_08074A94: @ 0x08074A94
	mov r3, sb
	push {r3}
	sub sp, #4
	mov r1, sb
	str r1, [sp]
	ldr r2, [r1]
	adds r1, r0, #0
	adds r1, #0x70
	strb r2, [r1]
	adds r0, #0x50
	ldrb r2, [r0]
	movs r1, #0x40
	orrs r1, r2
	strb r1, [r0]
	add sp, #4
	pop {r3}
	mov sb, r3
	bx lr
	.syntax divided
