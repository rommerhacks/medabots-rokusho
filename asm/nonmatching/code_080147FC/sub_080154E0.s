	.syntax unified

	thumb_func_start sub_080154E0
sub_080154E0: @ 0x080154E0
	adds r2, r1, #0
	ldr r1, _08015500 @ =0x03000590
	lsls r0, r0, #8
	adds r1, r0, r1
	adds r0, r1, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0x2b
	bne _08015504
	adds r0, r1, #0
	adds r0, #0xca
	ldrb r0, [r0]
	cmp r0, r2
	bne _08015504
	movs r0, #1
	b _08015506
	.align 2, 0
_08015500: .4byte 0x03000590
_08015504:
	movs r0, #0
_08015506:
	bx lr
	.syntax divided
