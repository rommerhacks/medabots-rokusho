	.syntax unified

	thumb_func_start sub_0806FF50
	.global sub_0806FF50
sub_0806FF50: @ 0x0806FF50
	ldr r2, _0806FF80 @ =0x03001800
	movs r3, #0
	movs r1, #0xc
	adds r0, r2, #0
	adds r0, #0xea
_0806FF5A:
	strh r3, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0806FF5A
	movs r1, #0
	adds r0, r2, #0
	adds r0, #0xd0
	strb r1, [r0]
	ldr r1, _0806FF84 @ =0x040000D4
	adds r0, #2
	str r0, [r1]
	ldr r0, _0806FF88 @ =0x0600FC44
	str r0, [r1, #4]
	ldr r0, _0806FF8C @ =0x8000000D
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	bx lr
	.align 2, 0
_0806FF80: .4byte 0x03001800
_0806FF84: .4byte 0x040000D4
_0806FF88: .4byte 0x0600FC44
_0806FF8C: .4byte 0x8000000D
	.syntax divided
