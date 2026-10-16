	.syntax unified

	thumb_func_start sub_0803769C
	.global sub_0803769C
sub_0803769C: @ 0x0803769C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r4, _080376EC @ =0x03001800
	adds r4, #0xe8
	movs r1, #0
	strh r1, [r4]
	ldr r6, _080376F0 @ =0x03000590
	lsls r1, r0, #8
	mov r8, r1
	adds r5, r1, r6
	adds r1, r5, #0
	adds r1, #0xab
	ldrb r1, [r1]
	strh r1, [r4]
	bl calc_bot_matching_part_power
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	bl rng_next_080424B8
	movs r1, #7
	ands r0, r1
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	adds r5, #0xa9
	ldrb r1, [r5]
	add r1, r8
	adds r6, #0x20
	adds r1, r1, r6
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r4]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080376EC: .4byte 0x03001800
_080376F0: .4byte 0x03000590
	.syntax divided
