	.syntax unified

	thumb_func_start sound_update_master_volume
	.global sound_update_master_volume
sound_update_master_volume: @ 0x0807387C
	push {r4, r5, lr}
	ldr r0, _080738BC @ =0x03007014
	ldr r3, [r0]
	ldr r0, _080738C0 @ =0x0000072C
	adds r4, r3, r0
	ldrb r1, [r4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080738B4
	ldr r2, _080738C4 @ =0x04000080
	ldr r1, _080738C8 @ =0x0000072D
	adds r0, r3, r1
	ldrb r1, [r0]
	lsls r1, r1, #4
	movs r5, #0xff
	lsls r5, r5, #8
	adds r0, r5, #0
	orrs r1, r0
	ldr r5, _080738CC @ =0x0000072E
	adds r0, r3, r5
	ldrb r0, [r0]
	orrs r0, r1
	strh r0, [r2]
	ldrb r1, [r4]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r4]
_080738B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080738BC: .4byte 0x03007014
_080738C0: .4byte 0x0000072C
_080738C4: .4byte 0x04000080
_080738C8: .4byte 0x0000072D
_080738CC: .4byte 0x0000072E
	.syntax divided
