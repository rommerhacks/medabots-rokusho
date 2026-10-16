	.syntax unified

	thumb_func_start sub_08074CEC
sub_08074CEC: @ 0x08074CEC
	mov ip, r3
	mov r3, sb
	push {r3}
	mov r3, ip
	sub sp, #4
	mov r1, sb
	str r1, [sp]
	adds r2, r0, #0
	adds r3, r1, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	ldr r0, [r3]
	cmp r1, r0
	bne _08074D20
	ldr r0, [r2, #0x14]
	cmp r0, #0
	beq _08074D20
	ldr r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x70
	strb r1, [r0]
	adds r2, #0x50
	ldrb r1, [r2]
	movs r0, #0x40
	orrs r0, r1
	strb r0, [r2]
_08074D20:
	add sp, #4
	pop {r3}
	mov sb, r3
	bx lr
	.syntax divided
