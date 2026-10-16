	.syntax unified

	thumb_func_start sub_0805BB10
sub_0805BB10: @ 0x0805BB10
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0xa0
	bls _0805BB1A
	movs r2, #0
_0805BB1A:
	ldr r0, _0805BB54 @ =0x04000050
	ldr r3, _0805BB58 @ =0x00000844
	adds r1, r3, #0
	strh r1, [r0]
	ldr r1, _0805BB5C @ =0x080AF6F0
	lsls r0, r2, #0x10
	asrs r2, r0, #0x10
	adds r0, r2, #0
	cmp r2, #0
	bge _0805BB30
	adds r0, r2, #7
_0805BB30:
	asrs r0, r0, #3
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r1, r3, #0
	orrs r0, r1
	ldr r1, _0805BB60 @ =0x04000052
	strh r0, [r1]
	adds r1, #2
	movs r0, #8
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bx lr
	.align 2, 0
_0805BB54: .4byte 0x04000050
_0805BB58: .4byte 0x00000844
_0805BB5C: .4byte 0x080AF6F0
_0805BB60: .4byte 0x04000052
	.syntax divided
