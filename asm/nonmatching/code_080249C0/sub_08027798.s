	.syntax unified

	thumb_func_start sub_08027798
sub_08027798: @ 0x08027798
	push {r4, r5, r6, lr}
	movs r2, #0
	movs r4, #0
	ldr r6, _080277D4 @ =0x030018D2
	movs r5, #0x21
_080277A2:
	adds r0, r4, r6
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080277B8
	adds r0, r5, #0
	movs r1, #4
	bl update_sprite_animations_tick_080370AC
	adds r2, r0, #0
_080277B8:
	adds r5, #4
	adds r4, #1
	cmp r4, #2
	bls _080277A2
	cmp r2, #0
	beq _080277CE
	ldr r1, _080277D8 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080277CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080277D4: .4byte 0x030018D2
_080277D8: .4byte 0x03001800
	.syntax divided
