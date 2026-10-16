	.syntax unified

	thumb_func_start sub_0805E170
sub_0805E170: @ 0x0805E170
	lsls r0, r0, #0x10
	ldr r2, _0805E18C @ =0x03002C30
	ldr r3, _0805E190 @ =0x080AF808
	movs r1, #0xc0
	lsls r1, r1, #0xa
	ands r1, r0
	lsrs r1, r1, #0xf
	adds r1, r1, r3
	ldrh r0, [r1]
	ldr r1, _0805E194 @ =0x00000506
	adds r2, r2, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_0805E18C: .4byte 0x03002C30
_0805E190: .4byte 0x080AF808
_0805E194: .4byte 0x00000506
	.syntax divided
