	.syntax unified

	thumb_func_start sub_08010BA0
sub_08010BA0: @ 0x08010BA0
	push {lr}
	bl update_scroll_movement_a
	ldr r0, _08010BB8 @ =0x03000440
	adds r0, #0x9c
	ldrb r0, [r0]
	cmp r0, #1
	bne _08010BC0
	ldr r1, _08010BBC @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08010BC4
	.align 2, 0
_08010BB8: .4byte 0x03000440
_08010BBC: .4byte 0x0300137C
_08010BC0:
	ldr r1, _08010BCC @ =0x0300137C
	movs r0, #0x70
_08010BC4:
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08010BCC: .4byte 0x0300137C
	.syntax divided
