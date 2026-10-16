	.syntax unified

	thumb_func_start sub_080660AC
sub_080660AC: @ 0x080660AC
	push {lr}
	ldr r0, _080660E0 @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x50
	bl blend_fade_step_08065598
	cmp r0, #0
	beq _080660DC
	ldr r1, _080660E4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #1
	movs r1, #0
	movs r2, #1
	bl text_window_init
	ldr r2, _080660E8 @ =0x03002C30
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
_080660DC:
	pop {r0}
	bx r0
	.align 2, 0
_080660E0: .4byte 0x03006F74
_080660E4: .4byte 0x0300137C
_080660E8: .4byte 0x03002C30
	.syntax divided
