	.syntax unified

	thumb_func_start sub_08031994
sub_08031994: @ 0x08031994
	push {lr}
	ldr r0, _080319B0 @ =0x083CF3B0
	ldr r0, [r0, #4]
	bl run_message
	cmp r0, #0
	beq _080319AA
	ldr r1, _080319B4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080319AA:
	pop {r0}
	bx r0
	.align 2, 0
_080319B0: .4byte 0x083CF3B0
_080319B4: .4byte 0x0300137C
	.syntax divided
