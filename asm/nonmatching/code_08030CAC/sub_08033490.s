	.syntax unified

	thumb_func_start sub_08033490
sub_08033490: @ 0x08033490
	push {r4, lr}
	ldr r2, _080334D8 @ =0x03000590
	ldr r4, _080334DC @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5d
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r1, r4, #0
	adds r1, #0x5c
	ldrb r1, [r1]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x56
	ldrb r0, [r0]
	subs r1, r0, #1
	lsls r0, r1, #8
	adds r0, r0, r2
	adds r0, #0xc4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080334CA
	adds r0, r1, #0
	bl sub_080331F8
	cmp r0, #0
	bne _080334D2
_080334CA:
	adds r1, r4, #0
	adds r1, #0x51
	movs r0, #1
	strb r0, [r1]
_080334D2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080334D8: .4byte 0x03000590
_080334DC: .4byte 0x03001800
	.syntax divided
