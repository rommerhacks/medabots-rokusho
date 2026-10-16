	.syntax unified

	thumb_func_start sub_0806FF90
	.global sub_0806FF90
sub_0806FF90: @ 0x0806FF90
	sub sp, #4
	mov r0, sp
	movs r3, #0
	strh r3, [r0]
	ldr r0, _0806FFDC @ =0x040000D4
	mov r1, sp
	str r1, [r0]
	ldr r1, _0806FFE0 @ =0x0600FB0A
	str r1, [r0, #4]
	ldr r2, _0806FFE4 @ =0x8100000A
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	mov r1, sp
	strh r3, [r1]
	str r1, [r0]
	ldr r1, _0806FFE8 @ =0x0600FB4A
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	mov r1, sp
	strh r3, [r1]
	str r1, [r0]
	ldr r1, _0806FFEC @ =0x0600FB8A
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r1, [r0, #8]
	mov r1, sp
	strh r3, [r1]
	str r1, [r0]
	ldr r1, _0806FFF0 @ =0x0600FBCA
	str r1, [r0, #4]
	str r2, [r0, #8]
	ldr r0, [r0, #8]
	ldr r0, _0806FFF4 @ =0x03001800
	adds r0, #0x2e
	strb r3, [r0]
	add sp, #4
	bx lr
	.align 2, 0
_0806FFDC: .4byte 0x040000D4
_0806FFE0: .4byte 0x0600FB0A
_0806FFE4: .4byte 0x8100000A
_0806FFE8: .4byte 0x0600FB4A
_0806FFEC: .4byte 0x0600FB8A
_0806FFF0: .4byte 0x0600FBCA
_0806FFF4: .4byte 0x03001800
	.syntax divided
