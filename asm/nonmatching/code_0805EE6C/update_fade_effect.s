	.syntax unified

	thumb_func_start update_fade_effect
update_fade_effect: @ 0x0805F2AC
	push {r4, lr}
	ldr r4, _0805F2C8 @ =0x03006F74
	ldr r2, [r4]
	ldrb r1, [r2]
	lsls r3, r1, #0x18
	lsrs r0, r3, #0x18
	cmp r0, #0
	beq _0805F2D0
	ldr r0, _0805F2CC @ =0x04000054
	adds r1, #0xff
	strb r1, [r2]
	lsrs r1, r3, #0x19
	strh r1, [r0]
	b _0805F310
	.align 2, 0
_0805F2C8: .4byte 0x03006F74
_0805F2CC: .4byte 0x04000054
_0805F2D0:
	movs r1, #0
	strh r0, [r2, #2]
	strb r1, [r2]
	ldr r0, [r4]
	strb r1, [r0, #6]
	ldr r0, [r4]
	adds r0, #0x48
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0x49
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0x4a
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0x4b
	strb r1, [r0]
	ldr r1, _0805F318 @ =0x03002C30
	ldrh r0, [r1]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r2, r3, #0
	orrs r0, r2
	strh r0, [r1]
	adds r1, #0x40
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	ldr r1, _0805F31C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805F310:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805F318: .4byte 0x03002C30
_0805F31C: .4byte 0x0300137C
	.syntax divided
