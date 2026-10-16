	.syntax unified

	thumb_func_start binary_search_sorted_table
binary_search_sorted_table: @ 0x080454F0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov ip, r2
	movs r3, #0
	cmp r6, #0
	beq _08045580
	movs r7, #0
	subs r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsrs r3, r2, #1
	cmp r3, #0
	beq _08045552
	cmp r3, r2
	beq _08045552
	lsls r0, r3, #3
	adds r0, r0, r5
	ldrh r0, [r0, #6]
	lsls r1, r0, #0x10
	mov r4, ip
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	cmp r1, r0
	beq _08045552
_08045528:
	asrs r0, r1, #0x10
	cmp r0, r4
	bge _08045530
	adds r7, r3, #0
_08045530:
	cmp r0, r4
	ble _08045536
	adds r2, r3, #0
_08045536:
	adds r0, r7, r2
	lsls r0, r0, #0xf
	lsrs r3, r0, #0x10
	cmp r3, r7
	beq _08045552
	cmp r3, r2
	beq _08045552
	lsls r0, r3, #3
	adds r0, r0, r5
	ldrh r0, [r0, #6]
	lsls r1, r0, #0x10
	asrs r0, r1, #0x10
	cmp r0, r4
	bne _08045528
_08045552:
	cmp r3, r6
	bhs _08045580
	lsls r0, r3, #3
	adds r0, r0, r5
	movs r2, #6
	ldrsh r1, [r0, r2]
	mov r4, ip
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bgt _08045580
	adds r2, r0, #0
_0804556A:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r6
	bhs _08045580
	lsls r0, r3, #3
	adds r0, r0, r5
	movs r1, #6
	ldrsh r0, [r0, r1]
	cmp r0, r2
	ble _0804556A
_08045580:
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.syntax divided
