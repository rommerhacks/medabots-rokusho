	.syntax unified

	thumb_func_start sound_channel_state_dispatch
sound_channel_state_dispatch: @ 0x08073E48
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r2, #0
	adds r4, #0x3e
	ldrb r0, [r4]
	subs r0, #1
	cmp r0, #4
	bhi _08073EA6
	lsls r0, r0, #2
	ldr r1, _08073E64 @ =_08073E68
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08073E64: .4byte _08073E68
_08073E68: @ jump table
	.4byte _08073E7C @ case 0
	.4byte _08073E84 @ case 1
	.4byte _08073E8C @ case 2
	.4byte _08073E94 @ case 3
	.4byte _08073E9C @ case 4
_08073E7C:
	adds r0, r2, #0
	bl sound_channel_init_full
	b _08073EA2
_08073E84:
	adds r0, r2, #0
	bl sound_start_channel_full
	b _08073EA2
_08073E8C:
	adds r0, r2, #0
	bl sound_restart_channel
	b _08073EA2
_08073E94:
	adds r0, r2, #0
	bl sound_channel_request_stop
	b _08073EA2
_08073E9C:
	adds r0, r2, #0
	bl sound_channel_trigger_pending
_08073EA2:
	movs r0, #0
	strb r0, [r4]
_08073EA6:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
