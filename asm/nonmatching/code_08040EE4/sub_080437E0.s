	.syntax unified

	thumb_func_start sub_080437E0
	.global sub_080437E0
sub_080437E0: @ 0x080437E0
	ldr r1, _0804380C @ =0x03000440
	adds r0, r1, #0
	adds r0, #0x98
	adds r3, r1, #0
	adds r3, #0x99
	ldrb r2, [r0]
	ldrb r3, [r3]
	cmp r2, r3
	bne _08043810
	adds r0, r1, #0
	adds r0, #0x9a
	ldrb r0, [r0]
	cmp r2, r0
	bne _08043810
	adds r0, r1, #0
	adds r0, #0x9b
	ldrb r0, [r0]
	cmp r2, r0
	bne _08043810
	movs r0, #1
	b _08043812
	.align 2, 0
_0804380C: .4byte 0x03000440
_08043810:
	movs r0, #0
_08043812:
	bx lr
	.syntax divided
