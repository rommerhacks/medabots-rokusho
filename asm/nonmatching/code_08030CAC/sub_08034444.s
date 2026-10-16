	.syntax unified

	thumb_func_start sub_08034444
sub_08034444: @ 0x08034444
	push {lr}
	bl sub_080227D8
	ldr r0, _0803445C @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034458
	bl sub_08034F08
_08034458:
	pop {r0}
	bx r0
	.align 2, 0
_0803445C: .4byte 0x03001800
	.syntax divided
