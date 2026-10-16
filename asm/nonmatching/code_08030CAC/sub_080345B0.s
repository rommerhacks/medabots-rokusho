	.syntax unified

	thumb_func_start sub_080345B0
sub_080345B0: @ 0x080345B0
	push {lr}
	bl sub_08025F2C
	ldr r0, _080345C8 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080345C4
	bl sub_08034F08
_080345C4:
	pop {r0}
	bx r0
	.align 2, 0
_080345C8: .4byte 0x03001800
	.syntax divided
