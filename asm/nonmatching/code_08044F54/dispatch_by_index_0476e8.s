	.syntax unified

	thumb_func_start dispatch_by_index_0476e8
	.global dispatch_by_index_0476e8
dispatch_by_index_0476e8: @ 0x080476E8
	push {lr}
	cmp r0, #0xc
	bls _080476F0
	b _0804783A
_080476F0:
	lsls r0, r0, #2
	ldr r1, _080476FC @ =_08047700
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080476FC: .4byte _08047700
_08047700: @ jump table
	.4byte _0804782A @ case 0
	.4byte _0804782A @ case 1
	.4byte _0804782A @ case 2
	.4byte _0804782A @ case 3
	.4byte _08047734 @ case 4
	.4byte _08047750 @ case 5
	.4byte _0804776C @ case 6
	.4byte _0804778C @ case 7
	.4byte _08047798 @ case 8
	.4byte _08047824 @ case 9
	.4byte _080477A4 @ case 10
	.4byte _080477DC @ case 11
	.4byte _0804782A @ case 12
_08047734:
	ldr r0, _08047744 @ =0x0300178C
	movs r1, #1
	str r1, [r0]
	ldr r0, _08047748 @ =0x03002B8C
	str r1, [r0]
	ldr r1, _0804774C @ =0x0300137C
	movs r0, #0x10
	b _08047838
	.align 2, 0
_08047744: .4byte 0x0300178C
_08047748: .4byte 0x03002B8C
_0804774C: .4byte 0x0300137C
_08047750:
	ldr r0, _08047760 @ =0x0300178C
	movs r1, #1
	str r1, [r0]
	ldr r0, _08047764 @ =0x03002B8C
	str r1, [r0]
	ldr r1, _08047768 @ =0x0300137C
	movs r0, #0x20
	b _08047838
	.align 2, 0
_08047760: .4byte 0x0300178C
_08047764: .4byte 0x03002B8C
_08047768: .4byte 0x0300137C
_0804776C:
	ldr r1, _08047780 @ =0x0300178C
	movs r0, #1
	str r0, [r1]
	ldr r1, _08047784 @ =0x03002B8C
	movs r0, #2
	str r0, [r1]
	ldr r1, _08047788 @ =0x0300137C
	movs r0, #8
	b _08047838
	.align 2, 0
_08047780: .4byte 0x0300178C
_08047784: .4byte 0x03002B8C
_08047788: .4byte 0x0300137C
_0804778C:
	ldr r1, _08047794 @ =0x03006D20
	movs r0, #7
	strb r0, [r1, #0xc]
	b _0804782A
	.align 2, 0
_08047794: .4byte 0x03006D20
_08047798:
	ldr r1, _080477A0 @ =0x03006D20
	movs r0, #8
	strb r0, [r1, #0xc]
	b _0804782A
	.align 2, 0
_080477A0: .4byte 0x03006D20
_080477A4:
	bl sub_08047574
	ldr r0, _080477C8 @ =0x030057E0
	movs r1, #0xcc
	lsls r1, r1, #4
	bl sub_080496C8
	ldr r1, _080477CC @ =0x03000588
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080477D0 @ =0x0300178C
	movs r1, #1
	str r1, [r0]
	ldr r0, _080477D4 @ =0x03002B8C
	str r1, [r0]
	ldr r1, _080477D8 @ =0x0300137C
	movs r0, #0
	b _08047838
	.align 2, 0
_080477C8: .4byte 0x030057E0
_080477CC: .4byte 0x03000588
_080477D0: .4byte 0x0300178C
_080477D4: .4byte 0x03002B8C
_080477D8: .4byte 0x0300137C
_080477DC:
	bl sub_08047574
	ldr r0, _08047808 @ =0x030057E0
	ldr r2, _0804780C @ =0x00000C88
	adds r1, r0, r2
	movs r2, #0
	strb r2, [r1]
	ldr r1, _08047810 @ =0x00000C89
	adds r0, r0, r1
	strb r2, [r0]
	ldr r1, _08047814 @ =0x03000588
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08047818 @ =0x0300178C
	movs r1, #1
	str r1, [r0]
	ldr r0, _0804781C @ =0x03002B8C
	str r1, [r0]
	ldr r1, _08047820 @ =0x0300137C
	movs r0, #0xa
	b _08047838
	.align 2, 0
_08047808: .4byte 0x030057E0
_0804780C: .4byte 0x00000C88
_08047810: .4byte 0x00000C89
_08047814: .4byte 0x03000588
_08047818: .4byte 0x0300178C
_0804781C: .4byte 0x03002B8C
_08047820: .4byte 0x0300137C
_08047824:
	ldr r1, _08047840 @ =0x03000588
	movs r0, #1
	strb r0, [r1]
_0804782A:
	ldr r0, _08047844 @ =0x0300178C
	movs r1, #1
	str r1, [r0]
	ldr r0, _08047848 @ =0x03002B8C
	str r1, [r0]
	ldr r1, _0804784C @ =0x0300137C
	movs r0, #5
_08047838:
	str r0, [r1]
_0804783A:
	pop {r0}
	bx r0
	.align 2, 0
_08047840: .4byte 0x03000588
_08047844: .4byte 0x0300178C
_08047848: .4byte 0x03002B8C
_0804784C: .4byte 0x0300137C
	.syntax divided
