	.syntax unified

	thumb_func_start sub_08034644
sub_08034644: @ 0x08034644
	push {lr}
	bl sub_0802645C
	ldr r1, _08034668 @ =0x03001800
	adds r0, r1, #0
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08034678
	adds r0, r1, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #1
	bne _0803466C
	bl sub_08034F08
	b _08034678
	.align 2, 0
_08034668: .4byte 0x03001800
_0803466C:
	ldr r1, _0803467C @ =0x03002B8C
	movs r0, #8
	str r0, [r1]
	ldr r1, _08034680 @ =0x0300137C
	movs r0, #0
	str r0, [r1]
_08034678:
	pop {r0}
	bx r0
	.align 2, 0
_0803467C: .4byte 0x03002B8C
_08034680: .4byte 0x0300137C
	.syntax divided
