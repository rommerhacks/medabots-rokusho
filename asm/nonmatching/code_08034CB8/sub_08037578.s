	.syntax unified

	thumb_func_start sub_08037578
	.global sub_08037578
sub_08037578: @ 0x08037578
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r6, #0
	bl rng_next_080424B8
	cmp r5, #1
	beq _080375EC
	cmp r5, #1
	blo _080375A0
	cmp r5, #2
	beq _08037614
	cmp r5, #3
	beq _0803763C
	cmp r4, #1
	bne _0803759A
	b _08037674
_0803759A:
	cmp r4, #1
	blo _0803766A
	b _08037664
_080375A0:
	cmp r4, #1
	beq _080375C4
	cmp r4, #1
	blo _080375AE
	cmp r4, #2
	beq _080375D8
	b _0803768C
_080375AE:
	ldr r2, _080375BC @ =0x083CED08
	ldr r0, _080375C0 @ =0x03000440
	adds r0, #0x8c
	ldrb r1, [r0]
	movs r0, #0x7f
	b _08037686
	.align 2, 0
_080375BC: .4byte 0x083CED08
_080375C0: .4byte 0x03000440
_080375C4:
	ldr r2, _080375D0 @ =0x083CED88
	ldr r0, _080375D4 @ =0x03000440
	adds r0, #0x8c
	ldrb r1, [r0]
	movs r0, #0x7f
	b _08037686
	.align 2, 0
_080375D0: .4byte 0x083CED88
_080375D4: .4byte 0x03000440
_080375D8:
	ldr r2, _080375E4 @ =0x083CEE08
	ldr r0, _080375E8 @ =0x03000440
	adds r0, #0x8c
	ldrb r1, [r0]
	movs r0, #0x7f
	b _08037686
	.align 2, 0
_080375E4: .4byte 0x083CEE08
_080375E8: .4byte 0x03000440
_080375EC:
	cmp r4, #1
	beq _08037604
	cmp r4, #1
	blo _080375FA
	cmp r4, #2
	beq _0803760C
	b _0803768C
_080375FA:
	ldr r2, _08037600 @ =0x083CEE88
	b _0803767E
	.align 2, 0
_08037600: .4byte 0x083CEE88
_08037604:
	ldr r2, _08037608 @ =0x083CEEC8
	b _0803767E
	.align 2, 0
_08037608: .4byte 0x083CEEC8
_0803760C:
	ldr r2, _08037610 @ =0x083CEF08
	b _0803767E
	.align 2, 0
_08037610: .4byte 0x083CEF08
_08037614:
	cmp r4, #1
	beq _0803762C
	cmp r4, #1
	blo _08037622
	cmp r4, #2
	beq _08037634
	b _0803768C
_08037622:
	ldr r2, _08037628 @ =0x083CEF48
	b _0803767E
	.align 2, 0
_08037628: .4byte 0x083CEF48
_0803762C:
	ldr r2, _08037630 @ =0x083CEF88
	b _0803767E
	.align 2, 0
_08037630: .4byte 0x083CEF88
_08037634:
	ldr r2, _08037638 @ =0x083CEFC8
	b _0803767E
	.align 2, 0
_08037638: .4byte 0x083CEFC8
_0803763C:
	cmp r4, #1
	beq _08037654
	cmp r4, #1
	blo _0803764A
	cmp r4, #2
	beq _0803765C
	b _0803768C
_0803764A:
	ldr r2, _08037650 @ =0x083CF008
	b _0803767E
	.align 2, 0
_08037650: .4byte 0x083CF008
_08037654:
	ldr r2, _08037658 @ =0x083CF048
	b _0803767E
	.align 2, 0
_08037658: .4byte 0x083CF048
_0803765C:
	ldr r2, _08037660 @ =0x083CF088
	b _0803767E
	.align 2, 0
_08037660: .4byte 0x083CF088
_08037664:
	cmp r4, #2
	beq _0803767C
	b _0803768C
_0803766A:
	ldr r2, _08037670 @ =0x083CF0C8
	b _0803767E
	.align 2, 0
_08037670: .4byte 0x083CF0C8
_08037674:
	ldr r2, _08037678 @ =0x083CF108
	b _0803767E
	.align 2, 0
_08037678: .4byte 0x083CF108
_0803767C:
	ldr r2, _08037694 @ =0x083CF148
_0803767E:
	ldr r0, _08037698 @ =0x03000440
	adds r0, #0x8c
	ldrb r1, [r0]
	movs r0, #0x3f
_08037686:
	ands r0, r1
	adds r0, r0, r2
	ldrb r6, [r0]
_0803768C:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08037694: .4byte 0x083CF148
_08037698: .4byte 0x03000440
	.syntax divided
