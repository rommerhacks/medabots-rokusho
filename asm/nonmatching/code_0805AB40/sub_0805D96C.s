	.syntax unified

	thumb_func_start sub_0805D96C
sub_0805D96C: @ 0x0805D96C
	push {lr}
	bl poll_choice_menu
	cmp r0, #0
	beq _0805D9AE
	bl sub_0803FB0C
	ldr r0, _0805D99C @ =0x03000440
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #0
	bne _0805D9A8
	ldr r2, _0805D9A0 @ =0x0300137C
	ldr r0, _0805D9A4 @ =0x03001784
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	movs r1, #6
	cmp r0, #0
	beq _0805D996
	movs r1, #0xd
_0805D996:
	str r1, [r2]
	b _0805D9AE
	.align 2, 0
_0805D99C: .4byte 0x03000440
_0805D9A0: .4byte 0x0300137C
_0805D9A4: .4byte 0x03001784
_0805D9A8:
	ldr r1, _0805D9B4 @ =0x0300137C
	movs r0, #9
	str r0, [r1]
_0805D9AE:
	pop {r0}
	bx r0
	.align 2, 0
_0805D9B4: .4byte 0x0300137C
	.syntax divided
