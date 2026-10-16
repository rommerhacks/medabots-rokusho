	.syntax unified

	thumb_func_start accumulate_team_armor_stats
accumulate_team_armor_stats: @ 0x0801277C
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	movs r4, #0
	ldr r0, _080127CC @ =0x03001800
	mov ip, r0
	ldr r0, _080127D0 @ =0x03000590
	ldr r1, _080127D4 @ =0x00000382
	adds r3, r0, r1
	ldr r7, _080127D8 @ =0x00000352
	adds r2, r0, r7
	adds r1, #0x38
	adds r5, r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
_08012798:
	ldrb r0, [r5]
	cmp r0, #0
	beq _080127AE
	ldrb r0, [r2]
	adds r0, r4, r0
	ldrb r7, [r2, #0x18]
	adds r4, r0, r7
	ldrb r0, [r3]
	adds r0, r4, r0
	ldrb r7, [r3, #0x18]
	adds r4, r0, r7
_080127AE:
	adds r3, r3, r1
	adds r2, r2, r1
	adds r5, r5, r1
	adds r6, #1
	cmp r6, #2
	bls _08012798
	movs r1, #0xb6
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080127CC: .4byte 0x03001800
_080127D0: .4byte 0x03000590
_080127D4: .4byte 0x00000382
_080127D8: .4byte 0x00000352
	.syntax divided
