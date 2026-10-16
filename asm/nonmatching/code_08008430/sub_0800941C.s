	.syntax unified

	thumb_func_start sub_0800941C
	.global sub_0800941C
sub_0800941C: @ 0x0800941C
	push {r4, r5, lr}
	ldr r4, _08009448 @ =0x03000440
	adds r5, r4, #0
	adds r5, #0x3d
	ldrb r0, [r5]
	movs r1, #6
	bl sub_0807CD58
	adds r1, r4, #0
	adds r1, #0x3f
	strb r0, [r1]
	ldrb r0, [r5]
	movs r1, #6
	bl sub_0807CDD0
	adds r1, r4, #0
	adds r1, #0x40
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08009448: .4byte 0x03000440
	.syntax divided
