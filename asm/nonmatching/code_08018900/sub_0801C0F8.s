	.syntax unified

	thumb_func_start sub_0801C0F8
sub_0801C0F8: @ 0x0801C0F8
	push {lr}
	bl sub_0801ABF8
	ldr r1, _0801C10C @ =0x03001800
	adds r1, #0xa1
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0801C10C: .4byte 0x03001800
	.syntax divided
