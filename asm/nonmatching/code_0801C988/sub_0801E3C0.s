	.syntax unified

	thumb_func_start sub_0801E3C0
sub_0801E3C0: @ 0x0801E3C0
	push {r4, lr}
	ldr r4, _0801E3E4 @ =0x03001800
	adds r1, r4, #0
	adds r1, #0xb9
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xb7
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801E3E8
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0x28
	b _0801E432
	.align 2, 0
_0801E3E4: .4byte 0x03001800
_0801E3E8:
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0801E3FC
	bl sub_0803628C
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0xa
	b _0801E432
_0801E3FC:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801E412
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0x30
	b _0801E432
_0801E412:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0801E422
	adds r1, r4, #0
	adds r1, #0xaa
	movs r0, #0x38
	b _0801E432
_0801E422:
	bl sub_08036270
	bl sub_0803628C
	adds r1, r4, #0
	adds r1, #0xaa
	ldrb r0, [r1]
	adds r0, #1
_0801E432:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
