	.syntax unified

	thumb_func_start sub_08033754
sub_08033754: @ 0x08033754
	push {r4, r5, r6, r7, lr}
	ldr r4, _080337C0 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r2, _080337C4 @ =0x03000590
	ldrb r0, [r1]
	adds r7, r4, #0
	lsls r0, r0, #8
	adds r1, r2, #0
	adds r1, #0x40
	adds r4, r0, r1
	adds r6, r2, #0
	adds r6, #0x4a
	movs r2, #0x80
	lsls r2, r2, #1
_08033780:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080337AA
	movs r3, #0
	ldr r0, _080337C8 @ =0x03001860
	ldrb r0, [r0]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r1, r0, r6
_08033792:
	ldrb r0, [r1, #0xf]
	cmp r0, #0
	beq _080337A2
	ldrb r0, [r1]
	cmp r0, #2
	beq _080337BA
	cmp r0, #3
	beq _080337BA
_080337A2:
	adds r1, #0x18
	adds r3, #1
	cmp r3, #2
	bls _08033792
_080337AA:
	adds r4, r4, r2
	adds r5, #1
	cmp r5, #2
	bls _08033780
	adds r1, r7, #0
	adds r1, #0x51
	movs r0, #1
	strb r0, [r1]
_080337BA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080337C0: .4byte 0x03001800
_080337C4: .4byte 0x03000590
_080337C8: .4byte 0x03001860
	.syntax divided
