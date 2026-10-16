	.syntax unified

	thumb_func_start check_room_exit_at_position
	.global check_room_exit_at_position
check_room_exit_at_position: @ 0x080525D8
	push {r4, r5, r6, r7, lr}
	movs r3, #1
	rsbs r3, r3, #0
	ldr r1, _08052614 @ =0x0840FAF4
	ldr r2, _08052618 @ =0x030057E0
	ldr r4, _0805261C @ =0x000007FE
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	movs r1, #0
	ldr r7, _08052620 @ =0x00000C56
	adds r0, r2, r7
	ldrb r5, [r0]
	ldr r4, _08052624 @ =0x00000C57
	adds r0, r2, r4
	ldrb r4, [r0]
	ldr r0, _08052628 @ =0x03002C30
	subs r7, #0x76
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, #1
	beq _08052640
	cmp r0, #1
	bgt _0805262C
	cmp r0, #0
	beq _08052636
	b _08052678
	.align 2, 0
_08052614: .4byte 0x0840FAF4
_08052618: .4byte 0x030057E0
_0805261C: .4byte 0x000007FE
_08052620: .4byte 0x00000C56
_08052624: .4byte 0x00000C57
_08052628: .4byte 0x03002C30
_0805262C:
	cmp r0, #2
	beq _08052658
	cmp r0, #3
	beq _08052662
	b _08052678
_08052636:
	lsls r0, r4, #0x18
	cmp r0, #0
	beq _08052672
	subs r4, #1
	b _08052678
_08052640:
	ldr r7, _08052654 @ =0x00000802
	adds r0, r2, r7
	ldrh r0, [r0]
	lsrs r0, r0, #1
	subs r0, #1
	cmp r4, r0
	beq _08052672
	adds r4, #1
	b _08052678
	.align 2, 0
_08052654: .4byte 0x00000802
_08052658:
	lsls r0, r5, #0x18
	cmp r0, #0
	beq _08052672
	subs r5, #1
	b _08052678
_08052662:
	movs r7, #0x80
	lsls r7, r7, #4
	adds r0, r2, r7
	ldrh r0, [r0]
	lsrs r0, r0, #1
	subs r0, #1
	cmp r5, r0
	bne _08052676
_08052672:
	adds r1, r3, #0
	b _08052678
_08052676:
	adds r5, #1
_08052678:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08052684
	adds r0, r1, #0
	b _080526E8
_08052684:
	ldrb r0, [r6, #2]
	cmp r0, #0
	beq _080526E6
	ldr r7, _080526B4 @ =0x03003810
	adds r2, r6, #0
_0805268E:
	ldrb r0, [r2]
	cmp r0, r5
	bne _080526D6
	ldrb r0, [r2, #1]
	cmp r0, r4
	bne _080526D6
	ldrb r3, [r2, #3]
	cmp r3, #0
	beq _080526D6
	ldrb r1, [r2, #2]
	ldrb r0, [r7]
	cmp r0, #1
	beq _080526CC
	cmp r0, #1
	bgt _080526B8
	cmp r0, #0
	beq _080526C2
	b _080526D6
	.align 2, 0
_080526B4: .4byte 0x03003810
_080526B8:
	cmp r0, #2
	beq _080526C6
	cmp r0, #3
	beq _080526CA
	b _080526D6
_080526C2:
	movs r0, #2
	b _080526CC
_080526C6:
	movs r0, #8
	b _080526CC
_080526CA:
	movs r0, #4
_080526CC:
	ands r1, r0
	cmp r1, #0
	bne _080526D6
	movs r3, #1
	rsbs r3, r3, #0
_080526D6:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r3, r0
	bne _080526E6
	adds r2, #4
	ldrb r0, [r2, #2]
	cmp r0, #0
	bne _0805268E
_080526E6:
	adds r0, r3, #0
_080526E8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
