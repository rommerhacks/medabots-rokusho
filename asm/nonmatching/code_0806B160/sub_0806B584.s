	.syntax unified

	thumb_func_start sub_0806B584
	.global sub_0806B584
sub_0806B584: @ 0x0806B584
	sub sp, #4
	lsls r0, r0, #0x18
	movs r1, #0
	str r1, [sp]
	ldr r2, _0806B5A4 @ =0x040000D4
	mov r1, sp
	str r1, [r2]
	lsrs r0, r0, #0x12
	ldr r1, _0806B5A8 @ =0x03002C30
	adds r0, r0, r1
	str r0, [r2, #4]
	ldr r0, _0806B5AC @ =0x85000010
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	add sp, #4
	bx lr
	.align 2, 0
_0806B5A4: .4byte 0x040000D4
_0806B5A8: .4byte 0x03002C30
_0806B5AC: .4byte 0x85000010
	.syntax divided
