	.syntax unified

	thumb_func_start sorted_array_insert_shift
sorted_array_insert_shift: @ 0x08045588
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	adds r1, r5, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	subs r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r1, #0
	beq _080455D6
	adds r0, r5, r2
	lsls r0, r0, #3
	adds r2, r4, r0
	lsls r0, r5, #3
	adds r4, r4, r0
	lsls r0, r3, #0x10
	asrs r3, r0, #0x10
_080455B2:
	movs r1, #6
	ldrsh r0, [r4, r1]
	cmp r0, r3
	ble _080455D4
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	cmp r5, #0
	beq _080455D2
	subs r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	subs r4, #8
	subs r2, #8
	b _080455B2
_080455D2:
	subs r4, #8
_080455D4:
	adds r4, #8
_080455D6:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
