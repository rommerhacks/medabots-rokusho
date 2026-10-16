	.syntax unified

	thumb_func_start sub_0801EA94
sub_0801EA94: @ 0x0801EA94
	push {r4, lr}
	ldr r4, _0801EAC0 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0xf8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	movs r1, #0
	cmp r0, #0
	bne _0801EAAA
	movs r1, #1
_0801EAAA:
	adds r0, r1, #0
	bl sub_08036BF4
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801EAC0: .4byte 0x03001800
_0801EAC4:
	.byte 0x02, 0x48, 0xB5, 0x30, 0x01, 0x21, 0x01, 0x70, 0x70, 0x47, 0x00, 0x00
	.byte 0x00, 0x18, 0x00, 0x03
	.syntax divided
