	.syntax unified

	thumb_func_start sub_08030608
sub_08030608: @ 0x08030608
	push {lr}
	bl sub_0801C154
	cmp r0, #0
	beq _0803061C
	ldr r1, _08030620 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0803061C:
	pop {r0}
	bx r0
	.align 2, 0
_08030620: .4byte 0x03001800
	.syntax divided
