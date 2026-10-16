	.syntax unified

	thumb_func_start sub_08064498
sub_08064498: @ 0x08064498
	push {lr}
	ldr r0, _080644B8 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x50
	bl blend_fade_step_08065598
	cmp r0, #0
	beq _080644B4
	ldr r1, _080644BC @ =0x03002B8C
	movs r0, #0x14
	str r0, [r1]
	ldr r1, _080644C0 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
_080644B4:
	pop {r0}
	bx r0
	.align 2, 0
_080644B8: .4byte 0x03006F74
_080644BC: .4byte 0x03002B8C
_080644C0: .4byte 0x0300137C
	.syntax divided
