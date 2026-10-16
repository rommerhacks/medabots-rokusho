	.syntax unified

	thumb_func_start clear_battle_action_selection
clear_battle_action_selection: @ 0x08032F64
	push {r4, lr}
	ldr r3, _08032FB0 @ =0x03001800
	adds r0, r3, #0
	adds r0, #0x5e
	movs r2, #0
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	ldr r4, _08032FB4 @ =0x03000590
	movs r0, #0x5d
	adds r0, r0, r3
	mov ip, r0
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r3, #0x5c
	ldrb r1, [r3]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r4
	adds r0, #0x56
	strb r2, [r0]
	mov r0, ip
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrb r1, [r3]
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r4
	adds r0, #0x57
	strb r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08032FB0: .4byte 0x03001800
_08032FB4: .4byte 0x03000590
	.syntax divided
