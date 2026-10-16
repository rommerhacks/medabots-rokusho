	.syntax unified

	thumb_func_start sub_0805F81C
sub_0805F81C: @ 0x0805F81C
	push {lr}
	bl poll_choice_menu
	cmp r0, #0
	beq _0805F858
	ldr r0, _0805F844 @ =0x03006F74
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #2]
	bl sub_0803FB0C
	ldr r0, _0805F848 @ =0x03000440
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne _0805F850
	ldr r1, _0805F84C @ =0x0300137C
	movs r0, #9
	b _0805F856
	.align 2, 0
_0805F844: .4byte 0x03006F74
_0805F848: .4byte 0x03000440
_0805F84C: .4byte 0x0300137C
_0805F850:
	ldr r1, _0805F85C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
_0805F856:
	str r0, [r1]
_0805F858:
	pop {r0}
	bx r0
	.align 2, 0
_0805F85C: .4byte 0x0300137C
	.syntax divided
