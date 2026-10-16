	.syntax unified

	thumb_func_start battle_check_action_counter
	.global battle_check_action_counter
battle_check_action_counter: @ 0x08036D24
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _08036D58 @ =0x03000590
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #3
	lsls r1, r1, #8
	adds r0, r0, r1
	adds r0, r0, r3
	adds r2, r0, #0
	adds r2, #0x59
	adds r0, #0x4c
	ldrb r1, [r2]
	ldrb r0, [r0]
	cmp r1, r0
	beq _08036D5C
	adds r0, r1, #1
	strb r0, [r2]
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08036D5C
	movs r0, #0
	b _08036D5E
	.align 2, 0
_08036D58: .4byte 0x03000590
_08036D5C:
	movs r0, #1
_08036D5E:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
