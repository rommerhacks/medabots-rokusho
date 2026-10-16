	.syntax unified

	thumb_func_start calc_medaforce_gauge_from_damage
calc_medaforce_gauge_from_damage: @ 0x080126EC
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	movs r2, #0
	ldr r7, _0801274C @ =0x03001800
	ldr r0, _08012750 @ =0x03000590
	ldr r3, _08012754 @ =0x000003A1
	adds r1, r0, r3
	ldr r4, _08012758 @ =0x00000389
	adds r5, r0, r4
	subs r4, #0x30
	adds r3, r0, r4
	movs r4, #0x80
	lsls r4, r4, #1
_08012706:
	ldrb r0, [r1, #0x19]
	cmp r0, #0
	beq _0801272C
	ldrb r0, [r3]
	cmp r0, #0
	bne _08012714
	adds r2, #8
_08012714:
	ldrb r0, [r3, #0x18]
	cmp r0, #0
	bne _0801271C
	adds r2, #0x10
_0801271C:
	ldrb r0, [r5]
	cmp r0, #0
	bne _08012724
	adds r2, #0x10
_08012724:
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801272C
	adds r2, #0x10
_0801272C:
	adds r1, r1, r4
	adds r5, r5, r4
	adds r3, r3, r4
	adds r6, #1
	cmp r6, #2
	bls _08012706
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r7, r0
	lsls r0, r2, #1
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801274C: .4byte 0x03001800
_08012750: .4byte 0x03000590
_08012754: .4byte 0x000003A1
_08012758: .4byte 0x00000389
	.syntax divided
