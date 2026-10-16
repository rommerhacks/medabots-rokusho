	.syntax unified

	thumb_func_start check_bot_can_use_shoot_part
	.global check_bot_can_use_shoot_part
check_bot_can_use_shoot_part: @ 0x08035A24
	push {r4, lr}
	adds r4, r2, #0
	ldr r3, _08035A64 @ =0x03000590
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #3
	lsls r1, r0, #8
	adds r2, r2, r1
	adds r2, r2, r3
	adds r2, #0x49
	ldrb r0, [r2]
	subs r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08035A52
	adds r0, r1, r3
	adds r0, #0xd6
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08035A68
_08035A52:
	adds r0, r4, #0
	movs r1, #0x1a
	bl sub_08035960
	cmp r0, #0
	beq _08035A68
	movs r0, #1
	b _08035A6A
	.align 2, 0
_08035A64: .4byte 0x03000590
_08035A68:
	movs r0, #0
_08035A6A:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
