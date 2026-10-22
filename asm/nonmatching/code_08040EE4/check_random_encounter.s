	.syntax unified

	thumb_func_start check_random_encounter
	.global check_random_encounter
check_random_encounter: @ 0x080438C4
	push {lr}
	ldr r2, _08043938 @ =0x030057E0
	ldr r1, _0804393C @ =0x00000C2D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08043958
	ldr r3, _08043940 @ =0x00000C5F
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08043958
	ldr r1, _08043944 @ =0x00000C29
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043958
	ldr r3, _08043948 @ =0x00000C2C
	adds r0, r2, r3
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08043958
	ldr r0, _0804394C @ =0x00000C2B
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bls _08043958
	cmp r0, #0x1f
	bhi _0804391E
	bl rng_next_080424B8
	movs r1, #0x1f
	ands r1, r0
	movs r0, #0
	cmp r1, #0x1f
	bne _0804391A
	movs r0, #1
_0804391A:
	cmp r0, #0
	beq _08043958
_0804391E:
	ldr r1, _08043938 @ =0x030057E0
	ldr r2, _0804394C @ =0x00000C2B
	adds r0, r1, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08043950 @ =0x00000C2E
	adds r0, r1, r3
	strb r2, [r0]
	ldr r0, _08043954 @ =0x00000C2F
	adds r1, r1, r0
	strb r2, [r1]
	movs r0, #1
	b _0804395A
	.align 2, 0
_08043938: .4byte 0x030057E0
_0804393C: .4byte 0x00000C2D
_08043940: .4byte 0x00000C5F
_08043944: .4byte 0x00000C29
_08043948: .4byte 0x00000C2C
_0804394C: .4byte 0x00000C2B
_08043950: .4byte 0x00000C2E
_08043954: .4byte 0x00000C2F
_08043958:
	movs r0, #0
_0804395A:
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
