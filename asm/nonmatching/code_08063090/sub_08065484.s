	.syntax unified

	thumb_func_start sub_08065484
sub_08065484: @ 0x08065484
	push {r4, r5, lr}
	movs r5, #1
	ldr r4, _080654B0 @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x4c
	ldrb r0, [r0]
	cmp r0, #0
	beq _080654B4
	bl game_state_execute_handler_a
	cmp r0, #0
	beq _080654C2
	ldr r0, [r4]
	adds r0, #0x4c
	movs r1, #0
	strb r1, [r0]
	movs r0, #1
	movs r2, #0
	bl text_window_init
	b _080654C2
	.align 2, 0
_080654B0: .4byte 0x03006F74
_080654B4:
	ldr r0, _080654E8 @ =0x08485788
	ldr r0, [r0, #0x38]
	bl run_message
	cmp r0, #0
	beq _080654C2
	movs r5, #0
_080654C2:
	cmp r5, #0
	bne _0806554C
	bl poll_choice_menu
	adds r5, r0, #0
	cmp r5, #0
	beq _0806554C
	movs r4, #0xf0
	ands r4, r5
	cmp r4, #0
	beq _080654F4
	ldr r0, _080654EC @ =0x03006F74
	ldr r0, [r0]
	adds r0, #0x4c
	movs r1, #1
	strb r1, [r0]
	ldr r1, _080654F0 @ =0x0300137C
	movs r0, #5
	b _0806554A
	.align 2, 0
_080654E8: .4byte 0x08485788
_080654EC: .4byte 0x03006F74
_080654F0: .4byte 0x0300137C
_080654F4:
	ldr r1, _08065514 @ =0x03002B70
	ldr r0, [r1]
	cmp r0, #0x63
	bhi _08065520
	ldr r1, _08065518 @ =0x0300137C
	movs r0, #8
	str r0, [r1]
	ldr r0, _0806551C @ =0x03006F74
	ldr r0, [r0]
	movs r1, #0xb4
	strh r1, [r0, #0x3a]
	adds r0, #0x4c
	movs r1, #1
	strb r1, [r0]
	b _0806554C
	.align 2, 0
_08065514: .4byte 0x03002B70
_08065518: .4byte 0x0300137C
_0806551C: .4byte 0x03006F74
_08065520:
	subs r0, #0x64
	str r0, [r1]
	ldr r2, _08065554 @ =0x030017EC
	ldr r0, _08065558 @ =0x03006F74
	ldr r3, [r0]
	adds r0, r3, #0
	adds r0, #0x2e
	ldrb r1, [r0]
	adds r0, #1
	ldrb r0, [r0]
	adds r1, r1, r0
	adds r0, r3, #0
	adds r0, #0xb0
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, _0806555C @ =0x03000440
	adds r0, #0x84
	strb r4, [r0]
	ldr r1, _08065560 @ =0x0300137C
	movs r0, #6
_0806554A:
	str r0, [r1]
_0806554C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08065554: .4byte 0x030017EC
_08065558: .4byte 0x03006F74
_0806555C: .4byte 0x03000440
_08065560: .4byte 0x0300137C
	.syntax divided
