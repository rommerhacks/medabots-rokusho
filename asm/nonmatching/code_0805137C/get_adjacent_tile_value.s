	.syntax unified

	thumb_func_start get_adjacent_tile_value
	.global get_adjacent_tile_value
get_adjacent_tile_value: @ 0x0805247C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r0, #0
	cmp r0, #1
	beq _080524D0
	cmp r0, #1
	bgt _08052492
	cmp r0, #0
	beq _0805249C
	b _0805255E
_08052492:
	cmp r2, #2
	beq _08052504
	cmp r2, #3
	beq _08052538
	b _0805255E
_0805249C:
	ldr r2, _080524C4 @ =0x030057E0
	ldr r1, _080524C8 @ =0x00000C57
	adds r0, r2, r1
	ldrb r1, [r0]
	subs r1, #1
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r2, r3
	ldrh r0, [r0]
	lsrs r0, r0, #1
	ldr r4, _080524CC @ =0x00000C56
	adds r3, r2, r4
	muls r0, r1, r0
	ldrb r3, [r3]
	adds r0, r0, r3
	movs r1, #0x81
	lsls r1, r1, #4
	adds r2, r2, r1
	adds r0, r0, r2
	b _0805255C
	.align 2, 0
_080524C4: .4byte 0x030057E0
_080524C8: .4byte 0x00000C57
_080524CC: .4byte 0x00000C56
_080524D0:
	ldr r2, _080524F8 @ =0x030057E0
	ldr r3, _080524FC @ =0x00000C57
	adds r0, r2, r3
	ldrb r1, [r0]
	adds r1, #1
	movs r4, #0x80
	lsls r4, r4, #4
	adds r0, r2, r4
	ldrh r0, [r0]
	lsrs r0, r0, #1
	ldr r4, _08052500 @ =0x00000C56
	adds r3, r2, r4
	muls r0, r1, r0
	ldrb r3, [r3]
	adds r0, r0, r3
	movs r1, #0x81
	lsls r1, r1, #4
	adds r2, r2, r1
	adds r0, r0, r2
	b _0805255C
	.align 2, 0
_080524F8: .4byte 0x030057E0
_080524FC: .4byte 0x00000C57
_08052500: .4byte 0x00000C56
_08052504:
	ldr r1, _0805252C @ =0x030057E0
	ldr r2, _08052530 @ =0x00000C57
	adds r0, r1, r2
	ldrb r2, [r0]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r1, r3
	ldrh r0, [r0]
	lsrs r0, r0, #1
	muls r0, r2, r0
	ldr r4, _08052534 @ =0x00000C56
	adds r2, r1, r4
	subs r0, #1
	ldrb r2, [r2]
	adds r0, r0, r2
	movs r2, #0x81
	lsls r2, r2, #4
	adds r1, r1, r2
	b _0805255A
	.align 2, 0
_0805252C: .4byte 0x030057E0
_08052530: .4byte 0x00000C57
_08052534: .4byte 0x00000C56
_08052538:
	ldr r1, _08052568 @ =0x030057E0
	ldr r3, _0805256C @ =0x00000C57
	adds r0, r1, r3
	ldrb r2, [r0]
	movs r4, #0x80
	lsls r4, r4, #4
	adds r0, r1, r4
	ldrh r0, [r0]
	lsrs r0, r0, #1
	muls r0, r2, r0
	subs r3, #1
	adds r2, r1, r3
	adds r0, #1
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r4, #0x10
	adds r1, r1, r4
_0805255A:
	adds r0, r0, r1
_0805255C:
	ldrb r1, [r0]
_0805255E:
	adds r0, r1, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08052568: .4byte 0x030057E0
_0805256C: .4byte 0x00000C57
	.syntax divided
