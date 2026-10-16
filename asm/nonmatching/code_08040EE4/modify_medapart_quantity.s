	.syntax unified

	thumb_func_start modify_medapart_quantity
	.global modify_medapart_quantity
modify_medapart_quantity: @ 0x08043560
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	ldr r6, [sp, #0x10]
	cmp r3, #0
	beq _08043588
	ldr r2, _08043584 @ =0x03004C40
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	lsls r1, r4, #1
	adds r0, r0, r1
	adds r0, r0, r5
	adds r0, r0, r2
	ldrb r1, [r0]
	subs r1, r1, r6
	strb r1, [r0]
	b _080435A4
	.align 2, 0
_08043584: .4byte 0x03004C40
_08043588:
	ldr r2, _080435AC @ =0x03004C40
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	lsls r1, r4, #1
	adds r0, r0, r1
	adds r0, r0, r5
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, r0, r6
	cmp r0, #0x63
	bls _080435A2
	movs r0, #0x63
_080435A2:
	strb r0, [r1]
_080435A4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080435AC: .4byte 0x03004C40
	.syntax divided
