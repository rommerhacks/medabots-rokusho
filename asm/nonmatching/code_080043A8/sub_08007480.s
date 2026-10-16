	.syntax unified

	thumb_func_start sub_08007480
sub_08007480: @ 0x08007480
	push {r4, r5, r6, lr}
	ldr r2, _080074BC @ =0x03000440
	adds r0, r2, #0
	adds r0, #0x5c
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	beq _080074CC
	movs r2, #0
	ldr r5, _080074C0 @ =0x03001841
	ldr r0, _080074C4 @ =0x03002C30
	ldr r4, _080074C8 @ =0x0000BFFF
	movs r1, #0x80
	lsls r1, r1, #1
	adds r3, r0, r1
_080074A2:
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080074B2
	ldrh r1, [r3]
	adds r0, r4, #0
	ands r0, r1
	strh r0, [r3]
_080074B2:
	adds r3, #0x40
	adds r2, #1
	cmp r2, #2
	bls _080074A2
	b _080074F4
	.align 2, 0
_080074BC: .4byte 0x03000440
_080074C0: .4byte 0x03001841
_080074C4: .4byte 0x03002C30
_080074C8: .4byte 0x0000BFFF
_080074CC:
	movs r2, #0
	ldr r4, _08007504 @ =0x03001841
	ldr r0, _08007508 @ =0x03002C30
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r0, r3
	movs r0, #0x80
	lsls r0, r0, #7
	adds r3, r0, #0
_080074DE:
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080074EC
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
_080074EC:
	adds r1, #0x40
	adds r2, #1
	cmp r2, #2
	bls _080074DE
_080074F4:
	adds r1, r6, #0
	adds r1, #0x5c
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08007504: .4byte 0x03001841
_08007508: .4byte 0x03002C30
	.syntax divided
