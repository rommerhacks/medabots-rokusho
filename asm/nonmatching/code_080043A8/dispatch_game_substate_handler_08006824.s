	.syntax unified

	thumb_func_start dispatch_game_substate_handler_08006824
dispatch_game_substate_handler_08006824: @ 0x08006824
	push {lr}
	ldr r0, _08006848 @ =0x03001780
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08006890
	ldr r0, _0800684C @ =0x03000440
	adds r0, #0x5a
	ldrb r0, [r0]
	cmp r0, #4
	bhi _080068E6
	lsls r0, r0, #2
	ldr r1, _08006850 @ =_08006854
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08006848: .4byte 0x03001780
_0800684C: .4byte 0x03000440
_08006850: .4byte _08006854
_08006854: @ jump table
	.4byte _08006868 @ case 0
	.4byte _08006870 @ case 1
	.4byte _08006878 @ case 2
	.4byte _08006880 @ case 3
	.4byte _08006888 @ case 4
_08006868:
	movs r0, #0
	bl sub_08006238
	b _080068E6
_08006870:
	movs r0, #0
	bl sub_08006284
	b _080068E6
_08006878:
	movs r0, #0
	bl sub_080062D0
	b _080068E6
_08006880:
	movs r0, #0
	bl sub_0800631C
	b _080068E6
_08006888:
	movs r0, #0
	bl sub_08006368
	b _080068E6
_08006890:
	ldr r0, _080068A4 @ =0x03000440
	adds r0, #0x5a
	ldrb r0, [r0]
	cmp r0, #4
	bhi _080068E6
	lsls r0, r0, #2
	ldr r1, _080068A8 @ =_080068AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080068A4: .4byte 0x03000440
_080068A8: .4byte _080068AC
_080068AC: @ jump table
	.4byte _080068C0 @ case 0
	.4byte _080068C8 @ case 1
	.4byte _080068D0 @ case 2
	.4byte _080068D8 @ case 3
	.4byte _080068E0 @ case 4
_080068C0:
	movs r0, #1
	bl sub_08006238
	b _080068E6
_080068C8:
	movs r0, #1
	bl sub_08006284
	b _080068E6
_080068D0:
	movs r0, #1
	bl sub_080062D0
	b _080068E6
_080068D8:
	movs r0, #1
	bl sub_0800631C
	b _080068E6
_080068E0:
	movs r0, #1
	bl sub_08006368
_080068E6:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
