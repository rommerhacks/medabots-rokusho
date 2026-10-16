	.syntax unified

	thumb_func_start sub_08074F34
sub_08074F34: @ 0x08074F34
	push {lr}
	mov r3, sb
	push {r3}
	sub sp, #4
	str r0, [sp]
	mov sb, sp
	movs r0, #0
	bl sub_08074EF4
	mov sb, sp
	movs r0, #1
	bl sub_08074EF4
	mov sb, sp
	movs r0, #2
	bl sub_08074EF4
	mov sb, sp
	movs r0, #3
	bl sub_08074EF4
	mov sb, sp
	movs r0, #8
	bl sub_08074EF4
	mov sb, sp
	movs r0, #9
	bl sub_08074EF4
	add sp, #4
	pop {r3}
	mov sb, r3
	pop {r0}
	bx r0
	.syntax divided
