	.syntax unified

	thumb_func_start sub_08007834
sub_08007834: @ 0x08007834
	push {lr}
	bl sub_080093F8
	bl sub_0800994C
	ldr r0, _08007860 @ =0x03001780
	ldrb r1, [r0]
	movs r0, #3
	movs r2, #0x18
	bl sub_08041C14
	bl update_blend_effect
	cmp r0, #0
	beq _0800785A
	ldr r1, _08007864 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0800785A:
	pop {r0}
	bx r0
	.align 2, 0
_08007860: .4byte 0x03001780
_08007864: .4byte 0x0300137C
	.syntax divided
