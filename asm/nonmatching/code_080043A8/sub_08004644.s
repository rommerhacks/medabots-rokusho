	.syntax unified

	thumb_func_start sub_08004644
sub_08004644: @ 0x08004644
	push {r4, lr}
	movs r0, #0
	movs r1, #0x80
	bl clear_battle_sprite_slot
	ldr r0, _08004670 @ =0x03000440
	adds r1, r0, #0
	adds r1, #0x96
	movs r2, #0
	strb r2, [r1]
	ldr r1, _08004674 @ =0x03000430
	str r2, [r1]
	adds r0, #0x5a
	ldrb r0, [r0]
	cmp r0, #4
	bhi _08004750
	lsls r0, r0, #2
	ldr r1, _08004678 @ =_0800467C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08004670: .4byte 0x03000440
_08004674: .4byte 0x03000430
_08004678: .4byte _0800467C
_0800467C: @ jump table
	.4byte _08004690 @ case 0
	.4byte _080046C4 @ case 1
	.4byte _080046E8 @ case 2
	.4byte _08004708 @ case 3
	.4byte _08004728 @ case 4
_08004690:
	ldr r4, _080046B8 @ =0x0300047C
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	movs r0, #1
	strb r0, [r4]
	adds r0, r4, #0
	adds r0, #0x5b
	ldrb r0, [r0]
	strb r0, [r4, #1]
	bl sub_080070F0
	ldr r1, _080046BC @ =0x03002B8C
	movs r0, #4
	str r0, [r1]
	ldr r1, _080046C0 @ =0x0300137C
	movs r0, #8
	b _0800474E
	.align 2, 0
_080046B8: .4byte 0x0300047C
_080046BC: .4byte 0x03002B8C
_080046C0: .4byte 0x0300137C
_080046C4:
	ldr r4, _080046E4 @ =0x0300047C
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	movs r1, #0
	movs r0, #1
	strb r0, [r4]
	adds r0, r4, #0
	adds r0, #0x5c
	ldrb r0, [r0]
	strb r0, [r4, #1]
	strb r1, [r4, #2]
	b _08004744
	.align 2, 0
_080046E4: .4byte 0x0300047C
_080046E8:
	ldr r4, _08004704 @ =0x0300047C
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	movs r1, #1
	strb r1, [r4]
	adds r0, r4, #0
	adds r0, #0x5d
	ldrb r0, [r0]
	strb r0, [r4, #1]
	strb r1, [r4, #2]
	b _08004744
	.align 2, 0
_08004704: .4byte 0x0300047C
_08004708:
	ldr r4, _08004724 @ =0x0300047C
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	movs r0, #1
	strb r0, [r4]
	adds r0, r4, #0
	adds r0, #0x5e
	ldrb r0, [r0]
	strb r0, [r4, #1]
	movs r0, #2
	b _08004742
	.align 2, 0
_08004724: .4byte 0x0300047C
_08004728:
	ldr r4, _08004758 @ =0x0300047C
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl sub_0803F624
	movs r0, #1
	strb r0, [r4]
	adds r0, r4, #0
	adds r0, #0x5f
	ldrb r0, [r0]
	strb r0, [r4, #1]
	movs r0, #3
_08004742:
	strb r0, [r4, #2]
_08004744:
	ldr r1, _0800475C @ =0x03002B8C
	movs r0, #5
	str r0, [r1]
	ldr r1, _08004760 @ =0x0300137C
	movs r0, #0x10
_0800474E:
	str r0, [r1]
_08004750:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08004758: .4byte 0x0300047C
_0800475C: .4byte 0x03002B8C
_08004760: .4byte 0x0300137C
	.syntax divided
