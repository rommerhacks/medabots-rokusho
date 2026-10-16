	.syntax unified

	thumb_func_start calc_average_bot_stat_080125B4
calc_average_bot_stat_080125B4: @ 0x080125B4
	push {r4, r5, r6, lr}
	movs r5, #0
	movs r4, #0
	ldr r6, _080125FC @ =0x03001800
	ldr r0, _08012600 @ =0x03000590
	ldr r1, _08012604 @ =0x000003BA
	adds r2, r0, r1
	movs r3, #0xc0
	lsls r3, r3, #2
	adds r1, r0, r3
	movs r3, #0x80
	lsls r3, r3, #1
_080125CC:
	ldrb r0, [r2]
	cmp r0, #0
	beq _080125D6
	ldrb r0, [r1, #5]
	adds r5, r5, r0
_080125D6:
	adds r2, r2, r3
	adds r1, r1, r3
	adds r4, #1
	cmp r4, #2
	bls _080125CC
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r0, r5, #0
	movs r1, #3
	bl sub_0807CD58
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080125FC: .4byte 0x03001800
_08012600: .4byte 0x03000590
_08012604: .4byte 0x000003BA
	.syntax divided
