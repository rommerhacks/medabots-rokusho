	.syntax unified

	thumb_func_start sub_0801B4C8
sub_0801B4C8: @ 0x0801B4C8
	push {r4, lr}
	movs r3, #0
	movs r2, #0
	ldr r1, _0801B4F4 @ =0x03000590
	lsls r0, r0, #8
	adds r1, #0xba
	adds r1, r0, r1
	movs r4, #0x80
	lsls r4, r4, #1
_0801B4DA:
	ldrb r0, [r1]
	cmp r0, #2
	bne _0801B4E2
	adds r3, #1
_0801B4E2:
	adds r1, r1, r4
	adds r2, #1
	cmp r2, #2
	bls _0801B4DA
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801B4F4: .4byte 0x03000590
	.syntax divided
