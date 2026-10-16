	.syntax unified

	thumb_func_start sub_08030CFC
sub_08030CFC: @ 0x08030CFC
	push {lr}
	ldr r1, _08030D1C @ =0x03000590
	ldr r0, _08030D20 @ =0x03001800
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r1
	adds r0, #0xc1
	ldrb r0, [r0]
	cmp r0, #0x50
	bne _08030D28
	ldr r1, _08030D24 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	b _08030D30
	.align 2, 0
_08030D1C: .4byte 0x03000590
_08030D20: .4byte 0x03001800
_08030D24: .4byte 0x0300137C
_08030D28:
	bl sub_0801AEB4
	ldr r1, _08030D38 @ =0x0300137C
	movs r0, #0x14
_08030D30:
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08030D38: .4byte 0x0300137C
	.syntax divided
