	.syntax unified

	thumb_func_start sub_0803DEB0
sub_0803DEB0: @ 0x0803DEB0
	push {lr}
	bl sub_0803E894
	ldr r0, _0803DEC8 @ =0x03000440
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803DED0
	ldr r0, _0803DECC @ =0x083CF3B0
	ldr r0, [r0, #8]
	b _0803DED4
	.align 2, 0
_0803DEC8: .4byte 0x03000440
_0803DECC: .4byte 0x083CF3B0
_0803DED0:
	ldr r0, _0803DEE8 @ =0x083CF3B0
	ldr r0, [r0, #0xc]
_0803DED4:
	bl run_message
	cmp r0, #0
	beq _0803DEE4
	ldr r1, _0803DEEC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DEE4:
	pop {r0}
	bx r0
	.align 2, 0
_0803DEE8: .4byte 0x083CF3B0
_0803DEEC: .4byte 0x0300137C
	.syntax divided
