	.syntax unified

	thumb_func_start medal_update_exp_progress
	.global medal_update_exp_progress
medal_update_exp_progress: @ 0x08036DE8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldr r2, _08036E10 @ =0x03002C30
	lsls r0, r6, #6
	adds r4, r0, r2
	ldrh r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08036E0A
	adds r3, r4, #0
	adds r3, #0x23
	ldrb r0, [r3]
	cmp r0, #0x10
	bne _08036E14
_08036E0A:
	movs r0, #1
	b _08036E48
	.align 2, 0
_08036E10: .4byte 0x03002C30
_08036E14:
	cmp r5, #0
	bne _08036E2C
	ldr r0, _08036E28 @ =0x083AF4B0
	ldrb r1, [r3]
	adds r1, r1, r0
	ldrh r0, [r4, #2]
	ldrb r1, [r1]
	adds r0, r0, r1
	b _08036E38
	.align 2, 0
_08036E28: .4byte 0x083AF4B0
_08036E2C:
	ldr r1, _08036E50 @ =0x083AF4B0
	ldrb r0, [r3]
	adds r0, r0, r1
	ldrb r1, [r0]
	ldrh r0, [r4, #2]
	subs r0, r0, r1
_08036E38:
	strh r0, [r4, #2]
	lsls r1, r6, #6
	adds r1, r1, r2
	adds r1, #0x23
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0
_08036E48:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08036E50: .4byte 0x083AF4B0
	.syntax divided
