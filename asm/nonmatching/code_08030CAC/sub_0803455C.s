	.syntax unified

	thumb_func_start sub_0803455C
sub_0803455C: @ 0x0803455C
	push {lr}
	bl sub_0802518C
	ldr r0, _08034574 @ =0x03001800
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034570
	bl sub_08034F08
_08034570:
	pop {r0}
	bx r0
	.align 2, 0
_08034574: .4byte 0x03001800
	.syntax divided
