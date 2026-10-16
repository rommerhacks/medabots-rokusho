	.syntax unified

	thumb_func_start sub_0802EF0C
sub_0802EF0C: @ 0x0802EF0C
	push {r4, r5, r6, lr}
	movs r5, #0
	movs r4, #0
	ldr r6, _0802EF50 @ =0x030018D2
_0802EF14:
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802EF2C
	adds r0, r4, #0
	adds r0, #0x24
	movs r1, #0
	bl medal_update_exp_progress
	cmp r0, #0
	beq _0802EF2C
	movs r5, #1
_0802EF2C:
	adds r4, #1
	cmp r4, #2
	bls _0802EF14
	cmp r5, #0
	beq _0802EF48
	ldr r0, _0802EF54 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	ldr r1, _0802EF58 @ =0x03001800
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802EF48:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802EF50: .4byte 0x030018D2
_0802EF54: .4byte 0x03000440
_0802EF58: .4byte 0x03001800
	.syntax divided
