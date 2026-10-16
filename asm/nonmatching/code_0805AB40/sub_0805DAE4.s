	.syntax unified

	thumb_func_start sub_0805DAE4
sub_0805DAE4: @ 0x0805DAE4
	push {r4, lr}
	ldr r0, _0805DB14 @ =0x03006F74
	ldr r2, [r0]
	ldrh r0, [r2, #2]
	adds r1, r0, #1
	strh r1, [r2, #2]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _0805DB18 @ =0x08485788
	ldr r0, [r0, #0x2c]
	bl run_message
	cmp r0, #0
	beq _0805DB0C
	cmp r4, #0x3c
	bls _0805DB0C
	ldr r1, _0805DB1C @ =0x0300137C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805DB0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805DB14: .4byte 0x03006F74
_0805DB18: .4byte 0x08485788
_0805DB1C: .4byte 0x0300137C
	.syntax divided
