	.syntax unified

	thumb_func_start sub_0802F89C
sub_0802F89C: @ 0x0802F89C
	push {r4, r5, lr}
	movs r4, #0
	movs r2, #0
	ldr r1, _0802F8D0 @ =0x03001800
	adds r5, r1, #0
	adds r5, #0xd2
	adds r3, r1, #0
	adds r3, #0xd6
_0802F8AC:
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802F8BC
	ldrh r0, [r3]
	cmp r0, #0
	beq _0802F8BC
	movs r4, #1
_0802F8BC:
	adds r3, #2
	adds r2, #1
	cmp r2, #2
	bls _0802F8AC
	cmp r4, #0
	bne _0802F8D4
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
	b _0802F8DA
	.align 2, 0
_0802F8D0: .4byte 0x03001800
_0802F8D4:
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #2
_0802F8DA:
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
