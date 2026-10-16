	.syntax unified

	thumb_func_start sub_080385D0
	.global sub_080385D0
sub_080385D0: @ 0x080385D0
	push {r4, lr}
	movs r2, #0
	ldr r1, _080385F4 @ =0x03001800
	adds r4, r0, #1
	movs r3, #0
	adds r1, #0x45
_080385DC:
	ldrb r0, [r1]
	cmp r0, r4
	bne _080385E6
	strb r3, [r1]
	strb r3, [r1, #1]
_080385E6:
	adds r1, #2
	adds r2, #1
	cmp r2, #5
	bls _080385DC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080385F4: .4byte 0x03001800
	.syntax divided
