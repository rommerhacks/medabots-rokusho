	.syntax unified

	thumb_func_start calc_average_bot_stat_0801264C
calc_average_bot_stat_0801264C: @ 0x0801264C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r7, #0
	movs r6, #0
	movs r2, #0
	mov r8, r2
	ldr r0, _080126E0 @ =0x03000590
	ldr r1, _080126E4 @ =0x000003BA
	adds r3, r0, r1
	movs r4, #0xc0
	lsls r4, r4, #2
	adds r1, r0, r4
	movs r4, #0x80
	lsls r4, r4, #1
_0801266A:
	ldrb r0, [r3]
	cmp r0, #0
	beq _08012678
	ldrb r0, [r1, #5]
	adds r7, r7, r0
	movs r0, #1
	add r8, r0
_08012678:
	adds r3, r3, r4
	adds r1, r1, r4
	adds r2, #1
	cmp r2, #2
	bls _0801266A
	adds r0, r7, #0
	mov r1, r8
	bl sub_0807CD58
	adds r7, r0, #0
	movs r2, #0
	movs r5, #0
	ldr r0, _080126E0 @ =0x03000590
	adds r1, r0, #0
	adds r1, #0xba
	adds r3, r0, #0
	movs r4, #0x80
	lsls r4, r4, #1
_0801269C:
	ldrb r0, [r1]
	cmp r0, #0
	beq _080126A8
	ldrb r0, [r3, #5]
	adds r6, r6, r0
	adds r5, #1
_080126A8:
	adds r1, r1, r4
	adds r3, r3, r4
	adds r2, #1
	cmp r2, #2
	bls _0801269C
	adds r0, r6, #0
	adds r1, r5, #0
	bl sub_0807CD58
	adds r6, r0, #0
	cmp r6, r7
	bhs _080126D6
	ldr r1, _080126E8 @ =0x03001800
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r1, r2
	subs r2, r7, r6
	mov r3, r8
	lsls r0, r3, #4
	muls r0, r2, r0
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
_080126D6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080126E0: .4byte 0x03000590
_080126E4: .4byte 0x000003BA
_080126E8: .4byte 0x03001800
	.syntax divided
