	.syntax unified

	thumb_func_start sub_0803DC58
sub_0803DC58: @ 0x0803DC58
	push {lr}
	bl update_scroll_movement_a
	ldr r0, _0803DC74 @ =0x03000440
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803DC7C
	ldr r1, _0803DC78 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _0803DC80
	.align 2, 0
_0803DC74: .4byte 0x03000440
_0803DC78: .4byte 0x0300137C
_0803DC7C:
	ldr r1, _0803DC88 @ =0x0300137C
	movs r0, #0x30
_0803DC80:
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803DC88: .4byte 0x0300137C
	.syntax divided
