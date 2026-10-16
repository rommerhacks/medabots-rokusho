	.syntax unified

	thumb_func_start sub_08068FD4
sub_08068FD4: @ 0x08068FD4
	push {lr}
	bl sub_08069F80
	cmp r0, #0
	beq _08068FF0
	ldr r1, _08068FF4 @ =0x03006F88
	movs r0, #0
	str r0, [r1]
	ldr r1, _08068FF8 @ =0x03006F80
	movs r0, #7
	str r0, [r1]
	ldr r1, _08068FFC @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_08068FF0:
	pop {r0}
	bx r0
	.align 2, 0
_08068FF4: .4byte 0x03006F88
_08068FF8: .4byte 0x03006F80
_08068FFC: .4byte 0x0300137C
	.syntax divided
