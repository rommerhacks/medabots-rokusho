	.syntax unified

	thumb_func_start sub_080393BC
	.global sub_080393BC
sub_080393BC: @ 0x080393BC
	push {r4, lr}
	ldr r0, _080393E8 @ =0x03002C30
	adds r1, r0, #0
	adds r1, #0x2a
	ldrb r0, [r1]
	cmp r0, #0
	bne _080393D6
	adds r4, r1, #0
_080393CC:
	bl sub_080393EC
	ldrb r0, [r4]
	cmp r0, #0
	beq _080393CC
_080393D6:
	bl sub_0803B8C8
	ldr r0, _080393E8 @ =0x03002C30
	adds r0, #0x2a
	movs r1, #0
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080393E8: .4byte 0x03002C30
	.syntax divided
