	.syntax unified

	thumb_func_start sub_0805D59C
sub_0805D59C: @ 0x0805D59C
	push {lr}
	ldr r1, _0805D5D8 @ =0x08483BDC
	ldr r0, _0805D5DC @ =0x0300137C
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r2, _0805D5E0 @ =0x03001780
	ldr r0, [r2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805D5C8
	ldr r0, _0805D5E4 @ =0x03001C04
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldrh r1, [r0, #2]
	adds r1, #1
	strh r1, [r0, #2]
_0805D5C8:
	ldr r0, [r2]
	lsls r0, r0, #0xd
	lsrs r0, r0, #0x10
	bl sub_0805D57C
	pop {r0}
	bx r0
	.align 2, 0
_0805D5D8: .4byte 0x08483BDC
_0805D5DC: .4byte 0x0300137C
_0805D5E0: .4byte 0x03001780
_0805D5E4: .4byte 0x03001C04
	.syntax divided
