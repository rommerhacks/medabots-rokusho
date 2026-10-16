	.syntax unified

	thumb_func_start sub_080085B4
sub_080085B4: @ 0x080085B4
	push {lr}
	bl sub_080093F8
	ldr r0, _080085CC @ =0x03000440
	adds r0, #0x3f
	ldrb r0, [r0]
	cmp r0, #0
	bne _080085D0
	bl sub_0800AC2C
	b _080085D4
	.align 2, 0
_080085CC: .4byte 0x03000440
_080085D0:
	bl sub_0800ACA8
_080085D4:
	bl sub_0803FB0C
	ldr r1, _080085E4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080085E4: .4byte 0x0300137C
	.syntax divided
