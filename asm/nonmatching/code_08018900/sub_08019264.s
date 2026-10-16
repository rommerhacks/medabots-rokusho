	.syntax unified

	thumb_func_start sub_08019264
sub_08019264: @ 0x08019264
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08019288 @ =0x03000590
	lsls r0, r4, #8
	adds r0, r0, r1
	ldrb r0, [r0, #5]
	movs r1, #0xa
	bl sub_0807CD58
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_080191A4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08019288: .4byte 0x03000590
	.syntax divided
