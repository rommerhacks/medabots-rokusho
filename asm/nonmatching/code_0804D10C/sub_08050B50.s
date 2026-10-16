	.syntax unified

	thumb_func_start sub_08050B50
sub_08050B50: @ 0x08050B50
	push {lr}
	ldr r0, _08050B70 @ =0x0300058C
	movs r1, #4
	bl sub_080496C8
	ldr r0, _08050B74 @ =0x03001798
	movs r1, #4
	bl sub_080496C8
	ldr r0, _08050B78 @ =0x03002B64
	movs r1, #4
	bl sub_080496C8
	pop {r0}
	bx r0
	.align 2, 0
_08050B70: .4byte 0x0300058C
_08050B74: .4byte 0x03001798
_08050B78: .4byte 0x03002B64
	.syntax divided
