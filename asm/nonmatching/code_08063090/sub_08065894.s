	.syntax unified

	thumb_func_start sub_08065894
sub_08065894: @ 0x08065894
	push {r4, lr}
	ldr r2, _080658E8 @ =0x08485BD8
	ldr r4, _080658EC @ =0x03006F74
	ldr r0, [r4]
	ldr r0, [r0, #8]
	movs r1, #0x18
	cmp r0, #0
	beq _080658A6
	movs r1, #0x1c
_080658A6:
	adds r0, r1, r2
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _08065900
	ldr r0, _080658F0 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08065900
	movs r0, #0xd
	bl play_sound_effect
	ldr r1, [r4]
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	cmp r0, #1
	ble _080658FC
	ldr r2, _080658F4 @ =0x03000440
	adds r1, r2, #0
	adds r1, #0x84
	movs r0, #0
	strb r0, [r1]
	strb r0, [r2, #0x1b]
	ldr r1, _080658F8 @ =0x0300137C
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	b _08065900
	.align 2, 0
_080658E8: .4byte 0x08485BD8
_080658EC: .4byte 0x03006F74
_080658F0: .4byte 0x0300058C
_080658F4: .4byte 0x03000440
_080658F8: .4byte 0x0300137C
_080658FC:
	bl sub_0803FB0C
_08065900:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
