	.syntax unified

	thumb_func_start sub_0803496C
sub_0803496C: @ 0x0803496C
	push {r4, r5, r6, r7, lr}
	ldr r4, _080349CC @ =0x03001800
	adds r0, r4, #0
	adds r0, #0x87
	ldrb r0, [r0]
	bl sub_08032FC4
	adds r4, #0x60
	strb r0, [r4]
	movs r2, #0
	ldr r5, _080349D0 @ =0x03000590
	ldrb r6, [r4]
	adds r7, r5, #0
	adds r7, #0x59
_08034988:
	adds r0, r6, r2
	lsls r0, r0, #8
	adds r0, r0, r5
	adds r0, #0xba
	ldrb r0, [r0]
	adds r4, r2, #1
	cmp r0, #0
	beq _080349BA
	movs r3, #0
	ldr r1, _080349D4 @ =0x03001860
	ldrb r0, [r1]
	adds r0, r0, r2
	lsls r0, r0, #8
	adds r1, #0x8c
	adds r2, r0, r7
_080349A6:
	ldrb r0, [r2]
	cmp r0, #0
	bne _080349B2
	ldrh r0, [r1]
	adds r0, #0xa
	strh r0, [r1]
_080349B2:
	adds r2, #0x18
	adds r3, #1
	cmp r3, #3
	bls _080349A6
_080349BA:
	adds r2, r4, #0
	cmp r2, #2
	bls _08034988
	bl sub_08034F08
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080349CC: .4byte 0x03001800
_080349D0: .4byte 0x03000590
_080349D4: .4byte 0x03001860
	.syntax divided
