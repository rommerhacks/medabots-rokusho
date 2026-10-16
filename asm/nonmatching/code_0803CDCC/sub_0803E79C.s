	.syntax unified

	thumb_func_start sub_0803E79C
	.global sub_0803E79C
sub_0803E79C: @ 0x0803E79C
	ldr r2, _0803E7B4 @ =0x03005010
	ldr r0, _0803E7B8 @ =0x0000FFFE
	strh r0, [r2, #6]
	ldrh r1, [r2, #0xa]
	cmp r1, r0
	bne _0803E7BC
	ldrh r0, [r2, #0xe]
	cmp r0, r1
	bne _0803E7BC
	movs r0, #1
	b _0803E7BE
	.align 2, 0
_0803E7B4: .4byte 0x03005010
_0803E7B8: .4byte 0x0000FFFE
_0803E7BC:
	movs r0, #0
_0803E7BE:
	bx lr
	.syntax divided
