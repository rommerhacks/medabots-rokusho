	.syntax unified

	thumb_func_start sub_080483AC
sub_080483AC: @ 0x080483AC
	ldr r2, _080483C8 @ =0x030057E0
	movs r1, #0xc3
	lsls r1, r1, #4
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _080483D4
	ldr r1, _080483CC @ =0x0847EB80
	ldr r3, _080483D0 @ =0x000007FE
	adds r0, r2, r3
	ldrb r0, [r0]
	adds r0, r0, r1
	b _080483D8
	.align 2, 0
_080483C8: .4byte 0x030057E0
_080483CC: .4byte 0x0847EB80
_080483D0: .4byte 0x000007FE
_080483D4:
	ldr r1, _080483DC @ =0x00000C31
	adds r0, r2, r1
_080483D8:
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080483DC: .4byte 0x00000C31
	.syntax divided
