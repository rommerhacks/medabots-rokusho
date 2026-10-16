	.syntax unified

	thumb_func_start sub_0804DCF0
sub_0804DCF0: @ 0x0804DCF0
	push {lr}
	ldr r0, _0804DD0C @ =0x0300058C
	ldr r0, [r0]
	lsls r1, r0, #0x1f
	lsrs r1, r1, #0x1f
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1f
	orrs r1, r0
	cmp r1, #0
	beq _0804DD08
	bl sub_08050244
_0804DD08:
	pop {r0}
	bx r0
	.align 2, 0
_0804DD0C: .4byte 0x0300058C
	.syntax divided
