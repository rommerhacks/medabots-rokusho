	.syntax unified

	thumb_func_start sub_08034508
sub_08034508: @ 0x08034508
	push {lr}
	bl sub_08024090
	ldr r0, _08034520 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803451C
	bl sub_08034F08
_0803451C:
	pop {r0}
	bx r0
	.align 2, 0
_08034520: .4byte 0x03001800
	.syntax divided
