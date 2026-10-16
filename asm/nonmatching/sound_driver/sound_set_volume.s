	.syntax unified

	thumb_func_start sound_set_volume
sound_set_volume: @ 0x0807506C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, _080750BC @ =0x03007014
	ldr r0, [r4]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r3, r0, r2
	ldrh r2, [r3]
	ldr r0, _080750C0 @ =0x0000FFFE
	cmp r2, r0
	bhi _08075086
	adds r0, r2, #1
	strh r0, [r3]
_08075086:
	ldr r0, [r4]
	ldr r2, _080750C4 @ =0x0000072D
	adds r0, r0, r2
	strb r5, [r0]
	ldr r0, [r4]
	adds r2, #1
	adds r0, r0, r2
	strb r1, [r0]
	ldr r1, [r4]
	ldr r0, _080750C8 @ =0x0000072C
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #1
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r4]
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080750B6
	subs r0, #1
	strh r0, [r1]
_080750B6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080750BC: .4byte 0x03007014
_080750C0: .4byte 0x0000FFFE
_080750C4: .4byte 0x0000072D
_080750C8: .4byte 0x0000072C
	.syntax divided
