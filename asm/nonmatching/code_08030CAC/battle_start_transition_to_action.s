	.syntax unified

	thumb_func_start battle_start_transition_to_action
battle_start_transition_to_action: @ 0x08031918
	push {r4, lr}
	ldr r0, _08031968 @ =0x03001800
	mov ip, r0
	movs r1, #0xb2
	lsls r1, r1, #1
	add r1, ip
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _0803196C @ =0x03000590
	mov r4, ip
	adds r4, #0x87
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xa8
	ldrb r0, [r0]
	adds r0, #0x50
	mov r1, ip
	adds r1, #0xa8
	strb r0, [r1]
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xe0
	strb r3, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #8
	adds r0, r0, r2
	adds r0, #0xe1
	strb r3, [r0]
	ldr r1, _08031970 @ =0x03002B8C
	movs r0, #9
	str r0, [r1]
	ldr r0, _08031974 @ =0x0300137C
	str r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08031968: .4byte 0x03001800
_0803196C: .4byte 0x03000590
_08031970: .4byte 0x03002B8C
_08031974: .4byte 0x0300137C
	.syntax divided
