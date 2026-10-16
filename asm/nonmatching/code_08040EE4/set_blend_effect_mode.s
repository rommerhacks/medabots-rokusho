	.syntax unified

	thumb_func_start set_blend_effect_mode
	.global set_blend_effect_mode
set_blend_effect_mode: @ 0x0804253C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	ldr r1, _0804256C @ =0x03000440
	mov ip, r1
	adds r1, #0x90
	movs r3, #0
	strb r0, [r1]
	mov r1, ip
	adds r1, #0x92
	strh r2, [r1]
	adds r1, #2
	strh r3, [r1]
	subs r0, #1
	cmp r0, #5
	bhi _080425AA
	lsls r0, r0, #2
	ldr r1, _08042570 @ =_08042574
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804256C: .4byte 0x03000440
_08042570: .4byte _08042574
_08042574: @ jump table
	.4byte _0804258C @ case 0
	.4byte _08042590 @ case 1
	.4byte _08042594 @ case 2
	.4byte _08042598 @ case 3
	.4byte _0804259C @ case 4
	.4byte _080425A6 @ case 5
_0804258C:
	movs r5, #0x40
	b _0804259E
_08042590:
	movs r5, #0x40
	b _080425AC
_08042594:
	movs r5, #0x80
	b _0804259E
_08042598:
	movs r5, #0x80
	b _080425AC
_0804259C:
	movs r5, #0xc0
_0804259E:
	movs r4, #0x10
	movs r0, #0x10
	movs r3, #0x10
	b _080425B2
_080425A6:
	movs r5, #0xc0
	b _080425AC
_080425AA:
	movs r5, #0
_080425AC:
	movs r4, #0
	movs r0, #0
	movs r3, #0
_080425B2:
	ldr r2, _080425D4 @ =0x04000052
	movs r1, #0x1f
	ands r0, r1
	lsls r0, r0, #8
	ands r4, r1
	orrs r0, r4
	strh r0, [r2]
	ldr r0, _080425D8 @ =0x04000054
	ands r3, r1
	strh r3, [r0]
	subs r0, #4
	orrs r5, r6
	strh r5, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080425D4: .4byte 0x04000052
_080425D8: .4byte 0x04000054
	.syntax divided
