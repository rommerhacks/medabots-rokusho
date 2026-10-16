	.syntax unified

	thumb_func_start sub_08060FD4
sub_08060FD4: @ 0x08060FD4
	push {r4, lr}
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r4, _08061054 @ =0x084E2E58
	ldr r1, _08061058 @ =0x0202F800
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _0806105C @ =0x084E2E38
	ldr r1, _08061060 @ =0x0202F9E0
	movs r2, #8
	bl CpuFastSet
	ldr r1, _08061064 @ =0x0202F9C0
	adds r0, r4, #0
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08061068 @ =0x08488AA4
	ldr r1, _0806106C @ =0x0202F820
	movs r2, #8
	bl CpuFastSet
	ldr r0, _08061070 @ =0x0879671C
	ldr r1, _08061074 @ =0x0202FA00
	movs r2, #0x80
	bl CpuFastSet
	ldr r0, _08061078 @ =0x03000440
	adds r0, #0x84
	movs r1, #0
	strb r1, [r0]
	ldr r1, _0806107C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08061054: .4byte 0x084E2E58
_08061058: .4byte 0x0202F800
_0806105C: .4byte 0x084E2E38
_08061060: .4byte 0x0202F9E0
_08061064: .4byte 0x0202F9C0
_08061068: .4byte 0x08488AA4
_0806106C: .4byte 0x0202F820
_08061070: .4byte 0x0879671C
_08061074: .4byte 0x0202FA00
_08061078: .4byte 0x03000440
_0806107C: .4byte 0x0300137C
	.syntax divided
