	.syntax unified

	thumb_func_start blend_fade_step_0806E2F8
blend_fade_step_0806E2F8: @ 0x0806E2F8
	push {r4, lr}
	ldr r1, _0806E328 @ =0x03001800
	ldr r2, [r1, #8]
	movs r0, #3
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	bne _0806E330
	asrs r2, r2, #2
	movs r1, #0x10
	subs r2, r1, r2
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	subs r1, r1, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, _0806E32C @ =0x04000052
	lsls r0, r1, #8
	orrs r0, r2
	strh r0, [r3]
	cmp r1, #0x10
	bne _0806E330
	movs r0, #1
	b _0806E338
	.align 2, 0
_0806E328: .4byte 0x03001800
_0806E32C: .4byte 0x04000052
_0806E330:
	ldr r0, [r4, #8]
	adds r0, #1
	str r0, [r4, #8]
	movs r0, #0
_0806E338:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
