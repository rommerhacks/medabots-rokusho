	.syntax unified

	thumb_func_start sub_08015508
sub_08015508: @ 0x08015508
	adds r2, r0, #0
	cmp r1, #1
	bne _08015524
	ldr r0, _08015520 @ =0x03000590
	lsls r1, r2, #8
	adds r1, r1, r0
	adds r1, #0x58
	ldrb r0, [r1]
	cmp r0, #0
	bne _08015524
	movs r0, #1
	b _08015526
	.align 2, 0
_08015520: .4byte 0x03000590
_08015524:
	movs r0, #0
_08015526:
	bx lr
	.syntax divided
