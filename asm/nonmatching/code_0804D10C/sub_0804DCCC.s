	.syntax unified

	thumb_func_start sub_0804DCCC
sub_0804DCCC: @ 0x0804DCCC
	push {lr}
	ldr r0, _0804DCE0 @ =0x030057E0
	ldr r2, _0804DCE4 @ =0x00000C94
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804DCE8
	subs r0, #1
	strb r0, [r1]
	b _0804DCEC
	.align 2, 0
_0804DCE0: .4byte 0x030057E0
_0804DCE4: .4byte 0x00000C94
_0804DCE8:
	bl sub_08050244
_0804DCEC:
	pop {r0}
	bx r0
	.syntax divided
