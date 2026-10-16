	.syntax unified

	thumb_func_start sub_080531EC
	.global sub_080531EC
sub_080531EC: @ 0x080531EC
	push {r4, lr}
	lsls r3, r0, #0x10
	lsrs r2, r3, #0x10
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	bne _08053218
	ldr r0, _08053214 @ =0x030057D8
	ldr r2, [r0]
	lsrs r0, r3, #0x11
	adds r2, r2, r0
	ldrb r1, [r2]
	movs r0, #0x8f
	ands r0, r1
	lsls r1, r4, #4
	orrs r0, r1
	strb r0, [r2]
	b _0805322A
	.align 2, 0
_08053214: .4byte 0x030057D8
_08053218:
	ldr r0, _08053230 @ =0x030057D8
	ldr r1, [r0]
	lsrs r0, r3, #0x11
	adds r1, r1, r0
	ldrb r2, [r1]
	movs r0, #0xf8
	ands r0, r2
	orrs r0, r4
	strb r0, [r1]
_0805322A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08053230: .4byte 0x030057D8
	.syntax divided
