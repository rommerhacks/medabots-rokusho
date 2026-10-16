	.syntax unified

	thumb_func_start validate_medapart_stats
	.global validate_medapart_stats
validate_medapart_stats: @ 0x08043814
	push {r4, lr}
	ldr r4, [sp, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	cmp r0, #0x1e
	beq _08043844
	cmp r1, #0x77
	bhi _08043844
	cmp r2, #0x77
	bhi _08043844
	cmp r3, #0x77
	bhi _08043844
	cmp r4, #0x77
	bhi _08043844
	movs r0, #1
	b _08043846
_08043844:
	movs r0, #0
_08043846:
	pop {r4}
	pop {r1}
	bx r1
	.syntax divided
