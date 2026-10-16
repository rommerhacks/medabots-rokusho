	.syntax unified

	thumb_func_start sub_08033A10
sub_08033A10: @ 0x08033A10
	push {lr}
	bl battle_dispatch_phase_handler_0801D2F0
	ldr r0, _08033A28 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08033A24
	bl sub_08034F08
_08033A24:
	pop {r0}
	bx r0
	.align 2, 0
_08033A28: .4byte 0x03001800
	.syntax divided
