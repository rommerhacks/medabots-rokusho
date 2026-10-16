	.syntax unified

	thumb_func_start sub_08025C84
sub_08025C84: @ 0x08025C84
	push {r4, r5, lr}
	ldr r4, _08025CDC @ =0x03000590
	ldr r5, _08025CE0 @ =0x03001800
	adds r0, r5, #0
	adds r0, #0x88
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r0, r0, r4
	adds r0, #0xc1
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0xec
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl sub_080374E0
	adds r0, r5, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	adds r3, r5, #0
	adds r3, #0x51
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0x87
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r2, r0, r4
	adds r0, r2, #0
	adds r0, #0xc0
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08025CE4
	adds r0, r2, #0
	adds r0, #0xc1
	ldrb r0, [r0]
	ldrb r2, [r3]
	lsls r2, r2, #1
	movs r1, #0x50
	bl sub_0803752C
	b _08025CF2
	.align 2, 0
_08025CDC: .4byte 0x03000590
_08025CE0: .4byte 0x03001800
_08025CE4:
	adds r0, r2, #0
	adds r0, #0xc1
	ldrb r0, [r0]
	ldrb r2, [r3]
	movs r1, #0x50
	bl sub_0803752C
_08025CF2:
	ldr r4, _08025D28 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0x52
	strb r0, [r1]
	adds r2, r4, #0
	adds r2, #0x87
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0x64
	strb r1, [r0]
	adds r0, #0x24
	ldrb r0, [r0]
	strb r0, [r2]
	bl sub_0801AEB4
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08025D28: .4byte 0x03001800
	.syntax divided
