	.syntax unified

	thumb_func_start sub_0800B498
	.global sub_0800B498
sub_0800B498: @ 0x0800B498
	push {r4, r5, r6, lr}
	ldr r5, _0800B4DC @ =0x03000590
	ldr r3, _0800B4E0 @ =0x03001800
	adds r3, #0x80
	ldrb r1, [r3]
	lsls r1, r1, #8
	adds r1, r1, r5
	ldr r4, _0800B4E4 @ =0x03000BE0
	ldr r2, _0800B4E8 @ =0x03000440
	adds r2, #0x3d
	ldrb r0, [r2]
	lsls r0, r0, #6
	adds r0, r0, r4
	ldrb r0, [r0, #9]
	strb r0, [r1, #9]
	movs r6, #0
	adds r5, #0x18
	adds r4, #0x18
_0800B4BC:
	ldrb r0, [r3]
	lsls r0, r0, #8
	adds r0, r6, r0
	adds r0, r0, r5
	ldrb r1, [r2]
	lsls r1, r1, #6
	adds r1, r6, r1
	adds r1, r1, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r6, #1
	cmp r6, #7
	bls _0800B4BC
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800B4DC: .4byte 0x03000590
_0800B4E0: .4byte 0x03001800
_0800B4E4: .4byte 0x03000BE0
_0800B4E8: .4byte 0x03000440
	.syntax divided
