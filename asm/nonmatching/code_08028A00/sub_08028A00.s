	.syntax unified

	thumb_func_start sub_08028A00
sub_08028A00: @ 0x08028A00
	push {r4, lr}
	movs r2, #0
	ldr r1, _08028A20 @ =0x03001800
	adds r4, r1, #0
	adds r4, #0xd2
	adds r3, r1, #0
	adds r3, #0xaa
_08028A0E:
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _08028A24
	ldrb r0, [r3]
	adds r0, #2
	strb r0, [r3]
	b _08028A32
	.align 2, 0
_08028A20: .4byte 0x03001800
_08028A24:
	adds r2, #1
	cmp r2, #2
	bls _08028A0E
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08028A32:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
