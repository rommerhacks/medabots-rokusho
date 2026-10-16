	.syntax unified

	thumb_func_start sub_08034DEC
sub_08034DEC: @ 0x08034DEC
	push {lr}
	bl battle_dispatch_phase_handler_0802E424
	ldr r0, _08034E04 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034E00
	bl sub_08034F08
_08034E00:
	pop {r0}
	bx r0
	.align 2, 0
_08034E04: .4byte 0x03001800
	.syntax divided
