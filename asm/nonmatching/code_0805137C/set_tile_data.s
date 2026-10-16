	.syntax unified

	thumb_func_start set_tile_data
	.global set_tile_data
set_tile_data: @ 0x08052E0C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r4, _08052E38 @ =0x030057E0
	movs r5, #0x80
	lsls r5, r5, #4
	adds r3, r4, r5
	ldrh r3, [r3]
	lsrs r3, r3, #1
	muls r1, r3, r1
	adds r1, r1, r0
	movs r0, #0x81
	lsls r0, r0, #4
	adds r4, r4, r0
	adds r1, r1, r4
	strb r2, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08052E38: .4byte 0x030057E0
	.syntax divided
