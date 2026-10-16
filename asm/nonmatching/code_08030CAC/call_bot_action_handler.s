	.syntax unified

	thumb_func_start call_bot_action_handler
call_bot_action_handler: @ 0x08031ABC
	push {r4, lr}
	ldr r4, _08031AF0 @ =0x083AEE10
	ldr r3, _08031AF4 @ =0x03000590
	ldr r2, _08031AF8 @ =0x03001800
	adds r0, r2, #0
	adds r0, #0x5d
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r2, #0x5c
	ldrb r1, [r2]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r3
	adds r0, #0x49
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	bl _call_via_r0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08031AF0: .4byte 0x083AEE10
_08031AF4: .4byte 0x03000590
_08031AF8: .4byte 0x03001800
	.syntax divided
