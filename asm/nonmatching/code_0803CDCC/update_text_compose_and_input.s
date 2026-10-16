	.syntax unified

	thumb_func_start update_text_compose_and_input
update_text_compose_and_input: @ 0x080405D0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r2, _08040640 @ =0x03000440
	ldrb r1, [r2, #0x14]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _08040608
	ldrb r0, [r2, #0x14]
	adds r1, r0, #0
	adds r1, #8
	asrs r1, r1, #3
	subs r1, #1
	lsls r1, r1, #0x18
	ldr r0, _08040644 @ =0x02020000
	lsrs r1, r1, #0x12
	ldrb r3, [r2, #0x17]
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #2
	adds r2, r2, r3
	lsls r2, r2, #7
	ldr r3, _08040648 @ =0x06000280
	adds r2, r2, r3
	adds r1, r1, r2
	movs r2, #0x20
	bl CpuSet
_08040608:
	ldr r0, _08040640 @ =0x03000440
	adds r0, #0x25
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08040654
	ldr r0, _0804064C @ =0x083B4AE0
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _08040650 @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #1
	movs r2, #0xe
	movs r3, #0x12
	bl write_tilemap_rect
	b _08040674
	.align 2, 0
_08040640: .4byte 0x03000440
_08040644: .4byte 0x02020000
_08040648: .4byte 0x06000280
_0804064C: .4byte 0x083B4AE0
_08040650: .4byte 0x04000008
_08040654:
	ldr r0, _080406E8 @ =0x083B4AE0
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _080406EC @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #2
	movs r1, #1
	movs r2, #0xe
	movs r3, #0x12
	bl write_tilemap_rect
_08040674:
	ldr r4, _080406F0 @ =0x03000440
	adds r6, r4, #0
	adds r6, #0x25
	ldrb r0, [r6]
	adds r0, #1
	movs r5, #0
	strb r0, [r6]
	movs r0, #1
	strb r0, [r4, #0x13]
	ldr r0, _080406F4 @ =0x03001798
	ldrb r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08040700
	movs r0, #0xd
	bl play_sound_effect
	strb r5, [r4, #0x14]
	strb r5, [r4, #0x16]
	strb r5, [r4, #0x18]
	strb r5, [r4, #0x19]
	strb r5, [r4, #0x17]
	strb r5, [r6]
	ldr r0, _080406E8 @ =0x083B4AE0
	movs r3, #0x92
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [sp]
	ldr r0, _080406EC @ =0x04000008
	ldrh r0, [r0]
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #2
	movs r1, #1
	movs r2, #0xe
	movs r3, #0x12
	bl write_tilemap_rect
	movs r4, #0
_080406C6:
	lsls r1, r4, #6
	ldr r0, _080406F8 @ =0x06000280
	adds r1, r1, r0
	ldr r0, _080406FC @ =0x084C01C8
	movs r2, #0x20
	bl CpuSet
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x33
	bls _080406C6
	ldr r1, _080406F0 @ =0x03000440
	movs r0, #0
	strb r0, [r1, #0x13]
	movs r0, #1
	b _08040702
	.align 2, 0
_080406E8: .4byte 0x083B4AE0
_080406EC: .4byte 0x04000008
_080406F0: .4byte 0x03000440
_080406F4: .4byte 0x03001798
_080406F8: .4byte 0x06000280
_080406FC: .4byte 0x084C01C8
_08040700:
	movs r0, #0
_08040702:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
