	.syntax unified

	thumb_func_start battle_find_strongest_part
battle_find_strongest_part: @ 0x08039158
	push {r4, lr}
	movs r3, #0
	movs r2, #3
	ldr r1, _08039184 @ =0x03000590
	lsls r0, r0, #8
	adds r1, r1, r0
	adds r1, #0xa1
_08039166:
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039174
	cmp r0, r3
	bls _08039174
	adds r4, r2, #0
	adds r3, r0, #0
_08039174:
	subs r1, #0x18
	subs r2, #1
	cmp r2, #0
	bne _08039166
	adds r0, r4, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08039184: .4byte 0x03000590
	.syntax divided
