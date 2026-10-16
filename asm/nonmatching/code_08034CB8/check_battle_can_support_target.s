	.syntax unified

	thumb_func_start check_battle_can_support_target
	.global check_battle_can_support_target
check_battle_can_support_target: @ 0x08035AFC
	push {r4, lr}
	adds r4, r2, #0
	ldr r3, _08035B40 @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r1, r0, #8
	adds r2, r2, r1
	adds r2, r2, r3
	adds r2, #0x49
	ldrb r0, [r2]
	subs r0, #6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08035B2A
	adds r0, r1, r3
	adds r0, #0xd6
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08035B44
_08035B2A:
	lsls r0, r4, #8
	adds r0, r0, r3
	adds r0, #0xd6
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08035B44
	movs r0, #1
	b _08035B46
	.align 2, 0
_08035B40: .4byte 0x03000590
_08035B44:
	movs r0, #0
_08035B46:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
