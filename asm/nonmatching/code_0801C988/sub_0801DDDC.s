	.syntax unified

	thumb_func_start sub_0801DDDC
sub_0801DDDC: @ 0x0801DDDC
	push {r4, r5, r6, lr}
	ldr r4, _0801DE14 @ =0x03001800
	adds r5, r4, #0
	adds r5, #0x87
	ldrb r0, [r5]
	adds r6, r4, #0
	adds r6, #0xde
	ldrb r1, [r6]
	bl sub_08035928
	ldrb r0, [r5]
	ldr r2, _0801DE18 @ =0x03000590
	ldrb r1, [r6]
	subs r1, #1
	lsls r1, r1, #8
	adds r1, r1, r2
	adds r1, #0xde
	ldrb r1, [r1]
	bl sub_08035944
	adds r1, r4, #0
	adds r1, #0xb5
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801DE14: .4byte 0x03001800
_0801DE18: .4byte 0x03000590
	.syntax divided
