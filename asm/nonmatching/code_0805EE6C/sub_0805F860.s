	.syntax unified

	thumb_func_start sub_0805F860
sub_0805F860: @ 0x0805F860
	push {lr}
	ldr r0, _0805F88C @ =0x08485788
	ldr r0, [r0, #0x40]
	bl run_message
	cmp r0, #0
	beq _0805F886
	ldr r0, _0805F890 @ =0x03006F74
	ldr r2, [r0]
	ldrh r0, [r2, #2]
	adds r1, r0, #1
	strh r1, [r2, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3c
	bls _0805F886
	ldr r1, _0805F894 @ =0x0300137C
	movs r0, #0xd
	str r0, [r1]
_0805F886:
	pop {r0}
	bx r0
	.align 2, 0
_0805F88C: .4byte 0x08485788
_0805F890: .4byte 0x03006F74
_0805F894: .4byte 0x0300137C
	.syntax divided
