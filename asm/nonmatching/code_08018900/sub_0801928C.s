	.syntax unified

	thumb_func_start sub_0801928C
sub_0801928C: @ 0x0801928C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080192B4 @ =0x03000590
	lsls r0, r4, #8
	adds r0, r0, r1
	adds r0, #0xa2
	ldrb r0, [r0]
	movs r1, #0x14
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
_080192B4: .4byte 0x03000590
	.syntax divided
