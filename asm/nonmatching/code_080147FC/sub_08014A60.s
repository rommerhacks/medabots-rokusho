	.syntax unified

	thumb_func_start sub_08014A60
sub_08014A60: @ 0x08014A60
	push {lr}
	ldr r0, _08014A7C @ =0x083CF3B0
	ldr r0, [r0, #4]
	bl run_message
	cmp r0, #0
	beq _08014A76
	ldr r1, _08014A80 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08014A76:
	pop {r0}
	bx r0
	.align 2, 0
_08014A7C: .4byte 0x083CF3B0
_08014A80: .4byte 0x0300137C
	.syntax divided
