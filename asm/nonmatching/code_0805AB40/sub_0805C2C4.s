	.syntax unified

	thumb_func_start sub_0805C2C4
sub_0805C2C4: @ 0x0805C2C4
	push {r4, lr}
	ldr r4, _0805C300 @ =0x03006F74
	ldr r0, [r4]
	adds r0, #0x50
	bl blend_fade_step_08065598
	cmp r0, #0
	beq _0805C2FA
	ldr r1, _0805C304 @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r1, [r4]
	movs r0, #0
	strh r0, [r1, #0x3a]
	bl sub_0805BB10
	ldr r1, [r4]
	strh r0, [r1, #0x3a]
	movs r2, #0x80
	lsls r2, r2, #0x13
	ldrh r0, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
_0805C2FA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805C300: .4byte 0x03006F74
_0805C304: .4byte 0x0300137C
	.syntax divided
