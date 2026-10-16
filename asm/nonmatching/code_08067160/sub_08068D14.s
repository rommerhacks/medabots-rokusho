	.syntax unified

	thumb_func_start sub_08068D14
sub_08068D14: @ 0x08068D14
	push {lr}
	sub sp, #4
	bl execute_scene_step
	cmp r0, #0
	beq _08068D4E
	movs r0, #0
	str r0, [sp]
	ldr r1, _08068D54 @ =0x040000D4
	mov r0, sp
	str r0, [r1]
	ldr r0, _08068D58 @ =0x03002C30
	str r0, [r1, #4]
	ldr r0, _08068D5C @ =0x85000800
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _08068D60 @ =0x030017F0
	ldr r0, _08068D64 @ =0x08000841
	str r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _08068D68 @ =0x000080FF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _08068D6C @ =0x0300137C
	ldr r0, _08068D70 @ =0x03006F80
	ldr r0, [r0]
	str r0, [r1]
_08068D4E:
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08068D54: .4byte 0x040000D4
_08068D58: .4byte 0x03002C30
_08068D5C: .4byte 0x85000800
_08068D60: .4byte 0x030017F0
_08068D64: .4byte 0x08000841
_08068D68: .4byte 0x000080FF
_08068D6C: .4byte 0x0300137C
_08068D70: .4byte 0x03006F80
	.syntax divided
