	.syntax unified

	thumb_func_start battle_dispatch_action_by_type
battle_dispatch_action_by_type: @ 0x08015390
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r2, _080153B4 @ =0x03000590
	lsls r3, r5, #8
	adds r1, r3, r2
	adds r1, #0x3f
	ldrb r1, [r1]
	adds r1, r1, r3
	adds r2, #0x18
	adds r1, r1, r2
	ldrb r4, [r1]
	cmp r4, #7
	bhi _0801540E
	lsls r0, r4, #2
	ldr r1, _080153B8 @ =_080153BC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080153B4: .4byte 0x03000590
_080153B8: .4byte _080153BC
_080153BC: @ jump table
	.4byte _08015408 @ case 0
	.4byte _080153DC @ case 1
	.4byte _080153DC @ case 2
	.4byte _080153DC @ case 3
	.4byte _080153EE @ case 4
	.4byte _080153FA @ case 5
	.4byte _080153FA @ case 6
	.4byte _080153FA @ case 7
_080153DC:
	adds r0, r5, #0
	adds r1, r4, #0
	bl can_bot_perform_action
	cmp r0, #0
	bne _08015408
	adds r0, r5, #0
	adds r1, r4, #0
	b _080153F2
_080153EE:
	adds r0, r5, #0
	movs r1, #0
_080153F2:
	bl battle_bot_select_part
	movs r0, #0
	b _0801540E
_080153FA:
	subs r1, r4, #5
	adds r0, r5, #0
	movs r2, #0
	bl check_medaforce_availability
	cmp r0, #0
	beq _0801540C
_08015408:
	movs r0, #1
	b _0801540E
_0801540C:
	movs r0, #0
_0801540E:
	pop {r4, r5}
	pop {r1}
	bx r1
	.syntax divided
