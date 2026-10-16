	.syntax unified

	thumb_func_start sub_08007C20
sub_08007C20: @ 0x08007C20
	push {lr}
	bl sub_080093F8
	bl sub_0800A180
	ldr r0, _08007C44 @ =0x083B53F8
	ldr r0, [r0, #0x10]
	bl run_message
	cmp r0, #0
	beq _08007C3E
	ldr r1, _08007C48 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08007C3E:
	pop {r0}
	bx r0
	.align 2, 0
_08007C44: .4byte 0x083B53F8
_08007C48: .4byte 0x0300137C
	.syntax divided
