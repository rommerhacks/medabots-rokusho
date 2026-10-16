	.syntax unified

	thumb_func_start sub_08040B5C
sub_08040B5C: @ 0x08040B5C
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _08040B84 @ =0x06000280
_08040B62:
	ldr r0, _08040B88 @ =0x084C01C8
	adds r1, r4, #0
	movs r2, #0x20
	bl CpuSet
	adds r4, #0x40
	adds r5, #1
	cmp r5, #0x33
	bls _08040B62
	ldr r1, _08040B8C @ =0x03000440
	ldrb r0, [r1, #0x1b]
	adds r0, #1
	strb r0, [r1, #0x1b]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08040B84: .4byte 0x06000280
_08040B88: .4byte 0x084C01C8
_08040B8C: .4byte 0x03000440
	.syntax divided
