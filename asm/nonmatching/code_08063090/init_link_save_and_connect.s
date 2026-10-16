	.syntax unified

	thumb_func_start init_link_save_and_connect
init_link_save_and_connect: @ 0x080663E0
	push {r4, lr}
	ldr r1, _080663F8 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
	ldr r0, _080663FC @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x4a
	ldrb r0, [r0]
	cmp r0, #0
	bne _08066410
	movs r4, #0
	b _08066402
	.align 2, 0
_080663F8: .4byte 0x0300137C
_080663FC: .4byte 0x03006F74
_08066400:
	adds r4, #1
_08066402:
	cmp r4, #3
	bgt _08066410
	movs r0, #0
	bl save_dispatch
	cmp r0, #0
	bne _08066400
_08066410:
	bl init_linking_mode
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
