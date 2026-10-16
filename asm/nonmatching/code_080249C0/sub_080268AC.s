	.syntax unified

	thumb_func_start sub_080268AC
sub_080268AC: @ 0x080268AC
	push {r4, r5, lr}
	ldr r4, _080268D0 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	bl sub_0803769C
	ldrb r0, [r5]
	bl sub_080376F4
	adds r4, #0xaa
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080268D0: .4byte 0x03001800
	.syntax divided
