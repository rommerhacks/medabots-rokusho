	.syntax unified

	thumb_func_start sub_08007584
sub_08007584: @ 0x08007584
	push {lr}
	bl sub_0803EED8
	cmp r0, #0
	bne _0800759E
	ldr r1, _080075A4 @ =0x083AC6EC
	ldr r0, _080075A8 @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_0800759E:
	pop {r0}
	bx r0
	.align 2, 0
_080075A4: .4byte 0x083AC6EC
_080075A8: .4byte 0x0300137C
	.syntax divided
