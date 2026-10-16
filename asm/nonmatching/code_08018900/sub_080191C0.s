	.syntax unified

	thumb_func_start sub_080191C0
sub_080191C0: @ 0x080191C0
	push {lr}
	adds r2, r0, #0
	ldr r0, _080191E0 @ =0x03000590
	lsls r1, r2, #8
	adds r1, r1, r0
	adds r1, #0xa1
	ldrb r0, [r1]
	cmp r0, #0
	bne _080191DA
	adds r0, r2, #0
	movs r1, #6
	bl sub_08019184
_080191DA:
	pop {r0}
	bx r0
	.align 2, 0
_080191E0: .4byte 0x03000590
	.syntax divided
