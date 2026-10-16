	.syntax unified

	thumb_func_start sub_0805D9E4
sub_0805D9E4: @ 0x0805D9E4
	push {lr}
	bl poll_choice_menu
	cmp r0, #0
	beq _0805DA12
	bl sub_0803FB0C
	ldr r0, _0805DA04 @ =0x03000440
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne _0805DA0C
	ldr r1, _0805DA08 @ =0x0300137C
	movs r0, #6
	b _0805DA10
	.align 2, 0
_0805DA04: .4byte 0x03000440
_0805DA08: .4byte 0x0300137C
_0805DA0C:
	ldr r1, _0805DA18 @ =0x0300137C
	movs r0, #9
_0805DA10:
	str r0, [r1]
_0805DA12:
	pop {r0}
	bx r0
	.align 2, 0
_0805DA18: .4byte 0x0300137C
	.syntax divided
