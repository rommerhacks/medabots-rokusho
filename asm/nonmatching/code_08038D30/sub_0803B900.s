	.syntax unified

	thumb_func_start sub_0803B900
sub_0803B900: @ 0x0803B900
	push {r4, lr}
	ldr r4, _0803B940 @ =0x03002C30
	ldr r0, _0803B944 @ =0x03000440
	ldr r1, _0803B948 @ =0x0000012F
	adds r3, r0, r1
	ldrb r1, [r3]
	lsls r0, r1, #6
	adds r0, r0, r4
	adds r2, r0, #0
	adds r2, #0x2b
	ldrb r0, [r2]
	cmp r0, #0
	beq _0803B99C
	cmp r1, #1
	bne _0803B954
	ldr r0, _0803B94C @ =0x03001800
	ldr r1, _0803B950 @ =0x0000015F
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B99C
	movs r0, #0
	strb r0, [r2]
	ldrb r0, [r3]
	lsls r0, r0, #6
	adds r1, r0, r4
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803B976
	b _0803B994
	.align 2, 0
_0803B940: .4byte 0x03002C30
_0803B944: .4byte 0x03000440
_0803B948: .4byte 0x0000012F
_0803B94C: .4byte 0x03001800
_0803B950: .4byte 0x0000015F
_0803B954:
	ldr r0, _0803B990 @ =0x03001800
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B99C
	movs r0, #0
	strb r0, [r2]
	ldrb r0, [r3]
	lsls r0, r0, #6
	adds r1, r0, r4
	adds r0, r1, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B994
_0803B976:
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #6
	adds r0, r0, r4
	adds r0, #0x29
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	b _0803B99C
	.align 2, 0
_0803B990: .4byte 0x03001800
_0803B994:
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0803B99C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
