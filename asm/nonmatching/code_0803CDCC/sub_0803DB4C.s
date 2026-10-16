	.syntax unified

	thumb_func_start sub_0803DB4C
sub_0803DB4C: @ 0x0803DB4C
	push {lr}
	bl update_scroll_movement_a
	ldr r0, _0803DB84 @ =0x083C3984
	ldr r0, [r0, #4]
	bl run_message
	cmp r0, #0
	beq _0803DB7E
	ldr r0, _0803DB88 @ =0x0300058C
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0803DB7E
	ldr r1, _0803DB8C @ =0x03000440
	movs r0, #0
	strb r0, [r1, #0x1b]
	movs r0, #0xd
	bl play_sound_effect
	ldr r1, _0803DB90 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803DB7E:
	pop {r0}
	bx r0
	.align 2, 0
_0803DB84: .4byte 0x083C3984
_0803DB88: .4byte 0x0300058C
_0803DB8C: .4byte 0x03000440
_0803DB90: .4byte 0x0300137C
	.syntax divided
