	.syntax unified

	thumb_func_start calc_medapart_table_index
	.global calc_medapart_table_index
calc_medapart_table_index: @ 0x0805027C
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	bl sub_08050264
	adds r5, r0, #0
	adds r0, r4, #0
	bl sub_0805026C
	adds r2, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r1, r2, #1
	adds r1, r1, r2
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
