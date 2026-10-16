	.syntax unified

	thumb_func_start sub_08008BB8
sub_08008BB8: @ 0x08008BB8
	push {lr}
	bl sub_080093F8
	ldr r0, _08008BD8 @ =0x083B53F8
	ldr r0, [r0, #0x14]
	bl run_message
	cmp r0, #0
	beq _08008BD2
	ldr r1, _08008BDC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08008BD2:
	pop {r0}
	bx r0
	.align 2, 0
_08008BD8: .4byte 0x083B53F8
_08008BDC: .4byte 0x0300137C
	.syntax divided
