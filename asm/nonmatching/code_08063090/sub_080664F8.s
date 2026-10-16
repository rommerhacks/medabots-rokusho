	.syntax unified

	thumb_func_start sub_080664F8
sub_080664F8: @ 0x080664F8
	push {lr}
	bl poll_choice_menu
	cmp r0, #0
	beq _0806652C
	ldr r0, _0806651C @ =0x03000440
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne _08066524
	ldr r1, _08066520 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bl sub_0803FB0C
	b _0806652C
	.align 2, 0
_0806651C: .4byte 0x03000440
_08066520: .4byte 0x0300137C
_08066524:
	ldr r1, _08066530 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #3
	str r0, [r1]
_0806652C:
	pop {r0}
	bx r0
	.align 2, 0
_08066530: .4byte 0x0300137C
	.syntax divided
