	.syntax unified

	thumb_func_start sub_0801AC24
sub_0801AC24: @ 0x0801AC24
	push {lr}
	adds r1, r0, #0
	ldr r0, _0801AC58 @ =0x03001360
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801AC3A
	ldr r0, _0801AC5C @ =0x03000440
	adds r0, #0x89
	ldrb r0, [r0]
	cmp r0, #1
	bne _0801AC64
_0801AC3A:
	ldr r0, _0801AC60 @ =0x083C65C4
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl run_message
	adds r2, r0, #0
	cmp r2, #0
	beq _0801AC52
	ldr r1, _0801AC5C @ =0x03000440
	movs r0, #0
	strb r0, [r1, #0x1b]
_0801AC52:
	adds r0, r2, #0
	b _0801AC66
	.align 2, 0
_0801AC58: .4byte 0x03001360
_0801AC5C: .4byte 0x03000440
_0801AC60: .4byte 0x083C65C4
_0801AC64:
	movs r0, #1
_0801AC66:
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
