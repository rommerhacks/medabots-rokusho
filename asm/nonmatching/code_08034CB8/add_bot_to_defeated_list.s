	.syntax unified

	thumb_func_start add_bot_to_defeated_list
	.global add_bot_to_defeated_list
add_bot_to_defeated_list: @ 0x08035234
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _08035258 @ =0x03000590
	lsls r1, r2, #8
	adds r1, r1, r0
	adds r1, #0x59
	ldrb r0, [r1]
	cmp r0, #0
	bne _08035266
	movs r3, #0
	ldr r4, _0803525C @ =0x030018E0
	adds r1, r2, #1
_0803524C:
	adds r2, r3, r4
	ldrb r0, [r2]
	cmp r0, #0
	bne _08035260
	strb r1, [r2]
	b _08035266
	.align 2, 0
_08035258: .4byte 0x03000590
_0803525C: .4byte 0x030018E0
_08035260:
	adds r3, #1
	cmp r3, #2
	bls _0803524C
_08035266:
	pop {r4}
	pop {r0}
	bx r0
	.syntax divided
