	.syntax unified

	thumb_func_start sub_08030E54
sub_08030E54: @ 0x08030E54
	push {lr}
	ldr r0, _08030E70 @ =0x03001800
	adds r0, #0xa6
	ldrb r0, [r0]
	bl sub_0801C0BC
	cmp r0, #0
	beq _08030E6C
	ldr r1, _08030E74 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08030E6C:
	pop {r0}
	bx r0
	.align 2, 0
_08030E70: .4byte 0x03001800
_08030E74: .4byte 0x0300137C
	.syntax divided
