	.syntax unified

	thumb_func_start sub_080507E0
sub_080507E0: @ 0x080507E0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r6, #0
	ldr r0, _080507FC @ =0x03006D20
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	beq _08050848
	ldrb r0, [r3, #2]
	cmp r0, #0
	beq _08050800
	subs r0, #1
	b _08050808
	.align 2, 0
_080507FC: .4byte 0x03006D20
_08050800:
	ldrb r0, [r3, #1]
	adds r0, #1
	strb r0, [r3, #1]
	ldrb r0, [r3, #3]
_08050808:
	strb r0, [r3, #2]
	ldrb r0, [r3, #1]
	movs r5, #1
	adds r2, r5, #0
	ands r2, r0
	cmp r2, #0
	beq _0805082C
	ldr r0, _08050828 @ =0x03002C30
	lsls r1, r4, #6
	adds r1, r1, r0
	adds r2, r1, #0
	adds r2, #0x2d
	movs r0, #0
	strb r5, [r2]
	b _0805083A
	.align 2, 0
_08050828: .4byte 0x03002C30
_0805082C:
	ldr r0, _08050844 @ =0x03002C30
	lsls r1, r4, #6
	adds r1, r1, r0
	adds r0, r1, #0
	adds r0, #0x2d
	strb r2, [r0]
	ldrh r0, [r1, #0x32]
_0805083A:
	strh r0, [r1]
	ldrb r0, [r3]
	subs r0, #1
	strb r0, [r3]
	b _0805085A
	.align 2, 0
_08050844: .4byte 0x03002C30
_08050848:
	ldr r0, _08050864 @ =0x03002C30
	lsls r1, r4, #6
	adds r1, r1, r0
	adds r0, r1, #0
	adds r0, #0x2d
	strb r6, [r0]
	ldrh r0, [r1, #0x32]
	strh r0, [r1]
	movs r6, #1
_0805085A:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08050864: .4byte 0x03002C30
	.syntax divided
