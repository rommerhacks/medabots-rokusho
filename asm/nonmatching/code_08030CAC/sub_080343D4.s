	.syntax unified

	thumb_func_start sub_080343D4
sub_080343D4: @ 0x080343D4
	push {lr}
	bl sub_080218BC
	ldr r0, _080343EC @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080343E8
	bl sub_08034F08
_080343E8:
	pop {r0}
	bx r0
	.align 2, 0
_080343EC: .4byte 0x03001800
	.syntax divided
