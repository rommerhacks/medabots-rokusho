	.syntax unified

	thumb_func_start sub_0801B53C
	.global sub_0801B53C
sub_0801B53C: @ 0x0801B53C
	push {r4, r5, lr}
	movs r0, #0
	bl sub_0801B4C8
	adds r4, r0, #0
	movs r0, #3
	bl sub_0801B4C8
	cmp r4, r0
	blo _0801B57A
	cmp r0, r4
	blo _0801B590
	movs r0, #0
	bl sub_0801B4F8
	adds r4, r0, #0
	movs r0, #3
	bl sub_0801B4F8
	cmp r4, r0
	blo _0801B57A
	cmp r0, r4
	blo _0801B590
	ldr r0, _0801B584 @ =0x03001800
	adds r1, r0, #0
	adds r1, #0x29
	adds r0, #0x31
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bls _0801B58C
_0801B57A:
	ldr r0, _0801B588 @ =0x03000440
	adds r0, #0x9c
	movs r1, #1
	strb r1, [r0]
	b _0801B5F6
	.align 2, 0
_0801B584: .4byte 0x03001800
_0801B588: .4byte 0x03000440
_0801B58C:
	cmp r1, r0
	bhs _0801B5A0
_0801B590:
	ldr r0, _0801B59C @ =0x03000440
	adds r0, #0x9c
	movs r1, #2
	strb r1, [r0]
	b _0801B5F6
	.align 2, 0
_0801B59C: .4byte 0x03000440
_0801B5A0:
	ldr r5, _0801B5C0 @ =0x03000440
	adds r0, r5, #0
	adds r0, #0x89
	ldrb r4, [r0]
	cmp r4, #1
	beq _0801B5C4
	bl rng_next_080424B8
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0801B5E6
	adds r0, r5, #0
	adds r0, #0x9c
	strb r1, [r0]
	b _0801B5F6
	.align 2, 0
_0801B5C0: .4byte 0x03000440
_0801B5C4:
	ldr r0, _0801B5D8 @ =0x03000B90
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801B5DC
	bl rng_next_080424B8
	ands r0, r4
	cmp r0, #0
	bne _0801B5F0
	b _0801B5E6
	.align 2, 0
_0801B5D8: .4byte 0x03000B90
_0801B5DC:
	bl rng_next_080424B8
	ands r0, r4
	cmp r0, #0
	beq _0801B5F0
_0801B5E6:
	adds r1, r5, #0
	adds r1, #0x9c
	movs r0, #2
	strb r0, [r1]
	b _0801B5F6
_0801B5F0:
	adds r0, r5, #0
	adds r0, #0x9c
	strb r4, [r0]
_0801B5F6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.syntax divided
