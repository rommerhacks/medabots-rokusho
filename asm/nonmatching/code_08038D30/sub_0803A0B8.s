	.syntax unified

	thumb_func_start sub_0803A0B8
sub_0803A0B8: @ 0x0803A0B8
	push {r4, lr}
	ldr r4, _0803A0D8 @ =0x03002C30
	ldr r1, _0803A0DC @ =0x000007A9
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803A0CA
	bl battle_advance_sequence_counter
_0803A0CA:
	adds r1, r4, #0
	adds r1, #0x2a
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A0D8: .4byte 0x03002C30
_0803A0DC: .4byte 0x000007A9
	.syntax divided
