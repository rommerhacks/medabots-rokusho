	.syntax unified

	thumb_func_start sub_08065348
sub_08065348: @ 0x08065348
	push {r4, r5, lr}
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _080653A0
	ldr r0, _08065380 @ =0x03000440
	adds r5, r0, #0
	adds r5, #0x84
	ldrb r0, [r5]
	cmp r0, #8
	bhi _08065388
	adds r1, r0, #0
	lsls r1, r1, #2
	ldr r4, _08065384 @ =0x0000FFFF
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F684
	ldrb r1, [r5]
	lsls r1, r1, #2
	movs r0, #0
	adds r2, r4, #0
	bl blend_obj_palettes_to_color_0803F998
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _080653A0
	.align 2, 0
_08065380: .4byte 0x03000440
_08065384: .4byte 0x0000FFFF
_08065388:
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r1, [r2]
	ldr r0, _080653A8 @ =0x0000FDFF
	ands r0, r1
	strh r0, [r2]
	ldr r1, _080653AC @ =0x03002B8C
	movs r0, #6
	str r0, [r1]
	ldr r1, _080653B0 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
_080653A0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080653A8: .4byte 0x0000FDFF
_080653AC: .4byte 0x03002B8C
_080653B0: .4byte 0x0300137C
	.syntax divided
