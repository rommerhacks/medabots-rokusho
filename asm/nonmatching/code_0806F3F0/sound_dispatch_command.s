	.syntax unified

	thumb_func_start sound_dispatch_command
sound_dispatch_command: @ 0x080724F4
	push {lr}
	adds r2, r0, #0
	adds r0, #0x62
	ldrb r0, [r0]
	cmp r0, #0
	beq _08072556
	adds r0, r2, #0
	adds r0, #0x61
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #4
	bhi _08072556
	lsls r0, r0, #2
	ldr r1, _08072518 @ =_0807251C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08072518: .4byte _0807251C
_0807251C: @ jump table
	.4byte _08072530 @ case 0
	.4byte _08072538 @ case 1
	.4byte _08072540 @ case 2
	.4byte _08072548 @ case 3
	.4byte _08072550 @ case 4
_08072530:
	adds r0, r2, #0
	bl sound_channel_tick_duration
	b _08072556
_08072538:
	adds r0, r2, #0
	bl sub_08072458
	b _08072556
_08072540:
	adds r0, r2, #0
	bl sub_080724A0
	b _08072556
_08072548:
	adds r0, r2, #0
	bl sub_080724E8
	b _08072556
_08072550:
	adds r0, r2, #0
	bl sound_channel_tick_decay
_08072556:
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
