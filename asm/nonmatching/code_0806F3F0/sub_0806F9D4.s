	.syntax unified

	thumb_func_start sub_0806F9D4
	.global sub_0806F9D4
sub_0806F9D4: @ 0x0806F9D4
	push {r4, r5, r6, lr}
	ldr r4, _0806FA14 @ =0x03001800
	ldrh r6, [r4, #6]
	ldr r5, [r4, #8]
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_0807CC88
	cmp r0, #0
	bne _0806FA20
	adds r0, r5, #0
	adds r1, r6, #0
	bl sub_0807CBBC
	movs r1, #0x10
	subs r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	ldr r0, _0806FA18 @ =0x04000054
	strh r3, [r0]
	ldr r2, _0806FA1C @ =0x0400004C
	movs r0, #0xf
	ands r0, r3
	lsls r1, r0, #4
	orrs r0, r1
	strh r0, [r2]
	cmp r3, #0
	bne _0806FA20
	str r3, [r4, #8]
	movs r0, #1
	b _0806FA28
	.align 2, 0
_0806FA14: .4byte 0x03001800
_0806FA18: .4byte 0x04000054
_0806FA1C: .4byte 0x0400004C
_0806FA20:
	ldr r0, [r4, #8]
	adds r0, #1
	str r0, [r4, #8]
	movs r0, #0
_0806FA28:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	.syntax divided
