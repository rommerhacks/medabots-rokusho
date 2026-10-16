	.syntax unified

	thumb_func_start sub_0802F880
sub_0802F880: @ 0x0802F880
	push {lr}
	bl sub_0803884C
	cmp r0, #0
	beq _0802F894
	ldr r1, _0802F898 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802F894:
	pop {r0}
	bx r0
	.align 2, 0
_0802F898: .4byte 0x03001800
	.syntax divided
