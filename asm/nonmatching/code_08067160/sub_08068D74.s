	.syntax unified

	thumb_func_start sub_08068D74
sub_08068D74: @ 0x08068D74
	push {lr}
	bl sub_08069EF8
	cmp r0, #0
	beq _08068D90
	ldr r1, _08068D94 @ =0x03006F88
	movs r0, #0
	str r0, [r1]
	ldr r1, _08068D98 @ =0x03006F80
	movs r0, #4
	str r0, [r1]
	ldr r1, _08068D9C @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_08068D90:
	pop {r0}
	bx r0
	.align 2, 0
_08068D94: .4byte 0x03006F88
_08068D98: .4byte 0x03006F80
_08068D9C: .4byte 0x0300137C
	.syntax divided
