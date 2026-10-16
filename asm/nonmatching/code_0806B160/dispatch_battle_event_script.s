	.syntax unified

	thumb_func_start dispatch_battle_event_script
dispatch_battle_event_script: @ 0x0806E238
	push {r4, lr}
	ldr r1, _0806E260 @ =0x08486EEC
	ldr r4, _0806E264 @ =0x03001800
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl run_message
	cmp r0, #0
	beq _0806E258
	movs r0, #5
	strh r0, [r4, #4]
	ldr r1, _0806E268 @ =0x0300137C
	movs r0, #2
	str r0, [r1]
_0806E258:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0806E260: .4byte 0x08486EEC
_0806E264: .4byte 0x03001800
_0806E268: .4byte 0x0300137C
	.syntax divided
