	.syntax unified

	thumb_func_start init_medapart_detail_view
init_medapart_detail_view: @ 0x08063624
	push {r4, lr}
	ldr r4, _080636A8 @ =0x03006F74
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	adds r1, #0x33
	ldrb r1, [r1]
	movs r2, #0
	bl load_medapart_sprite_animation
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r0, [r0]
	adds r1, #0x34
	ldrb r1, [r1]
	movs r2, #1
	bl load_medapart_sprite_animation
	bl update_scroll_animation_tiles
	ldr r0, [r4]
	movs r1, #0x3a
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080636A2
	ldr r1, _080636AC @ =0x03002C30
	movs r0, #0x84
	lsls r0, r0, #4
	adds r2, r1, r0
	movs r0, #0xc0
	lsls r0, r0, #8
	strh r0, [r2]
	ldr r0, _080636B0 @ =0x0000085C
	adds r2, r1, r0
	movs r0, #2
	strb r0, [r2]
	ldr r0, _080636B4 @ =0x00000842
	adds r2, r1, r0
	movs r0, #0x28
	strh r0, [r2]
	ldr r0, _080636B8 @ =0x00000844
	adds r2, r1, r0
	movs r0, #0x40
	strh r0, [r2]
	ldr r0, _080636BC @ =0x0000084A
	adds r2, r1, r0
	movs r0, #8
	strb r0, [r2]
	ldr r0, _080636C0 @ =0x00000846
	adds r1, r1, r0
	movs r0, #0x2a
	strh r0, [r1]
	movs r0, #1
	movs r1, #0
	movs r2, #1
	bl text_window_init
	ldr r1, _080636C4 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080636A2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080636A8: .4byte 0x03006F74
_080636AC: .4byte 0x03002C30
_080636B0: .4byte 0x0000085C
_080636B4: .4byte 0x00000842
_080636B8: .4byte 0x00000844
_080636BC: .4byte 0x0000084A
_080636C0: .4byte 0x00000846
_080636C4: .4byte 0x0300137C
	.syntax divided
