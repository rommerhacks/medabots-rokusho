	.syntax unified

	thumb_func_start sub_08063090
sub_08063090: @ 0x08063090
	push {r4, lr}
	ldr r4, _080630D4 @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x50
	bl blend_fade_step_08065598
	cmp r0, #0
	beq _080630BA
	ldr r1, _080630D8 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r1, [r4]
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r1, #0x3c]
	movs r0, #1
	movs r1, #0
	movs r2, #1
	bl text_window_init
_080630BA:
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	adds r1, #0x33
	ldrb r1, [r1]
	movs r2, #0
	bl load_medapart_sprite_animation
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080630D4: .4byte 0x03006F74
_080630D8: .4byte 0x0300137C
	.syntax divided
