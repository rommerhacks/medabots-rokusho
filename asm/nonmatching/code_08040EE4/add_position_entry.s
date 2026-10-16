	.syntax unified

	thumb_func_start add_position_entry
	.global add_position_entry
add_position_entry: @ 0x08042238
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r4, #0
	movs r5, #1
	ands r3, r5
	adds r2, r3, #0
	adds r2, #0x78
	ldr r1, _08042264 @ =0x030017A0
	movs r6, #0x1e
_0804224C:
	ldrb r0, [r1]
	cmp r0, #0
	bne _08042268
	strb r5, [r1]
	strb r3, [r1, #1]
	strb r6, [r1, #2]
	strb r2, [r1, #3]
	strb r2, [r1, #4]
	strb r2, [r1, #5]
	strb r2, [r1, #6]
	b _08042270
	.align 2, 0
_08042264: .4byte 0x030017A0
_08042268:
	adds r1, #8
	adds r4, #1
	cmp r4, #8
	bls _0804224C
_08042270:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	.syntax divided
