	.syntax unified

	thumb_func_start sub_0801E9FC
sub_0801E9FC: @ 0x0801E9FC
	push {r4, r5, r6, r7, lr}
	ldr r5, _0801EA54 @ =0x030018C8
	adds r6, r5, #0
	subs r6, #0x40
	ldrb r1, [r6]
	adds r0, r5, #0
	subs r0, #0x3d
	ldrb r2, [r0]
	adds r0, r5, #0
	bl sub_08036BB8
	adds r7, r0, #0
	adds r0, r5, #0
	adds r0, #0x30
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	movs r4, #0
	cmp r0, #0
	bne _0801EA26
	movs r4, #1
_0801EA26:
	ldrb r1, [r6]
	adds r0, r4, #0
	bl sub_08036370
	ldrb r1, [r6]
	adds r0, r4, #0
	bl sub_080364A8
	cmp r7, #0
	beq _0801EA4C
	ldr r0, _0801EA58 @ =0x03000440
	adds r0, #0x86
	movs r1, #0x3c
	strh r1, [r0]
	adds r1, r5, #0
	subs r1, #0x1e
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0801EA4C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801EA54: .4byte 0x030018C8
_0801EA58: .4byte 0x03000440
	.syntax divided
