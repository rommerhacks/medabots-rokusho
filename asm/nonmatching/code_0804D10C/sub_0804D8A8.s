	.syntax unified

	thumb_func_start sub_0804D8A8
	.global sub_0804D8A8
sub_0804D8A8: @ 0x0804D8A8
	push {r4, r5, r6, lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	movs r3, #0
	ldr r1, _0804D8C8 @ =0x030057E0
	ldr r6, _0804D8CC @ =0x00000FFF
	ldr r2, _0804D8D0 @ =0x000005DE
	adds r4, r1, r2
_0804D8BA:
	ldrh r2, [r4]
	adds r1, r6, #0
	ands r1, r2
	cmp r1, r5
	bne _0804D8D4
	adds r0, r3, #0
	b _0804D8E4
	.align 2, 0
_0804D8C8: .4byte 0x030057E0
_0804D8CC: .4byte 0x00000FFF
_0804D8D0: .4byte 0x000005DE
_0804D8D4:
	adds r4, #8
	adds r3, #1
	cmp r3, #0x3f
	ble _0804D8BA
	cmp r3, #0x40
	bne _0804D8E4
	movs r0, #1
	rsbs r0, r0, #0
_0804D8E4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
