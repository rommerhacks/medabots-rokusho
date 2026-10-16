	.syntax unified

	thumb_func_start sub_080336DC
sub_080336DC: @ 0x080336DC
	push {r4, r5, r6, r7, lr}
	ldr r4, _08033748 @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl sub_08032FB8
	adds r1, r4, #0
	adds r1, #0x60
	strb r0, [r1]
	movs r5, #0
	ldr r2, _0803374C @ =0x03000590
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
_08033708:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08033732
	movs r3, #0
	ldr r0, _08033750 @ =0x03001860
	ldrb r0, [r0]
	adds r0, r0, r5
	lsls r0, r0, #8
	adds r1, r0, r6
_0803371A:
	ldrb r0, [r1, #0xf]
	cmp r0, #0
	beq _0803372A
	ldrb r0, [r1]
	cmp r0, #0
	beq _08033742
	cmp r0, #1
	beq _08033742
_0803372A:
	adds r1, #0x18
	adds r3, #1
	cmp r3, #2
	bls _0803371A
_08033732:
	adds r4, r4, r2
	adds r5, #1
	cmp r5, #2
	bls _08033708
	adds r1, r7, #0
	adds r1, #0x51
	movs r0, #1
	strb r0, [r1]
_08033742:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08033748: .4byte 0x03001800
_0803374C: .4byte 0x03000590
_08033750: .4byte 0x03001860
	.syntax divided
